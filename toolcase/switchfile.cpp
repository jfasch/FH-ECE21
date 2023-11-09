#include <iostream>
#include <fstream>
#include <string>
#include <unistd.h>

class SysFSGPIOSwitch {
private:
    int gpioNumber;

    // Helper function to write a value to a sysfs file
    void writeToFile(const std::string& path, const std::string& value) {
        std::ofstream file(path.c_str());
        if (file.is_open()) {
            file << value;
            file.close();
        } else {
            std::cerr << "Unable to open file: " << path << std::endl;
        }
    }

public:
    // Constructor
    SysFSGPIOSwitch(int gpioNum) : gpioNumber(gpioNum) {
        // Export the GPIO
        writeToFile("/sys/class/gpio/export", std::to_string(gpioNumber));

        // Wait a bit until the gpio directory becomes visible
        usleep(100000); // Sleep for 100ms

        // Configure for output
        writeToFile("/sys/class/gpio/gpio" + std::to_string(gpioNumber) + "/direction", "out");
    }

    // Destructor
    ~SysFSGPIOSwitch() {
        // Unexport the GPIO
        writeToFile("/sys/class/gpio/unexport", std::to_string(gpioNumber));
    }

    // Method to set the state of the GPIO (0 or 1)
    void set_state(bool state) {
        writeToFile("/sys/class/gpio/gpio" + std::to_string(gpioNumber) + "/value", std::to_string(state));
    }
};

int main() {
    // Create an instance of SysFSGPIOSwitch for GPIO pin 20
    SysFSGPIOSwitch gpioSwitch(20);

    // Set the state to 1 (HIGH)
    gpioSwitch.set_state(true);

    // Sleep for a while
    usleep(1000000); // Sleep for 1 second

    // Set the state to 0 (LOW)
    gpioSwitch.set_state(false);

    return 0;
}
