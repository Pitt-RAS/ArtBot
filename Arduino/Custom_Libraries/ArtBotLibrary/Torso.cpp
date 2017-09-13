/*
  Torso.cpp - C++ file for controling the Panther torso (arms, spine, and tail)
  Fluid motion capabilities, and variable distances to send parts to
  @Author: Ben Posey
  @Date: September 2017
*/

#include "ArtBot.h"

Torso::Torso(int input1_SL, int input2_SL, int inputPot_SL, int input1_EL, int input2_EL, int inputPot_EL,
	int input1_SR, int input2_SR, int inputPot_SR, int input1_ER, int input2_ER, int inputPot_ER,
	int input1_Sp, int input2_Sp, int inputPot_Sp):
  armLeft(input1_SL, input2_SL, inputPot_SL, input1_EL, input2_EL, inputPot_EL),
  armRight(input1_SR, input2_SR, inputPot_SR, input1_ER, input2_ER, inputPot_ER),
  spine(input1_Sp, input2_Sp, inputPot_Sp),
  tail()
{
  moving = false;
}

void Torso::servo(int pinLoc1, int pinLoc2, int pinLoc3) {
	tail.init(pinLoc1);
	armLeft.servo(pinLoc2);
	armRight.servo(pinLoc3);
}

/*  @Author: Ben Posey
 *  @Date: September 2017
 *  
 *  @Input: int command - a numerical value symbolic of a particular arm movement
 *  This function sends commands to the arm(elbow, shoulder, wrist), spine and tail 
 *  actuators and servosto begin a predetermined movement.
 *	case 1: "Lie Down", retract elbow and shoulder & extend spine
 *	case 2: "Stand Up", extend elbow, retract shoulder & retract spine
 *	case 3: "Roar", extend elbow and shoulder & retract spine
 *  case 4: "Scratch Ear", lie down + extend left shoulder, then extend and retract left elbow
 *  case 10: retract elbow
 *  case 11: extend elbow
 */

void Torso::setMoveType(int command) {
	switch(command) {
		case 1: // Lie Down
			armLeft.setMoveType(1);
			armRight.setMoveType(1);
			spine.setPos(100);
			tail.setToPosWithSpeed(60,9);
			break;
		case 2: // Stand Up
			armLeft.setMoveType(2);
			armRight.setMoveType(2);
			spine.setPos(10);
			tail.setToPosWithSpeed(60,9);
			break;
		case 3: // Roar
			armLeft.setMoveType(3);
			armRight.setMoveType(3);
			spine.setPos(10);
			tail.setToPosWithSpeed(60,9);
			break;
		case 4: // Scratch Ear
			armLeft.setMoveType(4);
			armRight.setMoveType(1);
			spine.setPos(100);
			tail.setToPosWithSpeed(60,9);
			break;
		case 10: case 11: // Move elbows of both arms
			armLeft.setMoveType(command);
			armRight.setMoveType(command);
			break;
		case 12: case 13: // Move left elbow only
			armLeft.setMoveType(command - 2);
			break;
		case 14: case 15: // Move right elbow only
			armRight.setMoveType(command - 4);
			break;
		case 20: case 21: // Move shoulders of both arms
			armLeft.setMoveType(command);
			armRight.setMoveType(command);
			break;
		case 22: case 23: // Move left shoulder only
			armLeft.setMoveType(command - 2);
			break;
		case 24: case 25: // Move right shoulder only
			armRight.setMoveType(command - 4);
			break;
		default:
			armLeft.setMoveType(1);
			armRight.setMoveType(1);
			spine.setPos(100);
			tail.setToPosWithSpeed(60,9);
			break;
	}
}

/*  @Author: Ben Posey
 *  @Date: September 2017
 *  
 *  
 */
bool Torso::move() {
	moving = armLeft.move();
	moving = armRight.move() || moving;
	moving = spine.move() || moving;
	moving = tail.move() || moving;
	return moving;  
}

