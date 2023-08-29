#include "Wire.h"
byte CODE;
int PIN_LED[8] = {2,3,4,5,6,7};
int trigPin = 12;
int echoPin = 11;
int trigPin2 = 10;
int echoPin2 = 9;
int pingTime1,pingTime2;
int total = 6;

void setup() {
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(trigPin2, OUTPUT);
  pinMode(echoPin2, OUTPUT);
  pinMode(echoPin, OUTPUT);
  // put your setup code here, to run once:
  for (size_t i = 0; i < 6; i++)
  {
    pinMode(PIN_LED[i], OUTPUT);
  }
   Wire.begin(0x01);

}

void loop() {
  Wire.onReceive(EntradaDato);
  // put your main code here, to run repeatedly:
  digitalWrite(trigPin, HIGH);
  pingTime1 = pulseIn(echoPin, HIGH);
  delay(25);
  digitalWrite(trigPin, LOW);

  digitalWrite(trigPin2, HIGH);
  delayMicroseconds(10);
  pingTime2 = pulseIn(echoPin2, HIGH);
  delay(25);
  digitalWrite(trigPin2, LOW);
  if (pingTime1 < 199)
  {
    CODE = 1;
  }else if (pingTime2 < 199){
    CODE = 2;
  }
  Serial.println(CODE);
  Wire.onRequest(Peticion);
}

void SecuenciaLedAntiHorario(){
  for (size_t i = 6; i >= 0; i--)
  {
    digitalWrite(PIN_LED[i], HIGH);
    delay(2000);
  }
}

void EncenderLed(){
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

void Peticion(){
  Wire.write(CODE);
}

void EntradaDato(int re){
  if (Wire.available() == 1)
  {
    SecuenciaLedAntiHorario();
  }else if (Wire.available() == 2){
    EncenderLed();
  }else if (Wire.available() == 3){
    ApagarLed();
  }
}


