/*
  Head.h - Header file for the Panther head
  Author: Joe Lynch
  Date: October 2017
*/

#ifndef Head_h
#define Head_h

#include "Arduino.h"
#include "Servo.h"

class Head {  
  public:
	Eyes();
	void servo(int pinLocLeftEye, int pinLocRightEye);
	void blink();
	bool move();
	
  private:
	ServoDriver jaw;
	bool moving;
	bool jawOpen;
	bool openingClosingJaw;
};

#endif