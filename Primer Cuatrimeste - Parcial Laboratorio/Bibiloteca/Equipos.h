#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LIBRE 0
#define OCUPADO 1


typedef struct
{
    int codigo;
    char nombre[51];
    char localidad[33];
    int estado;
}eEquipo;


/** \brief
 *
 * \param eEquipo[]
 * \param int
 * \return int
 *
 */
int inicializarEquipos(eEquipo[], int);


/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
int buscarEquiposLibre(eEquipo[],int);


/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
int CargarEquipo(eEquipo[], int, int);


/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
void MostrarEquipo(eEquipo[]);


/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
void MostrarListaEquipos(eEquipo[], int);


/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
void OrdenarEquiposNombre(eEquipo[], int);
