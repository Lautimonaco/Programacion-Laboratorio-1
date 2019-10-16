#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LIBRE 0
#define OCUPADO 1


typedef struct
{
    int codigo;
    char apellido[31];
    char nombre[31];
    char sexo;
    char eMail[31];
    eFecha fechaNac;
    int estado;
}eReferi;


/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
int inicializarReferi(eReferi[], int);


/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
int buscarReferiLibre(eReferi[],int);


/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
int cargarReferi (eReferi[], int, int);


/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
void MostrarReferi(eReferi[]);


/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
void MostrarListaReferis(eReferi[], int);


