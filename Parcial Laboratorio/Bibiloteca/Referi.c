#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Equipos.h"
#include "Jugadores.h"
#include "Referi.h"
#include "Partido.h"
#include "FuncionesGet.h"

#define MAX 1000

void agregarReferi (eReferi* listaReferi, int tam)
{
    int CodigoReferi[4] = {1,2,3,4};
    char apellido[4][31] = {"Lopez", "Fernandez", "Fuez", "Gonzalez"};
    char nombre[4][31] = {"Luis","Fernando","Leandro","Lucas"};
    char sexo[4][31] = {"f", "m", "f", "m"};
    char eMail[4][31]= {"asdsad@gmail.com","qwe@fmail.com","asd@gmail.com","asda@hotmail.com"};

    int i;
    for (i=0; i<4; i++)
    {
        listaReferi[i].CodigoReferi = CodigoReferi[i];
        strcpy (listaReferi[i].apellido, apellido[i]);
        strcpy (listaReferi[i].nombre, nombre[i]);
        strcpy (listaReferi[i].sexo, sexo[i]);
        strcpy (listaReferi[i].eMail, eMail[i]);
    }
}

