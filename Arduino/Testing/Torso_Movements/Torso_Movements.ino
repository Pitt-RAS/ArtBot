/*
 * This program can be used to test sending movement commands to a single arm
 * The input it should recieve from the serial-in line
 * 
 * Command 0 is both retracted
 * Command 1 is elbow extended and shoulder retracted
 * Command 2 is elbow retracted and shoulder extended
 * Command 3 is both extended
 * 
 * Command 4 is retract elbow
 * Command 5 is extend elbow
 * 
 * Command 6 is retract shoulder
 * Command 7 is extend elbow
 */

#include <ArtBot.h>

Arm myArmLeft(9, 10, A0, 11, 12, A1);
Arm myArmRight(6, 7, A2, 3, 5, A3);
//LinearActuator spine(4, 13, A4);

char in;
bool retract;
bool movingLeft;
bool movingRight;
bool movingSpine;
bool armLeft;
bool armRight;
int moveCommand;
int moveArray[5];
bool longCommand;
bool moveDone[5];
int i;

// Movement Constants
int lie_down = 1;     // Retract elbow and shoulder & extend spine
int stand_up = 2;     // Extend elbow, retract shoulder & retract spine
int roar = 3;         // Extend elbow and shoulder & retract spine
int scratch_ear = 4;  // Raise arm and move elbow up & down

void setup() {
  retract = true;
  myArmLeft.servo(44);
  myArmRight.servo(45);
  movingLeft = false;
  movingRight = false;
  movingSpine = false;
  armLeft = false;
  armRight = false;
  moveCommand = 0;
  longCommand = false;
  Serial.begin(9600);
}

void loop() {
  movingLeft = myArmLeft.move(); 
  movingRight = myArmRight.move();
  //movingSpine = spine.move(); 
  in = Serial.read() - 48;
  if(in >= 0)
  {
    switch(in)
    {
        case 1: // Lie down
          moveCommand = lie_down;
          armLeft = true;
          armRight = true;
          retract = false;
          longCommand = false;
          break;
        case 2: // Stand up
          moveCommand = stand_up;
          armLeft = true;
          armRight = true;
          retract = true;
          longCommand = false;
          break;
        case 3: // Roar
          moveCommand = roar;
          armLeft = true;
          armRight = true;
          retract = true;
          longCommand = false;
          break;
        case 4: // Scratch Ear: Move 4->11->10->11->1
          moveArray[0] = scratch_ear;
          moveArray[1] = 11;
          moveArray[2] = 10;
          moveArray[3] = 11;
          moveArray[4] = lie_down;
          for (i=0;i<5;i++) { moveDone[i] = false; }
          armLeft = true;
          armRight = false;
          retract = false;
          longCommand = true;
          break;
        case 5: // Lick Paw
          moveCommand = 5;
          retract = false;
          break;
        case 6:
          moveCommand = 20;
          break;
        case 7:
          moveCommand = 21;
          break;
        /*case 8:
          servoCommand = eyelid_closed;
          //moveCommand = 8;
          break;
          retract = true;
          break;
        case 3: // Roar
          moveCommand = roar;
          retract = true;
        case 9:
          servoCommand = eyelid_opened;
          //moveCommand = 9;
          break;
        case 0:
          neckMove = true;
        */
        default:
          moveCommand = in;
          break;
    }
    Serial.print("moveCommand = ");
    Serial.println(moveCommand);
  }
  if(longCommand) {
    if(!moveDone[0]) {
      if(!movingLeft && !movingRight ) { // && !movingSpine
        if(armLeft) { myArmLeft.setMoveType(moveArray[0]); }
        if(armRight) { myArmRight.setMoveType(moveArray[0]); }  
        moveDone[0] = true; 
      }
    } else if(!moveDone[1]) {
      if(!movingLeft && !movingRight ) { // && !movingSpine
        if(armLeft) { myArmLeft.setMoveType(moveArray[1]); }
        if(armRight) { myArmRight.setMoveType(moveArray[1]); }   
        moveDone[1] = true;
      }
    } else if(!moveDone[2]) {
      if(!movingLeft && !movingRight ) { // && !movingSpine
        if(armLeft) { myArmLeft.setMoveType(moveArray[2]); }
        if(armRight) { myArmRight.setMoveType(moveArray[2]); } 
        moveDone[2] = true;  
      }
    } else if(!moveDone[3]) {
      if(!movingLeft && !movingRight ) { // && !movingSpine
        if(armLeft) { myArmLeft.setMoveType(moveArray[3]); }
        if(armRight) { myArmRight.setMoveType(moveArray[3]); }  
        moveDone[3] = true; 
      }
    } else if(!moveDone[4]) {
      if(!movingLeft && !movingRight ) { // && !movingSpine
        if(armLeft) { myArmLeft.setMoveType(moveArray[4]); }
        if(armRight) { myArmRight.setMoveType(moveArray[4]); }   
        moveDone[4] = true;
      }
    }
    
  } else {
    if(!movingLeft && !movingRight ) // && !movingSpine
    {
      if(armLeft) {
        myArmLeft.setMoveType(moveCommand);
      }
      if(armRight) {
        myArmRight.setMoveType(moveCommand);
      }    
      //myArmLeft.setMoveType(moveCommand);
      //myArmRight.setMoveType(moveCommand);
      /*if(retract) {
        spine.setPos(10);
      } else {
        spine.setPos(100);
      }*/
      //retract = !retract;
      //myservo.setToPosWithSpeed(servoCommand, 3);
    }
  }
}
