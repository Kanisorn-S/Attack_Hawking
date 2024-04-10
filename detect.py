# Import neccesary modules
import keyboard
import sys
from BlynkLib import *
import time

# Blynk authentication token 
'''
#define BLYNK_TEMPLATE_ID "TMPL69_HKO5iy"
#define BLYNK_TEMPLATE_NAME "Mahn automatic"
#define BLYNK_AUTH_TOKEN "cFMczdEq_b1rYcfLezwHhQu2RzY9lJOG"
'''
BLYNK_AUTH = "cFMczdEq_b1rYcfLezwHhQu2RzY9lJOG"

# Initialize Blynk
blynk = Blynk(BLYNK_AUTH)

# Start keyboard input program
print("Program running.")
print("Press c to exit")

while True:
    blynk.run()
    key_event = keyboard.read_event(suppress = True)
    if key_event.event_type == keyboard.KEY_DOWN:
        key_char = key_event.name
        if key_char == "c":
            sys.exit()
        print(f"{key_char} is being pressed")
        try:
           blynk.virtual_write(0, int(key_char)) 
        except:
            print("Can only input single digit integer")
        

