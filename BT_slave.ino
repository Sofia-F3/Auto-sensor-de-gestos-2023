#include <SoftwareSerial.h>
#define TXD 10
#define RXD 11

SoftwareSerial modu(TXD, RXD);

void setup() {
  modu.begin(9600);
  Serial.begin(9600);
}
char accion;
void loop() {
  /*if (modu.available()){
    Serial.write(modu.read()); //lee si hay info en modu y la manda al arduino
  }
  if (Serial.available()){
    modu.write(Serial.read()); //lee si hay info en el arduino y se la manda a modu
  }*/

  //IMPORTANTE: PARA USAR EL SIGUIENTE CÓDIGO SERIAL Y MODU DEBEN ESTAR A 9600 :
    if (modu.available()){
    accion = modu.read();
    Serial.println(accion);
  }
}
