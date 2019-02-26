
#define ch1  23
#define ch2 25
#define ch3  27
#define ch4  29

#define ch5 31
#define ch6 33
#define ch7  35
#define ch8  37
#define ch9  39


#define m1_1 22
#define m1_2 24
#define pwm1 2

#define m2_1 26
#define m2_2 28
#define pwm2 3

#define m3_1 30
#define m3_2 32
#define pwm3 4



#define m4_1 34
#define m4_2 36

#define m5_1 38
#define m5_2 40


#define m6_1 42
#define m6_2 44


#define m7_1 46
#define m7_2 48

#define m8_1 47
#define m8_2 45

#define m9_1 43
#define m9_2 41

#define pwmall 13

/*
  #define PULM1 34
  #define DIRM1 36
  #define ENAM1 38
  #define powerM1 40
  #define PULM2 42
  #define DIRM2 44
  #define ENAM2 46
  #define powerM2 48


#define PULM3 47
#define DIRM3 45
#define ENAM3 43
#define powerM3 41
*/

#define PULM4 52
#define DIRM4 53
#define ENAM4 51
#define powerM4 49


#define Realy1 8
#define Realy2 9
#define Realy3 10
#define Realy4 11
#define Realy5 12

#define ServoM1 5
#define ServoM2 6
#define ServoM3 7





void intital() {
  // begin DC motor
  pinMode(m1_1, OUTPUT); // motor DC 1
  pinMode(m1_2, OUTPUT);
  pinMode(pwm1, OUTPUT);

  pinMode(m2_1, OUTPUT); // motor DC 2
  pinMode(m2_2, OUTPUT);
  pinMode(pwm2, OUTPUT);

  pinMode(m3_1, OUTPUT); // motor DC 3
  pinMode(m3_2, OUTPUT);
  pinMode(pwm3, OUTPUT);
 

  pinMode(pwmall, OUTPUT);
  
  pinMode(m4_1, OUTPUT); // motor DC 4
  pinMode(m4_2, OUTPUT);

  pinMode(m5_1, OUTPUT); // motor DC 5
  pinMode(m5_2, OUTPUT);

  pinMode(m6_1, OUTPUT); // motor DC 6
  pinMode(m6_2, OUTPUT);

  pinMode(m7_1, OUTPUT); // motor DC 7
  pinMode(m7_2, OUTPUT);

  pinMode(m8_1, OUTPUT); // motor DC 8
  pinMode(m8_2, OUTPUT);

  pinMode(m9_1, OUTPUT); // motor DC 9
  pinMode(m9_2, OUTPUT);
  analogWrite(pwmall,255);

  /*

    pinMode(PULM1, OUTPUT); //motor Step 1
    pinMode(DIRM1, OUTPUT);
    pinMode(ENAM1, OUTPUT);
    pinMode(powerM1, OUTPUT);
    // end DC motor

    // begin Stepper Motor
    pinMode(PULM1, OUTPUT); //motor Step 1
    pinMode(DIRM1, OUTPUT);
    pinMode(ENAM1, OUTPUT);
    pinMode(powerM1, OUTPUT);
    digitalWrite(powerM1, HIGH);

    pinMode(PULM2, OUTPUT); //motor Step 2
    pinMode(DIRM2, OUTPUT);
    pinMode(ENAM2, OUTPUT);
    pinMode(powerM2, OUTPUT);
    digitalWrite(powerM2, HIGH);


    pinMode(PULM3, OUTPUT); //motor Step 3
    pinMode(DIRM3, OUTPUT);
    pinMode(ENAM3, OUTPUT);
    pinMode(powerM3, OUTPUT);
    digitalWrite(powerM3, HIGH);
  */
  pinMode(PULM4, OUTPUT);  //motor Step 4
  pinMode(DIRM4, OUTPUT);
  pinMode(ENAM4, OUTPUT);
  pinMode(powerM4, OUTPUT);
  digitalWrite(powerM4, HIGH);
  // end  Stepper Motor

  // begin Servo motor
  pinMode(ServoM1, OUTPUT);  //motor Servo 1
  pinMode(ServoM2, OUTPUT);  //motor Servo 2
  pinMode(ServoM3, OUTPUT); //motor Servo 3
  // end   Servo motor

  // begin Realy
  pinMode(Realy1, OUTPUT);
  pinMode(Realy2, OUTPUT);
  pinMode(Realy3, OUTPUT);
  pinMode(Realy4, OUTPUT);
  pinMode(Realy5, OUTPUT);
  // end Realy

}
