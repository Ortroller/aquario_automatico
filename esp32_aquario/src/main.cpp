#include <Arduino.h>
#include "ControleTemp/controleTemp.h"

// endereco do sensor 0x28
#define sensor_temp 13
#define test_led 4

TemperaturaChecker Controle(sensor_temp);

void setup() {

  Serial.begin(9600);
  pinMode(test_led, OUTPUT);
  Serial.println('\n');

  // temperatura.requestTemperatures();
}

void loop() {
  Serial.println(Controle.check_temperature());
  delay(500);
}