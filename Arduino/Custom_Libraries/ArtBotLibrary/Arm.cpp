/*
  Arm.cpp - C++ file for controling the Panther arms
  Fluid motion capabilities, and variable distances to send arm to
  Author: Woodrow Fulmer
  Date: November 2016
  Editor: Ben Posey
  Edited: September 2017
*/

#include "ArtBot.h"

Arm::Arm(int input1_S, int input2_S, int inputPot_S, int input1_E, int input2_E, int inputPot_E):
  elbow(input1_E, input2_E, inputPot_E),
  shoulder(input1_S, input2_S, inputPot_S),
  wrist()
{
  moving = false;
}

void Arm::servo(int pinLoc)
{
	wrist.init(pinLoc);
}

/*  @Author: Woodrow Fulmer
 *  @Date: November 2016
 *  @Editor: Ben Posey
 *  @Edited: September 2017
 *  
 *  @Input: int command - a numerical value symbolic of a particular arm movement
 *  This function sends commands to the elbow and shoulder actuators to begin 
 *	a predetermined movement.
 *	case 1: retract shoulder and elbow
 *	case 2: retract shoulder and extend elbow
 *	case 3: extend shoulder and elbow
 *	case 4: extend shoulder and retract elbow
 *	case 10: retract elbow
 *	case 11: extend elbow
 *	case 20: retract shoulder
 *	case 21: extend shoulder
 *  case 30: retract wrist
 *	case 31: extend wrist
 */
void Arm::setMoveType(ArmCommand command)
{
	switch(command)
	{
		case FULL_RETRACT:
			shoulder.setPos(ACTUATOR_IN);
			elbow.setPos(ACTUATOR_IN);
			wrist.setToPosWithSpeed(PAW_UP, SERVO_SPEED);
			break;
		case FULL_EXTEND:
			shoulder.setPos(ACTUATOR_OUT);
			elbow.setPos(ACTUATOR_OUT);
			wrist.setToPosWithSpeed(PAW_DOWN, SERVO_SPEED);
			break;
		case ELBOW_RETRACT:
			elbow.setPos(ACTUATOR_IN);
			break;
		case ELBOW_EXTEND:
			elbow.setPos(ACTUATOR_OUT);
			break;
		case SHOULDER_RETRACT:
			shoulder.setPos(ACTUATOR_IN);
			break;
		case SHOULDER_EXTEND:
			shoulder.setPos(ACTUATOR_OUT);
			break;
		case WRIST_DOWN:
			wrist.setToPosWithSpeed(PAW_DOWN, SERVO_SPEED);
			break;
		case WRIST_UP:
			wrist.setToPosWithSpeed(PAW_UP, SERVO_SPEED);
			break;
		default:
			shoulder.setPos(ACTUATOR_IN);
			elbow.setPos(ACTUATOR_IN);
			wrist.setToPosWithSpeed(PAW_DOWN, SERVO_SPEED);
			break;
	}
}

/*  @Author: Woodrow Fulmer
 *  @Date: November 2016
 *  
 *  
 */
bool Arm::move() {
	moving = shoulder.move();
	moving = elbow.move() || moving;
	moving = wrist.move() || moving;
	return moving;  
}

