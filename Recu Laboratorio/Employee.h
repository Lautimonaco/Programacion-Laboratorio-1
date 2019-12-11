#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
#include "LinkedList.h"
#include <string.h>
#include <stdio.h>
#include <conio.h>
typedef struct
{
    int idBike;
    int idAvion;
    int idPiloto;
    char nombre[50];
    char tipo[50];
    int cantPasajeros;
    int horaDespegue;
    int horaLlegada;
}sbicicleta;

/*typedef struct
{
    int idBike;
    char nombre[50];
    char tipo[50];
    int tiempo;
}sbicicleta;*/

sbicicleta* nuevoVuelo();
sbicicleta* vuelo_newParametros(char*,char*,char*,char*,char*,char*,char*,char*);
void employee_delete();

int setidBike(sbicicleta* this,int int1);
int setIdAvion(sbicicleta* this,int int1);
int setIdPiloto(sbicicleta* this,int int1);
int setCantPasajeros(sbicicleta* this,int int1);
int setHoraDespegue(sbicicleta* this,int int1);
int setHoraLlegada(sbicicleta* this,int int1);
int setnombre(sbicicleta* this,char* char1);
int settipo(sbicicleta* this,char* char1);

int getidBike(sbicicleta* this,int* int1);
int getIdAvion(sbicicleta* this,int* int1);
int getIdPiloto(sbicicleta* this,int* int1);
int getCantPasajeros(sbicicleta* this,int* int1);
int getHoraDespegue(sbicicleta* this,int* int1);
int getHoraLlegada(sbicicleta* this,int* int1);
int getnombre(sbicicleta* this,char* char1);
int gettipo(sbicicleta* this,char* char1);

int contadorPasajerosTotal(void*);
int contadorPasajerosIrlanda(void*);

int filtrarVuelosCortos(void*);
int filtrarVuelosPortugal(void*);
int filtrarAlexLifeson(void*);

int compararChars(void* , void* );
int compararInts(void*,void*);

int employee_findById(sbicicleta*,LinkedList*);
void showUnVuelo(LinkedList*,int);

#endif // employee_H_INCLUDED
