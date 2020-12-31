/* 1/8/2020
 * Samuel Ryckman
 * 
 * Header file for the Wingoneer BTS7960 motor controller library.
 * 
 * BTS7960(rPwmPin, lPwmPin, enPin, invert) - Constructor. Define control pins and motor direction.
 * init() - initialize the motor controller. Should be called in the Arduino setup().
 * run(speed) - Run the motor at the specified speed.
 * stop() - Stop the motor. Allow to coast.
 * brake() -  Stop the motor with braking action.
 */

#include "BTS7960.h"

/** Constructor for the class
* @param rPwmPin
*/
BTS7960::BTS7960(int rPwmPin, int lPwmPin, int enPin, bool invert = false)
    : rPwmPin(rPwmPin),
      lPwmPin(lPwmPin),
      enPin(enPin),
      invert(invert)
{ }


/**
* Initialize the controller pins.
*/
void BTS7960::init() {
	pinMode(rPwmPin, OUTPUT);
	pinMode(lPwmPin, OUTPUT);
	pinMode(enPin, OUTPUT);
    
    digitalWrite(enPin, HIGH);
}


/**
* Run the motor at the specified speed.
* 
* @param speed - the speed for the motor in the range 255 to -255.
*/
void BTS7960::run(int speed) {
    // Invert if needed
    if (invert) {
        speed = -speed;
    }
    
    // Set outputs accordingly.
    if (speed > 0) {
        analogWrite(rPwmPin, 0);
        analogWrite(lPwmPin, constrain(abs(speed), 0, 255));
    } else {
        analogWrite(rPwmPin, constrain(abs(speed), 0, 255));
        analogWrite(lPwmPin, 0);
    }
    
    // Enable output
	digitalWrite(enPin, HIGH);
}

/**
* Stop the motor. Allow to coast.
*/
void BTS7960::stop() {
    //pull both low.
	analogWrite(rPwmPin, 0);
	analogWrite(lPwmPin, 0);
    
    // Disable output
	digitalWrite(enPin, LOW);
}

/**
* Stop the motor with braking action. (Doesn't really do much. Just slows down sligtly faster.)
*/
void BTS7960::brake() {
    //pull both low.
	analogWrite(rPwmPin, 0);
	analogWrite(lPwmPin, 0);
    
    // Enable output
	digitalWrite(enPin, HIGH);
}