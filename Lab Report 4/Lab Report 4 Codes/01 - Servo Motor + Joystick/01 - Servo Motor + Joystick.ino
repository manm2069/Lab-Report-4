/*
  Servo Motor + Joystick

  This program moves the servo motor accordingly to the position of the joystick

  This program makes use of #include, Servo, int, void, myservo.attach, analogRead, map, myservo.write, and delay.
*/

#include <Servo.h> // Includes the servo library in the code

Servo myservo;  // Create servo object to control a servo

int potpin = A0;  // Analog pin used to connect the joystick
int val;    // Variable to read the value from the analog pin

void setup() {
  myservo.attach(9);  // Attaches the servo on pin 9 to the servo object
}

void loop() {
  val = analogRead(potpin);            // Reads the value of the joystick (value between 0 and 1023)
  val = map(val, 0, 1023, 0, 180);     // Scale it for use with the servo (value between 0 and 180)
  myservo.write(val);                  // Sets the servo position according to the scaled value
  delay(15);                           // Delays the loop to wait for the servo to get to the set position
}
