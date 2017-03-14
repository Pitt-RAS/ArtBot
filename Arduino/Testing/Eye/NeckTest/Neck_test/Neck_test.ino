/* Test code of rotating "neck" to follow user

    Joe Lynch
    Jonathan Kenneson
    Kyle Monto
    3/13/2017
*/

#include <Servo.h>

Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards

String serialInput = "";

bool tildaReceived = false;
bool cx1Received = false;
bool cx2Received = false;
bool cy1Received = false;
bool cy2Received = false;

char cx1;
char cx2;
char cy1;
char cy2;

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
  if (Serial.available() > 0)
  {

    if (cy1Received == true) {
      cy2 = Serial.read();
      
      cy1Received = false;
      cy2Received = true;
    }
    else if (cx2Received == true) {
      cy1 = Serial.read();

      cx2Received = false;
      cy1Received = true;
    }
    else if (cx1Received == true) {
      cx2 = Serial.read();

      cx1Received = false;
      cx2Received = true;
    }
    else if ( tildaReceived == true) {
      cx1 = Serial.read();

      Serial.println(cx1);

      tildaReceived = false;
      cx1Received = true;
    }
    else {
      char character = Serial.read(); // Receive a single character from the software serial port

      //Get our target coordinates
      if (character == 126) {                   //~
        tildaReceived = true;
      }
    }

  }

  //If we've read in all 4 coordinates, concatenate them
  if (cy2Received == true) {
    String cxString = String(cx1 + cx2);
    String cyString = String(cy1 + cy2);

    int cx = cxString.toInt();
    int cy = cyString.toInt();

    Serial.print("cx: ");
    Serial.print(cx);
    Serial.print(" cy: ");
    Serial.println(cy);

    cy2Received = false;
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

