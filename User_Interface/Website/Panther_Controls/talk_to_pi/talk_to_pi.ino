String incomingString = "";   // for incoming serial data
void setup() {
        Serial.begin(9600);     // opens serial port, sets data rate to 9600 bps
        pinMode(13, OUTPUT);
        digitalWrite(13, LOW);
}
void loop() {
    // send data only when you receive data:
    
    if (Serial.available() > 0) {

        // read the incoming string:
        incomingString = Serial.readString();
        // say what you got:
        Serial.print("I received: ");
        Serial.println(incomingString);
        if(incomingString.equals("1")) {
            digitalWrite(13, HIGH);
        }
    }
}
