#include <stdio.h>
#include <stdlib.h>

#define MAXIMO 100

float aplicarAumento(float valor, int porcentaje);

int main()
{
    aplicarAumento(500, 5);
}

float aplicarAumento(float valor, int porcentaje)
{
    float aumento;
    float sueldoactualizado;

    aumento = (valor * porcentaje) / 100;
    sueldoactualizado = valor + aumento;

    printf("El sueldo nuevo es %f", sueldoactualizado); //Deberia ir en el main ya que la funcion solo devuelve el valor no lo muestra
    return sueldoactualizado;
}



/*void contarVocales(char palabra[MAXIMO]);

int main
{
    contarVocales(palabra[MAXIMO]);
    return 0;
}

void contarVocales(char palabra[MAXIMO])
    {
        char palabra[MAXIMO];
        int vocales=0;
        int i;
        i=0;

        while (palabra!='\0')
        {
            if ((cadena=='a') ||(cadena=='e') ||(cadena=='i') ||(cadena=='o') ||(cadena=='u') ||
                    (cadena=='A') ||(cadena=='E') ||(cadena=='I') ||(cadena=='O') ||(cadena[i]=='U'))
                vocales++;
            i++;
        }
      printf("La palabra tiene: %d", vocales);

      return vocales;
    }

*/





/*void contarVocales(char palabra[]);

int main
{
    contarVocales(palabra["hola"]);
    return 0;
}


void contarVocales(char palabra[])
{
    int i;
    int vocales;

    for(int i=0; i< frasetamanio; i++)
    {
        switch(palabra[i])
        {
            case 'a': vocales[0]++;
            break;

            case 'e': vocales[1]++;
            break;

            case 'i': vocales[2]++;
            break;

            case 'o': vocales[3]++;
            break;

            case 'u': vocales[4]++;
            break;

        }
    }
    printf(" a: %d", vocales[0]);
    printf(" e: %d", vocales[1]);
    printf(" i: %d", vocales[2]);
    printf(" o: %d", vocales[3]);
    printf(" u: %d", vocales[4]);

   printf("la palabra tiene, %d vocales" vocales);

   return vocales;
}*/
