void crearUsuario(Usuario usr)
{
    EEPROM.get(0, USUARIOS_REGISTRADOS);                         // Obteniendo numero de usuarios registrados
    int posicion = 1 + (sizeof(Usuario) * USUARIOS_REGISTRADOS); // calculando la posicion a guardar el usuario
    EEPROM.put(posicion, usr);                                   // Guardando el usuario en esa posicion
    USUARIOS_REGISTRADOS++;                                      // Incrementando el numero de usuarios registrados
    EEPROM.put(0, USUARIOS_REGISTRADOS);                         // Guardando el numero de usuarios registrados/
}

bool esUsuario(char nombre[], char password[])
{
    struct Usuario usr;

    EEPROM.get(0, USUARIOS_REGISTRADOS); // Obteniendo el numero de usuarios guardados
    int direccionEEPROM = 1;             // Direccion inicial de los usuarios
    for (int i = 1; i <= USUARIOS_REGISTRADOS; i++)
    {
        EEPROM.get(direccionEEPROM, usr);
        if (memcmp(usr.nombre, nombre, 10) == 0 && memcmp(usr.password, password, 20) == 0)
        {
            Serial1.print("BIENVENIDO CONSUMIDOR: ");
            Serial1.println(usr.nombre);
            return true;
        }
        direccionEEPROM += sizeof(Usuario);
    }
    Serial1.println("USUARIO NO RECONOCIDO");
    return false;
}

/*
    Valida si el apodo y contraseña pertenecen al usuario administrador
*/
bool esAdmin(char nombre[], char password[])
{
    if (memcmp(USR_ADMIN.nombre, nombre, 10) == 0 && memcmp(USR_ADMIN.password, password, 20) == 0)
    {
        Serial1.print("BIENVENIDO ADMIN: ");
        Serial1.println(USR_ADMIN.nombre);
        return true;
    }
    Serial1.println("USUARIO NO ADMINISTRADOR");
    return false;
}
