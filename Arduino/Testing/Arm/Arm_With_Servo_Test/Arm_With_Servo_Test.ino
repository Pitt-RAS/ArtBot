/*
  @Author: Jonathan Kenneson
  @Date: November, 2016
  
  Arm testing file for dual linear actuator and single servo motor control
*/
#define SERVO_SPEED 13  //(minimum number of milliseconds per degree)
#include <LinearActuator.h>
#include <Servo.h>

//Create a new LinearActuator object by passing in In1, In2, and potPin in the constructor
LinearActuator myActuator1(6,5,A0);
LinearActuator myActuator2(11,3,A1);
Servo servo1;

bool moveAct1;
bool moveAct2;
bool moveServo;

int servo1_pos; // desired angle for servo1
static unsigned long servo_time;

void setup() {
  Serial.begin(9600);
  moveAct1 = false;
  moveAct2 = false;
  moveServo = false;
  servo1.attach(9);
}

void loop() {
  moveAct1 = true;
  moveAct2 = true;
  moveServo = true;
  servo1_pos = 0;
  //Send the actuator to a position (0-100%) with desired top speed (0-255)
  while(moveAct1 == true || moveAct2 == true || moveServo == true) {
    if(moveAct1 == true) {
      moveAct1 = myActuator1.sendToPosWithSpeed(0,255); 
    }
    if(moveAct2 == true) {
      moveAct2 = myActuator2.sendToPosWithSpeed(0,100);  
    }
    if(moveServo == true) {
      // check time since last servo position update 
      if ((millis()-servo_time) >= SERVO_SPEED) {
        servo_time = millis(); // save time reference for next position update
       
        // update servo1 position
        // if desired position is different from current position move one step left or right
        if (servo1_pos > servo1.read()) servo1.write(servo1.read() + 1);
        else if (servo1_pos < servo1.read()) servo1.write(servo1.read() - 1);
        else moveServo = false;
      }  
    }
  }
  
  moveAct1 = true;
  moveAct2 = true;
  moveServo = true;
  servo1_pos = 180;
  while(moveAct1 == true || moveAct2 == true || moveServo == true) {
    if(moveAct1 == true) {
      moveAct1 = myActuator1.sendToPosWithSpeed(100,255); 
    }
    if(moveAct2 == true) {
      moveAct2 = myActuator2.sendToPosWithSpeed(100,100);  
    }
    if(moveServo == true) {
      // check time since last servo position update 
      if ((millis()-servo_time) >= SERVO_SPEED) {
        servo_time = millis(); // save time reference for next position update
       
        // update servo1 position
        // if desired position is different from current position move one step left or right
        if (servo1_pos > servo1.read()) servo1.write(servo1.read() + 1);
        else if (servo1_pos < servo1.read()) servo1.write(servo1.read() - 1);
        else moveServo = false;
      }  
    }
  }
}
