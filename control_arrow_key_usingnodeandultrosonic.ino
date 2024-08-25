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
