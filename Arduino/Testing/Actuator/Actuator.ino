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

void loop() {
  //Read the potentiometer
  int sensorValue = analogRead(potPin);
  Serial.println(sensorValue);//prints value to serial port
  delay(50);        // delay in between reads for stability
}

void extendActuator(int actuator) {
  //Set one relay one and the other off
  //this will move extend the actuator
  digitalWrite(In1, HIGH);
  digitalWrite(In2, LOW);
}

void retractActuator(int actuator) { 
  //Set one relay off and the other on 
  //this will move retract the actuator 
  digitalWrite(In1, LOW);
  digitalWrite(In2, HIGH); 
}

void stopActuator(int actuator) {
 //Set both relays off
 //this will stop the actuator in a braking
 digitalWrite(In1, LOW);
 digitalWrite(In2, LOW); 
} 
