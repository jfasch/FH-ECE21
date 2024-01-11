import tkinter as tk
from tkinter import ttk
import paho.mqtt.client as mqtt
import json
import matplotlib.pyplot as plt
from matplotlib.backends.backend_tkagg import FigureCanvasTkAgg
from pygame import mixer
from collections import deque
from PIL import Image, ImageTk
import cv2

#########################################################
#####################   MQT   ###########################
#########################################################
class MQTTSubscriber:
    def __init__(self, master):
        self.master = master
        master.title("MQTT Subscriber")

        # Variables to store MQTT server address and port
        self.server_address = tk.StringVar(value="10.36.40.112")
        self.server_port = tk.IntVar(value=1883)

        # MQTT client setup
        self.client = mqtt.Client()
        self.client.on_message = self.on_message
        self.client.on_connect = self.on_connect

        # Flag to track whether the client is connected
        self.connected = False

        self.temperature_buffer = {}

        # GUI setup
        self.setup_gui()

    def setup_gui(self):
        # Entry for MQTT server address
        ttk.Label(self.master, text="Server Address:").grid(row=0, column=0, sticky="w")
        address_entry = ttk.Entry(self.master, textvariable=self.server_address)
        address_entry.grid(row=0, column=1, padx=5, pady=5, sticky="ew")

        # Scale for MQTT server port
        ttk.Label(self.master, text="Server Port:").grid(row=1, column=0, sticky="w")
        port_scale = ttk.Scale(self.master, from_=1500, to=2000, variable=self.server_port, orient="horizontal")
        port_scale.grid(row=1, column=1, padx=5, pady=5, sticky="ew")
        
        # Entry to display the current port value
        port_entry = ttk.Entry(self.master, textvariable=self.server_port, state="readonly", width=6)
        port_entry.grid(row=1, column=2, padx=5, pady=5, sticky="w")

        # Button to connect to MQTT broker
        connect_button = ttk.Button(self.master, text="Connect", command=self.connect_to_broker)
        connect_button.grid(row=0, column=4, columnspan=1, pady=10)

        # Connection status label
        self.connection_status_label = ttk.Label(self.master, text="Disconnected!", foreground="red")
        self.connection_status_label.grid(row=2, column=4, columnspan=1, pady=1)

        # Disconnect button
        disconnect_button = ttk.Button(self.master, text="Disconnect", command=self.disconnect_from_broker)
        disconnect_button.grid(row=1, column=4, columnspan=1, pady=10)

        # Matplotlib plot
        self.fig, self.ax = plt.subplots()

        # Set plot labels and legend
        self.ax.set_xlabel("Measurements")
        self.ax.set_ylabel("Temperature")
        self.ax.set_ylim(10, 90)

        self.canvas = FigureCanvasTkAgg(self.fig, master=self.master)
        self.canvas.get_tk_widget().grid(row=3, column=0, columnspan=6)

        # Set initial value in the port entry
        self.update_port_entry()

        # Update the port entry when the scale is adjusted
        port_scale.config(command=lambda value: self.update_port_entry())

        # Play music continuously
        self.play_music()
        
        # Load and display the video
        video_path = "image.gif"  # Replace "video.mp4" with the path to your video file
        self.video = cv2.VideoCapture(video_path)
        self.success, self.frame = self.video.read()
        self.image_label = ttk.Label(self.master)
        self.image_label.grid(row=0, column=5, rowspan=3, padx=10, pady=10)
        self.animate()
        
      

    def animate(self):
        if self.success:
            image = cv2.cvtColor(self.frame, cv2.COLOR_BGR2RGB)
            self.photo = self.get_photo_image(image)
            self.image_label.configure(image=self.photo)
            self.image_label.image = self.photo

        # Read the next frame
        self.success, self.frame = self.video.read()

        # Check if the video has reached the end
        if not self.success:
            # Reset the video to the beginning
            self.video.set(cv2.CAP_PROP_POS_FRAMES, 0)
            self.success, self.frame = self.video.read()

        # Schedule the next animation frame
        self.master.after(30, self.animate)

    def get_photo_image(self, image):
        return ImageTk.PhotoImage(image=Image.fromarray(image))

    def update_port_entry(self):
        # Update the port entry to show the current scale value
        self.server_port.set(int(self.server_port.get()))

    def connect_to_broker(self):
        try:
            # Connect to MQTT broker
            server_address = self.server_address.get()
            server_port = self.server_port.get()
            self.client.connect(server_address, server_port, 60)
            self.client.subscribe("fh-ece21")  # replace this text with the topic to subscribe to
            self.client.loop_start()

            # Clear the plot
            self.ax.clear()

            # Update connection status label
            self.update_connection_status(True)
            
            # Initial empty plot
            self.plot_temperatures({}, {"sensor_empty":"empty"})

        except Exception as e:
            # Handle connection error
            tk.messagebox.showerror("Error", f"Failed to connect: {str(e)}")

    def disconnect_from_broker(self):
        try:
            if self.connected:
                # Unsubscribe and disconnect only if connected
                self.client.unsubscribe("fh-ece21")
                self.client.disconnect()
                self.client.loop_stop()  # Stop the MQTT loop
                self.connected = False
                self.update_connection_status(False)
        except Exception as e:
            tk.messagebox.showerror("Error", f"Failed to disconnect: {str(e)}")

    def on_connect(self, client, userdata, flags, rc):
        if rc == 0:
            self.connected = True
            self.update_connection_status(True)
        else:
            self.connected = False
            self.update_connection_status(False)

    def update_connection_status(self, connected):
        status_text = "Connected!" if connected else "Disconnected!"
        color = "green" if connected else "red"
        self.connection_status_label.config(text=status_text, foreground=color)

    def on_message(self, client, userdata, msg):
        try:
            # Decode JSON data from the received message payload
            data = json.loads(msg.payload.decode())


            if not self.temperature_buffer:
                # Initialize buffers based on the number of sensors in the first message
                for i, sensor in enumerate(data.keys()):
                    self.temperature_buffer[i] = CircularBuffer(max_size=50)

            for i, (sensor, temperature) in enumerate(data.items()):
                self.temperature_buffer[i].append(temperature)

            self.plot_temperatures(self.temperature_buffer, list(data.keys()))

        except json.JSONDecodeError:
            print("Invalid JSON data")

    def plot_temperatures(self, data, sensor_names):
        # Clear existing plot
        self.ax.clear()

        # Plot each sensor's temperature
        for i, (sensor, buffer) in enumerate(data.items()):
            temperatures = buffer.get_values()
            self.ax.plot(range(len(temperatures)), temperatures, marker="o", label=sensor_names[i])

        self.ax.set_xlabel("Measurements")
        self.ax.set_ylabel("Temperature")
        self.ax.legend(loc='lower left')
        # Set y-axis limits
        self.ax.set_ylim(10, 90)

        # Calculate averages
        averages = self.calculate_averages(data)

        # Display averages as text
        avg_text = "\n".join([f'{"Average Temperature of " + sensor_names[i]}: {avg_temp:.2f} °C' for sensor, avg_temp in averages.items()])        
        self.ax.text(0.02, 0.98, avg_text, transform=self.ax.transAxes,
                    verticalalignment='top', horizontalalignment='left',
                    bbox=dict(boxstyle='round', facecolor='wheat', alpha=0.5))

        # Redraw the canvas
        self.canvas.draw()


    def calculate_averages(self, data):
            averages = {}
            for sensor, buffer in data.items():
                temperatures = buffer.get_values()
                if temperatures:
                    avg_temp = sum(temperatures) / len(temperatures)
                    averages[sensor] = avg_temp
            return averages
    
    def play_music(self):
        mixer.init()
        mixer.music.load('chipi.mp3')  # Replace with the path to your music file
        mixer.music.play(-1)  # -1 indicates infinite loop

    def stop_music(self):
        mixer.music.stop()

    def on_close(self):
        # Stop music when closing the window
        self.stop_music()
        # Disconnect from the broker if connected
        self.disconnect_from_broker()
        # Close the window
        self.master.destroy()



#########################################################
################   Circular Buffer   ####################
#########################################################
class CircularBuffer:
    def __init__(self, max_size):
        self.buffer = deque(maxlen=max_size)

    def append(self, item):
        self.buffer.append(item)

    def get_values(self):
        return self.buffer
    

#########################################################
######################   Main   #########################
#########################################################
def main():
    root = tk.Tk()
    app = MQTTSubscriber(root)
    # Set fixed window size
    #root.geometry("800x680")  # Change the values as needed

    # Disable window resizing
    #root.resizable(False, False)
    # Bind close event to on_close method
    root.protocol("WM_DELETE_WINDOW", app.on_close) 
    root.mainloop()


if __name__ == "__main__":
    main()
