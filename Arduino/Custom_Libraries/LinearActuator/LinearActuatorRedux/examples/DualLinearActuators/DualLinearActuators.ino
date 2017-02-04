/*
	@Author: Jonathan Kenneson
	@Date: October, 2016
	
	This file shows the functionality of creating a new LinearActuator object and then calling the function to retract and extend the arm
*/

#include <LinearActuator.h>

//Create a new LinearActuator object by passing in In1, In2, and potPin in the constructor
LinearActuator myActuator1(6,5,A0);
LinearActuator myActuator2(11,10,A1);

bool moveAct1;
bool moveAct2;
bool retract;

void setup() {
  moveAct1 = false;
  moveAct2 = false;
  retract = true;
}

void loop() {
  moveAct1 = myActuator1.move();
  moveAct2 = myActuator2.move();
  
	if(!moveAct1 && !moveAct2 && retract) {
	  myActuator1.setPos(0);
    myActuator2.setPos(0);	
    retract = false;
  }
  
  if(!moveAct1 && !moveAct2 && !retract) {
    myActuator1.setPos(100);
    myActuator2.setPos(100);  
    retract = true;
  }
}
