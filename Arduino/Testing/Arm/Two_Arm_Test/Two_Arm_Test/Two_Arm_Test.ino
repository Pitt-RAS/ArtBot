/*
  @Author: Jonathan Kenneson
  @Date: January, 2017
  
  Two arm testing file for 4 linear actuator and 2 servo motor control
  This file will extend all motors and retract them in a fluid motion

  *Note: servos and actuators cannot be on the same timer!
  See Arduino_Timers.txt in the data sheets folder for info on which timers are connected to which PWM pins
*/
#define SERVO_SPEED 13  //(minimum number of milliseconds per degree)
#include <LinearActuator.h> //See the custom libraries for info on how to import this library
#include <Servo.h>

//Create new LinearActuator objects by passing in In1, In2, and potPin in the constructor
//Left Arm
LinearActuator leftShoulder(4,13,A0); //Timer0
LinearActuator leftElbow(11,12,A1);   //Timer1
Servo leftPaw;                        //Timer5 - attach to 44
//Right Arm
LinearActuator rightShoulder(9,10,A2);//Timer2
LinearActuator rightElbow(2,3,A3);    //Timer3
Servo rightPaw;                       //Timer5 - attach to 45

//Left Arm helper variables
bool moveLeftShoulder;
bool moveLeftElbow;
bool moveLeftPaw;
int leftPawPos;     // desired angle for leftPaw

//Right Arm helper variables
bool moveRightShoulder;
bool moveRightElbow;
bool moveRightPaw;
int rightPawPos;    // desired angle for rightPaw

static unsigned long servoTimeLeft;   //Time since last servo movement
static unsigned long servoTimeRight; //For right arm

void setup() {
  Serial.begin(9600);       //Start the serial
  //Left arm initial conditions
  moveLeftShoulder = false;
  moveLeftElbow = false;
  moveLeftPaw = false;
  leftPaw.attach(44);

  //Right arm initial conditions
  moveRightShoulder = false;
  moveRightElbow = false;
  moveRightPaw = false;
  rightPaw.attach(45);
}

void loop() {
  //Reset variables for movement
  moveLeftShoulder = true;
  moveLeftElbow = true;
  moveLeftPaw = true;
  leftPawPos = 0;
  moveRightShoulder = true;
  moveRightElbow = true;
  moveRightPaw = true;
  rightPawPos = 0;
  
  //Send the actuator to a position (0-100%) with desired top speed (0-255)
  while(moveLeftShoulder == true || moveLeftElbow == true || moveLeftPaw == true || moveRightShoulder == true || moveRightElbow == true || moveRightPaw == true) {
    //Left arm movement
    if(moveLeftShoulder == true) {
      moveLeftShoulder = leftShoulder.sendToPosWithSpeed(0,255); 
    }
    if(moveLeftElbow == true) {
      moveLeftElbow = leftElbow.sendToPosWithSpeed(0,100);  
    }
    if(moveLeftPaw == true) {
      // check time since last servo position update 
      if ((millis()-servoTimeLeft) >= SERVO_SPEED) {
        servoTimeLeft = millis(); // save time reference for next position update
       
        // update leftPaw position
        // if desired position is different from current position move one step left or right
        if (leftPawPos > leftPaw.read()) leftPaw.write(leftPaw.read() + 1);
        else if (leftPawPos < leftPaw.read()) leftPaw.write(leftPaw.read() - 1);
        else moveLeftPaw = false;
      }  
    }

    //Right arm movement
    if(moveRightShoulder == true) {
      moveRightShoulder = rightShoulder.sendToPosWithSpeed(0,255); 
    }
    if(moveRightElbow == true) {
      moveRightElbow = rightElbow.sendToPosWithSpeed(0,100);  
    }
    if(moveRightPaw == true) {
      // check time since last servo position update 
      if ((millis()-servoTimeRight) >= SERVO_SPEED) {
        servoTimeRight = millis(); // save time reference for next position update
       
        // update rightPaw position
        // if desired position is different from current position move one step left or right
        if (rightPawPos > rightPaw.read()) rightPaw.write(rightPaw.read() + 1);
        else if (rightPawPos < rightPaw.read()) rightPaw.write(rightPaw.read() - 1);
        else moveRightPaw = false;
      }  
    }
  }

  //Reset variables for new movement
  moveLeftShoulder = true;
  moveLeftElbow = true;
  moveLeftPaw = true;
  leftPawPos = 180;
  moveRightShoulder = true;
  moveRightElbow = true;
  moveRightPaw = true;
  rightPawPos = 180;
  
  while(moveLeftShoulder == true || moveLeftElbow == true || moveLeftPaw == true) {
    //Left arm movements
    if(moveLeftShoulder == true) {
      moveLeftShoulder = leftShoulder.sendToPosWithSpeed(100,255); 
    }
    if(moveLeftElbow == true) {
      moveLeftElbow = leftElbow.sendToPosWithSpeed(100,100);  
    }
    if(moveLeftPaw == true) {
      // check time since last servo position update 
      if ((millis()-servoTimeLeft) >= SERVO_SPEED) {
        servoTimeLeft = millis(); // save time reference for next position update
       
        // update leftPaw position
        // if desired position is different from current position move one step left or right
        if (leftPawPos > leftPaw.read()) leftPaw.write(leftPaw.read() + 1);
        else if (leftPawPos < leftPaw.read()) leftPaw.write(leftPaw.read() - 1);
        else moveLeftPaw = false;
      }  
    }

    //Right arm movement
    if(moveRightShoulder == true) {
      moveRightShoulder = rightShoulder.sendToPosWithSpeed(100,255); 
    }
    if(moveRightElbow == true) {
      moveRightElbow = rightElbow.sendToPosWithSpeed(100,100);  
    }
    if(moveRightPaw == true) {
      // check time since last servo position update 
      if ((millis()-servoTimeRight) >= SERVO_SPEED) {
        servoTimeRight = millis(); // save time reference for next position update
       
        // update rightPaw position
        // if desired position is different from current position move one step left or right
        if (rightPawPos > rightPaw.read()) rightPaw.write(rightPaw.read() + 1);
        else if (rightPawPos < rightPaw.read()) rightPaw.write(rightPaw.read() - 1);
        else moveRightPaw = false;
      }  
    }
  }
}
