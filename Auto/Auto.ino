#include <SoftwareSerial.h>
#define TXD 10
#define RXD 11

#define mot1_DER 5
#define mot1_IZQ 4
#define mot2_DER 3
#define mot2_IZQ 2

SoftwareSerial modu(TXD, RXD);  //comunicación entre arduino y módulo

char accion = 'p';

void setup() {
  modu.begin(9600);
  Serial.begin(9600);

  pinMode(mot1_IZQ, OUTPUT);
  pinMode(mot1_DER, OUTPUT);
  pinMode(mot2_IZQ, OUTPUT);
  pinMode(mot2_DER, OUTPUT);
}

void loop() {
  if (modu.available()) {
    accion = modu.read();
    Serial.println(accion);
  }
  if (accion == 'f') {
    adelante();
  }
  if (accion == 'b') {
    atras();
  }
  if (accion == 'r') {
    derecha();
  }
  if (accion == 'l') {
    izquierda();
  }
  if (accion == 'p') {
    freno();
  }
}

void adelante() {
  digitalWrite(mot1_IZQ, LOW);
  digitalWrite(mot1_DER, HIGH);
  digitalWrite(mot2_IZQ, HIGH);
  digitalWrite(mot2_DER, LOW);
}

void atras() {
  digitalWrite(mot1_IZQ, HIGH);
  digitalWrite(mot1_DER, LOW);
  digitalWrite(mot2_IZQ, LOW);
  digitalWrite(mot2_DER, HIGH);
}

void izquierda() {
  digitalWrite(mot1_IZQ, HIGH);
  digitalWrite(mot1_DER, LOW);
  digitalWrite(mot2_IZQ, HIGH);
  digitalWrite(mot2_DER, LOW);
}

void derecha() {
  digitalWrite(mot1_IZQ, LOW);
  digitalWrite(mot1_DER, HIGH);
  digitalWrite(mot2_IZQ, LOW);
  digitalWrite(mot2_DER, HIGH);
}

void freno() {
  digitalWrite(mot1_IZQ, LOW);
  digitalWrite(mot1_DER, LOW);
  digitalWrite(mot2_IZQ, LOW);
  digitalWrite(mot2_DER, LOW);
}
