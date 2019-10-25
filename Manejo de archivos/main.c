#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/// https://mockaroo.com/ Generador random de datos

int main()
{
    FILE* pArchivos;

    char miNombre[50] = "Lautaro";

    //Crea el archivo en la carpeta del programa
    pArchivos = fopen("miNombre.txt","w");   //W = abrir  para guardar texto --- R = Leer el archivo solo texto --- Wv = Lectura binaria

    //pArchivos = fopen("miNombre.txt", "r");
    fgets(miNombre, 50, pArchivos);

    fprintf(pArchivos, "Mi nombre es %s", miNombre);  //Escribo en el archivo

    fclose(pArchivos);   //Cierra el archivo

    //printf("Mi nombre es: %s", miNombre); //Muestro en consola


    return 0;
}
