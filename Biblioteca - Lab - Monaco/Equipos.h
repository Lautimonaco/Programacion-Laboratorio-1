#ifndef EQUIPOS_H_INCLUDED
#define EQUIPOS_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LIBRE 0
#define OCUPADO 1

typedef struct
{
    int dia;
    int mes;
    int anio;
} sFecha;

typedef struct
{
    int codigo;
    char nombre[51];
    char localidad[33];
    int estado;
} eEquipos;

typedef struct
{
    int codigo;
    char apellido[31];
    char nombre[31];
    int codigoDeEquipo;
    char sexo;
    sFecha fechaNacimiento;
    int estado;
} eJugadores;

typedef struct
{
    int codigo;
    char apellido[31];
    char nombre[31];
    char sexo;
    char eMail[31];
    sFecha fechaNacimiento;
    int estado;
} eReferi;

typedef struct
{
    int codigo;
    int codigoDeEquipoVisitante;
    int codigoDeEquipoLocal;
    int codigoDeReferi;
    sFecha fechaDePartido;
    int estado;
} ePartidos;


int onlyLetters(char []);
char* enterString(char*);
int enterInt(char []);
float enterFloat(char []);
int validarSexo(char);
int validarEmail(char []);


int relacionJugadorEquipo(eJugadores,eEquipos [],int);
int relacionPartidoEquipoLocal(ePartidos, eEquipos [], int);
int relacionPartidoEquipoVisitante(ePartidos, eEquipos [], int);
int relacionPartidoReferi(ePartidos, eReferi [], int);
int mostrarJugadoresPorEquipo(eJugadores [], eEquipos [], int,int);
int mostrarReferiConMaePartidos(eReferi [],ePartidos [],int, int);
int mostrarPartidosPorFecha(ePartidos [], int);
void promedioEdadesPorEquipo(eJugadores [],eEquipos [],int, int);


void hardcodeoEquipos(eEquipos [], int);
int inicializarEquipos(eEquipos [], int);
int cargarEquipo(eEquipos [], int, int);
int buscarLibreEquipos(eEquipos [], int);
void mostrarUnEquipo(eEquipos);
void mostrarListadoDeEquipos(eEquipos [], int);
int ordenarEquiposPorNombre(eEquipos [],int);
int flagEquipos(eEquipos [], int);
int modificarEquipo(eEquipos [],int);
int buscarEquipoPorCodigo(eEquipos [], int );
int bajarEquipo(eEquipos [], int);
void mostrarEquipoMasLargo(eEquipos [], int);


void hardcodeoJugadores(eJugadores [], int);
int inicializarJugadores(eJugadores [], int);
int cargarJugador(eJugadores [],eEquipos[],int, int, int);
int buscarLibreJugadores(eJugadores [], int);
void mostrarUnJugador(eJugadores);
void mostrarListadoDeJugadores(eJugadores [], int);
int ordenarJugadoresPorApellido(eJugadores [],int);
int flagJugadores(eJugadores [], int);
int buscarJugadorPorCodigo(eJugadores [], int );
int bajarJugador(eJugadores [], int);
int mostrarJugadoresPorNombre(eJugadores [],int);


void hardcodeoReferees(eReferi [], int);
int inicializarReferees(eReferi [], int);
int cargarReferi(eReferi [], int, int);
int buscarLibreReferees(eReferi [], int);
void mostrarUnReferee(eReferi);
void mostrarListadoDeReferees(eReferi [], int);




void hardcodeoPartidos(ePartidos [], int);
int inicializarPartidos(ePartidos [], int);
int cargarPartido(ePartidos [],eEquipos[],eReferi[],int,int,int, int);
int buscarLibrePartidos(ePartidos [], int);
void mostrarUnPartido(ePartidos);
void mostrarListadoDePartidos(ePartidos [], int);
int ordenarPartidosPorFecha(ePartidos [],int cant);
int flagPartidos(ePartidos [],int);


#endif // EQUIPOS_H_INCLUDED
