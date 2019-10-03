#include <stdio.h>
#include <stdlib.h>
#include "Simulacro.h"

#define CANT 100
#define MAX 100

void IngresoPropietarios (Propietario Propietarios[MAX], int idMax)
{
    for(int i = 0; i < MAX; i++)
    {
            printf("Ingrese un nombre: ");
            fflush(stdin);
            scanf("%s", &Propietarios[i].nombre);

            printf("Ingrese un apellido: ");
            fflush(stdin);
            scanf("%s", &Propietarios[i].apellido);

            printf("Ingrese su edad: ");
            fflush(stdin);
            scanf("%d", &Propietarios[i].edad);

            break;
    }
}



/*
typedef struct {
    int dia;
    int mes;
    int anio;
}eFecha;

typedef struct {
    int id;
    char nombre[50];
    eFecha fechaNac;
}ePersona;


typedef struct {
    char patente[50];
    eFecha fechaIngreso;
    int horaIngreso;
    int horaSalida;
    int idDuenio;
}eVehiculo;
*/
