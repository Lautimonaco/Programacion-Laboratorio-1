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

int main()
{
    eEquipo listaEquipos[MAX];
    eJugadores listaJugadores[MAX];
    eReferi listaReferi[MAX];
    ePartido listaPartido[MAX];

    int opcion;
    int idJugadores = 1;
    int idEquipos = 1;
    int idReferi = 1;
    int idPartidos = 1;
    int r;

    if((inicializarEquipos(listaEquipos, E)== 0 && inicializarJugadores(listaJugadores, J) == 0) &&
            (inicializarReferi(listaReferi, R) == 0 && inicializarPartidos(listaPartido, P)== 0))
    {

        do
        {
            system("cls");
            printf("BIENVENIDO!\n\n");
            printf("1 - ALTA EQUIPOS\n");
            printf("2 - LISTAR EQUIPOS\n");
            printf("3 - ALTAS JUGADORES\n");
            printf("4 - LISTAR JUGADORES\n");
            printf("5 - ALTA REFERI\n");
            printf("6 - ALTA PARTIDO\n");
            printf("7 - LISTAR PARTIDOS\n");
            printf("8 - SALIR\n");

            printf("Debe elegir una opcion a realizar: ");
            fflush(stdin);
            scanf("%d", &opcion);

            while (opcion!='1' && opcion!='2' && opcion!='3' && opcion!='4' && opcion!='5' && opcion!='6' && opcion!='7' && opcion!='8')
            {
                printf("Error, la opcion es incorrecta!\n\n");
                printf("Reingrese una opcion: ");
                fflush(stdin);
                scanf("%d", &opcion);
            }

            switch (opcion)
            {
            case '1':
                r = CargarEquipo(listaEquipos, E, idEquipos);
                if(r==0)
                {
                    printf("Equipo cargado con exito.\n");
                    idEquipos++;
                }
                else
                {
                    printf("No hay mas espacio para cargar equipos.\n");
                }
                break;

            case '2':
                OrdenarEquiposNombre(listaEquipos, E);
                MostrarListaEquipos(listaEquipos, E);
                MostrarEquipo(listaEquipos);
                break;

            case '3':
                r = cargarJugadores(listaJugadores, listaPartido, J, P, idJugadores);
                if(r==0)
                {
                    printf("Jugador cargado con exito.\n");
                    idJugadores++;
                }
                else
                {
                    printf("No hay mas espacio para cargar jugadores.\n");
                }
                break;

            case '4':
                OrdenarJugadoresApellido(listaJugadores, J);
                MostrarListaJugadores(listaJugadores, J);
                break;

            case '5':
                r = cargarReferi(listaReferi, R, idReferi);
                if(r==0)
                {
                    printf("Referi cargado con exito.\n");
                    idReferi++;
                }
                else
                {
                    printf("No hay mas espacio para cargar referis.\n");
                }
                break;

            case '6':
                r = cargarPartido(listaPartido, listaEquipos, listaReferi, P, E, R, J, idPartidos);
                if(r==0)
                {
                    printf("Partido cargado con exito.\n");
                    idPartidos++;
                }
                else
                {
                    printf("No hay mas lugar para cargar partidos.\n");
                }
                break;

            case '7':
                OrdenarPartidosFecha(listaPartido, P);
                MostrarListaPartidos(listaPartido, P);
                break;

            default:
                printf("Erorr, Ingrese una opcion correcta del 1 al 7.\n\n\n");
            }

            system("pause");
            system("cls");
        }

        while (opcion!='8');
    }
    else
    {
        printf("No se pudo iniciar el programa.\n");
    }
    system("cls");
    printf("\nSaliendo del programa...\n");
    return 0;
}
