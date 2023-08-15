byte matriz_pantalla[16] = {};
byte matriz_limpia[16] = {};

int BTN_IZQ  = 22;
int BTN_ARRIBA = 23;
int BTN_DER  = 24;
int BTN_ABAJO  = 25;
int BTN_INICIO = 26;

LedControl matriz_driver = LedControl(51, 52, 53, 2);
bool puede_leer_btn = true; // Bandera auxiliar que sirve para leer correctamente los botones
int tiempo_boton_ini = 0;
bool inicioJuego;
int rangoV = 1;
enum Estado {
    CONFIG,
    JUEGO,
    PAUSA,
};

Estado ESTADO;

void buscarNumero(int nivel, byte *numero)
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
