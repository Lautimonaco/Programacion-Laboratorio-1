#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Equipos.h"
#include "Jugadores.h"
#include "Referi.h"
#include "Partido.h"
#include "FuncionesGet.h"

#define MAX 1000

void agregarPartido (ePartido* listaPartido, int tam)
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
}
