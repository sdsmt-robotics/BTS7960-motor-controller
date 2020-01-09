
# Wingoneer BTS7960  
Arduino Library for the Wingoneer BTS7960 Motor Controller. 

# Usage  
**Create:**  
Create a object to control an individual motor.  

    BTS7960 motor(rPwmPin, lPwmPin, enPin, invert);  

*rPwmPin, lPwmPin* - digital IO pins used to control direction.
*enPin* - pwm pin to control speed.
*invert* - (optional) [true/false] Invert motor direction.
  

**Initialize:**  
Initialize to control the motor. Should be run in the init() function.

    motor.init();

  
**Run the Motor:**  
Set the motor speed and direction.

    motor.run(speed);

*speed* - [-255 to 255] Speed to run the motor at.


**Stop the Motor:**  
Make the motor stop.

    motor.stop();


  
# Controller Info  
![Pinout](https://cdn.instructables.com/F3W/PCEK/JVH3KZLD/F3WPCEKJVH3KZLD.LARGE.jpg)

Datasheet: [https://cdn.instructables.com/ORIG/FYD/V3VU/HUL8W2ZW/FYDV3VUHUL8W2ZW.pdf](https://cdn.instructables.com/ORIG/FYD/V3VU/HUL8W2ZW/FYDV3VUHUL8W2ZW.pdf)

This device is an H-bridge cabable of controlling a single motor with peak current of 43A.

**Wiring:**  
The connections on the above pinout correspond to the following items in the code:
enPin -> PWM  
lPwmPin -> LPWM  
rPwmPin -> RPWM  
The enPin must be connected to some PWM cabable pin on the Arduino. The other two may be connected to any digital IO pins.

*Note: The two "PWM" pins on the BTS7960 are not normally connected. They must be bridged manually while wiring the device.*