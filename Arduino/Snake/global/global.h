byte matriz_pantalla[16] = {};
byte matriz_limpia[16] = {};

int BTN_IZQ  = 22;
int BTN_ARRIBA = 23;
int BTN_DER  = 24;
int BTN_ABAJO  = 25;

LedControl matriz_driver = LedControl(51, 52, 53, 2);
bool puede_leer_btn = true; // Bandera auxiliar que sirve para leer correctamente los botones

enum Estado{
    JUEGO,
};

Estado ESTADO;