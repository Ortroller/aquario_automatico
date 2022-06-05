#include <Arduino.h>
#include "ControleTemp/controleTemp.h"
#include "ControleBoia/nivelC.h"

// endereco do sensor 0x28
#define sensor_temp 12
#define bomba 13
#define sensor_boia 2

TemperaturaChecker Controle(sensor_temp);
nivelControlador aBoia(sensor_boia, bomba);


void controladoraNivel(){
    
    digitalWrite(aBoia.getBombaPin(), !aBoia.atualizaBombaStatus()); 
    // Serial.println(aBoia.verBombaStatus());

}


void setup() {

  Serial.begin(9600);
  Serial.println('\n');
  attachInterrupt( digitalPinToInterrupt(aBoia.getSensorPin()), controladoraNivel, CHANGE);
  // temperatura.requestTemperatures();
}

void loop() {
  Serial.println(Controle.check_temperature());
  delay(500);
}