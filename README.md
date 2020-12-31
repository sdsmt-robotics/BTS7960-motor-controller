
# BTS7960 Motor Controller  
Arduino Library for the BTS7960 Motor Controller. 

# Usage  
**Create:**  
Create a object to control an individual motor.  

    BTS7960 motor(rPwmPin, lPwmPin, enPin, invert);  

*rPwmPin, lPwmPin* - pwm pins used to control direction.  
*enPin* - digital pin to control speed.  
*invert* - (optional) [true/false] Invert motor direction.  
  

**Initialize:**  
Initialize to control the motor. Should be run in the init() function.

    motor.init();

  
**Run the Motor:**  
Set the motor speed and direction.

    motor.run(speed);

*speed* - [-255 to 255] Speed to run the motor at.


**Stop the Motor:**  
Make the motor coast to a stop.

    motor.stop();


**Stop the Motor with Braking:**  
Make the motor stop with the braking action. (Doesn't do that much. Just slows down slightly faster.)

    motor.brake();


  
# Controller Info  
<img src="http://drive.google.com/uc?export=view&id=11ksjhtVJ6fS-xGV-8BJH1_RkUEz0fTbs" width="600" />

Datasheet: [https://www.handsontec.com/dataspecs/module/BTS7960%20Motor%20Driver.pdf](https://www.handsontec.com/dataspecs/module/BTS7960%20Motor%20Driver.pdf)

This device is an H-bridge cabable of controlling a single motor with peak current of 43A.

**Wiring:**  
The connections on the above pinout correspond to the following items in the code:  
(code -> diagram)  
enPin -> L_EN, R_EN  
lPwmPin -> LPWM  
rPwmPin -> RPWM  
The RPWM and LPWM pins must be connected to some PWM cabable pin on the Arduino. The enable pin may be connected to any digital IO pin.

*Note: The two enable pins on the BTS7960 (R_EN & L_EN) are not normally connected. They must be bridged manually while wiring the device. You can also connect these two pins directly to the VCC pin on the controller to reduce wiring if you desire (although brake() will not work).*
