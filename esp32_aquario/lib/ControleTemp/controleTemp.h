#ifndef controleTemp_h
#define controleTemp_h

/* ========== Libs ========== */
#include <Arduino.h>

/* ========== PINOS ========== */
#define resistenciaPin 32
#define coolerPin 33

/* ========== Valores ========== */
#define offset_TemperaturasGerais 4

// Parâmetros do termistor
#define R1 1500.0   // voltage divider resistor value
#define Beta 4400.0  // Beta value
#define To 298.15    // Temperature in Kelvin for 25 degree Celsius
#define Ro 10000.0   // Resistance of Thermistor at 25 degree Celsius
#define adcMax 4095.0   // ADC resolution 10-bit (0-1023)
#define Vs 3.3          // supply voltage


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
