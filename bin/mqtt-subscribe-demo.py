#!/usr/bin/env python

from paho.mqtt import client

def message_received(client, userdata, message):
    print(message.payload)

c = client.Client()
c.connect('localhost', 1883)
c.on_message = message_received

c.subscribe('fh-ece21')
c.loop_forever()
