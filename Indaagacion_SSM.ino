const int pinLED = 13;          // LED integrado en la placa Arduino
const int pinDigital = 7;       // Conectado al pin DO del sensor
const int pinAnalogico = A0;    // Conectado al pin AO del sensor
const int pinBuzzer = 8;

int numeroPrueba= 1;
int analogVal;
const int totalPruebas = 5;
const int intensidadSonido = 10000;

unsigned long TiempoInicio = 0;
unsigned long TiempoFinal = 0;
unsigned long TiempoTotal = 0;

void setup() {
  pinMode(pinLED, OUTPUT);       
  pinMode(pinDigital, INPUT);    
  pinMode(pinBuzzer, OUTPUT);
  
  Serial.begin(9600);            
  
  Serial.println("--- INICIANDO SERIE DE EXPERIMENTOS ---");
  // Esta línea le permite a programas como Excel o Python graficar tus rangos automáticamente
  Serial.print("Intensidad_Configurada_Hz: ");
  Serial.println(intensidadSonido);
  Serial.println("Prueba,Tiempo_Respuesta_us,Intensidad_Analogica_AO");
  // CICLO AUTOMÁTICO DE 5 PRUEBAS
  for (int numeroPrueba = 1; numeroPrueba <= totalPruebas; numeroPrueba++) {
    noTone(pinBuzzer);
    delay(5000);

    tone(pinBuzzer, intensidadSonido);
    digitalWrite(pinLED, HIGH);
    
    while(digitalRead(pinDigital) == LOW){
  
    TiempoInicio= micros();

    while(digitalRead(pinDigital)==HIGH){
    }
  }
      noTone(pinBuzzer);
      digitalWrite(pinLED, LOW);

    TiempoFinal= micros();

    TiempoTotal= TiempoFinal - TiempoInicio;
    analogVal = analogRead(pinAnalogico);

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

}