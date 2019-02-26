// TB6600
#define CW 1
#define CCW 0
/*
void motorStep_1Go(int cycle, byte spins, int speeds) {
  int i = 0;
  int cycles = map(cycle, 0, 360, 0, 6400);
  while (i != cycles) {
    digitalWrite(DIRM1, spins);
    digitalWrite(ENAM1, HIGH);
    digitalWrite(PULM1, HIGH);
    delayMicroseconds(speeds);
    digitalWrite(PULM1, LOW);
    delayMicroseconds(speeds);
    i++;
  }
}

void motorStep_2Go(int cycle, byte spins, int speeds) {
  int i = 0;
  int cycles = map(cycle, 0, 360, 0, 6400);
  while (i != cycles) {
    digitalWrite(DIRM2, spins);
    digitalWrite(ENAM2, HIGH);
    digitalWrite(PULM2, HIGH);
    delayMicroseconds(speeds);
    digitalWrite(PULM2, LOW);
    delayMicroseconds(speeds);
    i++;
  }
}


void motorStep_3Go(int cycle, byte spins, int speeds) {
  int i = 0;
  int cycles = map(cycle, 0, 360, 0, 6400);
  while (i != cycles) {
    digitalWrite(DIRM3, spins);
    digitalWrite(ENAM3, HIGH);
    digitalWrite(PULM3, HIGH);
    delayMicroseconds(speeds);
    digitalWrite(PULM3, LOW);
    delayMicroseconds(speeds);
    i++;
  }
}
*/
void motorStep_4Go(int cycle, byte spins, int speeds) {
  int i = 0;
  int cycles = map(cycle, 0, 360, 0, 6400);
  while (i != cycles) {
    digitalWrite(DIRM4, spins);
    digitalWrite(ENAM4, HIGH);
    digitalWrite(PULM4, HIGH);
    delayMicroseconds(speeds);
    digitalWrite(PULM4, LOW);
    delayMicroseconds(speeds);
    i++;
  }
}
