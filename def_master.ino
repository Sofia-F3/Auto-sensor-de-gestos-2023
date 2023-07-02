#include <SoftwareSerial.h>
#define TXD 10
#define RXD 11

#define bot1 2
#define bot2 4
#define bot3 7
#define bot4 8

SoftwareSerial modu(TXD, RXD);

void setup() {
  pinMode(bot1, INPUT_PULLUP);
  pinMode(bot2, INPUT_PULLUP);
//  pinMode(bot3, INPUT_PULLUP);
  pinMode(bot4, INPUT_PULLUP);
  Serial.begin(9600);
  modu.begin(9600);
}

void loop() {
  if (digitalRead(bot1) == LOW){
    modu.write('r');
    Serial.println('r');
  } else if (digitalRead(bot2) == LOW){
    modu.write('l');
    Serial.println('l');
  } else if (digitalRead(bot3) == LOW){
    modu.write('b');
    Serial.println('b');
  } else if (digitalRead(bot4) == LOW){
    modu.write('f');
    Serial.println('f');
  } else {
    modu.write('q');
    Serial.println('q');
  }
}
