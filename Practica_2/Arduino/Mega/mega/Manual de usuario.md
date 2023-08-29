# ARQUITECTURA DE COMPUTADORES Y ENSAMBLADORES 1.
# Manual de Usuario
## Practica 2
### Segundo Semestre
```
Universidad San Carlos de Guatemala
Estudiantes :Richard Alexandro Marroquin Arana, Carlos Jezeh Toscano Palacios , 
Luis Josue Choc Boj, Pedro Luis Pu Tavico
Carne: 202102894, 201807292, 202000562, 201532643
```
---
## Descripción del Proyecto
Se solicita el desarrollo de un prototipo de máquina de pinball.
El diseño del tablero se presenta en la Figura 1. El principal
medio de interacción con el prototipo serán los dos botones cuyas
funciones específicas se describirán posteriormente.
Como principal medio de salida se tendrá un conjunto de LEDs y
una pantalla LCD con la que se podrá mostrar diversos tipos de
información. Físicamente, el prototipo deberá implementarse utilizando dos
placas Arduino conectadas por medio de un bus I2C, mediante el
cuál coordinarán la transferencia de datos para la correcta
ejecución del flujo de operación en todo momento.


## Introducción

¡Bienvenido al Manual de Usuario del Prototipo de Máquina de Pinball! Este manual está diseñado para ayudarte a comprender y disfrutar de la experiencia de jugar con nuestro emocionante prototipo de pinball. A continuación, te proporcionamos una guía detallada sobre cómo interactuar con el prototipo y sacar el máximo provecho de sus características.

## Contenido de la Caja

Antes de comenzar, asegúrate de que el contenido de la caja esté completo:

- Tablero de juego de pinball (Figura 1)
- Dos botones de interacción
- Conjunto de LEDs
- Pantalla LCD
- Dos placas Arduino conectadas por bus I2C
- Figura 1: Tablero de juego de pinball

