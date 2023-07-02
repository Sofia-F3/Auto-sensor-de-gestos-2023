#define der1 6
#define izq1 5
#define der2 9
#define izq2 3


void setup() {
  pinMode(der1, OUTPUT);
  pinMode(izq1, OUTPUT);
  pinMode(der2, OUTPUT);
  pinMode(izq2, OUTPUT);
}

void loop() {
  adelante();
  delay(2000);
  atras();
  delay(2000);
  izquierda();
  delay(2000);
  derecha();
  delay(2000);
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
