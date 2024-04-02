import socket
import keyboard

target_ip = "Wifi-name"
target_port = 4210

udp_socket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)

print("Program running.")
print("Press Ctrl+C to exit")

try:
    while True:
        key_event = keyboard.read_event(suppress = True)
        if key_event.event_type == keyboard.KEY_DOWN:
            key_char = key_event.name
            udp_socket.sendto(key_char.encode(), (target_ip, target_port))

except KeyboardInterrupt:
    print("Program terminated by the user.")
finally:
    udp_socket.close()