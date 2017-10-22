/*
  Ears.cpp - C++ file for controling the Panther ears
  Fluid motion capabilities for rotating the ears
  Author: Jonthan Kenneson
  Date: September 2017
*/

#include "ArtBot.h"

Ears::Ears():
  leftEar(),
  rightEar()
{
  moving = false;
}

void Ears::servo(int pinLocLeftEar, int pinLocRightEar)
{
	leftEar.init(pinLocLeftEar);
	rightEar.init(pinLocRightEar);
}

/*  @Author: Jonathan Kenneson
 *  @Date: September 2017
 *  
 *  @Input: int leftEarPosition - a numerical value for the position of the left ear
 *  @Input: int rightEarPosition - a numerical value for the position of the right ear
 */
void Ears::setMoveType(int leftEarPosition, int rightEarPosition)
{
	leftEar.setToPosWithSpeed(leftEarPosition, SERVO_SPEED);
	rightEar.setToPosWithSpeed(rightEarPosition, SERVO_SPEED);
}

/*  @Author: Woodrow Fulmer
 *  @Date: October 2017
 *  
 *  @Input: EarMovement command - a numerical value for the position of the left ear
 */
void Ears::setMoveType(EarMovement command)
{
	switch(command)
	{
		case FACE_IN:
			leftEar.setToPosWithSpeed(EAR_RIGHT, SERVO_SPEED);
			rightEar.setToPosWithSpeed(EAR_LEFT, SERVO_SPEED);
			break;
		case FACE_OUT:
			leftEar.setToPosWithSpeed(EAR_LEFT, SERVO_SPEED);
			rightEar.setToPosWithSpeed(EAR_RIGHT, SERVO_SPEED);
			break;
		case FORWARD:
		default:
			leftEar.setToPosWithSpeed(90, SERVO_SPEED);
			rightEar.setToPosWithSpeed(90,SERVO_SPEED);
			break;
	}
}

/*  @Author: Jonathan Kenneson
 *  @Date: September 2017  
 */
bool Ears::move() {
	moving = leftEar.move();
	moving = rightEar.move() || moving;
	return moving;  
}

