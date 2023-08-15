void Botones_Juego()
{
    if (digitalRead(BTN_IZQ) == LOW && digitalRead(BTN_ARRIBA) == LOW && digitalRead(BTN_DER) == LOW && digitalRead(BTN_ABAJO) == LOW)
    {
        puede_leer_btn = true;
    }
    if (digitalRead(BTN_IZQ) == HIGH && puede_leer_btn)
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
    }
}
