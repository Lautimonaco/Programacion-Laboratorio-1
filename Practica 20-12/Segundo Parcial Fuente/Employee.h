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
}Employee;

Employee* employee_new();

Employee* employee_newParametros(char*,char*,char*,char*,char*,char*,char*,char*);

void employee_delete();

int setIdVuelo(Employee* this,int int1);

int setIdAvion(Employee* this,int int1);

int setIdPiloto(Employee* this,int int1);

int setCantPasajeros(Employee* this,int int1);

int setHoraDespegue(Employee* this,int int1);

int setHoraLlegada(Employee* this,int int1);

int setFecha(Employee* this,char* char1);

int setDestino(Employee* this,char* char1);

int getIdVuelo(Employee* this,int* int1);

int getIdAvion(Employee* this,int* int1);

int getIdPiloto(Employee* this,int* int1);

int getCantPasajeros(Employee* this,int* int1);

int getHoraDespegue(Employee* this,int* int1);

int getHoraLlegada(Employee* this,int* int1);

int getFecha(Employee* this,char* char1);

int getDestino(Employee* this,char* char1);

int filtrar(void*);

int compararChars(void* , void* );

int compararInts(void*,void*);

int employee_findById(Employee*,LinkedList*);

void employee_showOneEmployee(LinkedList*,int);

#endif // employee_H_INCLUDED
