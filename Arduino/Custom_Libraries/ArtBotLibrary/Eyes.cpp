/*
  Eyes.cpp - C++ file for controling the Panther eyes
  Author: Woodrow Fulmer
  Date: September 2017
*/

#include "ArtBot.h"

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
	close();
	blinking = true;
}

/*  @Author: Joe Lynch
 *  @Date: October 2017
 */
void Eyes::open()
{
	leftEye.setToPosWithSpeed(LEFT_EYE_OPEN, SERVO_SPEED);
	rightEye.setToPosWithSpeed(RIGHT_EYE_OPEN, SERVO_SPEED);
	closed = false;
}

/*  @Author: Joe Lynch
 *  @Date: October 2017
 */
void Eyes::halfOpen()
{
	leftEye.setToPosWithSpeed(LEFT_EYE_OPEN + (LEFT_EYE_OPEN - LEFT_EYE_CLOSED) / 2, SERVO_SPEED);
	rightEye.setToPosWithSpeed(RIGHT_EYE_OPEN + (RIGHT_EYE_OPEN - RIGHT_EYE_CLOSED) / , SERVO_SPEED);
	closed = false;
}

/*  @Author: Joe Lynch
 *  @Date: October 2017
 */
void Eyes::close()
{
	leftEye.setToPosWithSpeed(LEFT_EYE_CLOSED, SERVO_SPEED);
	rightEye.setToPosWithSpeed(RIGHT_EYE_CLOSED, SERVO_SPEED);
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
		open();
		blinking = false;
		moving = true;
	}
	return moving;  
}

