//Pin declarations
int In1 = 6;
int In2 = 5;
int potPin = A0;

/*NOTE:
 * Sending HIGH to In2 and LOW to In1 will extend the actuator
 * Sending LOW to In2 and HIGH to In1 will retract the actuator
 * Sending LOW to In2 and LOW to In1 will stop the actuator movement
 */

void setup() {
  //Begins serial
  Serial.begin(9600); 
  //Define pins
  pinMode(In1,OUTPUT);
  pinMode(In2,OUTPUT);
  pinMode(potPin, INPUT);
}


//This loop simply tests functions below
void loop() {
<<<<<<< Updated upstream
  //Testing PWM for variable speed
  sendToPosition(0);
  sendToPosWithSpeed(100,255);
  sendToPosition(0);
  //Serial.println(analogRead(potPin));

  /*
=======
  Serial.println("Slide Forward");
  setDir(1);
  slide(5);

  Serial.println("Slide Backward");
  setDir(2);
  slide(5);
  }
  /*//Testing PWM for variable speed
  sendToPosition(100);
  analogWrite(In1, 50);
  digitalWrite(In2, 0);
  //Serial.println(analogRead(potPin));
  delay(10000);
*/
  
>>>>>>> Stashed changes
  //Testing variable distance control
  //Send to 1/4, 1/2, 3/4, and full
 /* sendToPosition(25);
  delay(1000);
  sendToPosition(50);
  delay(1000);
  sendToPosition(75);
  delay(1000);
  sendToPosition(100);
  delay(1000);*/
 
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
  int currentPos = getCurrentPosition();
  int startPos = currentPos;
  int currentSpeed;
  int difference = abs(finalPos - currentPos);
  int middlePos = difference / 2;
  
  //Find the A constant value
  double A = ((1-.03)*finalSpeed/(pow(startPos - middlePos,2)));
  Serial.println(A);
  //If we're below, extend the actuator
  while(currentPos < finalPos) {
	currentSpeed = -A * pow((currentPos - middlePos),2) + finalSpeed + 50;
	if(currentSpeed > 255) {
		currentSpeed = 255;
	}
	
	Serial.print("Speed: ");
	Serial.print(currentSpeed);
	Serial.print(" Position: ");
	Serial.println(currentPos);
	  
	  
    digitalWrite(In1, LOW);
    analogWrite(In2, currentSpeed);
      
	currentPos = getCurrentPosition();
	
  }
  
  //Otherwise, send both signals low to hold position there
  //Stop motion
  digitalWrite(In1, LOW);
  digitalWrite(In2, LOW);
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
void sendToPosition(int position, double speed) {
  int currentPosition = getCurrentPosition();
  
  //If we're below, extend the actuator
  if(currentPosition < position) {
    while(currentPosition < position) {
      digitalWrite(In1, LOW);
      analogWrite(In2, speed);
      currentPosition = getCurrentPosition();
    }
      //Stop motion
      digitalWrite(In1, LOW);
      digitalWrite(In2, LOW);
  }
  //If we're above, retract the actuator
  else if (currentPosition > position) {
     while(currentPosition > position) {
      analogWrite(In1, speed);
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

void slide(int d) {
  for(int v=0;v<256;++v) {
    analogWrite(3,v);
    delay(d);
  }
  for(int v=255;v>=0;--v) {
    analogWrite(3,v);
    delay(d);
  }
}

void setDir(int d) {
  switch(d) {
    case 0: // off?
    digitalWrite(2,LOW);
    digitalWrite(4,LOW);
    break;
    case 1: // forward
    digitalWrite(2,HIGH);
    digitalWrite(4,LOW);
    break;
    case 2:  // backward
    digitalWrite(2,LOW);
    digitalWrite(4,HIGH);
    break;
    case 3:  // locked?
    digitalWrite(2,HIGH);
    digitalWrite(4,HIGH);
    break;
  }
}
