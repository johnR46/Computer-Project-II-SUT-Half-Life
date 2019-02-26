/* Sweep
 by BARRAGAN <http://barraganstudio.com>
 This example code is in the public domain.

 modified 8 Nov 2013
 by Scott Fitzgerald
 http://www.arduino.cc/en/Tutorial/Sweep
*/

#include <Servo.h>

Servo servo1;  // create servo object to control a servo
Servo servo2;
Servo servo3;
// twelve servo objects can be created on most boards

int pos = 0;    // variable to store the servo position
int a=90;
int b=80;
int c=0;
void setup() {
  servo1.attach(7);  // attaches the servo on pin 9 to the servo object
  servo2.attach(8);
  servo3.attach(9);
  
    servo1.write(90);
    delay(15);
    servo2.write(80);
    delay(15);
    servo3.write(180);
    delay(15);
}

void loop() {
//
    a++;
    b++;
//    c++;
    servo1.write(a);
    delay(15);
    servo2.write(b);
    delay(15);
    servo3.write(180);
    delay(15);
    
    if (a>=130)
    {
      a=90;
    }
    if (b>=50)b=10;
//    if (c>=180)c=0;
}

