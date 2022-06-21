#include "nivelC.h"


nivelControlador::nivelControlador(unsigned char sensor_pin, unsigned char bomba_pin){

    bomba_pinAttach = bomba_pin;
    sensPin = sensor_pin;

    pinMode(bomba_pinAttach, OUTPUT);
    pinMode(sensPin, INPUT_PULLUP);
}

unsigned char nivelControlador::getSensorPin(){
    return sensPin;
}

unsigned char nivelControlador::getBombaPin(){
    return bomba_pinAttach;
}

bool nivelControlador::verBombaStatus(){
    return bomba;
}

bool nivelControlador::atualizaBombaStatus(){
    bomba = digitalRead(sensPin);
    return bomba;
}


