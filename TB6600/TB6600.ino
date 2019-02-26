int PUL = 34; //define Pulse pin
int DIR = 36; //define Direction pin
int ENA = 38; //define Enable Pin

#define powerM1 40

int PUL2 = 42 ; //define Pulse pin
int DIR2 = 44; //define Direction pin
int ENA2 = 46; //define Enable Pin

#define powerM2 48


#define CW  1
#define CCW  0
void setup() {
  pinMode (PUL, OUTPUT);
  pinMode (DIR, OUTPUT);
  
  pinMode (ENA, OUTPUT);
  pinMode (powerM1, OUTPUT);
  digitalWrite(powerM1, HIGH);
  pinMode (PUL2, OUTPUT);
  pinMode (DIR2, OUTPUT);
  pinMode (ENA2, OUTPUT);
  pinMode (powerM2, OUTPUT);
  digitalWrite(powerM2, HIGH);



}


void motor_Go(int cycle, byte spins, int speeds) {
  int i = 0;
  int cycles = map(cycle, 0, 360, 0, 6400);
  while (i != cycles) {
    digitalWrite(DIR, spins);
    digitalWrite(ENA, HIGH);
    digitalWrite(PUL, HIGH);
    digitalWrite(DIR2, spins);
    digitalWrite(ENA2, HIGH);
    digitalWrite(PUL2, HIGH);
    delayMicroseconds(speeds);
    digitalWrite(PUL, LOW);
    digitalWrite(PUL2, LOW);
    delayMicroseconds(speeds);
    i++;
  }

}



void loop() {



  

  motor_Go(360, CCW,256);



}
