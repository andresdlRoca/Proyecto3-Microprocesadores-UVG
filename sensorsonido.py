#-----------------------------------------
# sensorsonido.py
#-----------------------------------------
# Muestra la captura de datos del sensor de
# voz/sonido KY-030 y los guarda en un archivo
# .JSON.
#-----------------------------------------
# Universidad del Valle de Guatemala
# CC3056-10 Programacion de microprocesadores
# Proyecto Microprocesadores grupo 6
# integrantes: 
# Marco Jurado - 20308
# Jose Auyon - 201579
# Andres de la Roca - 20332
#-----------------------------------------

import time
import json
import random
import RPi.GPIO as GPIO
import csv

#Setup del GPIO de la Raspy

canalLed1 = 17
canalLed2 = 27
canalLed3 = 22
canalSensor = 23
#canalDigital =
GPIO.setmode(GPIO.BCM)
GPIO.setup(canalSensor, GPIO.IN) #Puerto que controla el sensor
GPIO.setup(canalLed1, GPIO.OUT)
GPIO.setup(canalLed2, GPIO.OUT)
GPIO.setup(canalLed3, GPIO.OUT)


dictMedicion = []

def write_csv(datos_nuevos, filename="data.csv"):
    
    with open(filename, 'w') as fp:
        writer = csv.writer(fp)
        for value in dictMedicion:
            writer.writerow(value)


        
def callback(canal):
    if GPIO.input(canal):
        print(" >> Sonido detectado!")        
    else:
        print(" >> Sonido detectado!")

GPIO.add_event_detect(canalSensor, GPIO.BOTH, bouncetime=300)
GPIO.add_event_callback(canalSensor, callback)

def main():
    print(" >> Bienvenido! \n")
    print(" >> A continuacion se activara el sensor por un aproximado de 6 segundos, dentro de este tiempo tienes que \n    generar sonidos (pueden ser aplausos) para encender el numero de leds que deseas. \n")
    print("        - dos o menos sonidos     : 1 led\n")
    print("        - entre dos y 4 sonidos   : 2 leds\n")
    print("        - mas de 4 sonidos        : 3 leds\n\n")
    input(" >> Presione cualquier tecla y/o enter para iniciar el conteo de input de sonido ")
    timer = 0
    ccc=0
    while timer <= 24:
        time.sleep(0.25)
        timer += 1
        if(GPIO.event_detected(canalSensor)):
            ccc += 1

    
    print("El sensor detecto sonido " + str(ccc) + " veces")

    dictMedicion.append(str(ccc))

    write_csv(dictMedicion)

    if ccc == 0:
        print(" >> No se han detectado sonidos :c")
    elif ccc <= 2:
        print(" >> Se ha encendido 1 led!")
        GPIO.output(canalLed1, GPIO.HIGH)
    elif ccc == 3 or ccc == 4:
        print(" >> Se ha encendido 2 leds!")
        GPIO.output(canalLed1, GPIO.HIGH)
        GPIO.output(canalLed2, GPIO.HIGH)
    elif ccc > 4:
        print(" >> Se ha encendido 3 leds!")
        GPIO.output(canalLed1, GPIO.HIGH)
        GPIO.output(canalLed2, GPIO.HIGH)
        GPIO.output(canalLed3, GPIO.HIGH)

    time.sleep(1)
    opcion = int(input(" >> Presione 1 para volver a correr el programa\n    Presione 2 para apagar todas las leds\n    Presione 3 para salir"))
    if opcion == 1:
        main()
    elif opcion == 2:
        GPIO.output(canalLed1, GPIO.LOW)
        GPIO.output(canalLed2, GPIO.LOW)
        GPIO.output(canalLed3, GPIO.LOW)
        main()
    elif opcion == 3:
        time.sleep(2)
        print(" >> Gracias ")
        GPIO.output(canalLed1, GPIO.LOW)
        time.sleep(2)
        print("por utilizar ")
        GPIO.output(canalLed2, GPIO.LOW)
        time.sleep(2)
        print("el programa!")
        GPIO.output(canalLed3, GPIO.LOW)
        GPIO.cleanup()
        print("  >> Creado por:            ")
        print("       -Andres de la Roca \n")
        print("       -Marco Jurado      \n")
        print("       -Jose Auyon      \n\n")
        print("       Hasta pronto!         ")
    else:
        print(" >> ERROR intente nuevamente.")
            

main()

