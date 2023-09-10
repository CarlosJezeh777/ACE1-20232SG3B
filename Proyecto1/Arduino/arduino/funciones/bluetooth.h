void ComunicacionBluetooth(string cadenaRecibida){
    char caracter;
    while (Serial.available() > 0)
    {
        caracter = Serial.read();
        cadenaRecibida += caracter;
    }
}

void LlenarMatrizBluetooth(){
    while (Serial.available() >0)
    {
        matriz_estacion[i] = Serial.read();
    }
    
}