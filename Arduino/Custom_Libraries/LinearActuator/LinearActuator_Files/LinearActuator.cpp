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

/*  @Author: Jon Kenneson
 *  @Date: October 2016
 *  
 *  @Input: int position - a percantage out of 100 of the length extended of the arm
 *          int speed - a percentage of 100 of the max speed of the movement of the actuator
 *  This function sends the actuator to a specified distance at a certain speed (after a warmup and a cooldown - both 20% of distance)
 *  To speed up -> currentSpeed = currPos * MaxSpeed / 20Pos
 *  To slow down -> MaxSpeed + (-((currPos-80Pos)+MaxSpeed)/20Pos)
 */
bool LinearActuator::sendToPosWithSpeed(int finalPos, int finalSpeed) {
  int currentPos = getCurrentPosition();
  int currentSpeed;
  //If this is our first time in the loop
  if(moving == false) {
    int startPos = currentPos;
	int difference = abs(finalPos - currentPos);
	int middlePos = difference / 2;
  
	//Find the A constant value
	double A = ((1-.03)*finalSpeed/(pow(startPos - middlePos,2)));
	//Serial.println(A);
	
	//Set our private variables
	_finalPos = finalPos;
	_A = A;
	_middlePos = middlePos;
	moving = true;
  }
  
  //If we're below, extend the actuator
  if(currentPos < finalPos) {
      currentSpeed = -_A * pow((currentPos - _middlePos),2) + finalSpeed + 50;
      if(currentSpeed > 255) {
        currentSpeed = 255;
      }      
      digitalWrite(In1, LOW);
      analogWrite(In2, currentSpeed);
        
      currentPos = getCurrentPosition();
    return moving;
  }
  //If we're above, extend the actuator
  else if(currentPos > finalPos) {
      currentSpeed = -_A * pow((currentPos - _middlePos),2) + finalSpeed + 50;
      if(currentSpeed > 255) {
        currentSpeed = 255;
      }      
      analogWrite(In1, currentSpeed);
      digitalWrite(In2, LOW);
        
      currentPos = getCurrentPosition();
	return moving;
  }
  else if(currentPos == finalPos) {
	//Send both signals low to hold position there
	//Stop motion
	digitalWrite(In1, LOW);
	digitalWrite(In2, LOW);
	moving = false;
	return moving;
  }
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

