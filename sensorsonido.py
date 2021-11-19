#-----------------------------------------
# sensorsonido.py
#-----------------------------------------
# Muestra la captura de datos del sensor de
# voz/sonido KY-030 y los guarda en un archivo
# .JSON.
#-----------------------------------------
# Universidad del Valle de Guatemala
# CC3056-10 Programación de microprocesadores
# Proyecto Microprocesadores grupo 6
# integrantes: 
# Marco Jurado - 20308
# Jose Auyon - 
# Andres de la Roca - 20332
#-----------------------------------------

import time
import json
import random
import RPI.GPIO as GPIO

#Setup del GPIO de la Raspy
canalAnalogo = No. de pin de la raspy en el que se conecta el output del sensor
#canalDigital =
GPIO.setmode(GPIO.BCM)
GPIO.setup(canalAnalogo, GPIO.IN)


dictMedicion = {
    "Datos_Sensor":[]
}

def write_json(datos_nuevos, filename="data.json"):
    with open(filename, 'w') as fp:
        json.dump(datos_nuevos, fp) 
    

try:
    while True:
        sonido = GPIO.input(canalAnalogo)

        """dictMedicion["Datos_Sensor"].append({
            "Unidad de Medida Sonido": str(sonido) + " Placeholder ",
        })"""


        #print(dictMedicion)
        print("Valor de sonido: " + str(sonido))
        #write_json(dictMedicion)
        input("Presione cualquier input y enter para obtener otra medicion")
        #time.sleep(10)
finally:
    GPIO.cleanup()