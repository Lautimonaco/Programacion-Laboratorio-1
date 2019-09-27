#include <stdio.h>
#include <stdlib.h>

float calcular(float numuno, float numdos, float operacion);
float sumar(float numuno, float numdos);
float restar(float numuno, float numdos);
float multiplicar(float numuno, float numdos);
float dividir(float numuno, float numdos);
float pedirdato(float);

int main()
{

    printf("Ingrese que operacion desea hacer:\n 1- /suma");
    printf("\n 2- Resta: \n 3- Multiplicar: \n 4- Division:\n");
    ///float operacion = pedirdato();
    printf("Ingrese el primer numero");
    ///float numuno = pedirdato();
    printf("Ingrese el segundo numero");
    ///float numdos = pedirdato();

    calcular(1,1,2);
    calcular(3,7,1);
    calcular(10,2,4);
    calcular(2,3,3);
}


float sumar(numuno, numdos)
{
    float resultado;
    float suma = (numuno + numdos);
    return suma;
}

float restar(numuno, numdos)
{
    float resultado;
    float resta = (numuno - numdos);
    return resta;
}

float multiplicar(numuno, numdos)
{
    float resultado;
    float multiplicacion = (numuno * numdos);
    return multiplicacion;
}

float dividir(numuno, numdos)
{
    float resultado;
    float division = (numuno / numdos);
    return division;
}


float calcular(float numuno, float numdos, float operacion)
{
    float resultado;

    switch(operacion)
    {
    case 1:
        resultado = sumar;
        break;
    case 2:
        resultado = restar;
        break;
    case 3:
        resultado = multiplicar;
        break;
    case 4:
        resultado = dividir;
        break;
    }

    printf("\n%f",resultado);
}

/*
int sumar(int numero1, int numero2);

int main()
{
    int valor;
    valor = sumar(33,77);
    printf("La suma es %d", valor);
    return 0;
}

int sumar(int numero1, int numero2)
{
   int suma = (numero1 + numero2);
   return suma;
}
*/
