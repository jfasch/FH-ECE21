from collections import deque
from matplotlib import pyplot

def make_fenster():
    fenster = deque(maxlen=100)
    x_axis = list(range(100))
    for x in x_axis:
        fenster.append(
            {
                'sensor-a': x**2,
                'sensor-b': x**1.5,
            }
        )
    return fenster

def show_fenster(fenster):
    x = list(range(len(fenster)))
    y_sensor_a = [sample['sensor-a'] for sample in fenster]
    y_sensor_b = [sample['sensor-b'] for sample in fenster]
    pyplot.plot(x, y_sensor_a)
    pyplot.plot(x, y_sensor_b)
    pyplot.show()


while True:
    fenster = make_fenster()
    show_fenster(fenster)
