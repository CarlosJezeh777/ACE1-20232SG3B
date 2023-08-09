class comida
{
private:
public:
    byte objetivo;
    int x;
    int y;
    comida(/* args */);
    void ColocarComida(byte *matriz_pantalla);
    void NuevaPosicion(int posiciones[], byte cuerpo[], int tam);
    ~comida();
};

comida::comida(/* args */)
{
    this->x = random(0, 15);
    this->y = random(0, 7);
    while (this->y == 4)
    {
        this->y = random(0, 7);
    }
    while (this->x == 5 && this->x == 6)
    {
        this->x = random(0, 15);
    }
    this->objetivo = 0b00000001 << this->y;
}

comida::~comida()
{
}

void comida::ColocarComida(byte *matriz_pantalla)
{
    matriz_pantalla[this->x] |= this->objetivo;
}

void comida::NuevaPosicion(int posiciones[], byte cuerpo[], int tam)
{
    this->x = random(0, 15);
    this->y = random(0, 7);

    for (size_t i = 0; i < tam; i++)
    {
        if (posiciones[i] == this->x)
        {
            this->x = random(0, 15);
            i = 0;
        }
    }
    for (size_t i = 0; i < tam; i++)
    {
        if (memcmp(cuerpo[i], 0b00000001 << this->y, 8) == 0)
        {
            this->y = random(0, 7);
            i = 0;
        }
    }
    this->objetivo = 0b00000001 << this->y;
}