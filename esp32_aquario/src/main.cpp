// Inclui as bibliotecas
#include "controleLed.h"
#include "controleTemp.h"
#include "nivelC.h"

/* ---------- Configuracao das horas --------------- */
#define hrOn 8
#define minOn 30
#define hrOff 18
#define minOff 45

/* ---------- Pinos --------------- */
#define releLed 26
#define sensor_temp 12
#define bomba 4 // Pino de saida de controle atuador
#define sensor_boia 5

ControleLED ctlLed(hrOn, minOn, hrOff, minOff, releLed);

TemperaturaChecker Controle(sensor_temp);
nivelControlador aBoia(sensor_boia, bomba);

void controladoraNivel(){
  digitalWrite(aBoia.getBombaPin(), !aBoia.atualizaBombaStatus());
  // Serial.println(aBoia.verBombaStatus());
}

void setup()
{
  Serial.begin(9600);
  Serial.println('\n');
  attachInterrupt( digitalPinToInterrupt(aBoia.getSensorPin()), controladoraNivel, CHANGE);

  pinMode(releLed, OUTPUT);
  digitalWrite(releLed, LOW);
  ctlLed.setupRTC();
}

void loop()
{
  Serial.println(Controle.check_temperature());
  // ctlLed.checkLed();
  Serial.println();
  delay(500);
}