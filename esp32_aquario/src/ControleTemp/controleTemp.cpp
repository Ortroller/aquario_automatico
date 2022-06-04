#include "controleTemp.h"

/* 
    TODO: Implementar validacoes mais precisas para valores considerados validos para funcoes de setar limites de temperaturas (setLimitesTemperatura)
*/

TemperaturaChecker::TemperaturaChecker(byte SensorPin){
    sens = OneWire(SensorPin);
    temperatura = DallasTemperature(&sens);

    pinMode(resistenciaPin, OUTPUT);
    pinMode(coolerPin, OUTPUT);

    minBaseTemp = 24;
    maxBaseTemp = 28;
    offset_temperatura = 1;
    resistence = false;
    cooler = false;
}

float TemperaturaChecker::check_temperature(){

    temperatura.requestTemperaturesByIndex(0);
    float temp_C = temperatura.getTempCByIndex(0);


    if(cooler && temp_C <= maxBaseTemp - offset_temperatura){
        cooler = false;
    }else if(resistence && temp_C >= minBaseTemp + offset_temperatura){
        resistence = false;
    }else{
        if(temp_C < minBaseTemp){ // Se temperatura for menor que a minima definida
            cooler = false; // cooler desliga
            resistence = true; // aquecedor lig
        }else if( temp_C > maxBaseTemp){
            resistence = false;
            cooler = true;
        }
    }
    
    digitalWrite(coolerPin, !cooler);
    digitalWrite(resistenciaPin, !resistence);
    return temp_C;
}

bool TemperaturaChecker::setMinTemperatura(unsigned char minimo){
    /* 
        Configura as temperaturas limites baseado na temperatura minima
        retorna True se temperatura for positiva maior que zero, False se for negativa
    */

    if (minimo <= 0){
        return false;
    }
    
    minBaseTemp = minimo;
    maxBaseTemp = minimo + offset_TemperaturasGerais;
    offset_temperatura = 1;

    return true;
}

bool TemperaturaChecker::setMaxTemperatura(unsigned char maximo){
    /* 
        Configura as temperaturas limites baseado na temperatura maxima
        retorna True se temperatura for positiva maior que zero, False se for negativa
    */

    if (maximo <= 0){
        return false;
    }
    
    maxBaseTemp = maximo;
    minBaseTemp = maximo - offset_TemperaturasGerais;
    offset_temperatura = 1;

    return true;
}


bool TemperaturaChecker::setLimitesTemperatura(unsigned char minimo, unsigned char maximo, unsigned char offset = 1){

    if( (maximo == minimo) || (maximo < minimo) || (minimo > maximo) || (maximo <= 0) ||  (minimo <= 0)){
        return false;
    }

    if( offset >= (maximo - minimo)){
        return false;
    }

    maxBaseTemp = maximo;
    minBaseTemp = minimo;
    offset_temperatura = offset;
    return true;
}