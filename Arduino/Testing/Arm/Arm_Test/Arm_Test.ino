/*
  @Author: Jonathan Kenneson
  @Date: November, 2016
  
  Arm testing file for dual linear actuator and single servo motor control
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
  //Send the actuator to a position (0-100%) with desired top speed (0-255)
  while(moveAct1 == true || moveAct2 == true) {
  if(moveAct1 == true) {
    moveAct1 = myActuator1.sendToPosWithSpeed(0,255); 
  }
    if(moveAct2 == true) {
    moveAct2 = myActuator2.sendToPosWithSpeed(0,120);  
  }
  }
  
  moveAct1 = true;
  moveAct2 = true;
  while(moveAct1 == true || moveAct2 == true) {
  if(moveAct1 == true) {
    moveAct1 = myActuator1.sendToPosWithSpeed(100,255); 
  }
    if(moveAct2 == true) {
    moveAct2 = myActuator2.sendToPosWithSpeed(60,120);  
  }
  }
}
