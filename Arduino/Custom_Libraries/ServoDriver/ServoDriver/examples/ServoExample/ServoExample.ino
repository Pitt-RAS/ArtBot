/*
	@Author: Woodrow Fulmer
	@Date: February 2017
	
	This file shows the functionality of creating a new ServoDriver object and then calling the function to retract and extend the arm
*/

#include <ServoDriver.h>

//Create a new ServoDriver object
ServoDriver s;
bool extended;
bool moving;

void setup() {
	s.init(44);
	extended = false;
	moving = false;
}

void loop() {
	moving = s.move();
	if(!moving)
	{
		if(extended)
			s.setToPosWithSpeed(0, 7);
		else
			s.setToPosWithSpeed(180, 7);
		extended = !extended;
	}
}
