//reads chars from python, lights corresponding LED up
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
    char line = Serial.read();
    char str[2];
    str[0] = line;
    str[1] = '\0';
    Serial.print(str[0]);
    if(strncmp(str, "r", 1) == 0) {
      color = red;
    }else if(strncmp(str, "y", 1) == 0) {
      color = yellow; 
    }else if(strncmp(str, "g", 1) == 0) {
      color = green;
    }
    analogWrite(color, 100);
    delay(1000);  
    analogWrite(color, 0);
    Serial.flush();           
  }
}
