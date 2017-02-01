/*
  ServoDriver.h - Header file for controling servo motors
  Fluid motion capabilities, changing speed, and variable distances to send servo to
  Author: Woodrow Fulmer
  Date: November 2016
*/
#ifndef ServoDriver_h
#define ServoDriver_h

#include "Arduino.h"
#include "Servo.h"

class ServoDriver {
  public:
    ServoDriver();
	void init(int pinLoc);
    void setToPosWithSpeed(int pos, int spd);
	bool move();
    
  private:
    Servo servo;
    int finalPos;
	int finalSpd;
	bool moving;
	
	//Use for the setToPosWithSpeed function
	unsigned long servo_time;
};

#endif
