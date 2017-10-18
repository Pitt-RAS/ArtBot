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
  blinking = false;
}

void Eyes::servo(int pinLocLeftEye, int pinLocRightEye)
{
	leftEye.init(pinLocLeftEye);
	rightEye.init(pinLocRightEye);
}

/*  @Author: Woodrow Fulmer
 *  @Date: September 2017
 */
void Eyes::blink()
{
	leftEye.setToPosWithSpeed(0,9);
	rightEye.setToPosWithSpeed(180,9);
	closed = true;
	blinking = true;
}

/*  @Author: Joe Lynch
 *  @Date: October 2017
 */
void Eyes::open()
{
	leftEye.setToPosWithSpeed(47,9);
	rightEye.setToPosWithSpeed(133,9);
	closed = false;
}

/*  @Author: Joe Lynch
 *  @Date: October 2017
 */
void Eyes::halfOpen()
{
	leftEye.setToPosWithSpeed(23,9);
	rightEye.setToPosWithSpeed(156,9);
	closed = false;
}

/*  @Author: Joe Lynch
 *  @Date: October 2017
 */
void Eyes::close()
{
	leftEye.setToPosWithSpeed(0,9);
	rightEye.setToPosWithSpeed(180,9);
	closed = false;
}

/*  @Author: Woodrow Fulmer
 *  @Date: September 2017  
 */
bool Eyes::move() {
	moving = leftEye.move();
	moving = rightEye.move() || moving;
	if(!moving && closed && blinking)
	{
		leftEye.setToPosWithSpeed(47,9);
		rightEye.setToPosWithSpeed(133,9);
		closed = false;
		blinking = false;
		moving = true;
	}
	return moving;  
}

