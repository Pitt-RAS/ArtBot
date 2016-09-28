//Pin declarations
int In1 = 5;
int In2 = 6;
int potPin = A0;

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
  //Send to 1/4, 1/2, 3/4, and full
  sendToPosition(25);
  delay(1000);
  sendToPosition(50);
  delay(1000);
  sendToPosition(75);
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
  sensorValue = map(sensorValue, 0, 900, 0, 100);

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
      digitalWrite(In1, HIGH);
      digitalWrite(In2, LOW);
      currentPosition = getCurrentPosition();
    }
      //Stop motion
      digitalWrite(In1, LOW);
      digitalWrite(In2, LOW);
  }
  //If we're above, retract the actuator
  else if (currentPosition > position) {
     while(currentPosition > position) {
      digitalWrite(In1, LOW);
      digitalWrite(In2, HIGH);
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

