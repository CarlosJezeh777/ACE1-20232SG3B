int servoIzq = 50;
int servoDer = 52;

int BTN_IZQ = A0;
int BTN_DER = A1;

Servo myServoIzq;
Servo myServoDer;

bool puede_leer_btn;


bool OPCIONES = true;

String Dato[] = {"Luis Josue Choc", "Richard Alexandro", "Carlos Jezeh Toscano", "Pedro Luis Pu"};

enum Estado
{
    MJS,
    MENU_JUEGO,
    JUEGO,
    PUNTAJES,
    INICIANDO,
};

Estado ESTADO;

// FUNCIONES DE IMPRIMIR LCD

LiquidCrystal_I2C lcd(0x27, 16, 2); // set the LCD address to 0x27 for a 16 chars and 2 line display

void imprimirLCD(String texto, int fila, int columna)
{
    lcd.setCursor(columna, fila);
    lcd.print(texto);
}

void imprimirLCD(int texto, int fila, int columna)
{
    lcd.setCursor(columna, fila);
    lcd.print(texto);
}

//Menu juego

byte CODE;
int puntos;
int cantidad =10;
int subpuntos;
int nivel;
int vidas = 3 ;
int listapuntos[20];
int popP = 0;