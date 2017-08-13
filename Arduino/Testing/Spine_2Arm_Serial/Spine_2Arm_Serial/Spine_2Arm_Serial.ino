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

Arm myArm1(9, 10, A0, 11, 12, A1);
Arm myArm2(6, 7, A2, 3, 5, A3);
LinearActuator spine(4, 13, A4);

char in;
bool retract;
bool moving1;
bool moving2;
bool movingSpine;
int moveCommand;

// Movement Constants
int lie_down = 4; // Retract elbow and shoulder & extend spine
int stand_up = 2; // Extend elbow, retract shoulder & retract spine

void setup() {
  retract = true;
  myArm1.servo(44);
  myArm2.servo(45);
  moving1 = false;
  moving2 = false;
  movingSpine = false;
  moveCommand = 0;
  Serial.begin(9600);
}

void loop() {
  moving1 = myArm1.move(); 
  moving2 = myArm2.move();
  movingSpine = spine.move(); 
  in = Serial.read() - 48;
  if(in >= 0)
  {
    switch(in)
    {
        case 1: // Lie down
          moveCommand = lie_down;
          retract = false;
          break;
        case 2: // Stand up
          moveCommand = stand_up;
          retract = true;
          break;
        case 4:
          moveCommand = 10;
          break;
        case 5:
          moveCommand = 11;
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
  if(!moving1 && !moving2 && !movingSpine)
  {
    myArm1.setMoveType(moveCommand);
    myArm2.setMoveType(moveCommand);
    if(retract) {
      spine.setPos(10);
    } else {
      spine.setPos(100);
    }
    //retract = !retract;
    //myservo.setToPosWithSpeed(servoCommand, 3);
  }
}
