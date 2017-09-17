/*
  Ear.cpp - C++ file for controling the Panther ears
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
 *  @Date: November 2017
 *  
 *  @Input: int leftEarPosition - a numerical value for the position of the left ear
 *  @Input: int rightEarPosition - a numerical value for the position of the right ear
 */
void Ear::setMoveType(int leftEarPosition, int rightEarPosition)
{
	leftEar.setToPosWithSpeed(leftEarPosition,9);
	rightEar.setToPosWithSpeed(rightEarPosition,9);
}

/*  @Author: Jonathan Kenneson
 *  @Date: November 2017  
 */
bool Ear::move() {
	moving = leftEar.move();
	moving = rightEar.move() || moving;
	return moving;  
}

