
#include "configpin.h"
#include "configremote.h"
#include "motor.h"
int CH1 = 0;
int CH2 = 0;
int CH3 = 0;
int CH4 = 0;
int CH5 = 0;
int CH6 = 0;
int CH7 = 0;
int CH8 = 0;
int CH9 = 0;
void setup() {
  intital();
  Serial.begin(115200);

}
byte command = 0;
void loop() {

  CH5 =  pulseIn(ch5, HIGH);
  CH6 =  pulseIn(ch6, HIGH);



  if (CH5 <= MID + Error &&  CH6 <= MID + Error ) {
    command = 1;
    //Serial.println("mode 1");
  } else if (CH5 <= MID + Error &&  CH6 >= MID + Error) {
    command  = 2;
    //Serial.println("mode 2");
  }
  else if (CH5 >= MID + Error &&  CH6 <= MID + Error) {
    command  = 3;
    // Serial.println("mode 3");
  }
  else if (CH5 >= MID + Error &&  CH6 >= MID + Error) {
    command  = 4;
    //  Serial.println("mode 4");
  }



  switch (command) {
    case 1  : {
        CH1 =  pulseIn(ch1, HIGH);
        CH2 =  pulseIn(ch2, HIGH);
        CH3 =  pulseIn(ch3, HIGH);
        int  val = map(CH3, MAXCH3, MINCH3, 0, 255);
        Serial.println(val);
        if ((CH2 <= MIDCH2 + Error ) && (CH2 >= MIDCH2 - Error) && (CH1 <= MIDCH1 + Error ) && (CH1 >= MIDCH1 - Error)  ) {
          Serial.println("IDLE Car ");
          motor_1Go(CCW, 0);
          motor_2Go(CCW, 0);
          motor_3Go(CCW, 0);
          motor_4Go(CCW, 0);
        }

        else if ((CH2 >= MIDCH2 + Error)) {
          Serial.println("reward");
          //motor_1Go(CCW, val);
          motor_1Go(CCW, val);
          motor_4Go(CCW, val);
        }  else if ((CH2 <= MIDCH2 - Error)) {
          Serial.println("forward");
          //   motor_1Go(CW, val);
          motor_1Go(CW, val);
          motor_4Go(CW, val);
        }
        else if ((CH1 >= MIDCH1 + Error)) {
          Serial.println("Right");
          //  motor_1Go(CCW, val);
          motor_1Go(CW, val);
          motor_4Go(CCW, val);
        }  else if ((CH1 <= MIDCH1 - Error)) {
          Serial.println("Left");
          //    motor_1Go(CW, val);
          motor_1Go(CCW, val);
          motor_4Go(CW, val);
        }

        break;
      }
    case 2 : {
        CH2 =  pulseIn(ch2, HIGH);
        if ((CH2 <= MIDCH2 + Error ) && (CH2 >= MIDCH2 - Error)) {
          motor_1Go(CW, 0);
          motor_2Go(CW, 0);
          motor_3Go(CW, 0);
          motor_4Go(CW, 0);
        }

        else if ((CH2 >= MIDCH2 + Error)) {
          Serial.println("reward");
          motor_1Go(CCW, 255);
          motor_2Go(CCW, 255);
          motor_3Go(CCW, 255);
          motor_4Go(CCW, 255);

        }  else if ((CH2 <= MIDCH2 - Error)) {
          Serial.println("forward");
          motor_1Go(CW, 255);
          motor_2Go(CW, 255);
          motor_3Go(CW, 255);
          motor_4Go(CW, 255);
        }

        break;
      }
    case 3 : {
        CH2 =  pulseIn(ch2, HIGH);
        if ((CH2 <= MIDCH2 + Error ) && (CH2 >= MIDCH2 - Error)) {

          motor_2Go(CW, 0);
          motor_3Go(CW, 0);
        }

        else if ((CH2 >= MIDCH2 + Error)) {
          Serial.println("reward");
          motor_2Go(CCW, 255);
          motor_3Go(CCW, 255);

        }  else if ((CH2 <= MIDCH2 - Error)) {
          Serial.println("forward");
          motor_2Go(CW, 255);
          motor_3Go(CW, 255);

        }


        break;
      }
    case 4: {
        /*Debug*/
        CH1 =  pulseIn(ch1, HIGH);
        CH2 =  pulseIn(ch2, HIGH);
        CH3 =  pulseIn(ch3, HIGH);
        CH4 =  pulseIn(ch4, HIGH);
        CH5 =  pulseIn(ch5, HIGH);
        CH6 =  pulseIn(ch6, HIGH);
        CH7 =  pulseIn(ch7, HIGH);
        CH8 =  pulseIn(ch8, HIGH);
        CH9 =  pulseIn(ch9, HIGH);
        Serial.print(CH1);
        Serial.print("\t");
        Serial.print(CH2);
        Serial.print("\t");
        Serial.print(CH3);
        Serial.print("\t");
        Serial.print(CH4);
        Serial.print("\t");
        Serial.print(CH5);
        Serial.print("\t");
        Serial.print(CH6);
        Serial.print("\t");
        Serial.print(CH7);
        Serial.print("\t");
        Serial.println(CH8);

        break;
      }

    default :
      Serial.println("error");
      break;
  }






}