![Texto alternativo](https://i.ibb.co/HHF5s5z/image.png)


## Componentes y Medios de Interacción

El prototipo de máquina de pinball consta de los siguientes componentes principales:

1. **Tablero de Juego**: El diseño del tablero de juego se presenta en la Figura 1. En él, encontrarás diversas áreas de juego, obstáculos y rutas para la bola de pinball. Tu objetivo es controlar la bola y conseguir la mayor puntuación posible.

2. **Botones de Interacción**: El prototipo está equipado con dos botones que son tus principales medios de control. El Botón A se utiliza para lanzar la bola y el Botón B para controlar los flippers (paletas) en el tablero y mantener la bola en juego.

3. **Conjunto de LEDs**: Los LEDs se iluminarán en diferentes momentos y situaciones para brindar feedback visual sobre el estado del juego, los puntos ganados y otras notificaciones importantes.

4. **Pantalla LCD**: La pantalla LCD muestra información relevante durante el juego, como puntuación actual, nivel alcanzado y mensajes especiales.


![Texto alternativo](https://i.ibb.co/SP4RmSy/image.png)


## Instrucciones de Uso

1. **Encendido y Conexión**: Conecta las dos placas Arduino mediante el bus I2C y asegúrate de que todos los componentes estén conectados correctamente.

2. **Inicio del Juego**: Presiona el Botón A para lanzar la bola al tablero. Utiliza el Botón B para activar los flippers y mantener la bola en juego.

3. **Objetivos del Juego**: Tu objetivo es obtener la mayor puntuación posible al golpear los objetivos y superar los obstáculos en el tablero.

4. **Feedback Visual**: Observa los LEDs para recibir información visual sobre tu progreso y estado del juego. La pantalla LCD mostrará detalles adicionales.

5. **Final del Juego**: El juego finaliza cuando se pierde la última bola. En la pantalla LCD verás tu puntuación final y tendrás la opción de reiniciar el juego.

6. **Pausa y Reinicio**: Puedes pausar el juego presionando ambos botones simultáneamente. Reinicia el juego siguiendo las instrucciones en la pantalla.

## Mantenimiento y Soporte

Si encuentras algún problema técnico o tienes preguntas sobre el funcionamiento del prototipo, por favor, consulta la sección de "Solución de Problemas" en este manual. Si el problema persiste, no dudes en contactar a nuestro equipo

Esperamos que disfrutes de la experiencia de jugar con nuestro prototipo de máquina de pinball. ¡Diviértete y compite por la puntuación más alta!



## Mensaje de Bienvenida e Información de Desarrolladores

¡Bienvenido al Prototipo de Máquina de Pinball!

En este emocionante juego de pinball, te proporcionamos una experiencia única llena de diversión y desafíos. Antes de comenzar, queremos presentarte a los apasionados desarrolladores que hicieron posible este proyecto.

![Texto alternativo](https://i.ibb.co/52q73Bz/Whats-App-Image-2023-08-28-at-9-31-15-PM.jpg)



### Desarrolladores

**Equipo de Desarrollo:**
- Richard Marroquin
- Carlos Toscano
- Luis Choc
- Pedro Luis

¡Estamos emocionados de que pruebes nuestro prototipo y experimentes la diversión que hemos creado para ti!

## Menú Interactivo

¡Explora las emocionantes opciones que tenemos para ti en nuestro prototipo de Máquina de Pinball!

### Menú Principal

**Instrucciones de Navegación:**
- Utiliza el **Botón Izquierdo** para alternar entre las opciones.
- Utiliza el **Botón Derecho** para seleccionar la opción elegida.

### Opciones Disponibles

1. **Nuevo Juego**
   - ¡Comienza una nueva partida y compite por la puntuación más alta!
   - Presiona el **Botón Derecho** para seleccionar esta opción.

2. **Puntajes Altos**
   - Consulta los mejores puntajes registrados hasta el momento.
   - Presiona el **Botón Derecho** para seleccionar esta opción.

Una vez que hayas seleccionado una opción, ¡estarás listo para disfrutar de la emoción del juego de pinball!

## Nuevo Juego

¡Prepárate para una emocionante partida de pinball! Cuando elijas la opción "Nuevo Juego" desde el Menú Principal, el prototipo se preparará para una nueva experiencia llena de desafíos.

1. **Secuencia de Inicio en LEDs**: Los LEDs alrededor de la pantalla LCD se iluminarán en una secuencia atractiva para crear un ambiente emocionante.

2. **Ingreso de la Pelota**: Coloca una pelota en el área de entrada del tablero. El sensor ultrasónico detectará la pelota cuando se ingrese desde el exterior.

3. **Inicio de la Partida**: Una vez que la pelota sea detectada por el sensor ultrasónico, la partida se iniciará automáticamente. ¡Prepárate para operar las paletas y marcar puntos!

![Texto alternativo](https://i.ibb.co/4K9Qys3/Whats-App-Image-2023-08-28-at-9-32-28-PM.jpg)


## Puntajes Altos

¿Estás listo para enfrentar los mejores puntajes? En la opción "Puntajes Altos", podrás explorar los diez mejores registros de puntuación en un recorrido circular.

1. **Exploración de Puntajes**: Al seleccionar "Puntajes Altos" desde el Menú Principal, podrás recorrer los registros de puntuación más altos. Utiliza el **Botón Izquierdo** para avanzar entre los registros.

2. **Regreso al Menú**: Si deseas regresar al Menú Principal, simplemente presiona el **Botón Derecho**. Esto te llevará de vuelta para que puedas disfrutar de otras opciones.

¡Compite por los puntajes más altos y demuestra tus habilidades en el juego de pinball!

![Texto alternativo](https://i.ibb.co/4K9Qys3/Whats-App-Image-2023-08-28-at-9-32-28-PM.jpg)


## Mecánica del Juego

¡Prepárate para sumergirte en la emocionante mecánica de juego de nuestra Máquina de Pinball! Tu objetivo principal es hacer pasar la pelota por la parte superior del cilindro del tablero la mayor cantidad de veces posible. Al lograrlo, podrás avanzar de nivel y obtener valiosos puntos.

### Avance de Niveles

1. **Objetivo de Avance**: Haz pasar la pelota por la parte superior del cilindro del tablero para avanzar de nivel. Cada vez que logres este objetivo, un LED alrededor de la pantalla LCD se encenderá, indicando tu progreso.

2. **Avance y Reinicio**: Una vez que todos los LEDs se enciendan, habrás avanzado de nivel. En este punto, los LEDs se apagarán y podrás comenzar la secuencia nuevamente. Los grupos de terminación par llenarán los LEDs en sentido horario, mientras que los grupos de terminación impar lo harán en sentido anti-horario.



