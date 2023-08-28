void Botones_Juegos()
{
    if (digitalRead(BTN_IZQ) == HIGH && digitalRead(BTN_DER) == HIGH)
    {
        puede_leer_btn = true;
    }
    else if (digitalRead(BTN_IZQ) == LOW && puede_leer_btn)
    {
        myServoIzq.write(180);
        delay(200);
        myServoIzq.write(90);
        delay(50);
        myServoIzq.write(0);
        delay(200);
        myServoIzq.write(90);
        puede_leer_btn = false;
        Serial.println("Izquierda");
    }
    else if (digitalRead(BTN_DER) == LOW && puede_leer_btn)
    {
        myServoDer.write(0);
        delay(200);
        myServoDer.write(90);
        delay(50);
        myServoDer.write(180);
        delay(200);
        myServoDer.write(90);
        puede_leer_btn = false;

        Serial.println("derecha");
    }
}

void Botones_Menu()
{
    if (digitalRead(BTN_IZQ) == HIGH && digitalRead(BTN_DER) == HIGH)
    {
        puede_leer_btn = true;
    }
    else if (digitalRead(BTN_IZQ) == LOW && puede_leer_btn)
    {
        OPCIONES = !OPCIONES;
        Serial.println(OPCIONES);
    }else if (digitalRead(BTN_DER) == LOW && puede_leer_btn)
    {
        Serial.println("D");
    }
}