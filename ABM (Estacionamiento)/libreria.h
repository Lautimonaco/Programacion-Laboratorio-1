#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int dia;
    int mes;
    int anio;
}eFecha;

typedef struct {
    int id;
    char nombre[50];
    eFecha fechaNac;
}ePersona;


typedef struct {
    char patente[50];
    eFecha fechaIngreso;
    int horaIngreso;
    int horaSalida;
    int idDuenio;
}eVehiculo;

void hardcodeoAutos(eVehiculo listaAutos[], int cant);
void hardcodePersonas(ePersona listaPersonas[],int cant);
void mostrarPersonas(ePersona personas[], int cantidad);
void mostrarVehiculos(ePersona personas[],eVehiculo vehiculos[], int cantidad, int cantPersonas);
int buscarIndicePersona(ePersona personas[], int cantidad, int id);
ePersona buscarPersona(ePersona personas[], int cantidad, int id);
