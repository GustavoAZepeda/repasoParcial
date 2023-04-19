const int LRD_PIN = A0; // Pin analógico utilizado para el sensor LRD
const int BOTON_PIN = 13; // Pin digital utilizado para el botón
const int LED_PIN = 12; // Pin digital utilizado para el LED
bool leerSensor = false; // Variable para indicar si se debe leer el sensor
bool ultimoEstadoBoton = false; // Variable para almacenar el último estado del botón

void setup() {
  Serial.begin(9600);
  pinMode(BOTON_PIN, INPUT_PULLUP); // Se establece el pin del botón como entrada con resistencia pull-up interna
  pinMode(LED_PIN, OUTPUT); // Se establece el pin del LED como salida
}

void loop() {
  bool estadoBoton = leerEstadoBoton(); // Se lee el estado actual del botón
  actualizarLecturaSensor(estadoBoton); // Se actualiza la variable leerSensor
  leerSensorLRD(); // Se lee el valor del sensor LRD si corresponde
  controlarLED(); // Se controla el LED según el estado del sensor
}

bool leerEstadoBoton() {
  bool estado = digitalRead(BOTON_PIN);
  delay(50); // Se añade un pequeño retraso para evitar lecturas erróneas debido a rebotes del botón
  return estado;
}

void actualizarLecturaSensor(bool estadoBoton) {
  if (estadoBoton != ultimoEstadoBoton && estadoBoton == LOW) {
    leerSensor = !leerSensor;
  }
  ultimoEstadoBoton = estadoBoton;
}

void leerSensorLRD() {
  if (leerSensor) {
    int valor = analogRead(LRD_PIN);
    Serial.println(valor);
  }
}

void controlarLED() {
  digitalWrite(LED_PIN, !leerSensor); // Se enciende el LED cuando el sensor no está leyendo
}
