#include <SoftwareSerial.h>
#define TXD 10
#define RXD 11

SoftwareSerial modu(TXD, RXD);

// Librerias I2C para controlar el mpu6050
// la libreria MPU6050.h necesita I2Cdev.h, I2Cdev.h necesita Wire.h
#include "I2Cdev.h"
#include "MPU6050.h"
#include "Wire.h"

// La dirección del MPU6050 puede ser 0x68 o 0x69, dependiendo
// del estado de AD0. Si no se especifica, 0x68 estará implicito
MPU6050 sensor;

// Valores RAW (sin procesar) del acelerometro  en los ejes x,y,z
int ax, ay, az;

void setup() {
  modu.begin(9600);
  Serial.begin(9600);    //Iniciando puerto serial
  Wire.begin();           //Iniciando I2C
  sensor.initialize();    //Iniciando el sensor

  if (sensor.testConnection()) Serial.println("Sensor iniciado correctamente");
  else Serial.println("Error al iniciar el sensor");
}

void loop() {
  // Leer las aceleraciones
  sensor.getAcceleration(&ax, &ay, &az);
  //Calcular los angulos de inclinacion:
  float accel_ang_x = atan(ax / sqrt(pow(ay, 2) + pow(az, 2))) * (180.0 / 3.14);
  float accel_ang_y = atan(ay / sqrt(pow(ax, 2) + pow(az, 2))) * (180.0 / 3.14);
  //Mostrar los angulos separadas por un [tab]
  /*Serial.print("Inclinacion en X: ");
    Serial.print(accel_ang_x);
    Serial.print("tInclinacion en Y:");
    Serial.println(accel_ang_y);*/
  delay(10);

  if (accel_ang_y < -40) {
    modu.write('r');
    Serial.println('r');
  }
  if (accel_ang_y > 40) {
    modu.write('l');
    Serial.println('l');
  }
  if (accel_ang_x < -40) {
    modu.write('b');
    Serial.println('b');
  }
  if (accel_ang_x > 40) {
    modu.write('f');
    Serial.println('f');
  }
  if (accel_ang_x < 40 && accel_ang_x > -40 && accel_ang_y < 40 && accel_ang_y > -40 ) {
    modu.write("p");
    Serial.println('p');
  }
}
