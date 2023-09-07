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

struct Usuario
{
    char nombre[20]; // 16 caracteres + 1 caracter de fin de cadena
    char contrasena[10];
};

const Usuario ADMIN = {"B0313D", "034123"}; // Usuario administrador
