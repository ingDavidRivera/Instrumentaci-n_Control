// Configuración de pines
const int LED_1 = 12; // Asocia el pin 12 al LED 1 (Amarillo)
const int LED_2 = 13; // Asocia el pin 13 al LED 2 (Rojo)
const int SetPointPin = 0; // Asocia el pin A0 con el Set Point
const int LDR = 1; // Asocia el pin A1 con la fotorresistencia
// Variables
int luz; // Variable que almacena el valor de la luz
int SetPoint; // Variable que almacena el valor del SetPoint

// Función que se ejecuta una única vez
void setup() {
  pinMode(LED_1, OUTPUT); // Configura LED 1 como salida
  pinMode(LED_2, OUTPUT); // Configura LED 2 como salida  
  Serial.begin(9600); // Inicializa la comunicación serial
}

// Función que se ejecuta mientras esté conectada la placa
void loop() {
  SetPoint = analogRead(SetPointPin); // Lee el valor del potenciómetro y lo almacena
  luz = analogRead(LDR); // Lee el valor de la fotorresistencia y lo almacena

  // Mapeos de las señales
  SP = map(SP, 0,1023,0,100);   // Lee la señal y la escala a valores entre 0 y 100
  luz = map(luz, 0,1023,0,100); // Lee la señal y la escala a valores entre 0 y 100

  /* Si la intensidad de luz es mayor que el Set Point, encienda
  el LED 1 y apague el LED 2
  */
  if(luz > SP){
    digitalWrite(LED_1, HIGH);
    digitalWrite(LED_2, LOW);
    Serial.println("La intensidad de luz es igual a: ");
    Serial.print(luz);
    Serial.println("El Set Point ingresado es igual a: ");
    Serial.print(SP);
  }else{
    digitalWrite(LED_1, LOW);    
    digitalWrite(LED_2, HIGH);
    Serial.println("La intensidad de luz es igual a: ");
    Serial.print(luz);
    Serial.println("El Set Point ingresado es igual a: ");
    Serial.print(SP);
  }
}
