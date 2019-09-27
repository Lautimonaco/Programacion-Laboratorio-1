#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>

/*
-altura de la mujer mas vieja
-altura de la persona mas joven
-sexo de la persona mas alta
-edad del hombre mas bajo
-promedio de edades
-promedio de altura de hombres*/

int main()
{
    char seguir;
    float altura;  ///(float: numero decimal)
    int edad;      ///(int: numero entero)
    char sexo;    ///(char : guardar un caracter)
    float alturamaximamujer;
    float alturamaximahombre;
    float alturajoven;
    char sexoalto;
    int minimaedad;
    float alturamayor;
    int edadhombrebajo;
    float minimaaltura;
    int edadmujermaxima = 0;
    int edadhombremaxima = 0;
    int acumuladoredad = 0;
    int contadoredad = 0;
    float promedioedad;
    int cantidadhombres = 0;
    int cantidadedad = 0;
    int flagvieja = 0;
    int flagjoven = 0;
    int flagenano = 0;
    float alturaalta = 0;
    int flagalta = 0;
    float alturahombres;
    int contadorhombres = 0;
    float promedioaltura;


    do
    {
        printf("Ingrese la edad: ");
        scanf("%d",&edad);

        while(edad < 0 || edad > 100)
        {
            printf("Error, reingrese una edad correcta: ");  ///Valido la edad
            scanf("%d",&edad);
        }


        printf("Ingrese la altura: ");
        scanf("%f",&altura);

        while(altura < 1 || altura > 2)
        {
            printf("Error, reingrese una altura correcta: ");  ///Valido la altura
            scanf("%f",&altura);
        }
        ///Setbuff (en linux)
        fflush(stdin);         ///Limpia el buffer ,se utiliza antes del char para que no tome teclas como un caracter
        printf("Ingrese el sexo (f/m):");
        scanf("%c",&sexo);
        sexo = tolower(sexo); ///Convierte a minuscula (f, m)

        while(!(sexo == 'm' || sexo == 'f'))
        {
            printf("Error, ingrese un sexo correcto: ");  ///Valido el sexo
            scanf("%c",&sexo);
            sexo = tolower(sexo);
        }

        fflush(stdin);
        printf("\n Desea continuar? (s/n)");  ///Le informo si desea continuar
        scanf("%c", &seguir);             ///\n sirve para bajar al otro renglon



        if(sexo == 'f')  ///si es mujer
        {

            if(edad > edadmujermaxima || flagvieja == 0)
            {
                edadmujermaxima = edad;           ///la altura de la mujer mas vieja.
                alturamaximamujer = altura;
                flagvieja = 1;
            }
        }
        else     ///si es hombre
        {
            if(altura < minimaaltura || flagenano == 0)
            {
                minimaaltura = altura;
                edadhombrebajo = edad;         ///edad del hombre mas bajo
                flagenano = 1;
            }

        }

        if(altura > alturaalta || flagalta == 0)       ///sexo de la persona mas alta
        {
            alturaalta = altura;
            flagalta = 1;
            sexoalto = sexo;
        }


        if(edad < minimaedad || flagjoven == 0 )
        {
            minimaedad = edad;            ///la altura de la persona mas joven
            alturajoven = altura;
            flagjoven = 1;
        }

        if(sexo == 'm')
        {
            contadorhombres++;  ///cuento los hombres
        }

        contadoredad++;             ///Cuento las edades
        acumuladoredad = acumuladoredad + edad;  ///Acumulo edades

        alturahombres = alturahombres + altura;  ///Acumula la altura de hombres

    }
    while(seguir == 's');

    promedioaltura = (float) alturahombres / contadorhombres;  ///Promedio altura de hombres

    promedioedad = (float) acumuladoredad / contadoredad; ///Promedio se ingresa despues del while
    ///(float) = casteo para que el resultado se convierta en decimal.

    printf(" La altura de la mujer mas vieja es: %.2f",alturamaximamujer);    ///%.2f (elijo cuantos numeros despues del 0)
    printf("\n La altura de la persona mas joven es: %.2f",alturajoven);
    printf("\n El sexo de la persona mas alta es: %c",sexoalto);
    printf("\n La edad del hombre mas bajo es: %d",edadhombrebajo);
    printf("\n El promedio de edades es: %.2f",promedioedad);
    printf("\n El promedio de altura de los hombres es: %.2f",promedioaltura);

    return 0;
}

/*
Variables:
Int (numero)
char (caracteres)
float (numero decimales) (colocarlo con .)


%d (mostrar variable numero)
%f (mostrar variable float)
%c (mostrar variable char)

scanf("%d",&valorA);*/


/*getc(); (no imprime el caracter en pantalla y continua)
getche(); imprime el caracter en pantalla y continua)*/




