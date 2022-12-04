/*
  Stepper Motor + Joystick

  This program changes the Stepper Motor's speed and direction from the position of joystick

  This program makes use of include, Stepper.h, const, float, int, Stepper, steppermotor, analogRead, map, switch...case, steppermotor.setSpeed, steppermotor.step, and break.
*/

#include <Stepper.h> // Includes the stepper motor library in the program

const float STEPS_PER_REV = 32; // Creates a constant float variable called "STEPS_PER_REV" and give it the value of 32

int StepsRequired; // Creates an integer variable called "StepsRequired"

int speed = 0; // Creates an integer variable called "speed"

// Pins entered in sequence 1-3-2-4
Stepper steppermotor(STEPS_PER_REV,8,10,9,11); // Defines the stepper motor as having 32 steps per revolution, and 8, 9, 10, and 11 as its Arduino pins

void setup() {
  
}

void loop() {
  int joystickX = analogRead(A0); // Creates an integer variable called "joystickX" and gives it the read value of pin A0
  int resultX = map(joystickX, 0, 470, 0, 3); // Creates an integer variable called "resultX" and gives it the mapped value of "joystickX" from 0 - 1023 to 0 - 3

  int rangeL = map(joystickX, 0, 157, 255, 0); // Creates an integer variable called "rangeL" and gives it the mapped value of "joystickX" from 0 - 341 to 255 - 0
  int rangeM = map(joystickX, 158, 314, 0, 255); // Creates an integer variable called "rangeM" and gives it the mapped value of "joystickX" from 342 - 683 to 0 - 255
  int rangeH = map(joystickX, 315, 470, 0, 255); // Creates an integer variable called "rangeH" and gives it the mapped value of "joystickX" from 684 - 1023 to 0 - 255

  switch(resultX){ // Compares the value of "resultX" with the values of the following cases
    case 0: // If "resultY" is 0
    speed = rangeL * 5; // Gives "speed" the value of the product of "rangeL" and 5
    steppermotor.setSpeed(speed); // Sets the speed of the stepper motor to the value of "speed"
    StepsRequired = rangeL / 5; // Gives "StepsRequired" the value of the quotient of "rangeL" and 5
    steppermotor.step(StepsRequired); // Moves the stepper motor in "StepsRequired" steps
    break; // Ends the statement

    case 1: // If "resultY" is 1
    speed = rangeM * 0; // Gives "speed" the value of the product of "rangeM" and 0
    steppermotor.step(0); // Moves the stepper motor in "StepsRequired" steps
    break; // Ends the statement

    case 2: // If "resultY" is 2
    speed = rangeH * 5; // Gives "speed" the value of the product of "rangeH" and 5
    steppermotor.setSpeed(speed); // Sets the speed of the stepper motor to the value of "speed"
    StepsRequired = - rangeH / 5; // Gives "StepsRequired" the value of the quotient of "rangeH" and 5
    steppermotor.step(StepsRequired); // Moves the stepper motor in "StepsRequired" steps
    break; // Ends the statement

    case 3: // If "resultY" is 3
    speed = rangeH * 5; // Gives "speed" the value of the product of "rangeH" and 5
    steppermotor.setSpeed(speed); // Sets the speed of the stepper motor to the value of "speed"
    StepsRequired = - rangeH / 5; // Gives "StepsRequired" the value of the quotient of "rangeH" and 5
    steppermotor.step(StepsRequired); // Moves the stepper motor in "StepsRequired" steps
    break; // Ends the statement
  }
}