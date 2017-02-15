/*
	@Author: Woodrow Fulmer
	@Date: January 2017
	
	This file shows the functionality of creating a new LinearActuator object and then calling the function to retract and extend the arm
*/

#include <LinearActuator.h>

//Create a new LinearActuator object by passing in In1, In2, and potPin in the constructor
LinearActuator myActuator(9,10,A2);
bool extended;
bool moving;

void setup() {
  extended = false;
  moving = false;
}

void loop() {
  moving = myActuator.move();
  if(!moving) 
  {
    if(extended)
      myActuator.setPos(10);
    else
      myActuator.setPos(100);
	extended = !extended;
  }
}