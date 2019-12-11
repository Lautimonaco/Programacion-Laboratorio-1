#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
#include "LinkedList.h"
#include <string.h>
#include <stdio.h>
#include <conio.h>
typedef struct
{
    int idVuelo;
    int idAvion;
    int idPiloto;
    char fecha[50];
    char destino[50];
    int cantPasajeros;
    int horaDespegue;
    int horaLlegada;
}sVuelo;

sVuelo* nuevoVuelo();
sVuelo* vuelo_newParametros(char*,char*,char*,char*,char*,char*,char*,char*);
void employee_delete();

int setIdVuelo(sVuelo* this,int int1);
int setIdAvion(sVuelo* this,int int1);
int setIdPiloto(sVuelo* this,int int1);
int setCantPasajeros(sVuelo* this,int int1);
int setHoraDespegue(sVuelo* this,int int1);
int setHoraLlegada(sVuelo* this,int int1);
int setFecha(sVuelo* this,char* char1);
int setDestino(sVuelo* this,char* char1);

int getIdVuelo(sVuelo* this,int* int1);
int getIdAvion(sVuelo* this,int* int1);
int getIdPiloto(sVuelo* this,int* int1);
int getCantPasajeros(sVuelo* this,int* int1);
int getHoraDespegue(sVuelo* this,int* int1);
int getHoraLlegada(sVuelo* this,int* int1);
int getFecha(sVuelo* this,char* char1);
int getDestino(sVuelo* this,char* char1);

int contadorPasajerosTotal(void*);
int contadorPasajerosIrlanda(void*);

int filtrarVuelosCortos(void*);
int filtrarVuelosPortugal(void*);
int filtrarAlexLifeson(void*);

int compararChars(void* , void* );
int compararInts(void*,void*);

int employee_findById(sVuelo*,LinkedList*);
void showUnVuelo(LinkedList*,int);

#endif // employee_H_INCLUDED
