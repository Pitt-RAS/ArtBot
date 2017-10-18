/**
 * Tail.cpp - C++ file for controlling panther tail
 * Author: Jeffrey Socash
 * Date: September 2017
 */
 
 #include "ArtBot.h"
 
 Tail::Tail():
	xMotor(),
	yMotor()
 {
	 moving = false;
 }
 
 /**
  * Initializes the two servos that compose the tail
  */
 void Tail::servo(int xPinLoc, int yPinLoc){
	 xMotor.init(xPinLoc);
	 yMotor.init(yPinLoc);
 }
 
 void Tail::setMoveType(TailCommand command){
	 //Will write once I find out what movements the tail needs
	 //TailCommand is an enumerated type defined in the class prototype in ArtBot.h
	 //can switch to int argument if enum implementation is too frustrating
 }
 
 bool Tail::move(){
	 moving = xMotor.move();
	 moving = yMotor.move() || moving;
	 return moving;
 }