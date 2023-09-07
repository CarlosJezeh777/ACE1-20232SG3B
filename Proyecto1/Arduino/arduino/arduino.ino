#include "LedControl.h"
#include "LiquidCrystal.h"
#include <EEPROM.h>
#include "global/global.h"
#include "funciones/matriz.h"
#include "funciones/memoria.h"
#include "funciones/bluetooth.h"

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial1.begin(9600);
  for (size_t i = 0; i < matriz_driver.getDeviceCount(); i++)
  {
    matriz_driver.shutdown(i, false);
    matriz_driver.setIntensity(i, 15);
    matriz_driver.clearDisplay(i);
  }  
  lcd.begin(16,2);
  ESTADO = INICIO;
}

void loop() {
  switch (ESTADO)
  {
  case INICIO:
    imprimirLCD("ACYE 1 G3",0,4);
    imprimirLCD("----------------",1,0); 
    delay(5000);
    lcd.clear();
    break;
  case MENU_PRINCIPAL:
    imprimirLCD("Conectando al Blutooo");
    //CONECION A BLUTTOO;
  case MENU_ADMIN:
    imprimirLCD("ESTADO : normal", 0, 0);
    imprimirLCD("> ACEDER CRUD");
  default:
    break;
  }
}
