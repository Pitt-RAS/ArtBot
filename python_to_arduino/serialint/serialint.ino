//reads ints from python (in ASCII) to light LEDs
int red = 3;
int yellow = 5;
int green = 9;
int color = 3;
int readNum;

void setup(){
 Serial.begin(9600);
 pinMode(red, OUTPUT);
 pinMode(yellow, OUTPUT);
 pinMode(green, OUTPUT);
}

void loop(){
  if(Serial.available() > 0){  
    readNum = Serial.read(); 
    Serial.print(readNum);
    if(readNum == 49) { //1
      color = red;
    }else if(readNum == 50) { //2
      color = yellow; 
    }else if(readNum == 51) { //3
      color = green;
    }
    analogWrite(color, 100);
    delay(1000);  
    analogWrite(color, 0);
    Serial.flush();           
  }
}
