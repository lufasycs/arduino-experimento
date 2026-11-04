# 🔬¿Cómo se relaciona la intensidad del sonido con el tiempo de reacción de un módulo de sonido sensor?

## Objetivo e Hipótesis
Este experimento busca medir la variación de el tiempo de reacción de un sensor de sonido KY-037 en relación con los camios de intensidad del sonido que lee.
Mi hipótesis es que el tiempo de reaccion del sensor varía de forma directamente proporcional con la intensidad del sonido.

##  Hardware Utilizado
* Arduino Uno R3
* Módulo sensor de sonido KY-037
* Cables de conexión

##  Circuito y Conexiones
El sensor KY-037 se conecta al Arduino de la siguiente manera:
* **VCC** ➡️ 3.3V
* **GND** ➡️ GND
* **SCL** ➡️ Pin A5
* **SDA** ➡️ Pin A4

*(Inserta aquí una foto de tu circuito o diagrama)*
![Diagrama del circuito](hardware/circuito.png)

##  Resultados
Los datos obtenidos a través del monitor serie se exportaron a la carpeta `/data`. A continuación se muestra la gráfica de la relación presión/temperatura:

*(Inserta aquí un gráfico generado con tus datos)*
![Gráfico de Resultados](data/grafico_resultados.png)

##  Comunidad y Discusiones
Si quieres replicar este experimento, tienes dudas con las calibraciones del sensor o quieres sugerir mejoras en el código, ¡abre un hilo en la pestaña de **Discussions** de este repositorio!
