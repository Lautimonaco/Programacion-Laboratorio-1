#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Equipos.h"
#include "Jugadores.h"
#include "Referi.h"
#include "Partido.h"
#include "FuncionesGet.h"

#define MAX 1000


int main()
{
    eEquipo listaEquipos[MAX];
    eJugadores listaJugadores[MAX];
    eReferi listaReferi[MAX];
    ePartido listaPartido[MAX];

    char opcion='n';

    do
    {
        system("cls");
        printf("BIENVENIDO A LA BIBLIOTECA\n\n");
        printf("1 - EQUIPOS\n");
        printf("2 - JUGADORES\n");
        printf("3 - REFERI\n");
        printf("4 - PARTIDO\n");
        printf("5 - LISTAR EQUIPOS\n");
        printf("6 - LISTAR JUGADORES\n");
        printf("7 - SALIR\n");

        printf("Debe elegir una opcion a realizar: ");
        fflush(stdin);
        scanf("%c", &opcion);

        while (opcion!='1' && opcion!='2' && opcion!='3' && opcion!='4' && opcion!='5' && opcion!='6' && opcion!='7')
        {
            printf("Error, la opcion es incorrecta!\n\n");
            printf("Elija una opcion: ");
            fflush(stdin);
            scanf("%c", &opcion);
        }

        switch (opcion)
        {
        case '1':


            break;

        case '2':


        case '3':


        case '4':


        case '5':


        case '6':
            break;


        case '7':
            opcion = '7';
            printf("\nSaliendo del programa...\n");
            break;

        default:
            printf("Erorr, Ingrese una opcion correcta del 1 al 5");
        }

        system("pause");
        system("cls");
    }

    while (opcion!='7');
    system("cls");
    printf("\nSaliendo del programa...\n");
    return 0;
}
