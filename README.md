Arduino Hand gesture Control Computer using Python 

Aim of this project try control keybord without tuach the keybord 
so i'm using python 'pyautogui' module and arduino 

Take the input using ultrosonic sensor and process the input and send to the computer thouer com3 port and get the input using python using pyautogui module get the out put 



#iot coding

const int tripin = A0;
const int echopin = A1;
const int tripin1 = A2;
const int echopin1 = A3;

long duration;
int distance;
long duration1;
int distance1;

void setup() {
  Serial.begin(9600);
  
  pinMode(tripin, OUTPUT);
  pinMode(echopin, INPUT);
  
  pinMode(tripin1, OUTPUT);
  pinMode(echopin1, INPUT);
}

void loop() {
  // First sensor
  digitalWrite(tripin, LOW);
  delayMicroseconds(2);

  digitalWrite(tripin, HIGH);
  delayMicroseconds(10);
  digitalWrite(tripin, LOW);

  duration = pulseIn(echopin, HIGH, 30000); // 30ms timeout
  distance = duration * 0.0344 / 2;

 
  
  // Second sensor
  digitalWrite(tripin1, LOW);
  delayMicroseconds(2);

  digitalWrite(tripin1, HIGH);
  delayMicroseconds(10);
  digitalWrite(tripin1, LOW);

  duration1 = pulseIn(echopin1, HIGH, 30000); // 30ms timeout
  distance1 = duration1 * 0.0344 / 2;

  

  if (distance<10 && distance1>0){
    Serial.println("value up");

  }
  else if( distance<20 && distance1>0){
     Serial.println("value down");
  }
   else if(distance>0 && distance1<10){
     Serial.println("right");
    
  }
   else if(distance>0 && distance1<20){
     Serial.println("left");
  }
   else if(distance<40 && distance1<40){
     Serial.println("pass");
  }
    
  // Add a small delay to avoid flooding the serial monitor
  delay(1000);
} 




# python coding

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
