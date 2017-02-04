#include <Arm.h>

Arm myArm(9, 10, A2, 2, 3, A3);

bool retract;

void setup() {
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
