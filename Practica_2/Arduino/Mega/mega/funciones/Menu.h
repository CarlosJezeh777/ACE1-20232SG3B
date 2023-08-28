void Mensaje_Inicial()
{
    imprimirLCD("<grupo     #3>", 0, 0);
    for (size_t i = 0; i < 4; i++)
    {
        imprimirLCD(Dato[i], 1, 0);
        delay(1000);
        imprimirLCD("                 ", 1, 0);
    }
    ESTADO = MENU_JUEGO;
    lcd.clear();
}

void MenuJuego()
{
    if (OPCIONES)
    {
        imprimirLCD("> Nuevo Juego", 0, 0);
        imprimirLCD("  Puntajes Alto", 1, 0);
    } else if (OPCIONES == false)
    {
        imprimirLCD("  Nuevo Juego", 0, 0);
        imprimirLCD("> Puntajes Alto", 1, 0);
    }
}