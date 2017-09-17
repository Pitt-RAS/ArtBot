/*
  Eyes.cpp - C++ file for controling the Panther eyes
  Author: Woodrow Fulmer
  Date: September 2017
*/

#include "Eyes.h"

Eyes::Eyes():
  leftEye(),
  rightEye()
{
  moving = false;
  closed = false;
}

void Ears::servo(int pinLocLeftEye, int pinLocRightEye)
{
	leftEye.init(pinLocLeftEye);
	rightEye.init(pinLocRightEye);
}

/*  @Author: Woodrow Fulmer
 *  @Date: September 2017
 */
void Eye::blink()
{
	leftEye.setToPosWithSpeed(0,9);
	rightEye.setToPosWithSpeed(180,9);
	closed = true;
}

/*  @Author: Woodrow Fulmer
 *  @Date: September 2017  
 */
bool Eye::move() {
	moving = leftEar.move();
	moving = rightEar.move() || moving;
	if(!moving && closed)
	{
		leftEye.setToPosWithSpeed(47,9);
		rightEye.setToPosWithSpeed(133,9);
		closed = false;
	}
	return moving;  
}

