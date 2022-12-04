/*
  DC Motor + Joystick (Speed and Direction)

  This program changes the DC Motor's speed and direction from the position of joystick

  This program makes use of pinMode, int, analogRead, map, switch...case, analogWrite, and break.
*/

void setup() {
  pinMode(5, OUTPUT); // Sets pin 5 as an output
  pinMode(6, OUTPUT); // Sets pin 6 as an output
}

void loop() {
  int joystickX = analogRead(A0); // Creates an integer variable called "joystickX" and gives it the read value of pin A0
  int resultX = map(joystickX, 0, 1023, 0, 3); // Creates an integer variable called "resultX" and gives it the mapped value of "joystickX" from 0 - 1023 to 0 - 3

  int rangeL = map(joystickX, 0, 347, 255, 0); // Creates an integer variable called "rangeL" and gives it the mapped value of "joystickX" from 0 - 347 to 255 - 0
  int rangeH = map(joystickX, 696, 1023, 0, 255); // Creates an integer variable called "rangeH" and gives it the mapped value of "joystickX" from 696 - 1023 to 0 - 255

  switch(resultX){ // Compares the value of "resultX" with the values of the following cases
    case 0: // If "resultX" is 0
    analogWrite(5, rangeL); // Gives pin 5 the value of "rangeL"
    analogWrite(6, 0); // Gives pin 6 the value of 0
    break; // Ends the statement

    case 1: // If "resultX" is 1
    analogWrite(5, 0); // Gives pin 5 the value of 0
    analogWrite(6, 0); // Gives pin 6 the value of 0
    break; // Ends the statement
    
    case 2: // If "resultX" is 2
    analogWrite(5, 0); // Gives pin 5 the value of 0
    analogWrite(6, rangeH); // Gives pin 6 the value of "rangeH"
    break; // Ends the statement
    
    case 3: // If "resultX" is 3
    analogWrite(5, 0); // Gives pin 5 the value of 0
    analogWrite(6, rangeH); // Gives pin 6 the value of "rangeH"
    break; // Ends the statement
  }
}
