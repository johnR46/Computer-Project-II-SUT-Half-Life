#include "configpin.h"
#include "configremote.h"
#include "motorDC.h"
#include "motorStepper.h"
#include"Realy.h"
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
  Realy_1Off();
  Realy_2Off();
  Realy_3Off();
  Realy_4Off();
  motor_1Go(CCW, 0);
  motor_2Go(CCW, 0);
  motor_3Go(CCW, 0);
  motor_4Go(CCW, 0);
  motor_5Go(CCW, 0);
  motor_6Go(CCW, 0);
  motor_7Go(CCW, 0);
  motor_8Go(CCW, 0);
  motor_9Go(CCW, 0);


}
byte command = 0;
void loop() {

  CH5 =  pulseIn(ch5, HIGH);
  CH6 =  pulseIn(ch6, HIGH);


  if (CH5 <= MID + Error &&  CH6 <= MID + Error ) {
    command = 1;
    //Serial.println("mode 1");
  } else if (CH5 <= MID + Error &&  (CH6 >= MID + Error  )) {
    command  = 2;
    //Serial.println("mode 2");
  }
  else if (CH5 >= MID + Error &&  (CH6 <= MID + Error  )) {
    command  = 3;
    //Serial.println("mode 3");
  }

  else if (CH5 >= MID + Error &&  (CH6 >= MID + Error  )) {
    command  = 4;
    //Serial.println("mode 4");
  }


  switch (command) {
    case 1  : {
        CH1 =  pulseIn(ch1, HIGH);
        CH2 =  pulseIn(ch2, HIGH);
        CH3 =  pulseIn(ch3, HIGH);
        int  val = map(CH3, MAXCH3, MINCH3, 0, 255);
        //Serial.println(val);
        if ((CH2 <= MIDCH2 + Error ) && (CH2 >= MIDCH2 - Error) && (CH1 <= MIDCH1 + Error ) && (CH1 >= MIDCH1 - Error)  ) {
          //Serial.println("IDLE Car ");
          motor_1Go(CCW, 0);
          motor_2Go(CCW, 0);
          motor_3Go(CCW, 0);
          motor_4Go(CCW, 0);
          motor_5Go(CCW, 0);
          motor_6Go(CCW, 0);
          motor_7Go(CCW, 0);
          motor_8Go(CCW, 0);
          motor_9Go(CCW, 0);
        }

        else if ((CH2 >= MIDCH2 + Error)) {
          //Serial.println("reward");
          motor_1Go(CW, val);
          motor_2Go(CW, val);

        }  else if ((CH2 <= MIDCH2 - Error)) {
          //Serial.println("forward");
          //   motor_1Go(CW, val);
          motor_1Go(CCW, val);
          motor_2Go(CCW, val);

        }
        else if ((CH1 >= MIDCH1 + Error)) {
          //Serial.println("Right");
          motor_1Go(CCW, val);
          motor_2Go(CW, val);


        }  else if ((CH1 <= MIDCH1 - Error)) {
          //Serial.println("Left");
          //    motor_1Go(CW, val);
          motor_1Go(CW, val);
          motor_2Go(CCW, val);


        }

        break;
      }
    case 2 : {
        CH2 =  pulseIn(ch2, HIGH);
        if ((CH2 <= MIDCH2 + Error ) && (CH2 >= MIDCH2 - Error)) {
          motor_1Go(CCW, 0);
          motor_2Go(CCW, 0);
          motor_3Go(CCW, 0);
          motor_4Go(CCW, 0);
          motor_5Go(CCW, 0);
          motor_6Go(CCW, 0);
          motor_7Go(CCW, 0);
          motor_8Go(CCW, 0);
          motor_9Go(CCW, 0);

        }

        else if ((CH2 >= MIDCH2 + Error)) {
          Serial.println("reward");
          motor_3Go(CW, 255);


        }  else if ((CH2 <= MIDCH2 - Error)) {
          Serial.println("forward");
          motor_3Go(CCW, 255);


        }

        break;
      }
    case 3 : {
        CH2 =  pulseIn(ch2, HIGH);
        if ((CH2 <= MIDCH2 + Error ) && (CH2 >= MIDCH2 - Error)) {
          motor_1Go(CCW, 0);
          motor_2Go(CCW, 0);
          motor_3Go(CCW, 0);
          motor_4Go(CCW, 0);
          motor_5Go(CCW, 0);
          motor_6Go(CCW, 0);
          motor_7Go(CCW, 0);
          motor_8Go(CCW, 0);
          motor_9Go(CCW, 0);
        }

        else if ((CH2 >= MIDCH2 + Error)) {
          //Serial.println("reward");

          motor_4Go(CCW, 255);

        }  else if ((CH2 <= MIDCH2 - Error)) {
          //Serial.println("forward");

          motor_4Go(CW, 255);

        }
        break;
      }
    case 4: { // motion control up down by ch2 left right by ch1  speed by ch 3 keep by ch 8
        CH1 =  pulseIn(ch1, HIGH);
        CH2 =  pulseIn(ch2, HIGH);
        CH3 =  pulseIn(ch3, HIGH);
        CH8 =  pulseIn(ch8, HIGH);

        int  val = map(CH3, MAXCH3, MINCH3, 30, 255);

        if ((CH2 <= MIDCH2 + Error ) && (CH2 >= MIDCH2 - Error) && (CH1 <= MIDCH1 + Error ) && (CH1 >= MIDCH1 - Error)  ) {
          //Serial.println("IDLE ARM ");
          motor_4Go(CCW, 0);
          motor_5Go(CCW, 0);
          motor_6Go(CCW, 0);
          motor_7Go(CCW, 0);
        }

        else if ((CH2 >= MIDCH2 + Error)) {

          //Serial.println("reward");
          motor_4Go(CW, 255);
          motor_5Go(CW, 255);
          motor_6Go(CW, 255);
          motor_7Go(CW, 255);


        }  else if ((CH2 <= MIDCH2 - Error)) {
          //  Serial.println("forward");
          motor_4Go(CCW, 255);
          motor_5Go(CCW, 255);
          motor_6Go(CCW, 255);
          motor_7Go(CCW, 255);

        }
        else if ((CH1 >= MIDCH1 + Error)) {
          //Serial.println("Right");



        }  else if ((CH1 <= MIDCH1 - Error)) {
          //Serial.println("Left");


        }

        break;
      }

    default : {
        ////Serial.println("error");
        break;
      }






  }

}
