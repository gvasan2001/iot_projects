import serial
import pyautogui
import time

# Configure the serial port       (ajust 'COM3' to your port and 9600 to your baud rate)
ser = serial.Serial('/dev/ttyACM0', 9600, timeout=1)
time.sleep(2)  # Wait for the serial connection to initialize

def simulate_key_press(command):
    if command == 'value up':
        print("Up Arrow Key Pressed")
        pyautogui.press('up')  # Simulate UP arrow key press
    elif command == 'value down':
        print("Down Arrow Key Pressed")
        pyautogui.press('down')  # Simulate DOWN arrow key press
    elif command == 'right':
        print("Left Arrow Key Pressed")
        pyautogui.press('left')  # Simulate LEFT arrow key press
    elif command == 'left':
        print("Right Arrow Key Pressed")
        pyautogui.press('right')
    elif command == 'pass':
        print("Right Arrow Key Pressed")
        pyautogui.press('space')



while True:
    if ser.in_waiting > 0:
        command = ser.readline().decode('utf-8').strip()
        print(f"Command received: {command}")  # Debugging line
        simulate_key_press(command)
