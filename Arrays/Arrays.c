#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Arrays.h"
#define TAM 3

void CargarDatos(int edad[], char nombre[][50])
{
    int i;

    for(i=0; i<TAM; i++)  ////cargar hasta 3 datos
    {
        printf("Ingrese la edad: ");
        scanf("%d", &edad[i]);

        printf("Ingrese el nombre: ");
        fflush(stdin);
        scanf("%s", &nombre[i]);

    }
}



void MostrarDatos(int edad[], char nombre[][50])
{
    int i;

    for (i=0; i<TAM; i++)
    {
        printf("\nLa edad es: %d \n", edad[i]);
        printf("\nEl nombre es: %s \n", nombre[i]);
    }

}

void cargarNombres (char nombre[][50], int cantidad)
{
    int i;
    for(i=0; i<cantidad; i++)
    {
        //atropy(nombre[i],cantidad[1]);
        scanf("%s", &nombre[i]);
    }
    scanf("Alfredo, Julio, Felipe, Carlos, %s /n", nombre[i]);
}

