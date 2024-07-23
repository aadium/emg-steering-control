#include <Servo.h>

Servo myservo;

const float setValue=2800.00;

int rightsensor;
int leftsensor;
float voltageLeft;
float voltageRight;

void setup() {

  myservo.attach(13);
  Serial.begin(9600);

  delay(100);
  
}

void loop() {

  rightsensor = analogRead(A0);
  leftsensor = analogRead(A1);

  voltageRight = rightsensor * (5.0 / 1023.0) * 1000;
  voltageLeft = leftsensor * (5.0 / 1023.0) * 1000;

  Serial.print("Right sensor value: ");
  Serial.print(rightsensor);
  Serial.print(" - Voltage (mV): ");
  Serial.println(voltageRight);

  Serial.print("Left sensor value: ");
  Serial.print(leftsensor);
  Serial.print(" - Voltage (mV): ");
  Serial.println(voltageLeft);

  Serial.println(); // Just to add a blank line for better readability

  if(voltageRight>setValue && voltageLeft<setValue){
    myservo.write(180);
    delay(100);
  }
  else if(voltageRight<setValue && voltageLeft>setValue){
    myservo.write(0);
    delay(100);
  }
  else {
    myservo.write(90);
    delay(100);
  }
}