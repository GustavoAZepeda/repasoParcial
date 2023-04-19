// Definición de pines
const int led1Pin = 2;
const int led2Pin = 3;
const int led3Pin = 4;
const int led4Pin = 5;
const int led5Pin = 6;
const int led6Pin = 7;

int ledNum = 0;  // Variable para almacenar el número del LED

void setup() {
  // Configuración de pines como salidas
  pinMode(led1Pin, OUTPUT);
  pinMode(led2Pin, OUTPUT);
  pinMode(led3Pin, OUTPUT);
  pinMode(led4Pin, OUTPUT);
  pinMode(led5Pin, OUTPUT);
  pinMode(led6Pin, OUTPUT);
  
  // Iniciar comunicación serial a 9600 bps
  Serial.begin(9600);
}

void loop() {
  if (Serial.available() > 0) {
    // Leer el comando enviado desde Python
    char comando = Serial.read();
    
    // Apagar todos los LEDs
    digitalWrite(led1Pin, LOW);
    digitalWrite(led2Pin, LOW);
    digitalWrite(led3Pin, LOW);
    digitalWrite(led4Pin, LOW);
    digitalWrite(led5Pin, LOW);
    digitalWrite(led6Pin, LOW);
    
    // Encender o apagar el LED correspondiente según el comando recibido
    if (comando >= '1' && comando <= '6') {
      ledNum = comando - '0';  // Convertir el carácter ASCII a número
      digitalWrite(ledNum + 1, HIGH);  // Encender el LED correspondiente
    }
  }
}
