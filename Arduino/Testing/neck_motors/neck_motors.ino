/* Sweep
 by BARRAGAN <http://barraganstudio.com>
 This example code is in the public domain.

 modified 8 Nov 2013
 by Scott Fitzgerald
 http://www.arduino.cc/en/Tutorial/Sweep
*/
/*
 * Ground = Black
 * 5V = Red
 * Signal(pin 9) = Yellow
 */

#include <Servo.h>

Servo vNeckServo;  // servo to control vertical neck movement
Servo hNeckServo;  // servo to control horizontal neck movement
// twelve servo objects can be created on most boards

int pos = 0;    // variable to store the servo position

#define vMin 0
#define vMax 180

#define hMin 0
#define hMax 100

void setup() {
  //vNeckServo.attach(9);  // attaches the servo on pin 9 to the servo object
  hNeckServo.attach(9);  // attaches the servo on pin 9 to the servo object
}

void loop() {
  for (pos = hMin; pos <= hMax; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    hNeckServo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
  for (pos = hMax; pos >= hMin; pos -= 1) { // goes from 180 degrees to 0 degrees
    hNeckServo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
}
