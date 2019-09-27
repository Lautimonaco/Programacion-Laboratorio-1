#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "utn.h"
#define MAX 1000   //Se podra ingresar hasta 1000 empleados

void estaVacio(Persona arrayPersonas[],int cantidadDeElementos,int valor);
int BuscarPrimerDato(Persona arrayPersonas[],int cantidadDeElementos,int valor);

int main()
{
    Persona arrayPersonas[MAX];

    Persona auxiliarCliente;

    char auxiliarNombreStr[51];
    char auxiliarApellidoStr[51];
    char auxiliarIDStr[51];
    int auxiliarID;

    int indiceLugarLibre;
    int indiceResultadoBusqueda;
    int opcion = 0;

    int i,j;

    estaVacio(arrayPersonas,MAX,-1); //Se indica con -1 que esa posicion esta vacia

    while(opcion != 5)
    {
         opcion = TomarEntero("\n1 - Ingresar los datos del empleado\n2 - Modificar\n3 - Bajas de empleados\n4 - Ordenar\n5 - Salir\n\n");
         switch(opcion)
         {
            case 1:
                system("cls");
                indiceLugarLibre = BuscarPrimerDato(arrayPersonas,MAX,-1);
                if(indiceLugarLibre == -1)
                {
                    printf("\nNo quedan lugares libres!\n");
                    break;
                }

                printf("\nALTA DE EMPLEADOS:\n");
                if (!getStringLetras("Ingrese el nombre: ",auxiliarNombreStr))
                {
                    printf ("El nombre debe estar compuesto solo por letras\n");
                    break;
                }

                if (!getStringLetras("Ingrese el apellido: ",auxiliarApellidoStr))
                {
                    printf ("El apellido debe estar compuesto solo por letras\n");
                    break;
                }

                if (!getStringNumeros("Ingrese el ID: ",auxiliarIDStr))
                {
                    printf ("El ID debe ser numerico\n");
                    break;
                }
                auxiliarID = atoi(auxiliarIDStr);

                if(BuscarPrimerDato(arrayPersonas,MAX,auxiliarID) != -1)
                {
                    printf("\n\nEl ID ya existe!\n");
                    break;
                }


                strcpy(arrayPersonas[indiceLugarLibre].nombre,auxiliarNombreStr);
                strcpy(arrayPersonas[indiceLugarLibre].apellido,auxiliarApellidoStr);
                arrayPersonas[indiceLugarLibre].ID = auxiliarID;

                break;

            case 2:
                system("cls");
                if (!getStringNumeros("Ingrese el ID a modificar: ",auxiliarIDStr))
                {
                    printf ("El ID debe ser numerico\n");
                    break;
                }

                indiceResultadoBusqueda = BuscarPrimerDato(arrayPersonas,MAX,atoi(auxiliarIDStr));

                if(indiceResultadoBusqueda == -1)
                {
                    printf("\n\nID no encontrado\n");
                    break;
                }

                if (!getStringLetras("Ingrese el nombre: ",auxiliarNombreStr))
                {
                    printf ("El nombre debe estar compuesto solo por letras\n");
                    break;
                }

                if (!getStringLetras("Ingrese el apellido: ",auxiliarApellidoStr)) //Valido si ingresa letras
                {
                    printf ("El apellido debe estar compuesto solo por letras\n");
                    break;
                }

                strcpy(arrayPersonas[indiceResultadoBusqueda].nombre,auxiliarNombreStr);
                strcpy(arrayPersonas[indiceResultadoBusqueda].apellido,auxiliarApellidoStr);

                break;

            case 3:
                system("cls");
                if (!getStringNumeros("Ingrese el ID a dar de baja: ",auxiliarIDStr))
                {
                    printf ("El ID debe ser numerico\n");
                    break;
                }
                indiceResultadoBusqueda = BuscarPrimerDato(arrayPersonas,MAX,atoi(auxiliarIDStr));

                if(indiceResultadoBusqueda == -1)
                {
                    printf("\n\No se encuentra el ID\n");

                }else
                {
                   printf("\n\nID dado de baja con exito\n");
                }
                break;
                arrayPersonas[indiceResultadoBusqueda].ID=-1;
                break;

            case 4:
                system("cls");
                printf("\nORDENADO!\n");

                for(i=0; i < MAX - 1; i++)
                {
                    if(arrayPersonas[i].ID == -1)
                    {
                       continue;
                    }
                    for(j=i+1; j < MAX; j++)
                    {
                        if(arrayPersonas[j].ID == -1)
                        {
                            continue;
                        }
                        if(strcmp(arrayPersonas[i].apellido,arrayPersonas[j].apellido) > 0)
                        {
                            auxiliarCliente = arrayPersonas[j];
                            arrayPersonas[j] = arrayPersonas[i];
                            arrayPersonas[i] = auxiliarCliente;
                        }
                    }
                }
                break;
         }
    }

    system("pause");
    system("cls");
    return 0;
}


void estaVacio(Persona arrayPersonas[],int cantidadDeElementos,int valor)
{
    int i;
    for(i=0;i < cantidadDeElementos; i++)
    {
        arrayPersonas[i].ID = valor;
    }
}


int BuscarPrimerDato(Persona arrayPersonas[],int cantidadDeElementos,int valor)
{
    int i;
    for(i=0;i < cantidadDeElementos; i++)
    {
        if(arrayPersonas[i].ID == valor)
        {
            return i;
        }
    }
    return -1;
}


