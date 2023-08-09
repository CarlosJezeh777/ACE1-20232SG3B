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
/*
void buscarNumero(int nivel,byte *numero)
{
    switch (nivel)
    {
    case 1:
        memcpy(numero, UNO, 8);
        break;
    case 2:
        memcpy(numero, DOS, 8);
        break;
    case 3:
        memcpy(numero, TRES, 8);
        break;
    case 4:
        memcpy(numero, CUATRO, 8);
        break;
    case 5:
        memcpy(numero, CINCO, 8);
        break;
    case 6:
        memcpy(numero, SEIS, 8);
        break;
    case 7:
        memcpy(numero, SIETE, 8);
        break;
    case 8:
        memcpy(numero, OCHO, 8);
        break;
    case 9:
        memcpy(numero, NUEVE, 8);
        break;
    case 0:
        memcpy(numero, CERO, 8);
        break;
    default:
        break;
    }
}
*/