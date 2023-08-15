
void ConfiguracionInicial(byte *matriz_pantalla)
{
    buscarNumero(rangoV, unidad);
    memcpy(matriz_pantalla, CERO, 8);
    memcpy(matriz_pantalla + 8, unidad, 8);
}