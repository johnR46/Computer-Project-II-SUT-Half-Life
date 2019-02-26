
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


#define PULM4 52
#define DIRM4 53
#define ENAM4 51
#define powerM4 49


#define ServoM1 5
#define ServoM2 6
#define ServoM3 7
#define ServoM4 8
#define ServoM5 9
#define ServoM6 10




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

  // end DC motor

  // begin Stepper Motor
  pinMode(PULM1, OUTPUT); //motor Step 1
  pinMode(DIRM1, OUTPUT);
  pinMode(ENAM1, OUTPUT);
  pinMode(powerM1,OUTPUT);
  digitalWrite(powerM1,HIGH);

  pinMode(PULM2, OUTPUT); //motor Step 2
  pinMode(DIRM2, OUTPUT);
  pinMode(ENAM2, OUTPUT);
  pinMode(powerM2,OUTPUT);
  digitalWrite(powerM2,HIGH);


  pinMode(PULM3, OUTPUT); //motor Step 3
  pinMode(DIRM3, OUTPUT);
  pinMode(ENAM3, OUTPUT);
  pinMode(powerM3,OUTPUT);
  digitalWrite(powerM3,HIGH);

  pinMode(PULM4, OUTPUT);  //motor Step 4
  pinMode(DIRM4, OUTPUT);
  pinMode(ENAM4, OUTPUT);
  pinMode(powerM4,OUTPUT);
  digitalWrite(powerM4,HIGH);
  // end  Stepper Motor

  // begin Servo motor
  pinMode(ServoM1, OUTPUT);  //motor Servo 1
  pinMode(ServoM2, OUTPUT);  //motor Servo 2
  pinMode(ServoM3, OUTPUT); //motor Servo 3
  pinMode(ServoM4, OUTPUT); //motor Servo 4
  pinMode(ServoM5, OUTPUT); //motor Servo 5
  pinMode(ServoM6, OUTPUT); //motor Servo 6
  // end   Servo motor

}
