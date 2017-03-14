/* Test code of rotating "neck" to follow user
 *  
 *  Joe Lynch
 *  3/13/2017
*/ 

#include <Servo.h> 
 
Servo myservo;  // create servo object to control a servo 
                // twelve servo objects can be created on most boards
 
int currentPosition = 0;    // variable to store the servo position 
int center = 90;
int X_facePosition = 0;
int Y_facePosition = 0;
 
void setup() 
{ 
  Serial.begin(9600);
  
  myservo.attach(10);  // attaches the servo on pin 10 to the servo object 
  myservo.write(center);
} 
 
void loop() 
{ 
  if(Serial.available() > 0)
  {
    String  
  }
  
/*  if(Serial.available() > 0)
  {
    switch (Serial.read()) {
    case 'X':
    {
      myservo.write(0);
      while(Serial.available() == 0)
      {
        delay(1);
      }
      int tempX = Serial.read();

      if(tempX != X_facePosition)
      {
        //update X position variable + move eye servo
        X_facePosition = tempX;
        myservo.write(X_facePosition);
        Serial.write(X_facePosition);
        
      }
    }
      break;
    case 'Y':
      while(Serial.available() == 0)
      {
        delay(1);
      }
      Y_facePosition = Serial.read();
      break;
  }
  }*/
/*  for(pos = eyelid_closed; pos <= eyelid_opened; pos += 1) // goes from 0 degrees to 180 degrees 
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
  delay(1000);*/
} 

