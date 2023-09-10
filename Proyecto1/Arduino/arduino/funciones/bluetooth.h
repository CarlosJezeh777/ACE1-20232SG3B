void ComunicacionBluetooth(String cadenaRecibida){
    char caracter;
    while (Serial.available() > 0)
    {
        caracter = Serial.read();
        cadenaRecibida += caracter;
    }
}

void LlenarMatrizBluetooth(){
    int i =0;
    while (Serial.available() >0)
    {
        matriz_estacion[i] = Serial.read();
    }
    
}