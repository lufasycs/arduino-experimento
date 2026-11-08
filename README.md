# 🔬¿Cómo se relaciona la intensidad del sonido con el tiempo de reacción de un módulo de sonido sensor?

## Objetivo e Hipótesis
Este experimento busca medir la variación de el tiempo de reacción de un sensor de sonido KY-037 en relación con los camios de intensidad del sonido que lee.
Mi hipótesis es que el tiempo de reaccion del sensor varía de forma directamente proporcional con la intensidad del sonido.

##  Hardware Utilizado
* Arduino Uno R3
* Módulo sensor de sonido KY-037
* Buzzer pasivo
* Protoboard
* Cables de conexión

##  Circuito y Conexiones
El sensor KY-037 se conecta al Arduino de la siguiente manera:
* **VCC** ➡️ 5V
* **GND** ➡️ GND
* **AO** ➡️ Pin A0
* **DO** ➡️ Pin 7

El buzzer se conecta al Arduino de la siguiente manera:
* **VCC** ➡️ Pin 8
* **GND** ➡️ GND

* Diagrama del circuito:
https://app.cirkitdesigner.com/project/06578eb7-8a59-4de0-b4fc-82426a1eaa82

##  Resultados
Los datos obtenidos a través del monitor serie se exportaron a la carpeta `/tabla.csv` y `/data_serial_monitor.txt/`.

## Conclusiones
* **Comportamiento del tiempo:** Al comparar las frecuencias de 250 Hz, con 4000 Hz y por último 10000 Hz, el sensor reaccionó perfectamente con un tiempo de reacción entre 20 y 28 microsegundos, solo interfiriendo el tiempo que demora el Arduino al leer la función digitalRead().

* **Comportamiento del sensor analogico:** Las lecturas analogicas se mantuvieron alrededor de 512 debido a que el voltaje de la salida analógica oscila de forma de onda senoidal exactamente 4,000 veces por segundo alrededor de su voltaje de referencia (que suele ser la mitad del voltaje de alimentación, aprox. 2.5V si lo alimentas con 5V).

* **Evaluación de la hipótesis:** Mi teoría inicial era que la intensidad cambiaría el tiempo, pero los datos demuestran que el tiempo de reacción es independiente a la frecuencia del sonido.


##  Comunidad y Discusiones
Estoy empezando a publicar mis experimentos en Github así que si quieres replicar este experimento, tienes dudas con las calibraciones del sensor o quieres sugerir mejoras en el código, siéntete libre de abrir un hilo en la pestaña de **Discussions** de este repositorio ^_^
