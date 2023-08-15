// Ejemplo para enviar mensajes deslizantes en módulos de matrices LEDs con Arduino basado en MAX7219
#include <Arduino.h>
#include <MD_Parola.h>
#include <MD_MAX72xx.h>
#include <SPI.h>
#define HARDWARE_TYPE MD_MAX72XX::FC16_HW
#define NUM_OF_MATRIX 2
#define CLK_PIN 52
#define DATA_PIN 51
#define CS_PIN 53

MD_MAX72XX cartel = MD_MAX72XX(HARDWARE_TYPE, DATA_PIN, CLK_PIN, CS_PIN, NUM_OF_MATRIX);
MD_Parola P = MD_Parola(HARDWARE_TYPE, CS_PIN, NUM_OF_MATRIX);
char matrizMensaje[][36] = {
    "<",
    "P",
    "R",
    "A",
    "C",
    "1",
    " ",
    "-",
    " ",
    "G",
    "R",
    "U",
    "P",
    "O",
    "3",
    " ",
    "-",
    "S",
    "E",
    "C",
    "C",
    "I",
    "O",
    "N",
    " ",
    "A",
    ">",
};

int entrada1 = 14;
int entrada2 = 15;
int entradavelocidad = A0;
int velocidad = 0;

int slider_val;
int slide_scroll_speed;
int scrollSpeed;

textEffect_t scrollEffect = PA_SCROLL_LEFT;

textPosition_t scrollAlign = PA_LEFT; // Alineacion del texto

int scrollPause = 0;

#define BUF_SIZE 75                                             // Maximum of 75 characters
char curMessage[BUF_SIZE] = {"< PRAC1 - GRUPO3 - SECCION A >"}; // used to hold current message
void setup()
{
  P.begin();
  // Declaro los pines
  pinMode(entrada1, INPUT);
  pinMode(entrada2, INPUT);
  pinMode(entradavelocidad, INPUT);
  // inicializar el objeto mx
  cartel.begin();
  P.setZone(0, 0, 3);
  P.setZone(1, 4, 7);
  P.setSpeed(50);
  // Establecer intencidad a un valor de 5
  cartel.control(MD_MAX72XX::INTENSITY, 10);

  // Desactivar auto-actualizacion
  cartel.control(MD_MAX72XX::UPDATE, false);

  cartel.transform(MD_MAX72XX::TRC);

  // inicializar puerto Serie a 9600 baudios
  Serial.begin(9600);
  P.displayText(curMessage, scrollAlign, scrollSpeed, scrollPause, scrollEffect, scrollEffect);
}
void funcionvelocidad()
{
  velocidad = map(analogRead(entradavelocidad), 0, 1023, 10, 1000);
}
void letraXletra()
{
  int numRows = sizeof(matrizMensaje) / sizeof(matrizMensaje[0]);

  for (int i = 0; i < numRows; i++)
  {
    funcionvelocidad();
    P.print(matrizMensaje[i]); // Imprime la letra actual
    delay(velocidad);          // Cambio la velocidad dependiendo el valor
  }
}

void loop()
{

  if (digitalRead(entrada1) == 0 && digitalRead(entrada2) == 0)
  {
    slider_val = analogRead(entradavelocidad);               // Leo los valores del potenciometro para cambiar el valor
    scrollEffect = PA_SCROLL_LEFT;                           // CUando las entradas esten 0-0 el scroll es hacia la izquierda, cambio el efecto
    P.setTextEffect(scrollEffect, scrollEffect);             // Actuzlizo el nuevo efecto
    slide_scroll_speed = map(slider_val, 1023, 0, 15, 1000); // Mapeo la velocidad de 15 a 1000 ms
    P.setSpeed(slide_scroll_speed);                          // actalizo la nueva velocidad
  }

  if (digitalRead(entrada1) == 0 && digitalRead(entrada2) == 1)
  {
    slider_val = analogRead(entradavelocidad);
    scrollEffect = PA_SCROLL_RIGHT;
    P.setTextEffect(scrollEffect, scrollEffect);
    slide_scroll_speed = map(slider_val, 1023, 0, 15, 1000);
    P.setSpeed(slide_scroll_speed);
  }

  if (digitalRead(entrada1) == 1 && digitalRead(entrada2) == 0)
  {
    P.displayClear();
    letraXletra();
  }
  if (P.displayAnimate())
  {
    P.displayReset();
  }
}
