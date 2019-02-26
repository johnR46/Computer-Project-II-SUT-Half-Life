#include "configpin.h"
#include "configremote.h"
#include "motorDC.h"
#include "motorStepper.h"
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
  //Serial.begin(115200);

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

        }

        else if ((CH2 >= MIDCH2 + Error)) {
          //Serial.println("reward");
          //motor_1Go(CCW, val);
          motor_2Go(CCW, val);
          motor_3Go(CCW, val);

        }  else if ((CH2 <= MIDCH2 - Error)) {
          //Serial.println("forward");
          //   motor_1Go(CW, val);
          motor_2Go(CW, val);
          motor_3Go(CW, val);


        }
        else if ((CH1 >= MIDCH1 + Error)) {
          //Serial.println("Right");
          //  motor_1Go(CCW, val);
          motor_2Go(CCW, val);
          motor_3Go(CW, val);


        }  else if ((CH1 <= MIDCH1 - Error)) {
          //Serial.println("Left");
          //    motor_1Go(CW, val);
          motor_2Go(CW, val);
          motor_3Go(CCW, val);


        }

        break;
      }
    case 2 : {
        CH2 =  pulseIn(ch2, HIGH);
        if ((CH2 <= MIDCH2 + Error ) && (CH2 >= MIDCH2 - Error)) {
          motor_1Go(CW, 0);
          motor_2Go(CW, 0);
          motor_3Go(CW, 0);

        }

        else if ((CH2 >= MIDCH2 + Error)) {
          //Serial.println("reward");
          motor_1Go(CCW, 255);



        }  else if ((CH2 <= MIDCH2 - Error)) {
          //Serial.println("forward");
          motor_1Go(CW, 255);


        }

        break;
      }
    case 3 : {
        CH2 =  pulseIn(ch2, HIGH);
        if ((CH2 <= MIDCH2 + Error ) && (CH2 >= MIDCH2 - Error)) {
          motor_1Go(CW, 0);
          motor_2Go(CW, 0);
          motor_3Go(CW, 0);
        }

        else if ((CH2 >= MIDCH2 + Error)) {
          //Serial.println("reward");
          motor_1Go(CCW, 255);
          motor_2Go(CCW, 255);
          motor_3Go(CCW, 255);

        }  else if ((CH2 <= MIDCH2 - Error)) {
          //Serial.println("forward");
          motor_1Go(CW, 255);
          motor_2Go(CW, 255);
          motor_3Go(CW, 255);

        }
        break;
      }
    case 4: { // motion control up down by ch2 left right by ch1  speed by ch 3 keep by ch 8
        CH1 =  pulseIn(ch1, HIGH);
        CH2 =  pulseIn(ch2, HIGH);
        CH3 =  pulseIn(ch3, HIGH);
        CH8 =  pulseIn(ch8, HIGH);

        int  val = map(CH3, MAXCH3, MINCH3, 50, 255);

        if ((CH2 <= MIDCH2 + Error ) && (CH2 >= MIDCH2 - Error) && (CH1 <= MIDCH1 + Error ) && (CH1 >= MIDCH1 - Error)  ) {
          //Serial.println("IDLE ARM ");
        }

        else if ((CH2 >= MIDCH2 + Error)) {
          //Serial.println("reward");
          motorStep_1Go(20, CW, val);
          motorStep_2Go(20, CCW, val);
          motorStep_3Go(20, CCW, val);

        }  else if ((CH2 <= MIDCH2 - Error)) {
          //  Serial.println("forward");
          motorStep_1Go(20, CCW, val);
          motorStep_2Go(20, CW, val);
          motorStep_3Go(20, CW, val); 
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
