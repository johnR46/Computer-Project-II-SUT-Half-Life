
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
  if (speeds == 0) {
    digitalWrite(m4_1, 0);
    digitalWrite(m4_2, 0);
  } else {
    if (x == 1) {
      digitalWrite(m4_1, 1);
      digitalWrite(m4_2, 0);


    } else {
      digitalWrite(m4_1, 0);
      digitalWrite(m4_2, 1);

    }
  }


}



void motor_5Go(byte x, byte speeds) {
  if (speeds == 0) {
    digitalWrite(m5_1, 0);
    digitalWrite(m5_2, 0);
  } else {
    if (x == 1) {
      digitalWrite(m5_1, 1);
      digitalWrite(m5_2, 0);


    } else {
      digitalWrite(m5_1, 0);
      digitalWrite(m5_2, 1);

    }
  }


}



void motor_6Go(byte x, byte speeds) {
  if(speeds == 0){
     digitalWrite(m6_1, 0);
    digitalWrite(m6_2, 0);
  }else {
    if (x == 1) {
    digitalWrite(m6_1, 1);
    digitalWrite(m6_2, 0);


  } else {
    digitalWrite(m6_1, 0);
    digitalWrite(m6_2, 1);

  }
  }
  

}



void motor_7Go(byte x, byte speeds) {
  if(speeds == 0){
     digitalWrite(m7_1, 0);
    digitalWrite(m7_2, 0);
  }else {
    if (x == 1) {
    digitalWrite(m7_1, 1);
    digitalWrite(m7_2, 0);


  } else {
    digitalWrite(m7_1, 0);
    digitalWrite(m7_2, 1);

  }
  }
  

}


void motor_8Go(byte x, byte speeds) {
  if(speeds == 0){
     digitalWrite(m8_1, 0);
    digitalWrite(m8_2, 0);
  }else {
    if (x == 1) {
    digitalWrite(m8_1, 1);
    digitalWrite(m8_2, 0);


  } else {
    digitalWrite(m8_1, 0);
    digitalWrite(m8_2, 1);

  }
  }
  

}




void motor_9Go(byte x, byte speeds) {
  if(speeds == 0){
     digitalWrite(m9_1, 0);
    digitalWrite(m9_2, 0);
  }else {
    if (x == 1) {
    digitalWrite(m9_1, 1);
    digitalWrite(m9_2, 0);


  } else {
    digitalWrite(m9_1, 0);
    digitalWrite(m9_2, 1);

  }
  }
  

}
