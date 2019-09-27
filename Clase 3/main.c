#include <stdio.h>
#include <stdlib.h>
#include "biblioteca.h" ///Incluyo mi biblioteca

int main()
{

    int edad = pedirEntero("Ingrese edad: ",1,200);  ///Parametros para validar ,1,100
    int legajo = pedirEntero("Ingrese legajo: ",0,2000);
    int nota = pedirEntero("Ingrese nota: ",1,10);
    int documento = pedirEntero("Ingrese documento: ",0,10000);

    printf("%d\n", edad);
    printf("%d\n", legajo);
    printf("%d\n", nota);
    printf("%d\n", documento);
    return 0;
}

///Trabajo practico entregado para viernes 6
