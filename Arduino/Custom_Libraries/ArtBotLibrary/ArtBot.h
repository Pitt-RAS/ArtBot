/*
  ArtBot.h - Header file for the ArtBot library
	Currently implements:
		LinearActuator.cpp
		ServoDriver.cpp
		Arm.cpp
		Torso.cpp
		Ears.cpp
		Tail.cpp
	Future Implementations:
		Eyes.cpp
		Head.cpp
		Panther.cpp
  Author: Woodrow Fulmer
  Date: October 2017
*/

#ifndef ArtBot_h
#define ArtBot_h

#include "Arduino.h"
#include "Servo.h"

#define SERVO_SPEED 9
#define ACTUATOR_OUT 95
#define ACTUATOR_IN 5
#define PAW_UP 60
#define PAW_DOWN 0
#define EAR_LEFT 70
#define EAR_RIGHT 130
#define JAW_OPEN 90
#define JAW_CLOSED 90
#define LEFT_EYE_OPEN 47
#define LEFT_EYE_CLOSED 0
#define RIGHT_EYE_OPEN 133
#define RIGHT_EYE_CLOSED 180

// Enums instaniated outside of classes to be accessible in Arduino code
enum ArmCommand{
	FULL_RETRACT = 1,
	FULL_EXTEND,
	ELBOW_RETRACT = 10,
	ELBOW_EXTEND,
	SHOULDER_RETRACT = 20,
	SHOULDER_EXTEND,
	WRIST_DOWN = 30,
	WRIST_UP
};

enum EarMovement  {
	FORWARD = 0,
	FACE_IN,
	FACE_OUT
};

enum TailCommand{
	//TODO: Figure out what discrete movements we want for tail
};

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
		void setMoveType(ArmCommand command);
		bool move();
		LinearActuator elbow;
		LinearActuator shoulder;
		ServoDriver wrist;
	
	private:	
		bool moving;
};


class Ears {  
	public:
		Ears();
		void servo(int pinLocLeftEar, int pinLocRightEar);
		void setMoveType(int leftEarPosition, int rightEarPosition);
		void setMoveType(EarMovement command);
		bool move();
	
	private:
		ServoDriver leftEar;
		ServoDriver rightEar;
		bool moving;
};

class Tail{
	public:
		Tail();
		void servo(int xPinLoc, int yPinLoc);
		void setMoveType(TailCommand command);
		bool move();
		
	private:
		ServoDriver xMotor;
		ServoDriver yMotor;
		bool moving;
};

class Torso {
	public:
		Torso(int input1_SL, int input2_SL, int inputPot_SL, int input1_EL, int input2_EL, int inputPot_EL, 
			int input1_SR, int input2_SR, int inputPot_SR, int input1_ER, int input2_ER, int inputPot_ER, 
			int input1_Sp, int input2_Sp, int inputPot_Sp);
		void servo(int pinLoc1, int pinLoc2, int pinLoc3);
		void setMoveType(int command);
		bool move();
		Arm armLeft;
		Arm armRight;
		LinearActuator spine;
		ServoDriver tail;

	private:
		bool moving;
};

class Eyes {  
  public:
	Eyes();
	void servo(int pinLocLeftEye, int pinLocRightEye);
	void blink();
	bool move();
	void open();
	void close();
	void halfOpen();
	
  private:
	ServoDriver leftEye;
	ServoDriver rightEye;
	bool moving;
	bool closed;
	bool blinking;
};

class Head {  
  public:
	Head();
	Eyes eyes;
	Ears ears;
	void servo(int jaw_pin);
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