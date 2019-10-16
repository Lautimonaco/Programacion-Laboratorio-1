#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LIBRE 0
#define OCUPADO 1


typedef struct {
    int dia;
    int mes;
    int anio;
}eFecha;


typedef struct
{
    int codigo;
    int CodigoEquipo;
    char apellido[31];
    char nombre[31];
    char sexo;
    eFecha fechaNac;
    int estado;
}eJugadores;


/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
int inicializarJugadores(eJugadores[], int);


/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
int buscarJugadoresLibre(eJugadores[],int);


/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
int cargarJugador(eJugadores [],eEquipo[],int, int, int);


/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
void MostrarJugador(eJugadores[]);


/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
void mostrarListaJugadores(eJugadores[], int);


/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
void OrdenarJugadoresApellido(eJugadores[], int);

