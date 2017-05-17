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

Arm myArm(9, 10, A2, 2, 3, A3);

bool moving;
int in;
int moveCommand;

void setup() {
  // put your setup code here, to run once:
  myArm.servo(44);
  moving = false;
  Serial.begin(9600);
  moveCommand = 0;
}

void loop() {
  moving = myArm.move();

  in = Serial.read() - 48;
  if(in >= 0)
  {
    switch(in)
    {
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
        default:
          moveCommand = in;
          break;
    }
    Serial.print("moveCommand = ");
    Serial.println(moveCommand);
  }
  if(!moving)
    myArm.setMoveType(moveCommand);
}
