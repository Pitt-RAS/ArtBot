#include <ArtBot.h>

Arm myArm(9, 10, A2, 2, 3, A3);

bool retract;
bool moving;

void setup() {
  moving = false;
  retract = true;
  myArm.servo(44);
}

void loop() {
  moving = myArm.move();
  if(!moving)
  {
    if(retract)
    {
      myArm.setMoveType(Arm::FULL_RETRACT);
      retract = false;
    }
    else
    {
      myArm.setMoveType(Arm::FULL_EXTEND);
      retract = true;
    }
  }
}