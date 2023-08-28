#include <Servo.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include "global/global.h"
#include "global/botones.h"
#include "funciones/Menu.h"




void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);
  myServoIzq.attach(servoIzq);
  myServoDer.attach(servoDer);
  pinMode(BTN_IZQ, INPUT);
  pinMode(BTN_DER, INPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

   lcd.init();
   lcd.backlight();
   ESTADO = MJS;
}

void loop() {
  switch (ESTADO)
  {
  case MJS:
    Mensaje_Inicial();
    break;
  case MENU_JUEGO:
    MenuJuego();
    Botones_Menu();
    break;
  case JUEGO:
    break;
  default:
    break;
  }
}
