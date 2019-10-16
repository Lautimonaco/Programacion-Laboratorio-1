#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LIBRE 0
#define OCUPADO 1


typedef struct
{
    int codigo;
    int CodigoEquipoVis;
    int CodigoEquipoLoc;
    int CodigoReferi;
    eFecha fechaPartido;
    int estado;
}ePartido;


/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
int inicializarPartidos(ePartido[], int);


/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
int buscarPartidosLibre(ePartido[],int);


/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
int cargarPartido(ePartido[], eEquipo[], eReferi[], int, int, int, int, int);


/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
void MostrarPartido(ePartido[]);


/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
void MostrarListaPartidos(ePartido[], int);


/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
void OrdenarPartidosFecha(ePartido[], int);





