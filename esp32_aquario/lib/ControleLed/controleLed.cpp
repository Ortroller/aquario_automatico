#include "controleLed.h"

RTC_DS1307 rtc;

ControleLED::ControleLED(unsigned char hOn, unsigned char minOn, unsigned char hOff, unsigned char minOff, unsigned char rele) {
    hrTurnOn = hOn;
    minTurnOn = minOn;
    hrTurnOff = hOff;
    minTurnOff = minOff;
    releLed = rele;
}

void ControleLED::setupRTC(){
    Wire.begin();

    if (!rtc.begin()){  // Se o RTC nao for inicializado, faz
        Serial.println("RTC NAO INICIALIZADO"); // Imprime o texto
        while (1)
        ; // Trava o programa
    }
    // rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
    // delay(100); // 100 Milissegundos
}

bool ControleLED::checkLed(){
    DateTime now = rtc.now(); // pega data e hora atual
    Serial.print(now.hour(), DEC);
    Serial.print(':');
    Serial.print(now.minute(), DEC);
    Serial.println("\n");
    
    if(now.hour() == hrTurnOn && now.minute() == minTurnOn) {
        digitalWrite(releLed,HIGH);
        Serial.println("Luz ON");
        return true;
    } else if (now.hour() == hrTurnOff && now.minute() == minTurnOff) {
        digitalWrite(releLed,LOW);
        Serial.println("Luz OFF");
        return false;
    } else {
        digitalWrite(releLed,LOW);
        Serial.println("Luz OFF");
        return false;
    }
}