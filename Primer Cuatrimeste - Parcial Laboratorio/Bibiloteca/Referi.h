#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LIBRE 0
#define OCUPADO 1


typedef struct
{
    int codigo;
    char apellido[31];
    char nombre[31];
    char sexo;
    char eMail[31];
    eFecha fechaNac;
    int estado;
}eReferi;


int inicializarReferi(eReferi[], int);

int buscarReferiLibre(eReferi[],int);

int cargarReferi (eReferi[], int, int);

void MostrarReferi(eReferi[]);

void MostrarListaReferis(eReferi[], int);


