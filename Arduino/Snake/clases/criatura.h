class criatura
{
private:
    /* data */
    int posiciones[64];
    int t_ultimo_x;
    byte cuerpo[64];
    /*Diferente movimietno de Serpiente*/
    bool MovimientoX;
    int EjeX;
    bool arriba;
    bool abajo;
    int tam;

public:
    criatura(/* args */);
    void GenerarCriatura(byte *matriz_pantalla);
    void Movimientos();
    void CambioOrientacion(int Orientacion);
    bool Velocidad();
    ~criatura();
};

criatura::criatura(/* args */)
{
    this->tam = 2;
    this->posiciones[0] = 6;
    this->posiciones[1] = 5;
    this->cuerpo[0] = 0b00001000;
    this->cuerpo[1] = 0b00001000;
    this->MovimientoX = true;
    this->abajo = false;
    this->arriba = false;
    this->EjeX = 1;
}

criatura::~criatura()
{
}

void criatura::GenerarCriatura(byte *matriz_pantalla)
{
    for (size_t i = 0; i < tam; i++)
    {
        matriz_pantalla[this->posiciones[i]] |= this->cuerpo[i];
    }
}

void criatura::Movimientos()
{
    
    int pop;
    byte temp;
    if (this->MovimientoX)
    {
        Serial.println(this->EjeX);
        Serial.println("------");
        pop = this->posiciones[0];
        temp = this->cuerpo[0];
        this->posiciones[0] = this->posiciones[0] + EjeX;
    }
    else if (this->arriba)
    {
        Serial.println("Arriba");
        pop = this->posiciones[0];
        temp = this->cuerpo[0];
        this->cuerpo[0] = this->cuerpo[0] << 1;
    }
    else if (this->abajo)
    {
        Serial.println("Abajo");
        pop = this->posiciones[0];
        temp = this->cuerpo[0];
        this->cuerpo[0] = this->cuerpo[0] >> 1;
    }
    int posicion;
    byte temp1;
    for (size_t i = 1; i < tam; i++)
    {
        posicion = this->posiciones[i];
        temp1 = this->cuerpo[i];
        this->posiciones[i] = pop;
        this->cuerpo[i] = temp;
    }
    this->t_ultimo_x = millis();
}

void criatura::CambioOrientacion(int Orientacion)
{
    Serial.println(Orientacion);
    switch (Orientacion)
    {
    case 1: /*'IZQ'*/
        this->EjeX = -1;
        this->MovimientoX = true;
        this->arriba = false;
        this->abajo = false;
        break;
    case 2: /*'DER'*/
        this->EjeX = 1;
        this->MovimientoX = true;
        this->arriba = false;
        this->abajo = false;
        break;
    case 3: /*'ARRIBA'*/
        this->arriba = true;
        this->abajo = false;
        this->MovimientoX = false;
        break;
    case 4: /*ABAJO*/
        this->arriba = false;
        this->abajo = true;
        this->MovimientoX = false;
        break;
    default:
        break;
    }
}

bool criatura::Velocidad()
{
    return (millis() - this->t_ultimo_x) > 1000;
}
