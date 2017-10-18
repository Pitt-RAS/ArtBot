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
	void servo(int lEar_pin, int rEar_pin, int jaw_pin);
	bool move();
	void earsOut();
	void earsIn();
	void earsParallel();
	void openJaw(bool closeAfterOpen);
	void closeJaw();
	
  private:
	Ears ears;
	ServoDriver jaw;
	bool moving;
	bool jawOpen;
	bool openingClosingJaw;
};

#endif