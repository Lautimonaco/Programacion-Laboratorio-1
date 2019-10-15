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

/*void agregarReferi (eReferi* listaReferi, int tam)
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
}*/

int inicializarReferi(eReferi listaReferi[], int cant)
{
    int i;
    int j=-1;
    if(cant > 0 && listaReferi != NULL)
    {
        j = 0;
        for(i=0; i<cant; i++)
        {
            listaReferi[i].estado = LIBRE;
        }
    }
    return j;
}

int buscarReferiLibre(eReferi listaReferi[],int cant)
{
    int i;
    int j = -1;
    for(i=0; i<cant; i++)
    {
        if(listaReferi[i].estado == LIBRE)
        {
            j = i;
            break;
        }
    }
    return j;
}


int cargarReferi (eReferi listaReferi[], int cant, int ID)
{
int i:
    int r = -1;
    i = buscarReferiLibre(listaReferi, cant);


    if(i != -1)
    {
        printf("Ingrese el apellido del referi: ");
        getString(listaReferi[i].apellido);
        r = esSoloLetras(listaReferi.apellido);
        while(r == -2)
        {
            printf("Error, Reingrese el apellido del referi: ");
            getString(listaReferi[i].apellido);
            r = esSoloLetras(listaReferi.apellido);
        }

        printf("Ingrese el nombre del referi: ");
        getString(listaReferi[i].nombre);
        r = esSoloLetras(listaReferi.nombre);
        while(r == -2)
        {
            printf("Error, Reingrese el nombre del referi: ");
            getString(listaReferi[i].nombre);
            r = esSoloLetras(listaReferi.nombre);
        }

        printf("Ingrese el sexo: ");
        getChar(listaReferi[i].sexo);

        printf("Ingrese el e-Mail del referi: ");
        fflush(stdin);
        getString(listaReferi[i].eMail);
        r = esSoloLetras(listaReferi.eMail);
        while(r == -2)
        {
            printf("Error, Reingrese el e-Mail del referi: ");
            fflush(stdin);
            getString(listaReferi[i].eMail);
            r = esSoloLetras(listaReferi.eMail);
        }

        printf("Ingrese su fecha de nacimiento: \n");
        printf("Ingrese el dia: ");
        scanf("%d", &listaReferi[i].fechaNac.dia);
        printf("Ingrese el mes: ");
        scanf("%d", &listaReferi[i].fechaNac.mes);
        printf("Ingrese el año: ");
        scanf("%d", &listaReferi[i].fechaNac.anio);

        listaReferi[i].codigo = ID;
        listaReferi[i].estado = OCUPADO;
    }
return r:
           ;
}


void MostrarReferi(eReferi Referi)
{
    printf("%03d \t %20s \t %20s \t %03d \t %c  %02d/%02d/%4d\n", Referi.codigo, Referi.apellido, Referi.nombre, Referi.sexo, Referi.eMail, Referi.fechaNac.dia, Referi.fechaNac.mes, Referi.fechaNac.anio);
}


void MostrarListaReferis(eReferi listaReferis, int cant)
{
    int i;
    printf("CODIGO \t   APELLIDO  \t   NOMBRE  \t   SEXO  \t   E-MAIL  \t   FECHA NACIMINETO \n\n");
    for(i=0; i<cant; i++)
    {
        if(listaReferis[i].estado == OCUPADO)
        {
            MostrarReferi(listaReferis[i]);
        }
    }
}

