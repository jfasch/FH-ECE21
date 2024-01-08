#!/usr/bin/env python

import json
from collections import defaultdict
from paho.mqtt import client
from matplotlib import pyplot


fenster = []

def message_received(client, userdata, message):
    values = json.loads(message.payload)
    fenster.append(values)

    sensor_names = list(values.keys())
    x = list(range(len(fenster)))
    ys = defaultdict(list)
    for sample in fenster:
        for name in sensor_names:
            ys[name].append(sample[name])

    #print(x, ys)
    for _, y in ys.items():
        pyplot.plot(x, y)

    pyplot.show()
    

c = client.Client()
c.connect('localhost', 1883)
c.on_message = message_received

c.subscribe('kochtopf')
c.loop_forever()
