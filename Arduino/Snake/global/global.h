byte matriz_pantalla[16] = {};
byte matriz_limpia[16] = {};

int BTN_IZQ = 22;
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
    GAMEOVER,
};

Estado ESTADO;

#define SP        \
  {               \
    0, 0, 0, 0, 0 \
  } // Espacio
#define EX          \
  {                 \
    0, 125, 0, 0, 0 \
  } // Exclamacion !
#define A              \
  {                    \
    31, 36, 68, 36, 31 \
  }
#define B                \
  {                      \
    127, 73, 73, 73, 54, \
  }
#define C              \
  {                    \
    62, 65, 65, 65, 34 \
  }
#define D               \
  {                     \
    127, 65, 65, 34, 28 \
  }
#define E               \
  {                     \
    127, 73, 73, 65, 65 \
  }
#define F               \
  {                     \
    127, 72, 72, 72, 64 \
  }
#define G              \
  {                    \
    62, 65, 65, 69, 38 \
  }
#define H             \
  {                   \
    127, 8, 8, 8, 127 \
  }
#define I             \
  {                   \
    0, 65, 127, 65, 0 \
  }
#define J           \
  {                 \
    2, 1, 1, 1, 126 \
  }
#define K              \
  {                    \
    127, 8, 20, 34, 65 \
  }
#define L           \
  {                 \
    127, 1, 1, 1, 1 \
  }
#define M                \
  {                      \
    127, 32, 16, 32, 127 \
  }
#define N               \
  {                     \
    127, 32, 16, 8, 127 \
  }
#define O              \
  {                    \
    62, 65, 65, 65, 62 \
  }
#define P               \
  {                     \
    127, 72, 72, 72, 48 \
  }
#define Q              \
  {                    \
    62, 65, 69, 66, 61 \
  }
#define R               \
  {                     \
    127, 72, 76, 74, 49 \
  }
#define S              \
  {                    \
    50, 73, 73, 73, 38 \
  }
#define T               \
  {                     \
    64, 64, 127, 64, 64 \
  }
#define U             \
  {                   \
    126, 1, 1, 1, 126 \
  }
#define V             \
  {                   \
    124, 2, 1, 2, 124 \
  }
#define W             \
  {                   \
    126, 1, 6, 1, 126 \
  }
#define X             \
  {                   \
    99, 20, 8, 20, 99 \
  }
#define Y              \
  {                    \
    96, 16, 15, 16, 96 \
  }
#define Z              \
  {                    \
    67, 69, 73, 81, 97 \
  }

byte frase[9][9] = {G, A, M, E, SP, O, V, E, R};
int largo = sizeof(frase) / 9;
int gnd[18] = {-5, -4, -3, -2, -1, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
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