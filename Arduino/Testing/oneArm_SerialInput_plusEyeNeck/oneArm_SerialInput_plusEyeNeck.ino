/*
 * This program can be used to test sending movement commands to a single arm
 * The input it should recieve from the serial-in line
 * 
 * Command 0 is both retracted
 * Command 1 is elbow extended and shoulder retracted
 * Command 2 is elbow retracted and shoulder extended
 * Command 3 is both extended
 * 
 * Command 4 is retract elbow
 * Command 5 is extend elbow
 * 
 * Command 6 is retract shoulder
 * Command 7 is extend elbow
 */
 
#include <Arm.h>
#include <ServoDriver.h>

Arm myArm(9, 10, A2, 2, 3, A3);

Servo neckServo;

bool moving;
int in;
int moveCommand;
int servoCommand;

ServoDriver myservo;  // create servo object to control a servo 
                // twelve servo objects can be created on most boards
 
int pos = 0;    // variable to store the servo position 
int eyelid_closed = 180;
int eyelid_opened = 140;


bool neckMove;


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


void setup() {
  myArm.servo(44);
  moving = false;
  Serial.begin(9600);
  moveCommand = 0;
  myservo.init(6);  // attaches the servo on pin 3 to the servo object 
  servoCommand = eyelid_opened;
  neckServo.attach(A9);
  neckServo.write(center);
  neckMove = false;
}

void loop() {
  if(neckMove)
    neck_loop();
  else
  {
    moving = myArm.move();
    myservo.move();
  
    in = Serial.read() - 48;
    if(in >= 0)
    {
      switch(in)
      {
          case 4:
            moveCommand = 10;
            break;
          case 5:
            moveCommand = 11;
            break;
          case 6:
            moveCommand = 20;
            break;
          case 7:
            moveCommand = 21;
            break;
          case 8:
            servoCommand = eyelid_closed;
            //moveCommand = 8;
            break;
          case 9:
            servoCommand = eyelid_opened;
            //moveCommand = 9;
            break;
          case 0:
            neckMove = true;
          default:
            moveCommand = in;
            break;
      }
      Serial.print("moveCommand = ");
      Serial.println(moveCommand);
    }
    if(!moving)
    {
      myArm.setMoveType(moveCommand);
      myservo.setToPosWithSpeed(servoCommand, 3);
    }
  }
}


void neck_loop()
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
      if(currentPosition > 180)
        currentPosition = 180;
      neckServo.write(currentPosition);
    }
    else if (cx < -50) //decrease angle
    {
      currentPosition -= 3;
      if(currentPosition < 0)
        currentPosition = 0;
      neckServo.write(currentPosition);
    }
  }
}

