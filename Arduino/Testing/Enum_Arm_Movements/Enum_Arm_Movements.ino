/*
 * This program can be used to test the enums in ArtBot.h
 * 
 * Commands 1 - 8 test movement types for the arms
 */

#include "ArtBot.h"

Arm myArmRight(6, 7, A2, 9, 10, A1);
Arm myArmLeft(4, 13, A4, 3, 5, A3);

char in;
bool retract;
bool movingLeft;
bool movingRight;

ArmCommand moveCommand;

void setup() {
  retract = true;
  myArmLeft.servo(44);
  myArmRight.servo(45);
  moveCommand = FULL_RETRACT;
  Serial.begin(9600);
}

void loop() {
  movingLeft = myArmLeft.move(); 
  movingRight = myArmRight.move();
  
  in = Serial.read() - 48;
  if(in >= 0)
  {
    switch(in)
    {
        case 1: 
          moveCommand = FULL_RETRACT;
          break;
        case 2: 
          moveCommand = FULL_EXTEND;
          break;
        case 3: 
          moveCommand = ELBOW_RETRACT;
          break;
        case 4: 
          moveCommand = ELBOW_EXTEND;
          break;
        case 5: 
          moveCommand = SHOULDER_RETRACT;
          break;
        case 6: 
          moveCommand = SHOULDER_EXTEND;
          break;
        case 7: 
          moveCommand = WRIST_DOWN;
          break;
        case 8: 
          moveCommand = WRIST_UP;
          break;
        default:
          moveCommand = FULL_RETRACT;
          break;
    }
    Serial.print("moveCommand = ");
    Serial.println(moveCommand);
  }
  
  if(!movingLeft && !movingRight )
  {
    myArmLeft.setMoveType(moveCommand);
    myArmRight.setMoveType(moveCommand);
  }

}
