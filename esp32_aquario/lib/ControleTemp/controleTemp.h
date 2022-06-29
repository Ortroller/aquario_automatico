#ifndef controleTemp_h
#define controleTemp_h

/* ========== Libs ========== */
#include <Arduino.h>

/* ========== PINOS ========== */
#define resistenciaPin 34
#define coolerPin 35

/* ========== Valores ========== */
#define offset_TemperaturasGerais 4

// Parâmetros do termistor
#define RT0 10000   // Ω
#define B 3600      // K
#define VCC 5    //Supply voltage
#define R 1500  //R=10KΩ
#define  T0 (25 + 273.15)


class TemperaturaChecker{
private:
    unsigned char minBaseTemp;
    unsigned char maxBaseTemp;
    unsigned char offset_temperatura;
    unsigned char SensorPin;
    bool resistence;
    bool cooler;
public:
    TemperaturaChecker(unsigned char SensorPin);
    float check_temperature();
    bool setLimitesTemperatura(unsigned char minimo, unsigned char maximo, unsigned char offset = 1);
    bool setMaxTemperatura(unsigned char maximo);
    bool setMinTemperatura(unsigned char minimo); 

};


#endif 
