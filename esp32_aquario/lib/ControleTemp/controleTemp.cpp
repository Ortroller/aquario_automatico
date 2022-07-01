#include "controleTemp.h"

/* 
    TODO: Implementar validacoes mais precisas para valores considerados validos para funcoes de setar limites de temperaturas (setLimitesTemperatura)
*/

TemperaturaChecker::TemperaturaChecker(unsigned char SensorPin){
    pinMode(resistenciaPin, OUTPUT);
    pinMode(coolerPin, OUTPUT);

    pinMode(SensorPin, INPUT); // Pino do NTC
    this->SensorPin = SensorPin;
    minBaseTemp = 24;
    maxBaseTemp = 28;
    offset_temperatura = 1;
    resistence = false;
    cooler = false;
}

float TemperaturaChecker::check_temperature(){  
    /* 
        Retorna a temperatura obtida no momento da verificacao e controla os atuadores (coolerPin, resistenciaPin)
        caso os parametros sejam satisfeitos
    */
    
    float Vout = analogRead(SensorPin) * (Vs/adcMax);
    float Rt = R1 * (Vout+0.1) / (Vs - (Vout+0.1));

    Serial.println(analogRead(SensorPin));
    Serial.println(Vout+0.1);
    Serial.println(Rt);
    Rt += 2000;

    float T = 1/(1/To + log(Rt/Ro)/Beta);    // Temperature in Kelvin
    float TX = T - 273.15;                   // Celsius
 

    if(cooler && TX <= maxBaseTemp - offset_temperatura){
        cooler = false;
    }else if(resistence && TX >= minBaseTemp + offset_temperatura){
        resistence = false;
    }else{
        if(TX < minBaseTemp){ // Se temperatura for menor que a minima definida
            cooler = false; // cooler desliga
            resistence = true; // aquecedor lig
        }else if( TX > maxBaseTemp){
            resistence = false;
            cooler = true;
        }
    }
    
    digitalWrite(coolerPin, !cooler);
    digitalWrite(resistenciaPin, !resistence);

    return TX;
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


bool TemperaturaChecker::setLimitesTemperatura(unsigned char minimo, unsigned char maximo, unsigned char offset){

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