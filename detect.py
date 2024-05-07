# Import neccesary modules
import keyboard
import sys
from BlynkLib import *
from BlynkTimer import BlynkTimer
import time

def sendInput():
    key_event = keyboard.read_event(suppress = True)
    if key_event.event_type == keyboard.KEY_DOWN:
        key_char = key_event.name
        if key_char == "c":
            sys.exit()
        print(f"{key_char} is being pressed")
        try:1
            blynk.virtual_write(1, int(key_char))
        except:
            print("Can only input single digit integer")

# Blynk authentication token 
'''
#define BLYNK_TEMPLATE_NAME "Attack Hawking"
#define BLYNK_AUTH_TOKEN "Y2K5GmGI1MxgwPn_oQJZFnHRGZO4B1JG"
'''
BLYNK_AUTH = "Y2K5GmGI1MxgwPn_oQJZFnHRGZO4B1JG"

# Initialize Blynk
blynk = Blynk(BLYNK_AUTH)
timer = BlynkTimer()

timer.set_interval(1, sendInput)

# Start keyboard input program
print("Program running.")
print("Press c to exit")

while True:
    blynk.run()
    timer.run()
    

        

