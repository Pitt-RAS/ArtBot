/*
 * This program can be used to test sending movement commands to a single arm
 * The input it should recieve from the serial-in line
 * 
 * 
 * Command 1: "Lie Down", retract elbow and shoulder & extend spine
 * Command 2: "Stand Up", extend elbow, retract shoulder & retract spine
 * Command 3: "Roar", extend elbow and shoulder & retract spine
 * Command 4: "Scratch Ear", lie down + extend left shoulder, then extend and retract left elbow
 * Command 5: "Wave", stand up + extend left shoulder, then extend and retract left wrist
 * Command 6: "Lick Paw", lie down + extend right shoulder, then move head (can't test yet)
 * Command 10: retract elbows
 * Command 11: extend elbows
 * Command 20: retract shoulders
 * Command 21: extend shoulders
 * Command 30: retract wrists
 * Command 31: extend wrists
 */

#include <ArtBot.h>

Torso torso(9, 10, A0, 11, 12, A1,
            6, 7, A2, 3, 5, A3,
            4, 13, A4);

char in;
bool moving;
int moveCommand;
int moveArray[5];
bool longCommand;
bool moveDone[5];
int i;

// Movement Constants
int lie_down = 1;     // Retract elbow and shoulder & extend spine
int stand_up = 2;     // Extend elbow, retract shoulder & retract spine
int roar = 3;         // Extend elbow and shoulder & retract spine
int scratch_ear = 4;  // Raise arm and move elbow up & down
int wave = 5;         // Stand up + extend left shoulder, then extend and retract left wrist
int lick_paw = 6;

void setup() {
  torso.servo(44, 45, 46);
  moving = false;
  moveCommand = 0;
  longCommand = false;
  Serial.begin(9600);
}

void loop() {
  moving = torso.move();
  in = Serial.read() - 48;
  if(in >= 0) {
    switch(in) {
        case 1: // Lie down
          moveCommand = lie_down;
          longCommand = false;
          break;
        case 2: // Stand up
          moveCommand = stand_up;
          longCommand = false;
          break;
        case 3: // Roar
          moveCommand = roar;
          longCommand = false;
          break;
        case 4: // Scratch Ear: Move 4->13->12->13->1
          moveArray[0] = scratch_ear;
          moveArray[1] = 13;
          moveArray[2] = 12;
          moveArray[3] = 13;
          moveArray[4] = lie_down;
          for (i=0;i<5;i++) { moveDone[i] = false; }
          longCommand = true;
          break;
        case 5: // Wave: Move 5->33->32->33->2
          moveArray[0] = wave;
          moveArray[1] = 33;
          moveArray[2] = 32;
          moveArray[3] = 33;
          moveArray[4] = stand_up;
          for (i=0;i<5;i++) { moveDone[i] = false; }
          longCommand = true;
          break;
        case 6: // Lick Paw
          moveCommand = lick_paw;
          longCommand = false;
          break;
        case 10:
          moveCommand = 10;
          longCommand = false;
          break;
        case 11:
          moveCommand = 11;
          longCommand = false;
          break;
        case 20:
          moveCommand = 20;
          longCommand = false;
          break;
        case 21:
          moveCommand = 21;
          longCommand = false;
          break;
        case 30:
          moveCommand = 30;
          longCommand = false;
          break;
        case 31:
          moveCommand = 31;
          longCommand = false;
          break;
        default:
          moveCommand = in;
          longCommand = false;
          break;
    }
    Serial.print("moveCommand = ");
    Serial.println(moveCommand);
  }

  
  if(longCommand) {
    // Executes sequence of five commands in order
    if(!moveDone[0]) {
      if(!moving) {
        torso.setMoveType(moveArray[0]);
        moveDone[0] = true; 
      }
    } else if(!moveDone[1]) {
      if(!moving) {
        torso.setMoveType(moveArray[1]);
        moveDone[1] = true; 
      }
    } else if(!moveDone[2]) {
      if(!moving) {
        torso.setMoveType(moveArray[2]);
        moveDone[2] = true; 
      }
    } else if(!moveDone[3]) {
      if(!moving) {
        torso.setMoveType(moveArray[3]);
        moveDone[3] = true; 
      }
    } else if(!moveDone[4]) {
      if(!moving) {
        torso.setMoveType(moveArray[4]);
        moveDone[4] = true; 
      }
    }  
  } else {
    if(!moving) {
      torso.setMoveType(moveCommand);
    }
  }
}
