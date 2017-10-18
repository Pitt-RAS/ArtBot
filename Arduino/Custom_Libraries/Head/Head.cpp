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

void Head::servo(int lEar_pin, int rEar_pin, int lEye_pin, int rEye_pin, int jaw_pin) {
	ears.servo(lEar_pin, rEar_pin);
	jaw.init(jaw_pin);
}

void Head::earsOut()
{
	ears.setMoveType(130, 70);
}

void Head::earsIn()
{
	ears.setMoveType(70, 130);
}

void Head::earsParallel()
{
	ears.setMoveType(90, 90);
}

void Head::openJaw(bool closeAfterOpen)
{
	jaw.setToPosWithSpeed(OPEN,9);
	openingClosingJaw = closeAfterOpen;
	jawOpen = true;
}

void Head::closeJaw()
{
	jaw.setToPosWithSpeed(CLOSE,9);
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
		jaw.setToPosWithSpeed(CLOSE,9);
		jawOpen = false;
		openingClosingJaw = false;
	}
	moving = ears.move() || moving;
	moving = eyes.move() || moving;
	return moving;  
}

