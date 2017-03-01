/*
	@Author: Woodrow Fulmer
	@Date: February 2017
	
	This file shows the functionality of creating a new ServoDriver object and then calling the function to retract and extend the arm
*/

#include <ServoDriver.h>

//Create a new ServoDriver object
ServoDriver s1;
ServoDriver s2;

bool ex1;
bool mov1;

bool ex2;
bool mov2;

void setup() {
	s1.init(44);
  s2.init(45);
	ex1 = false;
	mov1 = false;
	ex2 = false;
	mov2 = false;
}

void loop() {
	mov1 = s1.move();
	mov2 = s2.move();
	
	if(!mov1)
	{
		if(ex1)
			s1.setToPosWithSpeed(0, 7);
		else
			s1.setToPosWithSpeed(180, 7);
		ex1 = !ex1;
	}
	if(!mov2)
	{
		if(ex2)
			s2.setToPosWithSpeed(0, 7);
		else
			s2.setToPosWithSpeed(180, 7);
		ex2 = !ex2;
	}
}
