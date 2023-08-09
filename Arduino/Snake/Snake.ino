#include "LedControl.h"
#include "global/global.h"
#include "funciones/matriz.h"
#include "clases/comida.h"
#include "clases/criatura.h"

comida COMIDA;
criatura SNAKE;

#include "funciones/botones.h"


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  matriz_driver.shutdown(0, false);
  matriz_driver.setIntensity(0, 15);
  matriz_driver.clearDisplay(0);

  matriz_driver.shutdown(1, false);
  matriz_driver.setIntensity(1, 15);
  matriz_driver.clearDisplay(1);
  
  pinMode(BTN_IZQ,INPUT);
  pinMode(BTN_DER,INPUT);
  pinMode(BTN_ARRIBA, INPUT);
  pinMode(BTN_ABAJO,INPUT);

  ESTADO = JUEGO;
}

void loop() {
  // put your main code here, to run repeatedly:
  switch (ESTADO)
  {
  case JUEGO:
    limparMatriz();
    SNAKE.GenerarCriatura(matriz_pantalla);
    COMIDA.ColocarComida(matriz_pantalla);
    if (SNAKE.Velocidad())
    {
      SNAKE.Movimientos();
      SNAKE.ComioObjetivo(COMIDA);
    }
    SNAKE.Choques();
    pintarMatriz();
    Botones_Juego();
    break;
  default:
    break;
  }
}
