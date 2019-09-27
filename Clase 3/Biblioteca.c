#include "biblioteca.h" ///Se referencia con comillas porque no estan adentro de la carpeta include

int pedirEntero(char msj[], int min, int max)   ///[]ingreso cuantos caracteres quiero adentro del vector
{

    int numero;
    printf("%s", msj);   ///%s (para poder ver carateres)
    scanf("%d", &numero);
    while(numero<min || numero>max) ///Valido los datos
    {
        printf("ERROR, %s", msj);
        scanf("%d", &numero);
    }
    return numero;
}
