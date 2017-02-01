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
  //Testing PWM for variable speed
  sendToPosition(0);
  delay(1000);
  sendToPosition(100);
  delay(1000);
}

/*  @Author: Jon Kenneson
 *  @Date: September 2016
 *  
 *  This function reads the potentiometer and returns mapped value in range 0-100% 
 */
int getCurrentPosition() {
  int sensorValue = analogRead(potPin);
  sensorValue = map(sensorValue, 50, 850, 0, 100);
  if(sensorValue > 100) sensorValue = 100;
  else if(sensorValue < 0) sensorValue = 0;
  Serial.println(sensorValue);
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

