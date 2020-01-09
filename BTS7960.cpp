#include "L289N.h"

L289N::L289N(int _dir1, int _dir2, int _pwm, bool _invert = false)
{
	dir1 = _dir1;
	dir2 = _dir2;
	pwm  = _pwm ;
	invert = _invert;
	
	if (!invert)
	{
		forwardDirection = 1;
		backwardDirection = 0;
	}
	else
	{
		forwardDirection = 0;
		backwardDirection = 1;
	}
}

/**
* Initialize the controller pins.
*/
void L289N::init()
{
	pinMode(dir1, OUTPUT);
	pinMode(dir2, OUTPUT);
	pinMode(pwm, OUTPUT);
}

void L289N::forwards()
{  
	digitalWrite(dir1, forwardDirection);
	digitalWrite(dir2, backwardDirection);
}

void L289N::backwards()
{
	digitalWrite(dir1, backwardDirection);
	digitalWrite(dir2, forwardDirection);
}

void L289N::setSpeed(int speed)
{
	analogWrite(pwm, constrain(speed, 0, 255));
}

void L289N::setSpeedDirection(int speed)
{
	if (speed >= 0)
	{
		forwards();
		setSpeed(speed);
	}
	else
	{
		backwards();
		setSpeed(abs(speed));
	}
}