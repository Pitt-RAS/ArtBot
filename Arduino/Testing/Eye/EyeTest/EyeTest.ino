/* Test code of opening + closing the panther eyelids
 *  
 *  Joe Lynch
 *  1/21/2017
*/ 

#include <Servo.h> 
 
Servo myservo;  // create servo object to control a servo 
                // twelve servo objects can be created on most boards
 
int pos = 0;    // variable to store the servo position 
int eyelid_closed = 0;
int eyelid_opened = 47;
 
void setup() 
{ 
  myservo.attach(3);  // attaches the servo on pin 3 to the servo object 
  myservo.write(eyelid_closed);
} 
 
void loop() 
{ 
  for(pos = eyelid_closed; pos <= eyelid_opened; pos += 1) // goes from 0 degrees to 180 degrees 
  {                                  // in steps of 1 degree 
    myservo.write(pos);              // tell servo to go to position in variable 'pos' 
    delay(15);                       // waits 15ms for the servo to reach the position 
  } 
  delay(1000);
  for(pos = eyelid_opened; pos>=eyelid_closed; pos-=1)     // goes from 180 degrees to 0 degrees 
  {                                
    myservo.write(pos);              // tell servo to go to position in variable 'pos' 
    delay(15);                       // waits 15ms for the servo to reach the position 
  } 
  delay(1000);
} 

