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

#define LIBRE 0
#define OCUPADO 1

/*void agregarJugadores (eJugadores* listaJugadores, int tam)
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
 }*/

int inicializarJugadores(eJugadores listaJugadores[], int cant)
{
    int i;
    int j=-1;
    if(cant > 0 && listaJugadores != NULL)
    {
        j = 0;
        for(i=0; i<cant; i++)
        {
            listaJugadores[i].estado = LIBRE;
        }
    }
    return j;
}

int buscarJugadoresLibre(eJugadores listaJugadores[],int cant)
{
    int i;
    int j = -1;
    for(i=0; i<cant; i++)
    {
        if(listaJugadores[i].estado == LIBRE)
        {
            j = i;
            break;
        }
    }
    return j;
}


int cargarJugadores(eJugadores listaJugadores[], eEquipo listaEquipos[], int Cantjugadores, int cantEquipos, int ID)
{
    int i;
    int r = -1;
    int r1 = -1;
    //int j;

    i = buscarJugadoresLibre(listaJugadores, Cantjugadores);

    if(i != -1)
    {
        printf("Ingrese el apellido del jugador: ");
        ingresarString(listaJugadores[i].apellido);
        r = esSoloLetras(listaJugadores[i].apellido);
        while(r == -2)
        {
            printf("Error, Reingrese el apellido: ");
            ingresarString(listaJugadores[i].apellido);
            r = esSoloLetras(listaJugadores[i].apellido);
        }

        printf("Ingrese el nombre del jugador: ");
        ingresarString(listaJugadores[i].nombre);
        r = esSoloLetras(listaJugadores[i].nombre);
        while(r == -2)
        {
            printf("Error, Reingrese el apellido: ");
            ingresarString(listaJugadores[i].nombre);
            r = esSoloLetras(listaJugadores[i].nombre);
        }

        printf("Ingrese el codigo de su equipo: ");
        scanf("%d", &listaJugadores[i].CodigoEquipo);

        printf("Ingrese sexo: ");
        getChar(listaJugadores[i].sexo);

        printf("Ingrese su fecha de nacimiento: \n");
        printf("Ingrese el dia: ");
        scanf("%d", &listaJugadores[i].fechaNac.dia);
        printf("Ingrese el mes: ");
        scanf("%d", &listaJugadores[i].fechaNac.mes);
        printf("Ingrese el año: ");
        scanf("%d", &listaJugadores[i].fechaNac.anio);

        listaJugadores[i].codigo = ID;
        listaJugadores[i].estado = OCUPADO;
    }

    return r;
}

void MostrarJugador(eJugadores Jugador)
{
    printf("%03d \t %20s \t %20s \t %03d \t %c  %02d/%02d/%4d\n", Jugador.codigo, Jugador.apellido, Jugador.nombre, Jugador.CodigoEquipo, Jugador.sexo, Jugador.fechaNac.dia, Jugador.fechaNac.mes, Jugador.fechaNac.anio);
}


void MostrarListaJugadores(eJugadores listaJugadores[], int cant)
{
    int i;
    printf("CODIGO \t   APELLIDO  \t   NOMBRE  \t   CODIGO EQUIPO  \t   SEXO \t   FECHA NACIMINETO \n\n");
    for(i=0; i<cant; i++)
    {
        if(listaJugadores[i].estado == OCUPADO)
        {
            MostrarJugador(listaJugadores[i]);
        }
    }
}

void OrdenarJugadoresApellido(eJugadores listaJugadores[], int cant)
{
    eJugadores auxJugador;
    int i;
    int j;
    int retorno = -1;

    if(cant > 0 && listaJugadores != NULL)
    {
        for(i=0; i<cant-1; i++)
        {
            for(j=i+1; j<cant; j++)
            {
                if(strcmp(listaJugadores[i].apellido, listaJugadores[j].apellido) > 0)
                {
                    auxJugador = listaJugadores[i];
                    listaJugadores[i] = listaJugadores[i];
                    listaJugadores[j] = auxJugador;
                }
            }
        }
        retorno = 0;
    }
    return retorno;
}


