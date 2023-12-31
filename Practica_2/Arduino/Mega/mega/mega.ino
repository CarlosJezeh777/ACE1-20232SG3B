#include <Servo.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include "global/global.h"
#include "global/botones.h"
#include "funciones/Menu.h"
#include "funciones/conexion.h"

void setup()
{
  // put your setup code here, to run once:
  Wire.begin(0x01);
  Serial.begin(9600);
  myServoIzq.attach(servoIzq);
  myServoDer.attach(servoDer);
  pinMode(BTN_IZQ, INPUT);
  pinMode(BTN_DER, INPUT);

  lcd.init();
  lcd.backlight();
  ESTADO = MJS;
}

void loop()
{
  switch (ESTADO)
  {
  case MJS:
    Mensaje_Inicial();
    break;
  case MENU_JUEGO:
    MenuJuego();
    Botones_Menu();
    break;
  case INICIANDO:
    ConexionResiceEsclavo(1);
    ConexionResiceEsclavo(4);
    ConexionPeticionEsclavo();
    break;
  case JUEGO:
    ConexionPeticionEsclavo2();
    if (vidas == 3)
    {
      imprimirLCD("Nivel 3 ■ ■ ■", 0, 0);
      imprimirLCD(puntos, 1, 0);
    }
    else if (vidas == 2)
    {
      imprimirLCD("Nivel 2 ■ ■ o", 0, 0);
      imprimirLCD(puntos, 1, 0);
    }
    else if (vidas == 1)
    {
      imprimirLCD("Nivel 1 ■ o o", 0, 0);
      imprimirLCD(puntos, 1, 0);
    }
    else if (vidas == 0)
    {
      listapuntos[popP] = puntos;
      ConexionResiceEsclavo(3);
      ESTADO = MENU_JUEGO;
    }
    if (subpuntos == 6)
    {
      nivel++;
      cantidad = cantidad + 10;
      subpuntos = 0;
    }
    Botones_Juegos();
  case PUNTAJES:
    int n = sizeof(listapuntos) / sizeof(listapuntos[0]);
    bubbleSort(listapuntos, n);
    for (size_t i = 0; i < 10; i++)
    {
      imprimirLCD("Puntaje " + nombreLugares[i], 0, 0);
      imprimirLCD(listapuntos[i], 1, 5);
      delay(3000);
    }
    ESTADO = MENU_JUEGO;
    break;
  default:
    break;
  }
}
