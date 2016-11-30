/*
  Arm.cpp - C++ file for controling the Panther arms
  Fluid motion capabilities, and variable distances to send arm to
  Author: Woodrow Fulmer
  Date: November 2016
*/

#include "Arduino.h"
#include "Arm.h"
#include "LinearActuator.h"

LinearActuator::LinearActuator(int input1, int input2, int inputPot){
Arm::Arm(int input1_S, int input2_S, int inputPot_S, int input1_E, int input2_E, int inputPot_E){
  elbow = new LinearActuator(input1_E, input2_E, inputPot_E);
  shoulder = new LinearActuator(input1_S, input2_S, inputPot_S);
  
  moving = false;
}

/*  @Author: Woodrow Fulmer
 *  @Date: November 2016
 *  
 *  @Input: int command - a numerical value symbolic of a particular arm movement
 *  This function sends commands to the elbow and shoulder actuators to begin 
 *	a predetermined movement.
 *	case 1: extend the shoulder to max distance and retract the elbow to 0 at 90%
 *	case 2: retract the shoulder and extend the elbow to max distance at 90%
 *	case 3: send the shoulder and elbow both to half distance at 70%
 */
void setMoveType(int command)
{
	switch(command)
	{
		case 1:
			shoulder.sendToPosWithSpeed(100, 90);
			elbow.sendToPosWithSpeed(0, 90);
			break;
		case 2:
			shoulder.sendToPosWithSpeed(0, 90);
			elbow.sendToPosWithSpeed(100,90);
		case 3:
			shoulder.sendToPosWithSpeed(50,70);
			elbow.sendToPosWithSpeed(50,70);
		default:
			break;
	}
}

/*  @Author: Woodrow Fulmer
 *  @Date: November 2016
 *  
 *  
 */
bool Arm::move() {
	isMoving = shoulder.move();
	isMoving = elbow.move() || isMoving;
	return isMoving;  
}

