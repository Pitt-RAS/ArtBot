#include <ArtBot.h>

Ears ears;
bool moving;
bool fullRight;
int in;
int rightEarPos;
int leftEarPos;  

void setup() {
  ears.servo(3,6);
  Serial.begin(9600);
  moving = false;
  fullRight = false;
  rightEarPos = 90;
  leftEarPos = 90;
}

void loop() {
  moving = ears.move();

  in = Serial.read() - 48;
  if(in >= 0) {
    if(fullRight) {
      rightEarPos = 130;
      leftEarPos = 70;
      Serial.println("Turning In");
      fullRight = false;
    }
    else {
      rightEarPos = 70;
      leftEarPos = 130;
      Serial.println("Turning Out");
      fullRight = true;
    }
  }
  if(!moving)
    ears.setMoveType(leftEarPos, rightEarPos);
}
