/*
  Stepper Motor + Remote (Control Direction, Control Speed is Optional)

  This program changes the Stepper Motor's speed and direction from the input of an infrared remote

  This program makes use of #include, IRremote.h, #define, Stepper.h, const, float, int, Stepper, steppermotor, Serial.begin, IrReceiver.begin, if, IrReceiver.decode, IrReceiver.resume, switch...case, 
  IrReceiver.decodedIRData.command, break, steppermotor.setSpeed, and steppermotor.step.
*/

#include <IRremote.h> // Includes the infrared remote library in the program
#define IR_RECEIVE_PIN 4 // Defines pin 4 as the "IR_RECEIVE_PIN"

#include <Stepper.h> // Includes the stepper motor library in the program
const float STEPS_PER_REV = 32; // Creates a constant float variable called "STEPS_PER_REV" and give it the value of 32
int StepsRequired; // Creates an integer variable called "StepsRequired"
int speed = 0; // Creates an integer variable called "speed" and gives it the value of 0
int motorSetting = 0; // Creates an integer variable called "motorSetting" and gives it the value of 0

// Pins entered in sequence 1-3-2-4
Stepper steppermotor(STEPS_PER_REV,8,10,9,11); // Defines the stepper motor as having 32 steps per revolution, and 8, 9, 10, and 11 as its Arduino pins

void setup(){
  Serial.begin(9600); // Sets the data rate for serial transmission
  IrReceiver.begin(IR_RECEIVE_PIN); // Starts the infrared receiver with pin 4
}

void loop() {
  if (IrReceiver.decode()) { // Checks if the infrared sensor has decoded something
    IrReceiver.resume(); // Resumes the infrared reciever
  }
  
  switch (IrReceiver.decodedIRData.command) { // Compares the value of "IrReceiver.decodedIRData.command" with the values of the following cases
    case 0: // If "IrReceiver.decodedIRData.command" is 0
    IrReceiver.decodedIRData.command = -1; // Gives "IrReceiver.decodedIRData.command" the value of -1
    motorSetting = 0; // Gives "motorSetting" the value of 0
    break; // Ends the statement
    
    case 4: // If "IrReceiver.decodedIRData.command" is 4
    IrReceiver.decodedIRData.command = -1; // Gives "IrReceiver.decodedIRData.command" the value of -1
	  motorSetting = motorSetting - 1; // Gives "motorSetting" the value of the difference of "motorSetting" and 1
    break; // Ends the statement
    
    case 6: // If "IrReceiver.decodedIRData.command" is 6
    IrReceiver.decodedIRData.command = -1; // Gives "IrReceiver.decodedIRData.command" the value of -1
	  motorSetting = motorSetting + 1 ; // Gives "motorSetting" the value of the sum of "motorSetting" and 1
    break; // Ends the statement
  }
  
  if (motorSetting > 0) { // Checks if "motorSetting" is greater than 0
    speed = motorSetting * 5; // Gives "speed" the value of the product of "motorSetting" and 5
    steppermotor.setSpeed(speed); // Sets the speed of the stepper motor to the value of "speed"
    StepsRequired = motorSetting / 5; // Gives "StepsRequired" the value of the quotient of "rangeL" and 5
    steppermotor.step(StepsRequired); // Moves the stepper motor in "StepsRequired" steps
  }
  
  if (motorSetting < 0) { // Checks if "motorSetting" is less than 0
    speed = motorSetting * 5; // Gives "speed" the value of the product of "motorSetting" and 5
    steppermotor.setSpeed(speed); // Sets the speed of the stepper motor to the value of "speed"
    StepsRequired = motorSetting / - 5; // Gives "StepsRequired" the value of the quotient of "rangeL" and 5
    steppermotor.step(StepsRequired); // Moves the stepper motor in "StepsRequired" steps
  }
  
  if (motorSetting == 0) { // Checks if "motorSetting" is 0
    steppermotor.setSpeed(0); // Sets the speed of the stepper motor to the value of 0
  }
}