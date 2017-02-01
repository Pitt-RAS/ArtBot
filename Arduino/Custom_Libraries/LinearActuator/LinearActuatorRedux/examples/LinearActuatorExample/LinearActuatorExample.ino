/*
	@Author: Jonathan Kenneson
  @Edit: Woodrow Fulmer
	@Date: January 2017
	
	This file shows the functionality of creating a new LinearActuator object and then calling the function to retract and extend the arm
*/

#include <LinearActuator.h>

//Create a new LinearActuator object by passing in In1, In2, and potPin in the constructor
LinearActuator myActuator(6,5,A0);
bool retract;

void setup() {
  retract = true;
}

void loop() {
  if(!myActuator.move()) 
  {
    if(retract)
      myActuator.setPos(0);
    else
      myActuator.setPos(100);
  }
}
