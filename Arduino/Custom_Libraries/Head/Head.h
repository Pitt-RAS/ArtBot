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
	Head();
	Eyes eyes;
	Ears ears;
	void jawServo(int jaw_pin);
	bool move();
	void openJaw(bool closeAfterOpen);
	void closeJaw();
	
  private:
	ServoDriver jaw;
	bool moving;
	bool jawOpen;
	bool openingClosingJaw;
};

#endif