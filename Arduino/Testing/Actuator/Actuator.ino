
int motPlus = 6, motMinus = 5, potPin = 0;//global variables

void setup() {
  Serial.begin(9600);//begins serial 
  pinMode(motPlus,OUTPUT);
  pinMode(motMinus,OUTPUT);
}

void loop() {

  int sensorValue = analogRead(potPin);
  //switching motPlus and motMinus switches direction 
  digitalWrite(motPlus,HIGH);//sending HIGH value will send 12 Volts to motor "hot" wire
  digitalWrite(motMinus,LOW);//makes other motor wire "cold" wire
  Serial.println(sensorValue);//prints value to serial port
  delay(50);        // delay in between reads for stability
}
