#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListsVuelo LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile, LinkedList* pArrayListsVuelo)
{
    sVuelo* listaVuelos;
    int r = 0;
    char idVuelo[50];
    char idAvion[50];
    char idPiloto[50];
    char fecha[50];
    char destino[50];
    char cantPasajeros[50];
    char horaDespegue[50];
    char horaLlegada[50];
    if(pFile == NULL)
    {
        return -1;
    }
      fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",idVuelo,idAvion,idPiloto,fecha,destino,cantPasajeros,horaDespegue,horaLlegada);
    do
    {
        fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",idVuelo,idAvion,idPiloto,fecha,destino,cantPasajeros,horaDespegue,horaLlegada);
        listaVuelos = vuelo_newParametros(idVuelo,idAvion,idPiloto,fecha,destino,cantPasajeros,horaDespegue,horaLlegada);
        ll_add(pArrayListsVuelo, listaVuelos);

    }
    while(!feof(pFile));

    return r;
}





/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListsVuelo LinkedList*
 * \return int
 *
 */
int parser_sVueloFromBinary(FILE* pFile, LinkedList* pArrayListsVuelo)
{

    sVuelo* listsVuelos;
    if(pFile == NULL)
    {
        return -1;
    }
    while(!feof(pFile))
    {
        listsVuelos = nuevoVuelo();
        fread(listsVuelos,sizeof(sVuelo),1,pFile);
        if(feof(pFile))
        {
            break;
        }
        ll_add(pArrayListsVuelo, listsVuelos);
    }

    return 1;
}
