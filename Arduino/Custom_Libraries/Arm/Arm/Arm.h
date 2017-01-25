/*
  Arm.h - Header file for controling the Arm
  Fluid motion capabilities, and variable distances to send arm to
  Author: Woodrow Fulmer
  Date: November 2016
*/
#ifndef Arm_h
#define Arm_h

#include "Arduino.h"
#include "LinearActuator.h"
#include "ServoDriver.h"

class Arm {
  public:
    Arm(int input1_S, int input2_S, int inputPot_S, int input1_E, int input2_E, int inputPot_E);
	void servo(int pinLoc);
    void setMoveType(int command);
	bool move();
    
  private:
    LinearActuator elbow;
	LinearActuator shoulder;
	ServoDriver wrist;
	
	bool moving;
};

#endif