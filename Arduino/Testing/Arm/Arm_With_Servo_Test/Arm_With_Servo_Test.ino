/*
  @Author: Jonathan Kenneson
  @Date: November, 2016
  
  Arm testing file for dual linear actuator and single servo motor control
*/
#define SERVO_SPEED 13  //(minimum number of milliseconds per degree)
#include <LinearActuator.h>
#include <ServoDriver.h>

//Create a new LinearActuator object by passing in In1, In2, and potPin in the constructor
LinearActuator myActuator1(9,10,A2);
LinearActuator myActuator2(2,4,A3);
ServoDriver servo1;

bool moveAct1;
bool moveAct2;
bool moveServo;

void setup() {
  Serial.begin(9600);
  servo1.init(44);
  moveAct1 = false;
  moveAct2 = false;
  moveServo = false;
}

void loop() {
  moveAct1 = true;
  moveAct2 = true;
  moveServo = true;
  //Send the actuator to a position (0-100%) with desired top speed (0-255)
  servo1.setToPosWithSpeed(0,7);
  while(moveAct1 == true || moveAct2 == true || moveServo == true) {
    if(moveAct1 == true) {
      moveAct1 = myActuator1.sendToPosWithSpeed(0,255); 
    }
    if(moveAct2 == true) {
      moveAct2 = myActuator2.sendToPosWithSpeed(0,100);  
    }
    if(moveServo == true) {
      // check time since last servo position update 
      moveServo = servo1.move();
    }
  }
  
  moveAct1 = true;
  moveAct2 = true;
  moveServo = true;
  servo1.setToPosWithSpeed(180,7);
  while(moveAct1 == true || moveAct2 == true || moveServo == true) {
    if(moveAct1 == true) {
      moveAct1 = myActuator1.sendToPosWithSpeed(100,255); 
    }
    if(moveAct2 == true) {
      moveAct2 = myActuator2.sendToPosWithSpeed(100,100);  
    }
    if(moveServo == true) {
      // check time since last servo position update 
      moveServo = servo1.move();
    }
  }
  
}
