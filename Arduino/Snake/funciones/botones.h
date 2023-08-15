void Botones_Juego()
{
    if (digitalRead(BTN_IZQ) == LOW && digitalRead(BTN_ARRIBA) == LOW && digitalRead(BTN_DER) == LOW && digitalRead(BTN_ABAJO) == LOW && digitalRead(BTN_INICIO) == LOW)
    {
        if (tiempo_boton_ini != 0)
        {
            if ((millis() - tiempo_boton_ini) >= 200){
                ESTADO = PAUSA;
                inicioJuego = false;
            }
            else if ((millis() - tiempo_boton_ini) >= 3000)
            {
                Serial.println("Mensaje");
            }
            tiempo_boton_ini = 0;
        }
        puede_leer_btn = true;
    }
    else if (digitalRead(BTN_IZQ) == HIGH && puede_leer_btn)
    {
        SNAKE.CambioOrientacion(1);
        puede_leer_btn = false;
    }
    else if (digitalRead(BTN_ARRIBA) == HIGH && puede_leer_btn)
    {
        SNAKE.CambioOrientacion(3);
        puede_leer_btn = false;
    }
    else if (digitalRead(BTN_DER) == HIGH && puede_leer_btn)
    {
        SNAKE.CambioOrientacion(2);
        puede_leer_btn = false;
    }
    else if (digitalRead(BTN_ABAJO) == HIGH && puede_leer_btn)
    {
        SNAKE.CambioOrientacion(4);
        puede_leer_btn = false;
    }else if (digitalRead(BTN_INICIO) == HIGH && puede_leer_btn){
        inicioJuego = true;
        tiempo_boton_ini = millis();
        puede_leer_btn = false;
    }
}

void Botones_Pausa(){
    if (digitalRead(BTN_INICIO) == LOW)
    {
        puede_leer_btn = true;
    }
    else if (digitalRead(BTN_INICIO) == HIGH && puede_leer_btn)
    {
        ESTADO = JUEGO;
        delay(200);
    }
}

void Botones_Configuracion(){
    if (digitalRead(BTN_ARRIBA) == LOW && digitalRead(BTN_ABAJO) == LOW && digitalRead(BTN_INICIO) == LOW)
    {
        puede_leer_btn = true;
    }
    else if (digitalRead(BTN_ARRIBA) == HIGH && puede_leer_btn)
    {
        rangoV++;
        if (rangoV > 4)
        {
            rangoV = 4;
        }    
        delay(500);    
    }
    else if (digitalRead(BTN_ABAJO) == HIGH && puede_leer_btn)
    {
        rangoV--;
        if (rangoV == 0)
        {
            rangoV = 1;
        }
        delay(500);
    }
    else if (digitalRead(BTN_INICIO) == HIGH && puede_leer_btn)
    {
        ESTADO = JUEGO;
    }
}
