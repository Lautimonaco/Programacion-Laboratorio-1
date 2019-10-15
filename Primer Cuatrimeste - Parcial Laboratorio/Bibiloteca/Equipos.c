#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Equipos.h"
#include "Jugadores.h"
#include "Referi.h"
#include "Partido.h"
#include "FuncionesGet.h"

#define MAX 50
#define E 20
#define J 211
#define R 10
#define P 10

/*void agregarEquipo (eEquipo* listaEquipos, int tam)
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
 }*/


int inicializarEquipos(eEquipo listaEquipos[], int cant)
{
    int i;
    int j=-1;
    if(cant > 0 && listaEquipos != NULL)
    {
        j = 0;
        for(i=0; i<cant; i++)
        {
            listaEquipos[i].estado = LIBRE;
        }
    }
    return j;
}


int buscarEquiposLibre(eEquipo listaEquipos[],int cant)
{
    int i;
    int j = -1;
    for(i=0; i<cant; i++)
    {
        if(listaEquipos[i].estado == LIBRE)
        {
            j = i;
            break;
        }
    }
    return j;
}


int CargarEquipo(eEquipo listaEquipos[], int cant, int ID)
{
    int i;
    int r = -1;
    i = buscarEquiposLibre(listaEquipos, cant);

    if(i != -1)
    {
        printf("Ingrese el nombre del equipo : ");
        ingresarString(listaEquipos[i].nombre);
        r = esSoloLetras(listaEquipos[i].nombre);
        while(r == -2)
        {
            printf("Error, Reingrese el nombre: ");
            ingresarString(listaEquipos[i].nombre);
            r = esSoloLetras(listaEquipos[i].nombre);
        }

        printf("Ingrese la localidad del equipo: ");
        ingresarString(listaEquipos[i].nombre);
        r = esSoloLetras(listaEquipos[i].nombre);
        while(r == -2)
        {
            printf("Error, Reingrese la localidad: ");
            ingresarString(listaEquipos[i].nombre);
            r = esSoloLetras(listaEquipos[i].nombre);
        }

        r = 0;
        listaEquipos[i].codigo = ID;
        listaEquipos[i].estado = OCUPADO;
    }

    return r;
}

void MostrarEquipo(eEquipo Equipo)
{
    printf("%03d \t %20s \t %20s \n" Equipo.codigo, Equipo.nombre, Equipo.localidad);
}

void MostrarListaEquipos(eEquipo listaEquipos[], int cant)
{
    int i;
    printf("CODIGO \t\t\t   NOMBRE \t\t\t   LOCALIDAD \n\n");
    for(i=0; i<cant; i++)
    {
        if(listaEquipos[i].estado == OCUPADO)
        {
            MostrarEquipo(listaEquipos[i]);
        }
    }
}


void OrdenarEquiposNombre(eEquipo listaEquipos[], int cant)
{
    eEquipo auxEquipos;
    int i;
    int j;
    int retorno = -1;

    if(cant > 0 && listaEquipos != NULL)
    {
        for(i=0; i<cant-1; i++)
        {
            for(j=i+1; j<cant; j++)
            {
                if(strcmp(listaEquipos[i].nombre, listaEquipos[j].nombre) > 0)
                {
                    auxEquipos = listaEquipos[i];
                    listaEquipos[i] = listaEquipos[i];
                    listaEquipos[j] = auxEquipos;
                }
            }
        }
        retorno = 0;
    }
    return retorno;
}




