#define mot1_DER 5
#define mot1_IZQ 4
#define mot2_DER 3
#define mot2_IZQ 2

void setup() {
  pinMode(mot1_DER, OUTPUT);
  pinMode(mot1_IZQ, OUTPUT);
  
  pinMode(mot1_DER, OUTPUT);
  pinMode(mot2_IZQ, OUTPUT);
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
  digitalWrite(mot1_IZQ, LOW);
  digitalWrite(mot1_DER, HIGH);
  digitalWrite(mot2_IZQ, HIGH);
  digitalWrite(mot2_DER, LOW);
}

void atras(){
  digitalWrite(mot1_IZQ, HIGH);
  digitalWrite(mot1_DER, LOW);
  digitalWrite(mot2_IZQ, LOW);
  digitalWrite(mot2_DER, HIGH);
}

void derecha(){
  digitalWrite(mot1_IZQ, HIGH);
  digitalWrite(mot1_DER, LOW);
  digitalWrite(mot2_IZQ, HIGH);
  digitalWrite(mot2_DER, LOW);
}

void izquierda(){
  digitalWrite(mot1_IZQ, LOW);
  digitalWrite(mot1_DER, HIGH);
  digitalWrite(mot2_IZQ, LOW);
  digitalWrite(mot2_DER, HIGH);
}

void freno(){
  digitalWrite(mot1_IZQ, LOW);
  digitalWrite(mot1_DER, LOW);
  digitalWrite(mot2_IZQ, LOW);
  digitalWrite(mot2_DER, LOW);
}
