/*
 * This program can be used to test sending movement commands to a single arm
 * The input it should recieve from the serial-in line
 * 
 * 
 * Command 1: "Lie Down", retract elbow and shoulder & extend spine
 * Command 2: "Stand Up", extend elbow, retract shoulder & retract spine
 * Command 3: "Roar", extend elbow and shoulder & retract spine
 * Command 4: "Scratch Ear", lie down + extend left shoulder, then extend and retract left elbow
 * Command 5: "Wave"
 * Command 6: "Lick Paw"
 * Command 10: retract elbow
 * Command 11: extend elbow
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
        case 4: // Scratch Ear: Move 4->12->13->12->1
          moveArray[0] = scratch_ear;
          moveArray[1] = 13;
          moveArray[2] = 12;
          moveArray[3] = 13;
          moveArray[4] = lie_down;
          for (i=0;i<5;i++) { moveDone[i] = false; }
          longCommand = true;
          break;
        case 5: // Lick Paw
          moveCommand = 5;
          break;
        case 6:
          moveCommand = 10;
          break;
        case 7:
          moveCommand = 11;
          break;
        case 8:
          moveCommand = 20;
          break;
        case 9:
          moveCommand = 21;
          break;
        default:
          moveCommand = in;
          break;
    }
    Serial.print("moveCommand = ");
    Serial.println(moveCommand);
  }
  
  if(longCommand) {
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
        torso.setMoveType(moveArray[4]);
        moveDone[4] = true; 
      }
    } else if(!moveDone[4]) {
      if(!moving) {
        torso.setMoveType(moveArray[5]);
        moveDone[5] = true; 
      }
    }  
  } else {
    if(!moving) {
      torso.setMoveType(moveCommand);
    }
  }
}
