// Inclui as bibliotecas
#include "controleLed.h"

// TODO: Verificar o pq está dando segmentation fault ao juntar os dois códigos
// DONE: RTC c/ controle de iluminação funcionando p/ uma faixa de horário

#define hrOn 8
#define minOn 30
#define hrOff 18
#define minOff 45
// #define hrOn 10
// #define minOn 0
// #define hrOff 10
// #define minOff 5
#define rele 26

// char daysOfTheWeek[7][12] = {"Domingo", "Segunda", "Terca", "Quarta", "Quinta", "Sexta", "Sabado"}; // Dias da semana

ControleLED ctlLed(hrOn, minOn, hrOff, minOff, rele);

void setup()
{
  Serial.begin(115200);
  pinMode(rele, OUTPUT);
  digitalWrite(rele,LOW);
  ctlLed.setupRTC();
}

void loop()
{
  ctlLed.checkLed();
  delay(500);
}