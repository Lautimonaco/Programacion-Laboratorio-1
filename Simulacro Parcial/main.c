#include <stdio.h>
#include <stdlib.h>
#include "Simulacro.h"

#define MAX 100

int main()
{
    Propietario listapropietarios[MAX];

    Propietario ePropietarios[MAX];
    int salir = 1;
    char menu;
    int idMax;

    do
    {
        printf("Bienvenido!\n\n");
        printf("1) Ingresar un propietario. \n");
        printf("2) Modificar un propietario. \n");
        printf("3) Eliminar propietario. \n");
        printf("4) Ingresar vehiculo. \n");
        printf("5) Egresar vehiculo. \n");
        printf("6) Informar. \n");
        printf("7) Salir. \n");
        scanf("%c", &menu);


        switch(menu)
        {
        case '1':
            IngresoPropietarios (ePropietarios, idMax);
            idMax ++;
            break;

        case '7':
            salir = 0;
            printf("Saliendo del programa... \n");
            system("pause");

        default:
            printf("Error. Elija una opcion valida.\n");
            system("pause");
            break;
        }


        printf("hola");

        system("cls");

    }
    while(salir == 1);



}

/*
Informar:

a) Todas las personas ordenadas por nombre y a�o de nacimiento.
b) Todos los veh�culos ordenados por due�o y patente.
c) Cada auto con el nombre de su due�o.
d) Por cada due�o los autos que tiene estacionados.
e) Ingresar un due�o y mostrar todos sus autos.
f) Mostrar el total de la estad�a de cada auto, sabiendo que el valor hora es $100.
g) Mostrar cuanto deber� pagar cada due�o por todos sus autos estacionados.
h) Mostrar el/los due�os con m�s autos estacionados.*/
