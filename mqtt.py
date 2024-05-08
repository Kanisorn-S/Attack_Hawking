import paho.mqtt.client as paho
import keyboard
import sys

client = paho.Client()

print("Program running. ")
print("Press C to exit")

while True:
    if client.connect("test.mosquitto.org", 1883, 60):
        print("Could not connect to MQTT Broker!")
        sys.exit(-1)
    
    key_event = keyboard.read_event(suppress=True)
    if key_event.event_type == keyboard.KEY_DOWN:
        key_char = key_event.name
        if key_char == "c":
            break
        client.publish("carControl", key_char, 0)


    client.disconnect()