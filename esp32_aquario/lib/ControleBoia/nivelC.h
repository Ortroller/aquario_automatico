#ifndef nivelC_h
#define nivelC_h

#include <Arduino.h>


class nivelControlador{
    private:
        bool bomba;
        unsigned char sensPin;
        unsigned char bomba_pinAttach;

    public:
        nivelControlador(unsigned char sensor_pin, unsigned char bomba_pin);

        bool atualizaBombaStatus();
        bool verBombaStatus();

        unsigned char getSensorPin();
        unsigned char getBombaPin();


};

void controladoraNivel(nivelControlador* controllInstance);

#endif