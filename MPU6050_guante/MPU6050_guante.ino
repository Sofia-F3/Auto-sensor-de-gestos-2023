#include <SoftwareSerial.h>
#define TXD 10
#define RXD 11

SoftwareSerial modu(TXD, RXD);

#include "I2Cdev.h"
#include "MPU6050.h"
#include "Wire.h"

MPU6050 sensor;

int ax, ay, az;

void setup() {
  modu.begin(9600);
  Serial.begin(9600);
  Wire.begin();
  sensor.initialize();

  if (sensor.testConnection()) Serial.println("Sensor iniciado correctamente");
  else Serial.println("Error al iniciar el sensor");
}

void loop() {
  // Leer las aceleraciones
  sensor.getAcceleration(&ax, &ay, &az);
  //Calcular los angulos de inclinacion:
  float accel_ang_x = atan(ax / sqrt(pow(ay, 2) + pow(az, 2))) * (180.0 / 3.14);
  float accel_ang_y = atan(ay / sqrt(pow(ax, 2) + pow(az, 2))) * (180.0 / 3.14);
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
