/*
  ServoDriver.cpp - C++ file for controling servo motors
  Fluid motion capabilities, variable speeds, and variable distances to send servo to
  Author: Woodrow Fulmer
  Date: November 2016
*/

#include "Arduino.h"
#include "Servo.h"
#include "ServoDriver.h"

ServoDriver::ServoDriver(int pinLoc)
{
  servo.attach(pinLoc);
  finalPos = 0;
  moving = false;
  servo.write(0);
}

/*  @Author: Woodrow Fulmer
 *  @Date: November 2016
 *  
 *  @Input: int position - the desired angle for the servo to travel to
 *          int speed - the minimum number of milliseconds between each degree
 *  This function sets the position to move to, the speed to move at, and begins motion
 */
void ServoDriver::setToPosWithSpeed(int pos, int spd) 
{
  finalPos = pos;
  finalSpd = spd;
  moving = true;
}

/*  @Author: Woodrow Fulmer
 *  @Date: November 2016
 *  
 *  This function causes the Servo to move to the determined angle at the given speed
 * @Return: bool isMoving - this method returns if the Servo is still in motion
 */
bool ServoDriver::move() 
{
   if ((millis()-servo_time) >= finalSpd) 
   {
	   servo_time = millis(); // save time reference for next position update
	   if (finalPos > servo1.read()) 
		   servo1.write(servo1.read() + 1);
	   else if (finalPos < servo1.read())
		   servo1.write(servo1.read() - 1);
	   else
		   moving = false;
   ]
   return moving;
}

