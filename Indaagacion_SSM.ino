const int pinLED = 13;          // LED integrado en la placa Arduino
const int pinDigital = 7;       // Conectado al pin DO del sensor
const int pinAnalogico = A0;    // Conectado al pin AO del sensor
const int pinBuzzer = 8;        // Buzzer pasivo conectado al pin 8

int numeroPrueba= 1;
int analogVal;
const int totalPruebas = 5;
const int intensidadSonido = 10000; //Aqui puedes cambiar la frecuencia del sonido (Hz)
// Suave: 250; Medio: 4000; Alto: 10000

unsigned long TiempoInicio = 0;
unsigned long TiempoFinal = 0;
unsigned long TiempoTotal = 0;

void setup() {
  pinMode(pinLED, OUTPUT);       
  pinMode(pinDigital, INPUT);    
  pinMode(pinBuzzer, OUTPUT);
  
  Serial.begin(9600);            
  
  Serial.println("--- INICIANDO SERIE DE EXPERIMENTOS ---");
  Serial.print("Intensidad_Configurada_Hz: ");
  Serial.println(intensidadSonido);
  Serial.println("Prueba,Tiempo_Respuesta_us,Intensidad_Analogica_AO");
  // CICLO AUTOMÁTICO DE 5 PRUEBAS
  for (int numeroPrueba = 1; numeroPrueba <= totalPruebas; numeroPrueba++) {
   // 5 segundos de silencio
    noTone(pinBuzzer);
    delay(5000);
// Se activa el estímulo y el LED prende
    tone(pinBuzzer, intensidadSonido);
    digitalWrite(pinLED, HIGH);
    
    while(digitalRead(pinDigital) == LOW){
  // El tiempo se mide a partir de que el led integrado al sensor se apague
  // Nota: Si se queda congelado en tu monitor, cambia HIGH por LOW según la calibración de tu módulo
    TiempoInicio= micros();

    while(digitalRead(pinDigital)==HIGH){
    }
  }
    // Se apaga el estímulo y el LED
      noTone(pinBuzzer);
      digitalWrite(pinLED, LOW);

    TiempoFinal= micros();
// Cálculo de las variables físicas
    TiempoTotal= TiempoFinal - TiempoInicio;
    analogVal = analogRead(pinAnalogico);
// Imprimimos la fila CSV
    Serial.print(numeroPrueba);
    Serial.print(",");
    Serial.print(TiempoTotal); 
    Serial.print(",");
    Serial.println(analogVal);
  }
  Serial.println("--- EXPERIMENTO FINALIZADO ---");
  Serial.println("Puedes cambiar el valor de 'intensidadSonido' en el código para otra tanda de datos.");
}


void loop() {
// Esta función se deja en vació para que el experimento se reproduzca únicamente 5 veces
}
