# ARQUITECTURA DE COMPUTADORES Y ENSAMBLADORES 1.
# Manual de Usuario
## Practica 1
### Segundo Semestre
```
Universidad San Carlos de Guatemala
Estudiantes :Richard Alexandro Marroquin Arana, Carlos Jezeh Toscano Palacios , 
Luis Josue Choc Boj, Pedro Luis Pu Tavico
Carne: 202102894, 201807292, 202000562, 201532643
```
---
## Descripción del Proyecto
La creación de los autómatas de pila, como de gramáticas libres del contexto, será realizada a través de 
archivos de entrada que permitirán optimizar el funcionamiento del programa. Cabe resaltar que los 
archivos de entrada tendrán una estructura definida y sin errores, de manera que puedan ser leídos
utilizando funcionalidades propias de Python sin necesidad de implementar algún tipo de analizador

## Objetivos
● General
Que el estudiante interactúe con el microcontrolador arduino
● Específicos
Comprender el funcionamiento de las entradas y salidas, tanto
digitales como analógicas del microcontrolador Arduino.
Aplicar los conocimientos del lenguaje C para estructuras de
control en Arduino.
Conocer las funciones básicas de salida serial.



---
## Mensaje
Descripción:
El presente manual proporciona instrucciones detalladas sobre el funcionamiento y uso del cartel LED interactivo diseñado para la primera práctica. Este cartel está compuesto por dos matrices de LED de 8x8 cada una y permite mostrar un mensaje personalizado en movimiento, así como acceder a un juego sencillo. Además, se incluye la opción de controlar la velocidad del mensaje mediante un potenciómetro.

Componentes:

Cartel LED con dos matrices de 8x8 LEDs cada una.
Controlador (driver) para las matrices LED.
DIP switch con dos entradas.
Potenciómetro para ajustar la velocidad.
Fuente de alimentación.
Funciones del DIP Switch:
El DIP switch tiene dos entradas, cada una con dos posiciones (0 y 1), que determinan las funciones del cartel LED:

Entrada 1: Control de Mostrado del Mensaje:

Posición 0: Muestra el mensaje completo en movimiento.
Posición 1: Muestra el mensaje letra por letra sin movimiento.
Entrada 2: Dirección de Desplazamiento:

Posición 0: El mensaje se desplaza de izquierda a derecha.
Posición 1: El mensaje se desplaza de derecha a izquierda.
Mensaje a Mostrar:
El mensaje a mostrar en las matrices LED es el siguiente formato:
“<PRAC1 - GRUPO3 - SECCIÓN B>”

---
## Juego Snake

¡Bienvenido al emocionante juego "Snake" en el cartel LED interactivo! En este juego, controlarás una serpiente en su búsqueda de alimentos mientras evitas golpear las paredes o tu propia cola. Sigue las siguientes instrucciones para disfrutar del juego:

Objetivo del Juego:
Controla la serpiente para recoger la mayor cantidad de alimentos posible sin chocar contra las paredes o tu propia cola. Cada vez que la serpiente come un alimento, su cola crecerá, aumentando la dificultad del juego.

Configuración Inicial:

Antes de iniciar el juego, verás el número 1 en la matriz. Utiliza los botones de arriba y abajo para seleccionar la velocidad inicial de la serpiente, donde 1 es la opción más lenta y 4 es la más rápida.
Movimiento de la Serpiente:

Utiliza los botones de dirección (arriba, abajo, izquierda y derecha) para controlar la dirección de la cabeza de la serpiente.
La serpiente seguirá la dirección que elijas, y su cuerpo se moverá en consecuencia.
Recoger Alimentos:

En la matriz, aparecerán alimentos en puntos aleatorios. Tu objetivo es guiar a la serpiente para que los coma.
Cada vez que la serpiente come un alimento, su cola crecerá en un punto.
Evitar Obstáculos:

Evita chocar contra las paredes del área de juego y evita cruzar tu propia cola. Si la cabeza de la serpiente colisiona con la pared o su cola, el juego terminará.
Final del Juego:

Cuando la serpiente choque contra un obstáculo y el juego termine, se mostrará en pantalla el mensaje "GAME OVER" seguido de tu puntuación final.
La puntuación final se basa en la cantidad de alimentos que la serpiente logró comer antes de que terminara el juego.

# ARQUITECTURA DE COMPUTADORES Y ENSAMBLADORES 1.
# Manual de Tecnico
## Practica 1
### Segundo Semestre

## Objetivos
### General
- Que el estudiante interactúe con el microcontrolador Arduino.

