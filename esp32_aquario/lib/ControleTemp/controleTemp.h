#ifndef controleTemp_h
#define controleTemp_h

/* ========== Libs ========== */
#include "OneWire.h"
#include "DallasTemperature.h"
#include <Arduino.h>

/* ========== PINOS ========== */
#define resistenciaPin 27
#define coolerPin 14

/* ========== Valores ========== */
#define offset_TemperaturasGerais 4


class TemperaturaChecker{
private:
    unsigned char minBaseTemp;
    unsigned char maxBaseTemp;
    unsigned char offset_temperatura;
    OneWire sens;
    DallasTemperature temperatura;

    bool resistence;
    bool cooler;
public:
    TemperaturaChecker(byte SensorPin);
    float check_temperature();
    bool setLimitesTemperatura(unsigned char minimo, unsigned char maximo, unsigned char offset = 1);
    bool setMaxTemperatura(unsigned char maximo);
    bool setMinTemperatura(unsigned char minimo); 

};


#endif 
