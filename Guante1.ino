#include <Simple_Wire.h>

#include <SoftwareSerial.h>
#define TXD 10
#define RXD 11

SoftwareSerial modu(TXD, RXD);

#include "DMP_Image.h"
#include "MPU_ReadMacros.h"
#include "MPU_WriteMacros.h"
#include "Simple_MPU6050.h"

#include <I2Cdev.h>

#include "Simple_MPU6050.h"

#define MPU6050_ADDRESS_AD0_LOW     0x68 
#define MPU6050_DEFAULT_ADDRESS     MPU6050_ADDRESS_AD0_LOW

Simple_MPU6050 mpu;

//                  Eje X    Eje Y    Eje Z     Rot X   Rot Y     Rot Z 
#define OFFSETS  -4662,     220,     732,     -48,    -141,     -17   //Acá deberá poner sus OFFSETS.

#define spamtimer(t) for (static uint32_t SpamTimer; (uint32_t)(millis() - SpamTimer) >= (t); SpamTimer = millis()) 

#define printfloatx(Name,Variable,Spaces,Precision,EndTxt) print(Name); {char S[(Spaces + Precision + 3)];Serial.print(F(" ")); Serial.print(dtostrf((float)Variable,Spaces,Precision ,S));}Serial.print(EndTxt);

char accion;

void PrintAllValues(int16_t *gyro, int16_t *accel, int32_t *quat, uint16_t SpamDelay = 100) { //función para imprimir los valores del giroscopio.
  Quaternion q;
  VectorFloat gravity;
  float ypr[3] = { 0, 0, 0 };
  float xyz[3] = { 0, 0, 0 };
  spamtimer(SpamDelay) {
    mpu.GetQuaternion(&q, quat);
    mpu.GetGravity(&gravity, &q);
    mpu.GetYawPitchRoll(ypr, &q, &gravity);
    mpu.ConvertToDegrees(ypr, xyz);

   /*
  Esto hace los cálculos automaticamente y convierte en grados a los valores
  Yaw = xyz[0] Rotación en Z
  Pitch = xyz[1] Rotación en Y
  Roll = xyz[2] Rotación en X
   */
   if (xyz[1] < -30 && xyz[2] < 30 && xyz[2] > -30) {
      modu.write('b');
      Serial.println('b'); //back, atrás
   } else
   if (xyz[1] > 30 && xyz[2] < 30 && xyz[2] > -30) {
     modu.write('f');
     Serial.println('f'); //front, adelante
   } else
   if (xyz[1] < 30 && xyz[1] > -30 && xyz[2] < 30 && xyz[2] > -30){
      modu.write("p");
      Serial.println('p'); //parar, frenado
   } else
   if (xyz[2] < -30 && xyz[1] < 30 && xyz[1] > -30){
      modu.write('r');
      Serial.println('r'); //right, derecha
   } else
   if (xyz[2] > 30 && xyz[1] < 30 && xyz[1] > -30){
      modu.write('l');
      Serial.println('l'); //left, izquierda
   }
   /*
    modu.write(); hace que el Módulo Bluetooth envíe información.
   */
  }
}

void print_Values (int16_t *gyro, int16_t *accel, int32_t *quat) {
  uint8_t Spam_Delay = 100; 

  PrintAllValues(gyro, accel, quat, Spam_Delay);
 
}

void setup() {
  modu.begin(9600);
  Serial.begin(9600);
  while (!Serial);
  Serial.println(F("Start:"));
  mpu.Set_DMP_Output_Rate_Hz(100);
  
#ifdef OFFSETS
  Serial.println(F("Using Offsets"));
  mpu.SetAddress(MPU6050_DEFAULT_ADDRESS);
  mpu.load_DMP_Image(OFFSETS); // Does it all for you

#else
  Serial.println(F(" Como no hay offsets definidos vamos a crear unos,\n"
                   " Posiciona el MPU en un lugar plano para una calibración apropiada\n"
                   " Escribí los nuevos offsets en el #define OFFSETS... \n\n"
                   " \t\t\t[Press Any Key]"));
  while (Serial.available() && Serial.read());
  while (!Serial.available());
  while (Serial.available() && Serial.read());
  mpu.SetAddress(MPU6050_DEFAULT_ADDRESS);
  mpu.CalibrateMPU();
  mpu.load_DMP_Image();
#endif
  mpu.on_FIFO(print_Values); //Llama para que se impriman valores
}

void loop() {
  mpu.dmp_read_fifo(false);
}