### Específicos
- Comprender el funcionamiento de las entradas y salidas, tanto digitales como analógicas, del microcontrolador Arduino.
- Aplicar los conocimientos del lenguaje C para estructuras de control en Arduino.
- Conocer las funciones básicas de salida serial.

## Descripción
La primera práctica consiste en tener un cartel compuesto por 2 matrices de LED de 8x8 controladas por un driver. Se mostrará un mensaje y se podrá acceder a un juego. El mensaje se controla mediante un DIP switch con las siguientes opciones:

*Entrada 1:*
- 0: Mostrar mensaje en movimiento.
- 1: Mostrar mensaje letra por letra sin movimiento.

*Entrada 2:*
- 0: Desplazar mensaje de izquierda a derecha.
- 1: Desplazar mensaje de derecha a izquierda.

El mensaje a mostrar en las matrices es: "<PRAC1 - GRUPO# - SECCIÓN A|B>"


## Juego - Snake
El juego "Snake" consiste en controlar una serpiente que recoge alimentos y evita golpear su cola o las paredes. La serpiente crece al comer. El usuario controla la dirección de la cabeza.

*Inicio del juego:*
- Mostrar el número 1 en la matriz.
- Botones arriba/abajo seleccionan velocidad (1-4).

*Al perder:*
- Mostrar "GAME OVER - puntuación".

*Comida:*
- Generar en lugares aleatorios de la matriz sin ocupar por la serpiente.
- La serpiente crece al comer.

*Diseño del juego:*
- 4 botones para direcciones y 1 para inicio/pausa/mensaje.
- Mantener presionado 3s el botón para cambiar de modo.
- 
Lógica Detallada del Juego "Snake" en el Cartel LED Interactivo:

Inicio del Juego:

Al encender la emulación, se muestra el mensaje para la selección de velocidad de la serpiente.
Selección de Velocidad:

Los botones de arriba y abajo permiten navegar entre las opciones de velocidad (1 a 4).
Mantener presionado el botón "Start" durante 3 segundos confirma la velocidad seleccionada y da inicio al juego.
Comienzo del Juego:

Se determina una posición aleatoria en la primera columna de la matriz 1 o matriz 2, junto con una fila aleatoria.
La serpiente comienza con un tamaño de 2 puntos en la matriz.
Movimiento de la Serpiente:

La serpiente se desplaza de un punto a otro en la dirección indicada por el jugador.
El movimiento es en incrementos de un punto, reflejando el cambio en la posición de la cabeza y el resto del cuerpo.
Alimentación y Crecimiento:

Si la serpiente come un alimento, su tamaño aumenta en un punto.
La velocidad de la serpiente aumenta ligeramente cada vez que come.
Colisiones y Fin del Juego:

Se verifica si la cabeza de la serpiente choca con una pared o su propia cola.
Si se produce una colisión, se muestra el mensaje "GAME OVER" junto con la puntuación final.
El juego retorna al menú de inicio para seleccionar la velocidad nuevamente.
Pausa del Juego:

Al presionar el botón "Start" una vez durante el juego, se activa el modo pausa.
Se muestra la puntuación actual en pantalla.
Presionar nuevamente "Start" reanuda el juego en la misma posición y estado.
Salir del Juego:

Mantener presionado el botón "Start" durante 3 segundos durante el juego permite salir del juego.
El cartel retorna al modo de mensaje inicial.
Regreso al Menú Inicial:

Al finalizar el juego con el mensaje "GAME OVER" y la puntuación final, se regresa al menú de inicio para seleccionar la velocidad nuevamente

## Materiales
- Arduino Uno/Mega
- 2 Matrices LED 8x8
- Potenciómetro
- Driver para matriz led 8x8 (MAX7219)
- 2 Switch
- Botones

## Lógica del juego
1. Mostrar mensaje juego y seleccionar velocidad.
2. Botón Start (3s) inicia el juego.
3. Serpiente inicia en 1ª columna matriz 1 o 2, fila aleatoria.
4. Tamaño inicial de serpiente: 2 puntos matriz.
5. Movimiento de un punto a otro.
6. Comida: crece serpiente y aumenta velocidad.


## Materiales
● Arduino Uno/Mega
● 2 Matrices led 8x8
● 1 Potenciómetro
● Driver para la matriz led 8x8 (MAX7219)
● 2 Switch
● Botones


| Nombre             | Carnet | Puesto | 
| --                    | -- | -- |
| Richard Alexandro Marroquin Arana    | 202102894  | Alumno de A seccion P |
| Luis Josue Choc Boj                  | 201807292  | Alumno de A seccion P |
| Carlos Jezeh Toscano Palacios     | 201532643  | Alumno de A seccion P |
| Pedro Luis Pu Tavico   | 202000562  | Alumno de A seccion P |
