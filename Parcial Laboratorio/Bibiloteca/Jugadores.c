#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Equipos.h"
#include "Jugadores.h"
#include "Referi.h"
#include "Partido.h"
#include "FuncionesGet.h"

#define MAX 1000

void agregarJugadores (eJugadores* listaJugadores, int tam)
{
    int CodigoJugadores[4] = {1,2,3,4};
    char apellido[4][31] = {"Lopez", "Fernandez", "Fuez", "Gonzalez"};
    char nombre[4][31] = {"Luis","Fernando","Leandro","Lucas"};
    char sexo[4][31] = {"f", "m", "f", "m"};
    int mes[4]= {3,4,12,11};
    int dia[4]= {33,22,25,11};
    int anio[4]={100,101,105,106};

    int i;
    for (i=0; i<4; i++)
    {
        listaJugadores[i].CodigoJugadores = CodigoJugadores[i];
        strcpy (listaJugadores[i].apellido, apellido[i]);
        strcpy (listaJugadores[i].nombre, nombre[i]);
        strcpy (listaJugadores[i].sexo, sexo[i]);
    }
}

void mostrarJugadores(eJugadores* listaJugadores, int cantidad)
 {
    int i;
     for (i=0;i<cantidad;i++)
     {
        printf("\n Codigo Jugadores:    %d   \t", listaJugadores[i].CodigoJugadores);
        printf(" Apellido:    %c   \t", listaJugadores[i].apellido);
        printf(" Nombre:     %c   \t", listaJugadores[i].nombre);
        printf(" Sexo:    %c   \t", listaJugadores[i].sexo);
      }
 }
