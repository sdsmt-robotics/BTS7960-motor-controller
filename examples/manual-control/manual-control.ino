/* 1/8/2020
 * Samuel Ryckman
 * 
 * Example of how to use the library.
 * Allows you to control the motor using +/- keys and the spacebar.
 * 
 * +/-: increase or decrease speed.
 * space: toggle motor on/off.
 * b: brake.
 */

#include "BTS7960.h"

char readVal = 'u';

//Define motor controller.
//BTS7960(rPwmPin, lPwmPin, enPin, invert = false)
BTS7960 motor(6, 5, 7);


/**
 * Print the state of the motor controller.
 */
void printControllerState(bool motorRunning, int motorSpeed) 
{
  Serial.print("Motor state: ");
  if (motorRunning) {
    Serial.print("RUNNING @ ");
    Serial.println(motorSpeed);
  } else {
    Serial.println("STOPPED");
  }
}

//=====setup==============================
void setup() {
  Serial.begin(115200);
  
  //initialize the motor controller
  motor.init();
  motor.stop();

  printControllerState(false, 0);
}

//=====loop==============================
void loop() {
  static bool motorRunning = false;
  static int motorSpeed = 0;
  
  //wait for a value, read it, and clear the extra
  while (Serial.available() <= 0) {
    delay(100);
  }
  char readVal = Serial.read();
  while(Serial.available()){Serial.read();}
  
  switch (readVal) {
    case ' ':
      //toggle the motor on or off
      if (motorRunning) {
        motor.stop();
        motorRunning = false;
      } else {
        motor.run(motorSpeed);
        motorRunning = true;
      }
      break;
    case '+':
    case '=':
      motorSpeed += 5;
      motorRunning = true;
      motor.run(motorSpeed);
      break;
    case '-':
    case '_':
      motorSpeed -= 5;
      motorRunning = true;
      motor.run(motorSpeed);
      break;
    case 'b':
      Serial.println("Motor brake");
      motor.brake();
      motorRunning = false;
      break;
    default:
      break;
  }

  //Print the current state
  printControllerState(motorRunning, motorSpeed);
  
}