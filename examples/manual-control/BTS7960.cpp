/* 1/8/2020
 * Samuel Ryckman
 * 
 * Header file for the Wingoneer BTS7960 motor controller library.
 * 
 * BTS7960(rPwmPin, lPwmPin, enPin, invert) - Constructor. Define control pins and motor direction.
 * init() - initialize the motor controller. Should be called in the Arduino setup().
 * run(speed) - Run the motor at the specified speed.
 * stop() - Stop (brake) the motor.
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
void BTS7960::init()
{
	pinMode(rPwmPin, OUTPUT);
	pinMode(lPwmPin, OUTPUT);
	pinMode(enPin, OUTPUT);
}


/**
* Run the motor at the specified speed.
* 
* @param speed - the speed for the motor in the range 255 to -255.
*/
void BTS7960::run(int speed)
{
    //get the direction
    
    
    //set the direction. Invert if needed.
    if (speed > 0) {
        digitalWrite(rPwmPin, LOW ^ invert);
        digitalWrite(lPwmPin, HIGH ^ invert);
    } else {
        digitalWrite(rPwmPin, HIGH ^ invert);
        digitalWrite(lPwmPin, LOW ^ invert);
    }
    
    //set the speed
	analogWrite(enPin, constrain(abs(speed), 0, 255));
}


/**
* Stop (break) the motor.
*/
void BTS7960::stop()
{
    //pull both low.
	digitalWrite(rPwmPin, LOW);
	digitalWrite(lPwmPin, LOW);
    
    //enable
	analogWrite(enPin, 255);
}
