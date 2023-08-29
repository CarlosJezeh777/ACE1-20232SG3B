#include <Wire.h>
  
byte CODE = 0; // Inicializamos CODE en 0
int PIN_LED[8] = {2, 3, 4, 5, 6, 7};
int trigPin = 12;
int echoPin = 11;
int trigPin2 = 10;
int echoPin2 = 9;
int pingTime1, pingTime2;
int total = 6;

void setup()
{
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(trigPin2, OUTPUT);
  pinMode(echoPin2, INPUT); // Cambiamos a INPUT
  pinMode(echoPin, INPUT);  // Cambiamos a INPUT

  for (size_t i = 0; i < 8; i++) // Cambiamos <= a < en el bucle
  {
    pinMode(PIN_LED[i], OUTPUT);
  }
  Wire.begin(0x01);
  Wire.onReceive(EntradaDato); // Movemos esta línea al setup
}

void loop()
{
  digitalWrite(trigPin, HIGH);
  digitalWrite(trigPin2, HIGH);
  pingTime1 = pulseIn(echoPin, HIGH);
  pingTime2 = pulseIn(echoPin2, HIGH);
  if (pingTime1 < 199)
  {
    CODE = 1;
  }
  else if (pingTime2 < 199)
  {
    CODE = 2;
  }
  Serial.println(pingTime1);
  // Serial.println(CODE); // Comentamos esto para evitar sobreescritura de CODE en loop
  delay(1000); // Agregamos un retraso para evitar lecturas continuas
}

void SecuenciaLedAntiHorario()
{
  for (size_t i = 6; i >= 0; i--)
  {
    digitalWrite(PIN_LED[i], HIGH);
    delay(2000);
    digitalWrite(PIN_LED[i], LOW); // Apagamos el LED después del retraso
  }
}

void EncenderLed()
{
  for (size_t i = 6; i >= total; i--)
  {
    digitalWrite(PIN_LED[i], HIGH);
  }
}

void ApagarLed()
{
  for (size_t i = 6; i >= 0; i--)
  {
    digitalWrite(PIN_LED[i], LOW);
  }
}

void Peticion()
{
  Wire.write(CODE);
}

void EntradaDato(int byteCount)
{
  if (Wire.available() >= 1) // Comprobamos si hay al menos un byte disponible
  {
    CODE = Wire.read(); // Leemos el código enviado por el maestro
    Serial.print("Código recibido: ");
    Serial.println(CODE);
    if (CODE == 4)
    {
      // Lógica para manejar el código 4
      Serial.println("Código 4 recibido");
    }
    // Añade más lógica según tus necesidades para otros códigos
  }
}
