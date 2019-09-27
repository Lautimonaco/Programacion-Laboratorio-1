#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "ArrayEmployees.h"
#define MAX 1000   //Se podra ingresar hasta 1000 empleados


int main()
{
    void initEmployees(Employee arrayEmployees[],int cantidadDeElementos,int valor);
    int addEmployees(Employee arrayEmployees[],int cantidadDeElementos,int valor);
    //void CargarEmpleados(Employee arrayPersonas[], int cantidad);

    Employee arrayEmployees[MAX];
    Employee auxiliarCliente;

    char auxiliarNombreStr[MAX];
    char auxiliarApellidoStr[MAX];
    char auxiliarIDStr[MAX];
    int auxiliarID;

    int indiceLugarLibre;
    int indiceResultadoBusqueda;
    int opcion = 0;

    int i,j;

    initEmployees(arrayEmployees,MAX,-1); //Se indica con -1 que esa posicion esta vacia

    while(opcion != 5)
    {
         opcion = TomarEntero("\n1 - Ingresar empleado\n2 - Modificar\n3 - Bajas de empleados\n4 - Ordenar\n5 - Salir\n\n");
         switch(opcion)
         {
            case 1:
                system("cls");
                indiceLugarLibre = addEmployees(arrayEmployees,MAX,-1);
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

                if(addEmployees(arrayEmployees,MAX,auxiliarID) != -1)
                {
                    printf("\n\nEl ID ya existe!\n");
                    break;
                }


                strcpy(arrayEmployees[indiceLugarLibre].name,auxiliarNombreStr);
                strcpy(arrayEmployees[indiceLugarLibre].lastname,auxiliarApellidoStr);
                arrayEmployees[indiceLugarLibre].ID = auxiliarID;

                break;

            case 2:
                system("cls");
                if (!getStringNumeros("Ingrese el ID a modificar: ",auxiliarIDStr))
                {
                    printf ("El ID debe ser numerico\n");
                    break;
                }

                indiceResultadoBusqueda = addEmployees(arrayEmployees,MAX,atoi(auxiliarIDStr));

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

                strcpy(arrayEmployees[indiceResultadoBusqueda].name,auxiliarNombreStr);
                strcpy(arrayEmployees[indiceResultadoBusqueda].lastname,auxiliarApellidoStr);

                break;

            case 3:
                system("cls");
                if (!getStringNumeros("Ingrese el ID a dar de baja: ",auxiliarIDStr))
                {
                    printf ("El ID debe ser numerico\n");
                    break;
                }
                indiceResultadoBusqueda = addEmployees(arrayEmployees,MAX,atoi(auxiliarIDStr));

                if(indiceResultadoBusqueda == -1)
                {
                    printf("\n\No se encuentra el ID\n");

                }else
                {
                   printf("\n\nID dado de baja con exito\n");
                }
                break;
                arrayEmployees[indiceResultadoBusqueda].ID=-1;
                break;

            case 4:
                system("cls");
                printf("\nORDENADO!\n");

                for(i=0; i < MAX - 1; i++)
                {
                    if(arrayEmployees[i].ID == -1)
                    {
                       continue;
                    }
                    for(j=i+1; j < MAX; j++)
                    {
                        if(arrayEmployees[j].ID == -1)
                        {
                            continue;
                        }
                        if(strcmp(arrayEmployees[i].lastname,arrayEmployees[j].lastname) > 0)
                        {
                            auxiliarCliente = arrayEmployees[j];
                            arrayEmployees[j] = arrayEmployees[i];
                            arrayEmployees[i] = auxiliarCliente;
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
