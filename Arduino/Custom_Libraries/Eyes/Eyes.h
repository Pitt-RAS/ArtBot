/*
  Eyes.h - Header file for the Panther eyes
  Author: Woodrow Fulmer
  Date: September 2017
*/

#ifndef Eyes_h
#define Eyes_h

#include "Arduino.h"
#include "Servo.h"

class Eyes {  
  public:
	Eyes();
	void servo(int pinLocLeftEye, int pinLocRightEye);
	void blink();
	bool move();
	
  private:
	ServoDriver leftEye;
	ServoDriver rightEye;
	bool moving;
	bool closed;
	bool blinking;
};

#endif