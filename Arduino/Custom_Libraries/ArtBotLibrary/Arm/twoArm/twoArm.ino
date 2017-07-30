#include <ArtBot.h>

Arm myArm1(9, 10, A0, 11, 12, A1);
Arm myArm2(6, 7, A2, 3, 5, A3);

bool retract;
bool moving1;
bool moving2;

void setup() {
  retract = true;
  myArm1.servo(44);
  myArm2.servo(45);
  moving1 = false;
  moving2 = false;
}

void loop() {
	moving1 = myArm1.move();
	moving2 = myArm2.move();
  if(!moving1 && !moving2)
  {
    if(retract)
    {
      myArm1.setMoveType(0);
	    myArm2.setMoveType(0);
      retract = false;
    }
    else
    {
      myArm1.setMoveType(3);
	    myArm2.setMoveType(3);
      retract = true;
    }
  }
}
