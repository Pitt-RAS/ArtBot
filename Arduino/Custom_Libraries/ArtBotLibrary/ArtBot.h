/*
  ArtBot.h - Header file for the ArtBot library
	Currently implements:
		LinearActuator.cpp
		ServoDriver.cpp
		Arm.cpp
	Future Implementations:
		Head.cpp
		Panther.cpp
  Author: Woodrow Fulmer
  Date: May 2017
*/

#ifndef ArtBot_h
#define ArtBot_h

#include "Arduino.h"
#include "Servo.h"

class LinearActuator {
  public:
    LinearActuator(int input1, int input2, int inputPot);
    int setPos(int position);
	bool move();
	int getFinalPos();
	bool getMoving();
	int getPos();
    
  private:
    int In1;
    int In2;
    int potPin;
	
	//Use for the sendToPos function
	bool moving;
	bool decreasing;
	int finalPos;
	
    int getCurrentPosition();
};

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

class Ears {  
	//TODO: Create movement types. i.e. EarsPointedInward, etc.
	enum EarMovements {
		
	};
	Ears();
	void servo(int pinLocLeftEar, int pinLocRightEar);
	void setMoveType(int leftEarPosition);
	bool move();
	
  private:
	ServoDriver leftEar;
	ServoDriver rightEar;
	bool moving;
}

#endif