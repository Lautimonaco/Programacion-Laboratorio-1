#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Arrays.h"
#define TAM 3 //tamaño del array

int main()
{
    int edades[TAM];   //cantidad de edades
    char nombres[TAM][50]; //cantidad y tamaño del char

    CargarDatos(edades, nombres);
    MostrarDatos(edades, nombres);

    return 0;
}

///Validar solo letras, validar solo numeros, validar alfanumerico
