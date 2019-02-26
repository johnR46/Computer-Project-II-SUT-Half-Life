
#define CW 1
#define CCW 0



void motor_1Go(byte x, byte speeds) {
  if (x == 1) {
    digitalWrite(m1_1, 1);
    digitalWrite(m1_2, 0);
    analogWrite(pwm1, speeds);

  } else {
    digitalWrite(m1_1, 0);
    digitalWrite(m1_2, 1);
    analogWrite(pwm1, speeds);
  }

}


void motor_2Go(byte x, byte speeds) {
  if (x == 1) {
    digitalWrite(m2_1, 1);
    digitalWrite(m2_2, 0);
    analogWrite(pwm2, speeds);

  } else {
    digitalWrite(m2_1, 0);
    digitalWrite(m2_2, 1);
    analogWrite(pwm2, speeds);
  }

}


void motor_3Go(byte x, byte speeds) {
  if (x == 1) {
    digitalWrite(m3_1, 1);
    digitalWrite(m3_2, 0);
    analogWrite(pwm3, speeds);

  } else {
    digitalWrite(m3_1, 0);
    digitalWrite(m3_2, 1);
    analogWrite(pwm3, speeds);
  }

}


void motor_4Go(byte x, byte speeds) {
  if (x == 1) {
    digitalWrite(m4_1, 1);
    digitalWrite(m4_2, 0);
    analogWrite(pwm4, speeds);

  } else {
    digitalWrite(m4_1, 0);
    digitalWrite(m4_2, 1);
    analogWrite(pwm4, speeds);
  }

}


int previous = 0;
void motorarm_1Go(int  speeds) { // stepping motor 
 analogWrite(pwm1,255);
 analogWrite(pwm2,255);
  StepperOne.step(speeds - previous);
  previous = speeds;
  
}




void motorarm_2Go(int  speeds) {

}
