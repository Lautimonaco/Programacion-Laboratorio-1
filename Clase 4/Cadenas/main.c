#include <stdio.h>
#include <stdlib.h>

int main()
{
    char palabra[10];
    printf("Ingrese una palabra: ");
    gets(palabra);  //%s: le indicamos que se guarda una cadena
                    //scanf: solo guarda una palabra hasta un espacio
                    //gets: funcion que sirve para guardar cadenas de caracteres
    printf("%s", palabra);
    return 0;
}
