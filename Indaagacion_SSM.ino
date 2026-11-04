const int pinLED = 13;          // LED integrado en la placa Arduino
const int pinDigital = 7;       // Conectado al pin DO del sensor
const int pinAnalogico = A0;    // Conectado al pin AO del sensor

int digitalVal;
int analogVal;

unsigned long TiempoInicio = 0;
unsigned long TiempoFinal = 0;
unsigned long TiempoTotal = 0;

bool sonidoMedido = false; 

void setup() {  
  pinMode(pinLED, OUTPUT);       // El LED es una salida
  pinMode(pinDigital, INPUT);    // El pin digital del sensor es entrada
  
  Serial.begin(9600);            // Inicializar el graficador/monitor serie
}

void loop() {
  // 1. Leer el pin digital (DO) para encender o apagar el LED integrado
  while(digitalRead(pinDigital) == LOW) {
  }

  TiempoInicio = micros();

 while(digitalRead(pinDigital) == HIGH) {
 }
 TiempoFinal = micros();

 TiempoTotal = TiempoFinal - TiempoInicio;

 Serial.print("Tiempo de reaccion del circuito: ");
  Serial.print(TiempoTotal);
  Serial.println(" microsegundos (us)");

    medirSonido();

delay(2000); 
  Serial.println("\nListo para el siguiente aplauso...");


}

void medirSonido() {

   digitalVal = digitalRead(pinDigital);

  if (digitalVal == HIGH) {      
    digitalWrite(pinLED, HIGH);
  } else {
    digitalWrite(pinLED, LOW);
  }

  // 2. Leer el pin analógico (AO) para medir la intensidad del sonido
  analogVal = analogRead(pinAnalogico);

  // 3. Enviar la lectura al Serial Plotter para ver la gráfica correcta
  Serial.print("Intensidad de volumen analógico: ");
  Serial.println(analogVal);
  
  delay(10); // Una pausa microscópica para que la gráfica no vaya tan rápido
}
