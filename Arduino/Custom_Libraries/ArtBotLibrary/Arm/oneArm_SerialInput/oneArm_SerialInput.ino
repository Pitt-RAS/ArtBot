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
Arm::ArmCommand moveCommand;

void setup() {
  // put your setup code here, to run once:
  myArm.servo(44);
  moving = false;
  Serial.begin(9600);
  moveCommand = Arm::FULL_RETRACT;
}

void loop() {
  moving = myArm.move();

  in = Serial.read() - 48;
  if(in >= 0)
  {
    switch(in)
    {
		case 2:
			moveCommand = Arm::FULL_EXTEND;
        case 3:
			moveCommand = Arm::ELBOW_RETRACT;
			break;
        case 4:
			moveCommand = Arm::ELBOW_EXTEND;
			break;
        case 5:
			moveCommand = Arm::SHOULDER_RETRACT;
			break;
        case 6:
			moveCommand = Arm::SHOULDER_EXTEND;
			break;
		case 7:
			moveCommand = Arm::WRIST_DOWN;
			break;
		case 8:
			moveCommand = Arm::WRIST_UP;
			break;
        default:
			moveCommand = Arm::FULL_RETRACT;
			break;
    }
    Serial.print("moveCommand = ");
    Serial.println(moveCommand);
  }
  if(!moving)
    myArm.setMoveType(moveCommand);
}
