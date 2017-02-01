/*
  LinearActuator.h - Header file for controling linear actuator motors
  Fluid motion capabilities, and variable distances to send arm to
  Author: Jonathan Kenneson & Alex Furches
  Date: October 2016
*/
#ifndef LinearActuator_h
#define LinearActuator_h

#include "Arduino.h"

class LinearActuator {
  public:
    LinearActuator(int input1, int input2, int inputPot);
    void setPos(int position);
	bool move();
    
  private:
    int In1;
    int In2;
    int potPin;
	
	//Use for the sendToPos function
	bool moving;
	int finalPos;
	
    int getCurrentPosition();
};

#endif
