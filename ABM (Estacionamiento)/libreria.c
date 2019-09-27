#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libreria.h"
#define T 6

void hardcodeoAutos(eVehiculo listaAutos[], int cant)
{
    int i;
    char patente[][6]= {"AAA 111", "BBB 222", "AAA 222", "WWW 777", "GVJ120", "321AGH"};
    int dia = {26, 10, 5, 13};
    int mes = {9, 11, 5, 1};
    int anio = {2019, 2017, 2011, 2007};
    int horaIngreso[] = {10,9,8,11,10,11,9,7,7,14};
    int horaSalida[] = {11,11,11,12,14,15,12,10,11,17};
    int idPersona[]={101,106,100,106,101,101,100,105,106,106};

    for(i=0; i<cant; i++)
    {
        strcpy(listaAutos[i].patente,patente[i]);
        listaAutos[i].fechaIngreso.dia = dia;
        listaAutos[i].fechaIngreso.mes = mes;
        listaAutos[i].fechaIngreso.anio = anio;
        listaAutos[i].horaIngreso = horaIngreso[i];
        listaAutos[i].horaSalida = horaSalida[i];
        listaAutos[i].idDuenio = idPersona[i];
    }
}


void hardcodePersonas(ePersona listaPersonas[],int cant)
{
    char nombre[][51]= {"Maria","Ezequiel","German","Yanina", "Juan", "Ignacio"};
    int anio[]= {1990,1980,2000,1995,1990,2000};
    int mes[]= {3,4,12,11,15,16};
    int dia[]= {33,22,25,11,15,20};
    int id[]={100,101,105,106,110,150};
    int i;

    for(i=0; i<cant; i++)
    {
        listaPersonas[i].id=id[i];
        listaPersonas[i].fechaNac.anio = anio[i];
        listaPersonas[i].fechaNac.mes = mes[i];
        listaPersonas[i].fechaNac.dia = dia[i];
        strcpy(listaPersonas[i].nombre, nombre[i]);
    }
}

 void mostrarPersonas(ePersona personas[], int cantidad)
 {
    int i;
     for (i=0;i< cantidad;i++)
     {
        /*printf("%s  \t %d  %d  %d", personas[i].nombre,personas[i].fechaNac.dia,personas[i].fechaNac.mes, personas[i].fechaNac.anio);*/
        printf("\n Nombre:    %s   \t", personas[i].nombre);
        printf(" Dia:    %d   \t", personas[i].fechaNac.dia);
        printf(" Mes:     %d   \t", personas[i].fechaNac.mes);
        printf(" Anio:    %d   \t", personas[i].fechaNac.anio);
        printf(" Id Duenio:    %d   \t", personas[i].id);
      }
 }

 void mostrarVehiculos(ePersona personas[],eVehiculo vehiculos[], int cantidad, int cantPersonas)
 {
    int i;
     for (i=0;i< cantidad;i++)
     {
        printf("\nNombre :%s \t",buscarPersona
            (personas,cantPersonas,vehiculos[i].idDuenio).nombre);
        printf(" Dia :%d \t", vehiculos[i].fechaIngreso.dia);
        printf(" Mes  :%d \t", vehiculos[i].fechaIngreso.mes);
        printf(" Año :%d \n", vehiculos[i].fechaIngreso.anio);
        printf(" Hora Ingreso :%d \t", vehiculos[i].horaIngreso);
        printf(" Hora Salida :%d \t", vehiculos[i].horaSalida);
        printf(" Patente :%s \t", vehiculos[i].patente);
     }
 }

ePersona buscarPersona(ePersona personas[], int cantidad, int id)
{
    int i;
     for (i=0;i< cantidad;i++)
     {
       if(id == personas[i].id)
        return personas[i];
     }
     return ;
}
 int buscarIndicePersona(ePersona personas[], int cantidad, int id)
 {
     int i;
     for (i=0;i< cantidad;i++)
     {
       if(id == personas[i].id)
        return i;
     }
     return -1;
 }


