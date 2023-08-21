byte unidad[8] = {};
byte decena[8] = {};


void MostrarPuntuacion(byte *matriz_pantalla , int puntos)
{
    if (puntos < 10)
    {
        buscarNumero(puntos, unidad);

        memcpy(matriz_pantalla, CERO, 8);
        memcpy(matriz_pantalla + 8, unidad, 8);
    }
    else
    {
        int temp = puntos;
        int u = temp % 10;
        buscarNumero(u, unidad);
        temp /= 10;
        int d = temp % 10;
        buscarNumero(d, decena);
        memcpy(matriz_pantalla, decena, 8);
        memcpy(matriz_pantalla + 8, unidad, 8);
    }
}