#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "parser.h"
#include "Bicicleta.h"

/** \brief Parsea los datos los datos de los ciclistas desde el archivo bicicletas.txt (modo texto).
 *
* \param FILE* pFile puntero al archivo
 * \param pArrayListCachorro LinkedList* puntero a la lista con la cual se trabajar�
 * \return int (-1)Error: si el puntero a la lista es NULL o el puntero al archivo es NULL
                (1) si se pudo realizar la operaci�n
 *
 */
int parser_BicicletaFromText(FILE* pFile, LinkedList* pArrayList)
{
    int todoOk=-1;
    Bicicleta* auxBici;
    char auxId[30];
    char auxNombre[30];
    char auxTipo[30];
    char auxTiempo[30];


    int cant;
    //  int r;
    if(pFile != NULL && pArrayList!=NULL)
    {

        fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n", auxId, auxNombre,auxTipo,auxTiempo );
        while( !feof(pFile))
        {
            cant = fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n", auxId, auxNombre,auxTipo,auxTiempo );
            printf(" %s  %s %s %s  \n ",auxId, auxNombre,auxTipo,auxTiempo);
            //devolvera la cantidad que pudo cargar
            if( cant == 4) //si pudo cargar los 6
            {
                auxBici = bicicleta_new();
                bicicleta_setId(auxBici,atoi(auxId));
                bicicleta_setNombre(auxBici,auxNombre);
                bicicleta_setTiempo(auxBici,atoi(auxTiempo));
                bicicleta_setTipo(auxBici,auxTipo);
                ll_add(pArrayList,auxBici);
            }
        }
        fclose(pFile);
        todoOk=1;
    }
    else
    {
        printf("Archivo vacio");
    }
    return todoOk;
}
