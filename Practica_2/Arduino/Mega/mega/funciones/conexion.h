#include <Wire.h>

byte CODE;
byte ESTADO;
int puntos = 0;
int cantidad = 0;
int subpuntos = 0;
int vidas = 3;

void setup()
{
    Serial.begin(9600);
    Wire.begin(); // No especificamos dirección en el maestro
}

void loop()
{
    // Coloca aquí tu lógica principal si es necesario
}

void ConexionPeticionEsclavo()
{
    Wire.requestFrom(0x01, 1); // Solicitamos 1 byte al esclavo con dirección 0x01
    if (Wire.available())
    {
        CODE = Wire.read();   // Leemos el byte recibido
        Serial.println(CODE); // Imprimimos el valor leído
        if (CODE == 1)
        {
            ESTADO = JUEGO;
        }
    }
}

void ConexionResiceEsclavo(byte pin)
{
    Wire.beginTransmission(0x01); // Especificamos la dirección del esclavo 0x01
    Wire.write(pin);              // Enviamos un byte al esclavo
    Wire.endTransmission();
    delay(1000);
}

void ConexionPeticionEsclavo2()
{
    Wire.requestFrom(0x01, 1); // Solicitamos 1 byte al esclavo con dirección 0x01
    if (Wire.available())
    {
        CODE = Wire.read(); // Leemos el byte recibido
        if (CODE == 1)
        {
            puntos = cantidad + puntos;
            subpuntos++;
            ConexionResiceEsclavo(2); // Enviamos un byte al esclavo
        }
        else if (CODE == 2)
        {
            vidas--;
        }
    }
}