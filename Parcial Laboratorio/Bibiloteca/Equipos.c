#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Equipos.h"
#include "Jugadores.h"
#include "Referi.h"
#include "Partido.h"
#include "FuncionesGet.h"

#define MAX 1000

void agregarEquipo (eEquipo* listaEquipos, int tam)
{
    int CodigoEquipo[4] = {1,2,3,4};
    char nombre[4][51] = {"Equipo1", "Equipo2", "Equipo3", "Equipo4"};
    char localidad[4][33] = {"Lanus","Avellaneda","Banfield","Lomas"};

    int i;
    for (i=0; i<4; i++)
    {
        listaEquipos[i].CodigoEquipo = CodigoEquipo[i];
        strcpy (listaEquipos[i].nombre, nombre[i]);
        strcpy (listaEquipos[i].localidad, localidad[i]);
    }
}

void mostrarJugadores(eEquipo* listaEquipos, int cantidad)
 {
    int i;
     for (i=0;i<cantidad;i++)
     {
        printf("\n Codigo Equipo:    %d   \t", listaEquipos[i].CodigoEquipo);
        printf(" Nombre:     %c   \t", listaEquipos[i].nombre);
        printf(" localidad:    %c   \t", listaEquipos[i].localidad);
      }
 }






