#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libreria.h"
#define T 6


int main()
{
    printf("\n Estacionamiento!\n");
    eVehiculo ListaDeAutos[T];
    ePersona ListadoDePersonas[T];
    hardcodePersonas(ListadoDePersonas, T);
    hardcodeoAutos(ListaDeAutos, 4);
    mostrarPersonas(ListadoDePersonas,T);
    mostrarVehiculos(ListaDeAutos, T, 10, 5);
    return 0;
}

