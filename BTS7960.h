/* 1/8/2020
 * Samuel Ryckman
 * 
 * Header file for the Wingoneer BTS7960 motor controller library.
 */

#ifndef BTS7960_H
#define BTS7960_H

#include "Arduino.h"

class BTS7960
{
public:
  BTS7960(int rPwmPin, int lPwmPin, int enPin, bool invert = false);
  
  void init();
  void run(int speed);
  void stop();
  
private:
  int rPwmPin, lPwmPin, enPin;
  bool invert;
};

#endif
