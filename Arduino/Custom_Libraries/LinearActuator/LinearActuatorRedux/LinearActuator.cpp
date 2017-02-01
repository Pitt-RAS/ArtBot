/*
  LinearActuator.cpp - C++ file for controling linear actuator motors
  Fluid motion capabilities, and variable distances to send arm to
  Author: Jonathan Kenneson & Alex Furches
  Date: October 2016
*/

#include "Arduino.h"
#include "LinearActuator.h"

LinearActuator::LinearActuator(int input1, int input2, int inputPot){
  In1 = input1;
  In2 = input2;
  potPin = inputPot;
  pinMode(In1,OUTPUT);
  pinMode(In2,OUTPUT);
  pinMode(potPin, INPUT);
  
  //Set some variables to null for checking
  moving = false;
}

/*	@Author: Woodrow Fulmer
 *	@Date: January 2017
 *
 *  @Input: int position - a percantage out of 100 of the length extended of the arm
 *          int speed - a percentage of 100 of the max speed of the movement of the actuator
 *	This function starts the movement of the actuator, setting all the variables needed for motion.
 */
bool LinearActuator::setPos(int position) {
	int finalPos = position;
	moving = true;
}

/*  @Author: Jon Kenneson
 *	@Edit: Woodrow Fulmer
 *  @Date: January 2017
 *  
 *  @Input: int position - a percantage out of 100 of the length extended of the arm
 *          int speed - a percentage of 100 of the max speed of the movement of the actuator
 *  This function sends the actuator to a specified distance at a certain speed (after a warmup and a cooldown - both 20% of distance)
 *  To speed up -> currentSpeed = currPos * MaxSpeed / 20Pos
 *  To slow down -> MaxSpeed + (-((currPos-80Pos)+MaxSpeed)/20Pos)
 */
bool LinearActuator::move() {
  int currentPos = getCurrentPosition();
  
  //If we're below, extend the actuator
  if(currentPos < finalPos) {
      digitalWrite(In1, LOW);
      digitalWrite(In2, HIGH);
      
    moving = true;
  }
  //If we're above, retract the actuator
  else if(currentPos > finalPos) {
      digitalWrite(In1, HIGH);
      digitalWrite(In2, LOW);
        
	moving = true;
  }
  else {
	//Send both signals low to hold position there
	//Stop motion
	digitalWrite(In1, LOW);
	digitalWrite(In2, LOW);
	moving = false;
  }
  return moving;
}

/*  @Author: Jon Kenneson
 *  @Date: September 2016
 *  
 *  This function reads the potentiometer and returns mapped value in range 0-100% 
 */
int LinearActuator::getCurrentPosition() {
  int sensorValue = analogRead(potPin);
  if(sensorValue > 850) sensorValue = 850;
  if(sensorValue < 0)   sensorValue = 50;
  sensorValue = map(sensorValue, 50, 850, 0, 100);
  //Serial.println(sensorValue);
  return sensorValue;
}

