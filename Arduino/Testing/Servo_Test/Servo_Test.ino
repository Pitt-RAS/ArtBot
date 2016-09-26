int servoPin=5;//pin number on arduino board

void setup() {
  // put your setup code here, to run once:
  pinMode(servoPin, OUTPUT);//initializes pin as output

}

void loop() {
  //moves servo to "HIGH" position then moves it back to "zero" after delay

  analogWrite(servoPin, 1023);
  delay(1000);
  analogWrite(servoPin, 0);
   delay(1000);
}

