#include "LedControl.h"
#include "global/caracteres.h"
#include "global/global.h"
#include "funciones/matriz.h"
#include "clases/comida.h"
#include "clases/criatura.h"

comida COMIDA;
criatura SNAKE;

#include "funciones/botones.h"
#include "funciones/pausa.h"
#include "funciones/configuracion.h"


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

  ESTADO = CONFIG;
}

void loop() {
  // put your main code here, to run repeatedly:
  switch (ESTADO)
  {
  case CONFIG:
    limparMatriz();
    ConfiguracionInicial(matriz_pantalla); 
    pintarMatriz();
    SNAKE.reset();
    SNAKE.aceleracion = map(rangoV, 1, 4, 1024, 256);
    SNAKE.veloz = map(rangoV, 1, 4, 128, 8);
    Botones_Configuracion();
    break;
  case JUEGO:
    limparMatriz();
    SNAKE.GenerarCriatura(matriz_pantalla);
    COMIDA.ColocarComida(matriz_pantalla);
    if (inicioJuego)
    {
      if (SNAKE.Velocidad())
      {
        SNAKE.Movimientos();
        SNAKE.ComioObjetivo(COMIDA);
      }
      SNAKE.Choques();
    }
    pintarMatriz();
    Botones_Juego();
    break;
  case PAUSA:
    MostrarPuntuacion(matriz_pantalla, SNAKE.puntaje);
    pintarMatriz();
    Botones_Pausa();
  default:
    break;
  }
}
