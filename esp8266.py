import socket
import keyboard
import sys

target_ip = "192.168.1.145"
target_port = 4210

udp_socket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)

print("Program running. ")
print("Press C to exit")


while True:
    key_event = keyboard.read_event(suppress=True)
    if key_event.event_type == keyboard.KEY_DOWN:
        key_char = key_event.name
        if key_char == "c":
            break
        udp_socket.sendto(key_char.encode(), (target_ip, target_port))

udp_socket.close()