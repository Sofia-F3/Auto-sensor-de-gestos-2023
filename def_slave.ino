#include <SoftwareSerial.h>
#define TXD 10
#define RXD 11

SoftwareSerial modu(TXD, RXD);

#define der1 6
#define izq1 5
#define der2 3
#define izq2 9

void setup() {
  modu.begin(9600);
  Serial.begin(9600);

  pinMode(der1, OUTPUT);
  pinMode(izq1, OUTPUT);
  pinMode(der2, OUTPUT);
  pinMode(izq2, OUTPUT);
}
char accion;
void loop() {
    if (modu.available()){
    accion = modu.read();
    Serial.println(accion);
  }
  if (accion == 'q'){
    freno();
  }
  if (accion == 'r'){
    derecha();
  }
  if (accion == 'l'){
    izquierda();
  }
  if (accion == 'b'){
    atras();
  }
  if (accion == 'f'){
    adelante();
  }
}

void adelante(){
  digitalWrite(izq1, LOW);
  digitalWrite(der1, HIGH);
  digitalWrite(izq2, LOW);
  digitalWrite(der2, HIGH);
}

void atras(){
  digitalWrite(izq1, HIGH);
  digitalWrite(der1, LOW);
  digitalWrite(izq2, HIGH);
  digitalWrite(der2, LOW);
}

void izquierda(){
  digitalWrite(izq1, LOW);
  digitalWrite(der1, HIGH);
  digitalWrite(izq2, HIGH);
  digitalWrite(der2, LOW);
}

void derecha(){
  digitalWrite(izq1, HIGH);
  digitalWrite(der1, LOW);
  digitalWrite(izq2, LOW);
  digitalWrite(der2, HIGH);
}

void freno(){
  digitalWrite(izq1, LOW);
  digitalWrite(der1, LOW);
  digitalWrite(izq2, LOW);
  digitalWrite(der2, LOW);
}
