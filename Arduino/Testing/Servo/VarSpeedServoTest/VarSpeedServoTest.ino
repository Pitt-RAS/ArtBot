//This code uses the custom VarSpeedServo library, found at https://forum.arduino.cc/index.php?topic=61586.15
//VarSpeedServo hosted on the thread is a bit outdated, so a tweaked library has been put on GitHub for use
//Note: do not use with Servo; use one or the other.

#include <VarSpeedServo.h>
VarSpeedServo servo;
const int pin = 5;
int spd;


void setup() {
  servo.attach(pin);
  //slowmove(position,speed), where a speed of 0 is the servo's normal unregulated speed
  servo.slowmove(0,0);

}

void loop() {
  // testing the slowmove() function by using increasing speeds
  //slowmove accepts a speed from 1 to 255, but this is not a concrete scale and not all servos can reach 255 as a max
  //more testing would be necessary to find our servos' "max" speed values
  
  for(spd=20;spd<=255;spd+=50){
    servo.slowmove(180,spd);
    delay(10000);
    servo.slowmove(0,0);
    delay(1000);
  }
}
