// Pinta en la matriz_estado columna por columna de izquierda a derecha
void pintarMatriz()
{
    for (int columna = 0; columna < 16; columna++)
    {
        if (columna < 8)
        {
            matriz_driver.setColumn(0, columna, matriz_pantalla[columna]);
        }
        if (columna >= 8)
        {
            matriz_driver.setColumn(1, columna-8, matriz_pantalla[columna]);
        }
    }
}

void limparMatriz()
{
    // Compia a la matriz estado el contenido de la matriz limpia (que son solo 0's) para limpiar la matriz, es decir, dejar todas las posiciones en 0's de la matriz_estado
    memcpy(matriz_pantalla, matriz_limpia, 16);
}