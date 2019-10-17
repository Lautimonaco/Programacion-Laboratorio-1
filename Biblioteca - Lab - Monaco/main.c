#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Equipos.h"

#define E 10
#define J 50
#define R 30
#define P 30

int main()
{
    eJugadores listaJugadores[J];
    eEquipos listaEquipos[E];
    eReferi listaReferi[R];
    ePartidos listaPartidos[P];

    int opcion;
    int idJugador=1;
    int idEquipos=1;
    int idReferi=1;
    int idPartidos=1;
    int r;
    char salir = 'n';

    if((inicializarEquipos(listaEquipos, E)==0 && inicializarJugadores(listaJugadores, J)==0) &&
            (inicializarReferees(listaReferi, R)==0 && inicializarPartidos(listaPartidos, P)==0))
    {
        do
        {
            printf("--------------BIENVENIDO--------------\n\n");
            printf("1  -  ALTA EQUIPO\n");
            printf("2  -  LISTAR EQUIPOS\n");
            printf("3  -  ALTA JUGADOR\n");
            printf("4  -  LISTAR JUGADORES\n");
            printf("5  -  ALTA REFERI\n");
            printf("6  -  ALTA PARTIDO\n");
            printf("7  -  LISTAR PARTIDOS\n");
            printf("8  -  MODIFICAR EQUIPO\n");
            printf("9  -  BAJA DE EQUIPO\n");
            printf("10 -  BAJA JUGADOR\n");
            printf("11 -  MOSTRAR JUGADORES POR EQUIPO\n");
            printf("12 -  REFERI CON MAS PARTIDOS DIRIGIDOS\n");
            printf("13 -  MOSTRAR JUGADORES POR NOMBRE\n");
            printf("14 -  EQUIPOS CON NOMBRE MAS LARGO.\n");
            printf("15 -  MOSTRAR PARTIDOS POR FECHA\n");
            printf("16 -  MOSTRAR EL EQUIPO MAS JOVEN\n");
            printf("17 -  SALIR\n");

            printf("Debe elegir una opcion a realizar: ");
            fflush(stdin);
            scanf("%d", &opcion);

            switch(opcion)
            {
            case 1:
                r=cargarEquipo(listaEquipos, E,idEquipos);
                if(r==0)
                {
                    printf("Equipo cargado con exito.\n");
                    idEquipos ++;
                }
                else
                {
                    printf("No hay mas espacio para cargar equipos.\n");
                }
                hardcodeoEquipos(listaEquipos, E);   //Comienza con los datos ingresados
                break;
            case 2:
                if(flagEquipos(listaEquipos, E)==0)
                {
                    ordenarEquiposPorNombre(listaEquipos, E);
                    mostrarListadoDeEquipos(listaEquipos, E);
                }
                else
                {
                    printf("No hay equipos cargados.\n");
                }
                break;
            case 3:
                r=cargarJugador(listaJugadores,listaEquipos,J,E,idJugador);
                if(r==0)
                {
                    printf("Jugador cargado exitosamente.\n\n");
                    idJugador++;
                }
                else
                {
                    printf("No hay mas espacio para cargar jugadores\n\n");
                }
                hardcodeoJugadores(listaJugadores, J);
                break;
            case 4:
                if(flagJugadores(listaJugadores, J)==0)
                {
                    ordenarJugadoresPorApellido(listaJugadores, J);
                    mostrarListadoDeJugadores(listaJugadores,J);
                }
                else
                {
                    printf("No hay jugadores cargados\n");
                }

                break;
            case 5:
                r= cargarReferi(listaReferi, R,idReferi);
                 if(r==0)
                 {
                     printf("Referi cargado\n");
                     idReferi ++;
                 }
                 else
                 {
                     printf("No hay mas espacio de referees\n");
                 }
                hardcodeoReferees(listaReferi, R);
                break;
            case 6:
                r = cargarPartido(listaPartidos,listaEquipos,listaReferi, P,E,R,idPartidos);
                if(r==0)
                {
                    printf("Partido cargado\n");
                    idPartidos ++;
                }
                else
                {
                    printf("No hay mas espacio de partidos.\n");
                }
                hardcodeoPartidos(listaPartidos, P);
                break;
            case 7:
                if(flagPartidos(listaPartidos, P) ==0)
                {
                    ordenarPartidosPorFecha(listaPartidos, P);
                    mostrarListadoDePartidos(listaPartidos, P);
                }
                else
                {
                    printf("No hay partidos cargados.\n");
                }
                break;
            case 8:
                if(flagEquipos(listaEquipos, E)==0)
                {
                    r = modificarEquipo(listaEquipos, E);
                    if(r == 0)
                    {
                        printf("Equipo modificado.\n");
                    }
                    else if(r==1)
                    {
                        printf("Accion cancelada.\n");
                    }
                    else
                    {
                        printf("No se encontro al equipo.\n");
                    }
                }
                else
                {
                    printf("No hay equipos cargados.\n");
                }
                break;
            case 9:
                if(flagEquipos(listaEquipos, E)==0)
                {
                    r = bajarEquipo(listaEquipos, E);
                    if(r == 0)
                    {
                        printf("Equipo eliminado.\n");
                    }
                    else if(r==1)
                    {
                        printf("Accion cancelada.\n");
                    }
                    else
                    {
                        printf("No se encontro al equipo.\n");
                    }
                }
                else
                {
                    printf("No hay equipos cargados.\n");
                }
                break;
            case 10:
                if(flagJugadores(listaJugadores, J)==0)
                {
                    r = bajarJugador(listaJugadores, J);
                    if(r == 0)
                    {
                        printf("Jugador eliminado con exito.\n");
                    }
                    else if(r==1)
                    {
                        printf("Accion cancelada.\n");
                    }
                    else
                    {
                        printf("No se encontro al Jugador.\n");
                    }
                }
                else
                {
                    printf("No hay jugadores cargados.\n");
                }
                break;
            case 11:
                if(flagJugadores(listaJugadores, J)==0 && flagEquipos(listaEquipos, E)==0)
                {
                    r = mostrarJugadoresPorEquipo(listaJugadores,listaEquipos, J,E);
                    if(r == 0)
                    {
                        printf("Jugadores listados con exito.\n");
                    }
                    else
                    {
                        printf("No se encontro al Jugador.\n");
                    }
                }
                else
                {
                    printf("Faltan jugadores o equipos a cargar.\n");
                }
                break;
            case 12:
                break;
            case 13:
                if(flagJugadores(listaJugadores, J)==0)
                {
                    r = mostrarJugadoresPorNombre(listaJugadores, J);
                    if(r==0)
                    {
                        printf("Jugadores mostrados exitosamente.\n");
                    }
                    else
                    {
                        printf("No se ha encontrado el nombre.\n");
                    }
                }
                else
                {
                    printf("No hay jugadores cargados.\n");
                }
                break;
            case 14:

                break;
            case 15:
                if(flagPartidos(listaPartidos,P)==0)
                {
                    r=mostrarPartidosPorFecha(listaPartidos,P);
                    if(r==0)
                    {
                        printf("Partidos listados exitosamente.\n");
                    }
                    else
                    {
                        printf("No se encontro ningun partido con esa fecha.\n");
                    }
                }
                else
                {
                    printf("No hay partidos cargados.\n");
                }
                break;
            case 16:
                promedioEdadesPorEquipo(listaJugadores,listaEquipos,J,E);
                break;

            default:
                printf("\nNo has elegido una opcion valida.\n\n");
                break;
            case 17:
                printf("Desea salir del programa?: SI:'s' --- NO:'n'  \n");
                fflush(stdin);
                scanf("%c",&salir);
                break;

            }
            system("pause");
            system("cls");
        }
        while(salir == 'n');
    }
    else
    {
        printf("\nNo fue posible iniciar el menu\n");
    }
    system("cls");
    printf("\nSaliendo del programa...\n");
    return 0;
}
