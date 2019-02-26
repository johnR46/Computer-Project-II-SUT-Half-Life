
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
