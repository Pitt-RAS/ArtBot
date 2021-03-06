/*
  Head.cpp - C++ file for controling the Panther Head (eyes, ears, and jaw)
  @Author: Joe Lynch
  @Date: September 2017
*/

#include "ArtBot.h"
#include "Head.h"

Head::Head():
  ears(),
  eyes()
{
  moving = false;
}

void Head::jawServo(int jaw_pin) {
	jaw.init(jaw_pin);
}

void Head::openJaw(bool closeAfterOpen)
{
	jaw.setToPosWithSpeed(JAW_OPEN,9);
	openingClosingJaw = closeAfterOpen;
	jawOpen = true;
}

void Head::closeJaw()
{
	jaw.setToPosWithSpeed(JAW_CLOSED,9);
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

