/*
	@Author: Jonathan Kenneson
  @Edit: Woodrow Fulmer
	@Date: January 2017
	
	This file shows the functionality of creating a new LinearActuator object and then calling the function to retract and extend the arm
*/

#include <LinearActuator.h>

//Create a new LinearActuator object by passing in In1, In2, and potPin in the constructor
LinearActuator myActuator(6,5,A0);

void setup() {
  myActuator.setPosWithSpd(100,255);
}

void loop() {
  //Send the actuator to a position (0-100%) with desired top speed (0-255)
  myActuator.move();
}
