void crearUsuario(Usuario usr)
{
    EEPROM.get(0, USUARIOS_REGISTRADOS);                         // Obteniendo numero de usuarios registrados
    int posicion = 1 + (sizeof(Usuario) * USUARIOS_REGISTRADOS); // calculando la posicion a guardar el usuario
    EEPROM.put(posicion, usr);                                   // Guardando el usuario en esa posicion
    USUARIOS_REGISTRADOS++;                                      // Incrementando el numero de usuarios registrados
    EEPROM.put(0, USUARIOS_REGISTRADOS);                         // Guardando el numero de usuarios registrados
}
