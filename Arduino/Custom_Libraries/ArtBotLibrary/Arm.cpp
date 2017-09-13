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
 */
void Arm::setMoveType(int command)
{
	switch(command)
	{
		case 1:
			shoulder.setPos(5);
			elbow.setPos(5);
			wrist.setToPosWithSpeed(60,9);
			break;
		case 2:
			shoulder.setPos(5);
			elbow.setPos(95);
			wrist.setToPosWithSpeed(120,9);
			break;
		case 3:
			shoulder.setPos(95);
			elbow.setPos(95);
			wrist.setToPosWithSpeed(180,9);
			break;
		case 4:
			shoulder.setPos(95);
			elbow.setPos(5);
			wrist.setToPosWithSpeed(60,9);
			break;
		case 10:
			elbow.setPos(5);
			wrist.setToPosWithSpeed(0, 9);
			break;
		case 11:
			elbow.setPos(95);
			wrist.setToPosWithSpeed(180, 9);
			break;
		case 20:
			shoulder.setPos(5);
			wrist.setToPosWithSpeed(0, 9);
			break;
		case 21:
			shoulder.setPos(95);
			wrist.setToPosWithSpeed(180, 9);
			break;
		case 0:
		default:
			shoulder.setPos(5);
			elbow.setPos(5);
			wrist.setToPosWithSpeed(0,9);
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

