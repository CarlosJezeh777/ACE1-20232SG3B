// Pinta en la matriz_estado columna por columna de izquierda a derecha
void pintarMatrizEstaciones()
{
    for (int columna = 0; columna < 24; columna++)
    {
        if (columna < 8)
        {
            matriz_driver.setColumn(0, columna, matriz_estaciones[columna]);
        }
        if (columna >= 8 && columna < 16)
        {
            matriz_driver.setColumn(1, columna - 8, matriz_estaciones[columna]);
        }
        if (columna >= 16)
        {
            matriz_driver.setColumn(2, columna - 16, matriz_estaciones[columna]);
        }
    }
}

void limparEstaciones()
{
    // Compia a la matriz estado el contenido de la matriz limpia (que son solo 0's) para limpiar la matriz, es decir, dejar todas las posiciones en 0's de la matriz_estado
    memcpy(matriz_estaciones, matriz_limpia, 24);
}
