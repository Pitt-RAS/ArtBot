//Pin declarations
int In1 = 6;
int In2 = 5;
int potPin = A0;

/*NOTE:
 * Sending HIGH to In2 and LOW to In1 will extend the actuator
 * Sending LOW to In2 and HIGH to In1 will retract the actuator
 * Sending LOW to In2 and LOW to In1 will stop the actuator movement
 */
bool forward;
bool backward;
int currentPos;
int startPos;
int currentSpeed;
int difference;
int middlePos;
int finalSpd;
int finalPosi;
double A;
bool start;

void setup() {
  //Begins serial
  Serial.begin(9600); 
  //Define pins
  pinMode(In1,OUTPUT);
  pinMode(In2,OUTPUT);
  pinMode(potPin, INPUT);

  forward = false;
  backward = false;
  start = true;
}

//This loop simply tests functions below
void loop() {
  sendToPosWithSpeed(100, 255);
  moveLoop();
}

/*  @Author: Jon Kenneson
 *  @Date: October 2016
 *  
 *  @Input: int position - a percantage out of 100 of the length extended of the arm
 *          int speed - a percentage of 100 of the max speed of the movement of the actuator
 *  This function sends the actuator to a specified distance at a certain speed (after a warmup and a cooldown - both 20% of distance)
 *  To speed up -> currentSpeed = currPos * MaxSpeed / 20Pos
 *  To slow down -> MaxSpeed + (-((currPos-80Pos)+MaxSpeed)/20Pos)
 */
int sendToPosWithSpeed(int finalPos, int finalSpeed) {
  currentPos = getCurrentPosition();
  startPos = currentPos;
  difference = abs(finalPos - currentPos);
  middlePos = difference / 2;
  finalPosi = finalPos;
  finalSpd = finalSpeed;
  
  //Find the A constant value
  A = ((1-.03)*finalSpeed/(pow(startPos - middlePos,2)));
  Serial.println(A);
  //If we're below, extend the actuator
  if(currentPos < finalPos) {
    backward = true;
  }
  //If we're above, extend the actuator
  else if(currentPos > finalPos) {
    forward = true;
  }
}

//Woody is going to write a program to fix the loop error
void moveLoop() 
{
  currentSpeed = -A * pow((currentPos - middlePos),2) + finalSpd + 50;
  if(currentSpeed > 255) 
  {
    currentSpeed = 255;
  } 
  if(forward)
  {
      if(currentPos > finalPosi)
      {
        analogWrite(In1, currentSpeed);
        digitalWrite(In2, LOW);
      }
      else
      {
        forward = false;
      }
  }
  else if(backward)
  {
      if(currentPos < finalPosi) 
      {
        digitalWrite(In1, LOW);
        analogWrite(In2, currentSpeed);
      }
      else
      {
        backward = false;
      }
  }
  else
  {
    digitalWrite(In1, LOW);
    digitalWrite(In2, LOW);
  }
  currentPos = getCurrentPosition();
}

/*  @Author: Jon Kenneson
 *  @Date: September 2016
 *  
 *  This function reads the potentiometer and returns mapped value in range 0-100% 
 */
int getCurrentPosition() {
  int sensorValue = analogRead(potPin);
  sensorValue = map(sensorValue, 50, 850, 0, 100);
  //Serial.println(sensorValue);
  return sensorValue;
}

/*  @Author: Jon Kenneson
 *  @Date: September 2016
 *  
 *  This function sends the actuator to a certain position determined by percentage extended sent in 
 *  The actuator will extend if it is below the intended position, retract if above, or stay still if already in place
 */
void sendToPosition(int position) {
  int currentPosition = getCurrentPosition();
  
  //If we're below, extend the actuator
  if(currentPosition < position) {
    while(currentPosition < position) {
      digitalWrite(In1, LOW);
      digitalWrite(In2, HIGH);
      currentPosition = getCurrentPosition();
    }
      //Stop motion
      digitalWrite(In1, LOW);
      digitalWrite(In2, LOW);
  }
  //If we're above, retract the actuator
  else if (currentPosition > position) {
     while(currentPosition > position) {
      digitalWrite(In1, HIGH);
      digitalWrite(In2, LOW);
      currentPosition = getCurrentPosition();
    }
    //Stop motion
    digitalWrite(In1, LOW);
    digitalWrite(In2, LOW);
  }
  //Otherwise, send both signals low to hold position there
  else {
    //Stop motion
    digitalWrite(In1, LOW);
    digitalWrite(In2, LOW);
  }
}

