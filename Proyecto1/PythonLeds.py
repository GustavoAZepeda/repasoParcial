import serial
import time

# Configurar la comunicación serial
ser = serial.Serial('COM3', 9600)  # Cambia 'COM3' por el nombre del puerto serial en tu sistema

# Secuencia ascendente y descendente de LEDs
while True:
    # Encender LEDs en secuencia ascendente
    for i in range(1, 7):
        ser.write(str(i).encode())  # Envía el número del LED como carácter ASCII
        time.sleep(1)  # Espera 1 segundo
    # Apagar LEDs en secuencia descendente
    for i in range(6, 0, -1):
        ser.write(str(i).encode())  # Envía el número del LED como carácter ASCII
        time.sleep(1)  # Espera 1 segundo

