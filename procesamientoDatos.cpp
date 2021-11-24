/**
 * Universidad del Valle de Guatemala
 * CC3056-10 Programación de microprocesadores
 * Proyecto Microprocesadores grupo 6
 * integrantes: 
 *      Marco Jurado 20308
 *      Andrés de la Roca 20332
 *      José Auyón 20157
 * 
 * Procesamiento de datos del sensor de valor
 * de sonido hacia decibeles.
 **/

#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <json/value.h>
#include <fstream>

int main(int argc, char* argv[]) 
{
    
    
    float led1V= 1.7
    float led2V= 1.8
    float led3V= 1.6

    float led1_amp= 0.3 
    float led2_amp=0.3
    float led3_amp= 0.3

    float voltaje= led1+led2+led3;
    printf("El consumo en voltios de las leds es %f", voltaje);
    
    float amperaje= led1_amp+led2_amp+ led3_amp
    printf("El amperaje de las leds es %f", amperaje);

    poder= voltaje*amperaje;
    printf("El poder en watts es %.2f watts\n", poder)

    int diario= (60*60*24);
    int semanal= (7*24*60*60);
    int mensual= (31*24*60*60);
    int anual=  (365*24*60*60);

    float kilo_Watts= 1000;

    int consumo_minutoW= poder*60;
    int consumo_diarioW= poder * diario;
    int consumo_ semanalW=poder*semanal;
    int consumo_mensualW= poder* mensual;
    int consumo_anualW= poder* anual;

    float consumo_minutoKhw= consumo_minutoW/kilo_Watts;
    float consumo_diarioKhw= consumo_diarioW/kilo_Watts;
    float consumo_semanalKhw= consumo_semanalW/kilo_Watts
    float consumo_mensualKhw= consumo_mensualW/kilo_Watts;
    float consumo_anualKhw = consumo_anualW/kilo_Watts;


    print("El consumo por minuto es de %d watts", consumo_minutoW + "o %f KWhw ", consumo_minutoKhw );
    print("El consumo diario es de %d watts", consumo_diarioW + "o %f KWhw ", consumo_diarioKhw );
    print("El consumo diario es de %d watts", consumo_diarioW + "o %f KWhw ", consumo_diarioKhw )

    return 0;
}
