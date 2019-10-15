#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LIBRE 0
#define OCUPADO 1


typedef struct
{
    int codigo;
    char nombre[51];
    char localidad[33];
    int estado;
}eEquipo;


int inicializarEquipos(eEquipo[], int);

int buscarEquiposLibre(eEquipo[],int);

int CargarEquipo(eEquipo[], int, int);

void MostrarEquipo(eEquipo[]);

void MostrarListaEquipos(eEquipo[], int);

void OrdenarEquiposNombre(eEquipo[], int);
