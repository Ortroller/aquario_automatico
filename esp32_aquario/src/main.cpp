#include <Arduino.h>
#include "OneWire/OneWire.h"
#include "OneWire/DallasTemperature.h"

// endereco do sensor 0x28
#define sensor_temp 15
#define test_led 4

OneWire sens(sensor_temp);
DallasTemperature temperatura(&sens);

bool val = 0;

void setup() {

  Serial.begin(9600);
  pinMode(test_led, OUTPUT);
  Serial.println('\n');

  // temperatura.requestTemperatures();
}

void loop() {
  val = !val;
  digitalWrite(test_led, val);
  // Serial.println(val);
  temperatura.requestTemperaturesByIndex(0);
  Serial.println(temperatura.getTempCByIndex(0));
  delay(1000);
}