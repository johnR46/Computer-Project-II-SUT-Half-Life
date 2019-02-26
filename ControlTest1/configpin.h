
#define ch1  22
#define ch2 23
#define ch3  24
#define ch4  25

#define ch5 26
#define ch6 27
#define ch7  28
#define ch8  29
#define ch9  30
#define ch10  31

#define m1_1 34
#define m1_2 35
#define pwm1 2

#define m2_1 36
#define m2_2 37
#define pwm2 3

#define m3_1 38
#define m3_2 39
#define pwm3 4

#define m4_1 40
#define m4_2 41
#define pwm4 5

#define m5_1 42
#define m5_2 43
#define pwm5 6

#define m6_1 44
#define m6_2 45
#define pwm6 7

#define m7_1 46
#define m7_2 47
#define pwm7 8

#define m8_1 48
#define m8_2 49
#define pwm8 9

#define m9_1 50
#define m9_2 51
#define pwm9 10

#define m10_1 52
#define m10_2 53
#define pwm10 11


const int stepsPerRevolution = 200;  // change this to fit the number of steps per revolution
#include <Stepper.h>

Stepper StepperOne(stepsPerRevolution, 34, 35, 36, 37);


void intital() {
  pinMode(m1_1, OUTPUT);
  pinMode(m1_2, OUTPUT);
  pinMode(pwm1, OUTPUT);
  pinMode(m2_1, OUTPUT);
  pinMode(m2_2, OUTPUT);
  pinMode(pwm2, OUTPUT);
  pinMode(m3_1, OUTPUT);
  pinMode(m3_2, OUTPUT);
  pinMode(pwm3, OUTPUT);
  pinMode(m4_1, OUTPUT);
  pinMode(m4_2, OUTPUT);
  pinMode(pwm4, OUTPUT);
  StepperOne.setSpeed(30);
  //  pinMode(m5_1, OUTPUT);
  //  pinMode(m5_2, OUTPUT);
  //  pinMode(pwm5, OUTPUT);
  //  pinMode(m6_1, OUTPUT);
  //  pinMode(m6_2, OUTPUT);
  //  pinMode(pwm6, OUTPUT);
  //  pinMode(m7_1, OUTPUT);
  //  pinMode(m7_2, OUTPUT);
  //  pinMode(pwm7, OUTPUT);
  //  pinMode(m8_1, OUTPUT);
  //  pinMode(m8_2, OUTPUT);
  //  pinMode(pwm8, OUTPUT);
  //  pinMode(m9_1, OUTPUT);
  //  pinMode(m9_2, OUTPUT);
  //  pinMode(pwm9, OUTPUT);
  //  pinMode(m10_1, OUTPUT);
  //  pinMode(m10_2, OUTPUT);
  //  pinMode(pwm10, OUTPUT);


}
