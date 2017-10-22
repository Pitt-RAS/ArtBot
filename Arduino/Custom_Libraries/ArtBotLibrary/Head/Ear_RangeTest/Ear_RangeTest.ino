#include <ArtBot.h>

Ears ears;
bool moving;
bool fullRight;
int in;
Ears::EarMovement movement;  

void setup() {
  ears.servo(3,6);
  Serial.begin(9600);
  moving = false;
  fullRight = false;
  movement = Ears::FORWARD;
}

void loop() {
  moving = ears.move();

  in = Serial.read() - 48;
  if(in >= 0) {
    if(fullRight) {
      movement = Ears::FACE_IN;
      Serial.println("Turning In");
      fullRight = false;
    }
    else {
      movement = Ears::FACE_OUT;
      Serial.println("Turning Out");
      fullRight = true;
    }
  }
  if(!moving)
    ears.setMoveType(movement);
}
