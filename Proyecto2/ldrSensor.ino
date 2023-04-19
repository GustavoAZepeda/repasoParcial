const int LRD_PIN = A0; // Pin analógico utilizado para el sensor LRD
const int BOTON_PIN = 13; // Pin digital utilizado para el botón
bool leerSensor = false; // Variable para indicar si se debe leer el sensor
bool ultimoEstadoBoton = false; // Variable para almacenar el último estado del botón

void setup() {
  Serial.begin(9600);
  pinMode(BOTON_PIN, INPUT_PULLUP); // Se establece el pin del botón como entrada con resistencia pull-up interna
}

void loop() {
  // Se lee el estado actual del botón
  bool estadoBoton = digitalRead(BOTON_PIN);

  // Si el estado del botón cambió, se actualiza la variable leerSensor
  if (estadoBoton != ultimoEstadoBoton && estadoBoton == LOW) {
    leerSensor = !leerSensor;
  }

  // Se almacena el estado actual del botón
  ultimoEstadoBoton = estadoBoton;

  // Si la variable leerSensor es true, se lee el valor del sensor LRD y se imprime
  if (leerSensor) {
    int valor = analogRead(LRD_PIN);
    Serial.println(valor);
  }
}
