#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LIBRE 0
#define OCUPADO 1


typedef struct
{
    int codigo;
    int CodigoEquipoVis;
    int CodigoEquipoLoc;
    int CodigoReferi;
    eFecha fechaPartido;
}ePartido;

int inicializarPartidos(ePartido[], int);

int buscarPartidosLibre(ePartido[],int);

int cargarPartido(ePartido[], eEquipo[], eReferi[], int, int, int, int, int);

void MostrarPartido(ePartido[]);

void MostrarListaPartidos(ePartido[], int);

void OrdenarPartidosFecha(ePartido[], int);





