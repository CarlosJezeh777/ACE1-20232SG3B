#  Practica 2 Grupo 3

### Descripción:
Este manual técnico proporciona información detallada sobre el desarrollo y funcionamiento de un prototipo de máquina de pinball. El prototipo consiste en un tablero con componentes electrónicos y sensores para interactuar con una pelota y realizar un juego de pinball. El prototipo está compuesto por dos placas Arduino que se comunican a través de un bus I2C.

### Diseño:
El diseño del tablero incluye un cilindro superior como objetivo principal, paletas para interactuar con la pelota, y botones para acciones de juego y navegación en la pantalla LCD. Se utilizan sensores ultrasónicos para detectar eventos relacionados con la pelota. La salida se compone de LEDs de puntaje y una pantalla LCD.

### Mensaje Inicial:
Cuando el prototipo se inicia, se muestra un mensaje de bienvenida en la pantalla LCD con los nombres de los desarrolladores.

### Menú:
El menú incluye dos opciones: "Nuevo juego" y "Puntajes altos". Se implementa un menú interactivo con botones para navegar y seleccionar opciones.

### Nuevo Juego:
Al seleccionar "Nuevo juego", se inicia una secuencia de LEDs y se espera que se ingrese una pelota al prototipo. El sensor ultrasónico detecta la pelota y el juego comienza.

### Puntajes Altos:
La opción "Puntajes altos" muestra los diez mejores puntajes registrados. Los botones exteriores permiten navegar por los puntajes.

### Mecánica:
El objetivo es hacer pasar la pelota por encima del cilindro para avanzar de nivel. El avance de nivel se representa con LEDs que rodean la pantalla LCD.

### Puntajes:
El puntaje aumenta según el nivel: 10 puntos en nivel 1, 20 puntos en nivel 2, y así sucesivamente.

### Detalles Físicos:
El tablero debe tener inclinación, y se debe considerar un orificio para ingresar la pelota. Los sensores ultrasónicos detectan eventos de pelota.

### Pantalla LCD:
Una pantalla LCD de 16x2 muestra el nivel actual, vidas disponibles y puntaje.

### LEDs de Punteo:
Los LEDs alrededor de la pantalla LCD muestran la cantidad de veces que la pelota pasa por el cilindro en el nivel actual.

### Acción de las Paletas:
Las paletas son controladas por botones y deben moverse para impulsar la pelota hacia arriba.

### Comunicación I2C:
Los dos microcontroladores Arduino se comunican a través del protocolo I2C.

### Materiales:

2 microcontroladores Arduino
2 botones
Pantalla LCD de 16x2
6 LEDs
2 motores
2 sensores ultrasónicos
Resistencias y componentes necesarios

