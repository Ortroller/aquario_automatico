#ifndef CONTROLELED_H
#define CONTROLELED_H

#include <Arduino.h>
#include <Wire.h>
#include "RTClib.h"

class ControleLED {
    private:
        unsigned char hrTurnOn;
        unsigned char minTurnOn;
        unsigned char hrTurnOff;
        unsigned char minTurnOff;
        unsigned char releLed;
    public:
        // ControleLED(unsigned char hOn, unsigned char minOn, unsigned char hOff, unsigned char minOff) : hrTurnOn(hOn), minTurnOn(minOn), hrTurnOff(hOff), minTurnOff(minOff) {
        //     releLed = rele; //pin 26
        // }
        ControleLED(unsigned char hOn, unsigned char minOn, unsigned char hOff, unsigned char minOff, unsigned char rele);


        bool checkLed();
        void setupRTC();
};

#endif // CONTROLELED_H