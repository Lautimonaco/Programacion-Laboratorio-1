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

/*void agregarPartido (ePartido* listaPartido, int tam)
{
    int CodigoPartido[4] = {1,2,3,4};
    int CodigoEquipoVis[4][31] = {12,23,34,23};
    int CodigoEquipoLoc[4][31] = {65,45,34,21};
    int CodigoReferi[4][31] = {10,20,30,40};

    int i;
    for (i=0; i<4; i++)
    {
        listaPartido[i].CodigoPartido = CodigoPartido[i];
        strcpy (listaPartido[i].CodigoPartido, CodigoPartido[i]);
        strcpy (listaPartido[i].CodigoEquipoVis, CodigoEquipoVis[i]);
        strcpy (listaPartido[i].CodigoEquipoLoc, CodigoEquipoLoc[i]);
        strcpy (listaPartido[i].CodigoReferi, CodigoReferi[i]);
    }
}*/


int inicializarPartidos(ePartido listaPartido[], int cant)
{
    int i;
    int j=-1;
    if(cant > 0 && listaPartido != NULL)
    {
        j = 0;
        for(i=0; i<cant; i++)
        {
            listaPartido[i].estado = LIBRE;
        }
    }
    return j;
}

int buscarPartidosLibre(ePartido listaPartido[],int cant)
{
    int i;
    int j = -1;
    for(i=0; i<cant; i++)
    {
        if(listaPartido[i].estado == LIBRE)
        {
            j = i;
            break;
        }
    }
    return j;
}

int cargarPartido(ePartido listaPartido[], eEquipo listaEquipos[], eReferi listaReferi, int cantP, int cantE, int cantR, int cant, int ID)
{
    int i;
    int j;
    int r1 = -1;
    int r = -1;

    i = buscarPartidosLibre(listaPartido, cantP);

    if(i != 1)
    {
        listaPartido[i].CodigoEquipoLoc = getInt("Ingrese el codigo del equipo local: ");

        listaPartido[i].CodigoEquipoVis = getInt("Ingrese el codigo del equipo visitante: ");

        listaPartido[i].CodigoReferi = getInt("Ingrese el codigo del referi: ");


        listaPartido[i].CodigoEquipoVis = getInt("Ingrese el codigo del equipo visitante : ");
        listaPartido[i].CodigoReferi = getInt("Ingrese el codigo del referi : ");
        printf("Ingrese la fecha del partido: \n");
        listaPartido[i].fechaPartido.dia = getInt("Dia: ");
        listaPartido[i].fechaPartido.mes = getInt("Mes: ");
        listaPartido[i].fechaPartido.anio = getInt("Anio: ");
        listaPartido[i].codigo = ID;
        listaPartido[i].estado = OCUPADO;
        listaPartidoP[i].codigo = ID;
        listaPartido[i].estado = OCUPADO;
    }
    return r;
}


void MostrarPartido(ePartido Partido)
{
    printf("%03d \t %20d \t %20d \t %03d \t  %02d/%02d/%4d\n", Partido.codigo, Partido.CodigoEquipoLoc, Partido.CodigoEquipoVis, Partido.CodigoReferi, Partido.fechaPartido.dia, Partido.fechaPartido.mes, Partido.fechaPartido.anio);
}


void MostrarListaPartidos(ePartido listaPartidos, int cant)
{
    int i;
    printf("CODIGO  \t  COD. VISITANTE  \t  COD. LOCAL  \t  COD. REFERI  \t   FECHA NACIMINETO \n\n");
    for(i=0; i<cant; i++)
    {
        if(listaPartidos[i].estado == OCUPADO)
        {
            MostrarPartido(listaPartidos[i]);
        }
    }
}

void OrdenarPartidosFecha(ePartido listaPartidos[], int cant)
{
    ePartido auxPartidos;
    int i;
    int j;
    int retorno = -1;

    if(cant > 0 && listaPartidos != NULL)
    {
        for(i=0; i<cant-1; i++)
        {
            for(j=i+1; j<cant; j++)
            {
                if(listaPartidos[i].fechaPartido.anio > listaPartidos[j].fechaPartido.anio)
                {
                    auxPartidos = listaPartidos[i];
                    listaPartidos[i] = listaPartidos[i];
                    listaPartidos[j] = auxJugador;
                }
            }
        }
        retorno = 0;
    }
    return retorno;
}


