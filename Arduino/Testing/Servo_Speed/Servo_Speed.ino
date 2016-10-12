//include the Servo library (analogous to importing in Java)
#include <Servo.h>

Servo servo;
const int pin=5;
int angle=0;
int delayTime=15;

void setup() {
  //Initialize the servo motor connected to pin
  servo.attach(pin);
  servo.write(0);
  Serial.begin(9600);
  //timeTest();

}

void loop() {
  //Method to sweep the servo between a certain range
  sweep(0, 180, 10);
 // timeTest();
  

}

void sweep(int a, int b, int d){
  //extend from beginning of range to end of range
  for(angle=a;angle<b;angle++){
    servo.write(angle);
   // Serial.println(servo.read());
    delay(d);
  }
  
  for(angle=b;angle>a;angle--){
    servo.write(angle);
 //   Serial.println(servo.read());
    delay(d);
  }

}
void sweepTest(int d){
  sweep(0,180,d);
  delay(500);
  
}

