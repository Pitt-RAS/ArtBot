/*
	@Author: Jonathan Kenneson
	@Date: October, 2016
	
	This file shows the functionality of creating a new LinearActuator object and then calling the function to retract and extend the arm
*/

#include <LinearActuator.h>

//Create a new LinearActuator object by passing in In1, In2, and potPin in the constructor
LinearActuator myActuator(6,5,A0);

void setup() {
}

void loop() {
  //Send the actuator to a position (10-100%) with desired top speed (0-255)
  while(myActuator.sendToPos(10)) {}
  while(myActuator.sendToPos(100)) {}
}
