#include "Wire.h"

void ConexionPeticionEsclavo(){
    Wire.requestFrom(0x01,1);
    while (Wire.available())
    {
        CODE = Wire.read();
        Serial.println(CODE);
    }
    if (CODE == 1)
    {
        ESTADO = JUEGO;
    }   
}

void ConexionPeticionEsclavo2()
{
    Wire.requestFrom(0x01, 1);
    while (Wire.available())
    {
        CODE = Wire.read();
    }
    if (CODE == 1)
    {
        puntos = cantidad + puntos;
        subpuntos++;
    }else if (CODE == 2){
        vidas--;
    }
}

void ConexionResiceEsclavo(byte pin){
    Wire.beginTransmission(1);
    Wire.write(pin);
    ConexionPeticionEsclavo();
        Wire.endTransmission();
    delay(1000);
}