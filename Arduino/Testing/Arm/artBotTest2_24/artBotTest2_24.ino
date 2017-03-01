/*
 * This program can be used to test sending movement commands to 2-arms
 * The input it should recieve from the serial is of the format
 * "A B"
 * where A is the command for myArm1 and B is the command for myArm2
 * Command 0 is both retracted
 * Command 1 is elbow extended and shoulder retracted
 * Command 2 is elbow retracted and shoulder extended
 * Command 3 is both extended
 */



#include <Arm.h>

Arm myArm1(9, 10, A2, 2, 3, A3);
Arm myArm2(4, 13, A0, 11, 12, A1);

bool moving1;
bool moving2;
int getFirst;
int in;
int first;
int second;

void setup() {
  myArm1.servo(44);
  myArm2.servo(45);
  moving1 = false;
  moving2 = false;
  Serial.begin(9600);
  getFirst = 0;
}

void loop() {  
  moving1 = myArm1.move();
  moving2 = myArm2.move();
  
  in = Serial.read() - 48;
  if(in >= 0)
  {
    if(getFirst == 0)
    {
      first = in;
      getFirst = 1;
    }
    else if (getFirst == 1)
    {
      second = in;
      getFirst = 2;
    }
    Serial.print(in);
    Serial.print(", getFirst = ");
    Serial.print(getFirst);
    Serial.print(", first = ");
    Serial.print(first);
    Serial.print(", second = ");
    Serial.println(second);
  }
  
  if(!moving1 && !moving2)
  {
    if(getFirst == 2)
    {
      myArm1.setMoveType(first);
      myArm2.setMoveType(second);
      getFirst = 0;
    }
  }
}
