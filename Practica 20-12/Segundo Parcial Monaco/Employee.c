#include "Employee.h"
#include <malloc.h>


sVuelo* nuevoVuelo()
{
    return (sVuelo*)(malloc(sizeof(sVuelo)));
}


sVuelo* vuelo_newParametros(char* idVueloStr,char* idAvionStr,char* idPilotoStr,char* fechaStr,char* destinoStr,char* cantPasajerosStr, char* horaDespegueStr, char* horaLlegadaStr)
{
    sVuelo* unVuelo = nuevoVuelo();
    if(unVuelo!=NULL)
    {
        setIdVuelo(unVuelo,atoi(idVueloStr));
        setIdAvion(unVuelo,atoi(idAvionStr));
        setIdPiloto(unVuelo,atoi(idPilotoStr));
        setCantPasajeros(unVuelo,atoi(cantPasajerosStr));
        setHoraDespegue(unVuelo,atoi(horaDespegueStr));
        setHoraLlegada(unVuelo,atoi(horaLlegadaStr));
        setFecha(unVuelo,fechaStr);
        setDestino(unVuelo,destinoStr);
    }
    return unVuelo;
}


int setIdVuelo(sVuelo* this,int int1)
{
    int r = -1;
    if(this != NULL && int1>0)
    {
        this->idVuelo=int1;
        r = 0;
    }
    return r;
}

int setIdAvion(sVuelo* this,int int1)
{
    int r = -1;
    if(this != NULL && int1>0)
    {
        this->idAvion=int1;
        r = 0;
    }
    return r;
}

int setIdPiloto(sVuelo* this,int int1)
{
    int r = -1;
    if(this != NULL && int1>0)
    {
        this->idPiloto=int1;
        r = 0;
    }
    return r;
}

int setCantPasajeros(sVuelo* this,int int1)
{
    int r = -1;
    if(this != NULL && int1>0)
    {
        this->cantPasajeros=int1;
        r = 0;
    }
    return r;
}

int setHoraDespegue(sVuelo* this,int int1)
{
    int r = -1;
    if(this != NULL && int1>0)
    {
        this->horaDespegue=int1;
        r = 0;
    }
    return r;
}

int setHoraLlegada(sVuelo* this,int int1)
{
    int r = -1;
    if(this != NULL && int1>0)
    {
        this->horaLlegada=int1;
        r = 0;
    }
    return r;
}



int setDestino(sVuelo* this,char* char1)
{
    int r = -1;
    if(this != NULL && char1>0)
    {
        strcpy(this->destino,char1);
        r = 0;
    }
    return r;
}

int setFecha(sVuelo* this,char* char1)
{
    int r = -1;
    if(this != NULL && char1>0)
    {
        strcpy(this->fecha,char1);
        r = 0;
    }
    return r;
}

int getIdVuelo(sVuelo* this,int* int1)
{
    if(this != NULL)
    {
        *int1 = this->idVuelo;
    }
    return *int1;
}

int getIdAvion(sVuelo* this,int* int1)
{
    if(this != NULL)
    {
        *int1 = this->idAvion;
    }
    return *int1;
}

int getIdPiloto(sVuelo* this,int* int1)
{
    if(this != NULL)
    {
        *int1 = this->idPiloto;
    }
    return *int1;
}

int getCantPasajeros(sVuelo* this,int* int1)
{
    if(this != NULL)
    {
        *int1 = this->cantPasajeros;
    }
    return *int1;
}

int getHoraDespegue(sVuelo* this,int* int1)
{
    if(this != NULL)
    {
        *int1 = this->horaDespegue;
    }
    return *int1;
}

int getHoraLlegada(sVuelo* this,int* int1)
{
    if(this != NULL)
    {
        *int1 = this->horaLlegada;
    }
    return *int1;
}

int getFecha(sVuelo* this,char* char1)
{
    if(this != NULL)
    {
        strcpy(char1, this->fecha);
    }
    return char1;
}

int getDestino(sVuelo* this,char* char1)
{
    if(this != NULL)
    {
        strcpy(char1, this->destino);
    }
    return char1;
}


void showUnVuelo(LinkedList* pArrayListsVuelo,int index)
{
    sVuelo* aux;
    int idVuelo;
    int idAvion;
    int idPiloto;
    char fecha[50];
    char destino[50];
    int cantPasajeros;
    int horaDespegue;
    int horaLlegada;
    char idPilotoText[50];

    aux = ll_get(pArrayListsVuelo, index);
    getIdVuelo(aux, &idVuelo);
    getIdAvion(aux,&idAvion);
    getIdPiloto(aux,&idPiloto);
    getFecha(aux, &fecha);
    getDestino(aux, &destino);
    getCantPasajeros(aux,&cantPasajeros);
    getHoraDespegue(aux,&horaDespegue);
    getHoraLlegada(aux, &horaLlegada);
    switch(idPiloto)
    {
    case 1:
        strcpy(idPilotoText,"Alex Lifeson");
        break;
    case 2:
        strcpy(idPilotoText,"Richard Bach");

        break;
    case 3:
        strcpy(idPilotoText,"John Kerry");

        break;
    case 4:
        strcpy(idPilotoText,"Erwin Rommel");

        break;
    case 5:
        strcpy(idPilotoText,"Stephen Coonts");

        break;

    }
    printf("%d--%d--%s--%s--%s--%d--%d--%d\n",idVuelo,idAvion,idPilotoText,fecha,destino,cantPasajeros,horaDespegue,horaLlegada);
}


int filtrarVuelosCortos(void* p1)
{
    sVuelo* unVuelo = (sVuelo*)p1;
    int duracion = unVuelo->horaLlegada - unVuelo->horaDespegue;
    if(duracion < 3) //Vuelos menores a 3 horas
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int filtrarVuelosPortugal(void* p1)
{
    sVuelo* unVuelo = (sVuelo*)p1;
    if(strcmp(unVuelo->destino,"Portugal")==0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int filtrarAlexLifeson(void* p1)
{
    sVuelo* unVuelo = (sVuelo*)p1;
    if(unVuelo->idPiloto == 1)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}


/*int compararInts(void* p1, void* p2)
{
    sVuelo* empleado1 = (sVuelo*)p1;
    sVuelo* empleado2 = (sVuelo*)p2;
    return intCmp(empleado1->CAMBIAR,empleado2->CAMBIAR);

}

int compararChars(void* p1, void* p2)
{
    sVuelo* empleado1 = (sVuelo*)p1;
    sVuelo* empleado2 = (sVuelo*)p2;
    return strcmp(empleado1->CAMBIAR,empleado2->CAMBIAR);
}*/


/*int employee_findById(sVuelo* listsVuelos,LinkedList* pArrayListsVuelo)
{
    int i;
    int idsVuelo;
    int id;
    int r = -1;
    printf("Ingrese el ID del empleado : ");
    scanf("%d",&id);

    for(i=0;i<ll_len(pArrayListsVuelo);i++)
    {
       listsVuelos = ll_get(pArrayListsVuelo,i);
       employee_getId(listsVuelos,&idsVuelo);
       if(idsVuelo==id)
       {
           return i;
       }
    }
    return r;
}*/

int contadorPasajerosTotal(void* p1)
{
    sVuelo* unVuelo = (sVuelo*)p1;
    return unVuelo->cantPasajeros;
}

int contadorPasajerosIrlanda(void* p1)
{
    sVuelo* unVuelo = (sVuelo*)p1;
    int r;
    if(strcmp(unVuelo->destino, "Irlanda")==0)
    {
       r = unVuelo->cantPasajeros;
    }
    else
    {
        r=0;
    }
    return r;
}
