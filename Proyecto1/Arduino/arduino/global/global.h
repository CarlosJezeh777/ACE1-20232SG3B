byte matriz_estacion[8] = {};
byte matriz_estaciones[24] = {};
byte matriz_limpia[8] = {};


//ESTABLECIO LA MATRIZ DE LED 4
LedControl matriz_driver = LedControl(24, 22, 23, 4);
// ESTABLECIO LCD
LiquidCrystal lcd(35,36,37,38,39,40);

enum Estado
{
    INICIO,
    MENU_PRINCIPAL,
    MENU_ADMIN,
    MENU_USUARIO,
};

Estado ESTADO;

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

//Teclado

const byte ROWS = 4;
const byte COLS = 3;
char keys[ROWS][COLS] = {
    {'1', '2', '3'},
    {'4', '5', '6'},
    {'7', '8', '9'},
    {'*', '0', '#'}};
byte rowPins[ROWS] = {5, 4, 3, 2};
byte colPins[COLS] = {6, 8, 7};

Keypad Key = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

//usuarios
struct Usuario
{
    char nombre[10]; 
    char password[10];
};

const Usuario USR_ADMIN = {"B0313D", "034123"}; // Usuario administrador

uint8_t USUARIOS_REGISTRADOS = 0;