/*
  Head.cpp - C++ file for controling the Panther Head (eyes, ears, and jaw)
  @Author: Joe Lynch
  @Date: September 2017
*/

#include "ArtBot.h"

Head::Head():
  ears(),
  eyes()
{
  moving = false;
}

void Head::servo(int jaw_pin) {
	jaw.init(jaw_pin);
}

void Head::openJaw(bool closeAfterOpen)
{
	jaw.setToPosWithSpeed(JAW_OPEN, SERVO_SPEED);
	openingClosingJaw = closeAfterOpen;
	jawOpen = true;
}

void Head::closeJaw()
{
	jaw.setToPosWithSpeed(JAW_CLOSED, SERVO_SPEED);
	jawOpen = false;
}


/*  @Author: Joe Lynch
 *  @Date: September 2017
 *  
 *  
 */
bool Head::move() {
	moving = jaw.move();
	if(!moving && jawOpen && openingClosingJaw)
	{
		closeJaw();
		openingClosingJaw = false;
	}
	moving = ears.move() || moving;
	moving = eyes.move() || moving;
	return moving;  
}

