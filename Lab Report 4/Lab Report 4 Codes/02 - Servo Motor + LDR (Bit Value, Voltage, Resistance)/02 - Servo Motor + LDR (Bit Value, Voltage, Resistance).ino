/*
  Servo Motor + LDR (Bit Value, Voltage, Resistance)

  This program moves the servo motor accordingly to the position of the joystick

  This program makes use of #include, Servo, Serial.begin, myservo.attach, int, float, Serial.print, Serial.println, and myservo.write.
*/

#include <Servo.h> // Includes the servo library in the code

Servo myservo; // Creates servo object to control a servo

void setup() {
  Serial.begin(9600); // Sets data rate for serial transmittion

  myservo.attach(9); // Attaches pin 9 to the servo motor
}

void loop() {
  int bit = analogRead(A0); // Creates an integer variable called "bit" and gives it the value of pin A0

  float volt = bit/204.6; // Creates a float variable called "volt" and gives it the value of the quotient of "bit" and 204.6
  
  float resistance = ((5/volt)-1)*1000; // Creates a float variable called "resistance" and gives it the value of the resistance computed

  Serial.print("Bit Value = "); // Prints in the serial monitor the text: "Bit Value = "
  Serial.print(bit); // Prints in the serial monitor the value of "bit"

  Serial.print(" || Voltage = "); // Prints in the serial monitor the text: " || Voltage = "
  Serial.print(volt); // Prints in the serial monitor the value of "volt"
  Serial.print(" V"); // Prints in the serial monitor the text: " V"

  Serial.print(" || Resistance = "); // Prints in the serial monitor the text: " || Resistance = "
  Serial.print(resistance); // Prints in the serial monitor the value of "resistance"
  Serial.println(" ohms"); // Prints in the serial monitor the text: " ohms" and goes to the next line
  
  int motorServo = map(volt, 0, 5, 0, 180); // Creates an integer variable called "motorServo" and gives it the mapped value of "volt" from 0 - 5 to 0 - 180
  myservo.write(motorServo); // Places the servo motor in the position of the angle "motorServo"
}
