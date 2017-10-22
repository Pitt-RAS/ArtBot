#include <Eyes.h>

Eyes eyes;
bool moving;
int in;

void setup() {
  eyes.servo(3, 6);
  Serial.begin(9600);
  moving = false;
  in = -1;
  eyes.open();
}

void loop() {
  moving = eyes.move();
  in = Serial.read() - 48;
  if(in >= 0 && !moving) {
    eyes.blink();
  }
}
