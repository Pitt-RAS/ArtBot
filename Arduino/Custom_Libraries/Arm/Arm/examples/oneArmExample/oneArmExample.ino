#include <Arm.h>

Arm myArm( 6, 5, A0, 11, 10, A1);

bool moveArm;

void setup() {
  moveArm = false;
  retract = true;
  myArm.servo(44);
}

void loop() {
  if(!myArm.move())
  {
    if(retract)
      myArm.setMoveType(0);
    else
      myArm.setMoveType(3);
  }
}
