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

void setup() {
  moveAct1 = false;
  moveAct2 = false;
}

void loop() {
  moveAct1 = true;
  moveAct2 = true;
  //Send the actuator to a position (10-100%) 
  while(moveAct1 == true || moveAct2 == true) {
	if(moveAct1 == true) {
	  moveAct1 = myActuator1.sendToPos(10);	
	}
    if(moveAct2 == true) {
	  moveAct2 = myActuator2.sendToPos(10);	
	}
  }
  
  moveAct1 = true;
  moveAct2 = true;
  while(moveAct1 == true || moveAct2 == true) {
	if(moveAct1 == true) {
	  moveAct1 = myActuator1.sendToPos(100);	
	}
    if(moveAct2 == true) {
	  moveAct2 = myActuator2.sendToPos(100);	
	}
  }
}
