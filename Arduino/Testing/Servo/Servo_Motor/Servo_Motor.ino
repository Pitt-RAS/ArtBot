#define SERVO_SPEED 5  //(minimum number of milliseconds per degree)
#include <Servo.h>


int servo1_pos = 180;  // desired angle for servo1
int servo2_pos = 90;  // desired angle for servo2

Servo servo1;
Servo servo2;

void setup()
{
servo1.attach(A0);
servo2.attach(A1);
servo1.write(0);
servo2.write(0);
}

void loop()
{
 static unsigned long servo_time;
 
 // check time since last servo position update 
 if ((millis()-servo_time) >= SERVO_SPEED) {
   servo_time = millis(); // save time reference for next position update
   
   // update servo1 position
   // if desired position is different from current position move one step left or right
   if (servo1_pos > servo1.read()) servo1.write(servo1.read() + 1);
   else if (servo1_pos < servo1.read()) servo1.write(servo1.read() - 1);
   

   // update servo2 position
   // if desired position is different from current position move one step left or right
   if (servo2_pos > servo2.read()) servo2.write(servo2.read() + 1);
   else if (servo2_pos < servo2.read()) servo2.write(servo2.read() - 1);
 }
}
