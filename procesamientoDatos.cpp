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
#include <fstream>
#include <iostream>
//#include <vector>
#include <string.h>
#include <string>

using namespace std;

int main(int argc, char* argv[]) 
{
    ifstream ip("data.csv");

    if(!ip.is_open()) std::cout << "ERROR: No se encontro el archivo" << "\n" ;

    string dato;

    while(ip.good()){
        getline(ip, dato, ' ');
    }
    
    ip.close();
    string numeroLeds;
    
    numeroLeds = dato;

    int contadorPruebas = 0;
    for(int i = 0; i < dato.size(); i++)
    {
        contadorPruebas++;
        printf("\nPrueba %d\n", contadorPruebas);
        float led1V= 0;
        float led2V= 0;
        float led3V= 0;
        
        float led1_amp= 0; 
        float led2_amp=0;
        float led3_amp= 0;
        char valorComparable = dato[i];
        if(valorComparable == '0'){
          led1V= 0;
          led2V= 0;
          led3V= 0;
          
          led1_amp= 0; 
          led2_amp=0;
          led3_amp= 0;
        } else if (valorComparable == '1') {
          led1V= 1.7;
          led1_amp= 0.3;

          led2V= 0;
          led3V= 0;
          led2_amp=0;
          led3_amp= 0;
        } else if (valorComparable == '2') {
          led1V = 1.7;
          led2V = 1.8;
          led1_amp= 0.3; 
          led2_amp=0.3;
          
          led3V= 0;
          led3_amp= 0;
        } else if (valorComparable == '3') {
          led1V= 1.7;
          led2V= 1.8;
          led3V= 1.6;
          led1_amp= 0.3; 
          led2_amp=0.3;
          led3_amp= 0.3;
        }

        float voltaje= led1V+led2V+led3V;
        printf("El consumo en voltios de las leds es %f\n", voltaje);
        
        float amperaje= led1_amp+led2_amp+ led3_amp;
        printf("El amperaje de las leds es %f\n", amperaje);

        float poder= voltaje*amperaje;
        printf("El poder en watts es %.2f watts\n", poder);

        int diario= (60*60*24);
        int semanal= (7*24*60*60);
        int mensual= (31*24*60*60);
        int anual=  (365*24*60*60);
        
        int consumo_minutoW = 0;
        int consumo_diarioW = 0;
        int consumo_semanalW = 0;
        int consumo_mensualW = 0;
        int consumo_anualW = 0;

        float consumo_minutoKhw= 0;
        float consumo_diarioKhw= 0;
        float consumo_semanalKhw= 0;
        float consumo_mensualKhw= 0;
        float consumo_anualKhw = 0;

        float kilo_Watts= 1000;
        #pragma omp sections
        {
            #pragma omp section
            {
                #pragma omp critical
                {
                    consumo_minutoW = poder*60;
                    consumo_diarioW= poder * diario;
                    consumo_semanalW=poder*semanal;
                    consumo_mensualW= poder* mensual;
                    consumo_anualW= poder* anual;
                }   
            } 
            #pragma omp section
            {
                #pragma omp critical 
                {
                    consumo_minutoKhw= consumo_minutoW/kilo_Watts;
                    consumo_diarioKhw= consumo_diarioW/kilo_Watts;
                    consumo_semanalKhw= consumo_semanalW/kilo_Watts;
                    consumo_mensualKhw= consumo_mensualW/kilo_Watts;
                    consumo_anualKhw = consumo_anualW/kilo_Watts;
                }
            }     
        }     
        cout<<"\nEl consumo por minuto es de "<<consumo_minutoW<<" KWhw";
        cout<<"\nEl consumo por diario es de "<<consumo_diarioKhw<<" KWhw";
        cout<<"\nEl consumo por semanal es de "<<consumo_semanalKhw<<" KWhw";
        cout<<"\nEl consumo por mensual es de "<<consumo_mensualKhw<<" KWhw";
        cout<<"\nEl consumo por anual es de "<<consumo_anualKhw<<" KWhw";
        cout<<"\n";
        i++;
    }
    return 0;
  }

