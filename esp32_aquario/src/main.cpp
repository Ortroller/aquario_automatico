// Inclui as bibliotecas
#include "controleLed.h"
#include "controleTemp.h"
#include "nivelC.h"

#define hrOn 8
#define minOn 30
#define hrOff 18
#define minOff 45
#define releLed 26
#define sensor_temp 25
#define bomba 33
#define sensor_boia 32

ControleLED ctlLed(hrOn, minOn, hrOff, minOff, releLed);

TemperaturaChecker Controle(sensor_temp);
nivelControlador aBoia(sensor_boia, bomba);

void controladoraNivel()
{

  digitalWrite(aBoia.getBombaPin(), !aBoia.atualizaBombaStatus());
  // Serial.println(aBoia.verBombaStatus());
}

void setup()
{
  Serial.begin(115200);
  Serial.println('\n');
  attachInterrupt( digitalPinToInterrupt(aBoia.getSensorPin()), controladoraNivel, CHANGE);

  pinMode(releLed, OUTPUT);
  digitalWrite(releLed, LOW);
  ctlLed.setupRTC();
}

void loop()
{
  Serial.println(Controle.check_temperature());
  delay(500);
  ctlLed.checkLed();
  delay(500);
}