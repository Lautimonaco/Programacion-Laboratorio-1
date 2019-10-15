#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LIBRE 0
#define OCUPADO 1


typedef struct {
    int dia;
    int mes;
    int anio;
}eFecha;


typedef struct
{
    int codigo;
    int CodigoEquipo;
    char apellido[31];
    char nombre[31];
    char sexo;
    eFecha fechaNac;
    int estado;
}eJugadores;


int inicializarJugadores(eJugadores[], int);

int buscarJugadoresLibre(eJugadores[],int);

int cargarJugador(eJugadores [],eEquipo[],int, int, int);

void MostrarJugador(eJugadores);

void mostrarListaJugadores(eJugadores[], int);

void OrdenarJugadoresApellido(eJugadores[], int);

