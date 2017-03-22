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

unsigned char newSerialData;
unsigned char cx1;
unsigned char cx2;
unsigned char cy1;
unsigned char cy2;

int center = 90;
int currentPosition = center;    // variable to store the servo position
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
    newSerialData = (unsigned char)Serial.read();
//    Serial.print("Serial available: ");
//    Serial.println(newSerialData, HEX);
    if (cy1Received == true) {
      cy2 = newSerialData;
      
      cy1Received = false;
      cy2Received = true;
    }
    else if (cx2Received == true) {
      cy1 = newSerialData;

      cx2Received = false;
      cy1Received = true;
    }
    else if (cx1Received == true) {
      cx2 = newSerialData;

      cx1Received = false;
      cx2Received = true;
    }
    else if ( tildaReceived == true) {
      cx1 = newSerialData;

      tildaReceived = false;
      cx1Received = true;
    }
    else if (newSerialData == 126) {
                   
        tildaReceived = true;

        //Reset all others to be false
        cx1Received = false;
        cx2Received = false;
        cy1Received = false;
        cy2Received = false;
        
 //       Serial.println("tilda");
    }
  }

  //If we've read in all 4 coordinates, concatenate them
  if (cy2Received == true) {
    String cxString = String(cx1*256 + cx2);
    String cyString = String(cy1*256 + cy2);

    int cx = cxString.toInt();
    int cy = cyString.toInt();

/*    Serial.print("cx: ");
    Serial.print(cx);
    Serial.print(" cy: ");
    Serial.println(cy);
*/
    cy2Received = false;

    //Turn servo
    if(cx > 50) //increase angle
    {
      currentPosition += 3;
      myservo.write(currentPosition);
    }
    else if (cx < -50) //decrease angle
    {
      currentPosition -= 3;
      myservo.write(currentPosition);
    }
  }
}

