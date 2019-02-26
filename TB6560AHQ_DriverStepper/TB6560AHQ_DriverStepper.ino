int Distance = 0; // Record the number of steps we've taken
#define CW  1
#define CCW  0
int temp = 0;
int dir = 999;
int x = 0;
int pin_bus = 10;
byte bit, port;
volatile uint8_t *rPIN;
int i = 0;
void setup() {
  pinMode(9, OUTPUT);
  Serial.begin(115200);
  pinMode(10, OUTPUT);
  digitalWrite(9, LOW);
  digitalWrite(10, LOW);
  bit = digitalPinToBitMask(pin_bus);
  port = digitalPinToPort(pin_bus);
  rPIN = portOutputRegister(port);

}

void fSetpper(int cycle, byte cw, int delays) {
  int del = map(cycle, 1, 360, 10, 3200);

  if (cw == 0) {
    digitalWrite(9, CW);
    while (i != del) {
      *rPIN |= bit; // Set to HIGH
      delayMicroseconds(delays);
      *rPIN &= ~bit; // Set to LOW
      delayMicroseconds(delays);
      i++;
    }
 
    Serial.println("OK !! ");
  }

  if (cw == 1) {
    digitalWrite(9, CCW);
    while (i != del) {
      *rPIN |= bit; // Set to HIGH
      delayMicroseconds(delays);
      *rPIN &= ~bit; // Set to LOW
      delayMicroseconds(delays);
      i++;
    }

    Serial.println("OK !! ");
  }
}
void loop() {

  if (Serial.available() > 0 ) {
    x =  Serial.parseInt();
    temp = x - temp;
    Serial.print(" Go ==> "); Serial.print(x);
    Serial.print(" Temp ==> "); Serial.println(temp);
    if (x >= 0)fSetpper(abs(x), CW, 35);
    if (x <= 0)fSetpper(abs(x), CCW, 35);
  }
}
