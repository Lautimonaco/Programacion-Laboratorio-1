#include "Employee.h"
#include <malloc.h>


sbicicleta* nuevoVuelo()
{
    return (sbicicleta*)(malloc(sizeof(sbicicleta)));
}


sbicicleta* vuelo_newParametros(char* idBikeStr,char* idAvionStr,char* idPilotoStr,char* nombreStr,char* tipoStr,char* cantPasajerosStr, char* horaDespegueStr, char* horaLlegadaStr)
{
    sbicicleta* unVuelo = nuevoVuelo();
    if(unVuelo!=NULL)
    {
        setidBike(unVuelo,atoi(idBikeStr));
        setIdAvion(unVuelo,atoi(idAvionStr));
        setIdPiloto(unVuelo,atoi(idPilotoStr));
        setCantPasajeros(unVuelo,atoi(cantPasajerosStr));
        setHoraDespegue(unVuelo,atoi(horaDespegueStr));
        setHoraLlegada(unVuelo,atoi(horaLlegadaStr));
        setnombre(unVuelo,nombreStr);
        settipo(unVuelo,tipoStr);
    }
    return unVuelo;
}


int setidBike(sbicicleta* this,int int1)
{
    int r = -1;
    if(this != NULL && int1>0)
    {
        this->idBike=int1;
        r = 0;
    }
    return r;
}

int setIdAvion(sbicicleta* this,int int1)
{
    int r = -1;
    if(this != NULL && int1>0)
    {
        this->idAvion=int1;
        r = 0;
    }
    return r;
}

int setIdPiloto(sbicicleta* this,int int1)
{
    int r = -1;
    if(this != NULL && int1>0)
    {
        this->idPiloto=int1;
        r = 0;
    }
    return r;
}

int setCantPasajeros(sbicicleta* this,int int1)
{
    int r = -1;
    if(this != NULL && int1>0)
    {
        this->cantPasajeros=int1;
        r = 0;
    }
    return r;
}

int setHoraDespegue(sbicicleta* this,int int1)
{
    int r = -1;
    if(this != NULL && int1>0)
    {
        this->horaDespegue=int1;
        r = 0;
    }
    return r;
}

int setHoraLlegada(sbicicleta* this,int int1)
{
    int r = -1;
    if(this != NULL && int1>0)
    {
        this->horaLlegada=int1;
        r = 0;
    }
    return r;
}



int settipo(sbicicleta* this,char* char1)
{
    int r = -1;
    if(this != NULL && char1>0)
    {
        strcpy(this->tipo,char1);
        r = 0;
    }
    return r;
}

int setnombre(sbicicleta* this,char* char1)
{
    int r = -1;
    if(this != NULL && char1>0)
    {
        strcpy(this->nombre,char1);
        r = 0;
    }
    return r;
}

int getidBike(sbicicleta* this,int* int1)
{
    if(this != NULL)
    {
        *int1 = this->idBike;
    }
    return *int1;
}

int getIdAvion(sbicicleta* this,int* int1)
{
    if(this != NULL)
    {
        *int1 = this->idAvion;
    }
    return *int1;
}

int getIdPiloto(sbicicleta* this,int* int1)
{
    if(this != NULL)
    {
        *int1 = this->idPiloto;
    }
    return *int1;
}

int getCantPasajeros(sbicicleta* this,int* int1)
{
    if(this != NULL)
    {
        *int1 = this->cantPasajeros;
    }
    return *int1;
}

int getHoraDespegue(sbicicleta* this,int* int1)
{
    if(this != NULL)
    {
        *int1 = this->horaDespegue;
    }
    return *int1;
}

int getHoraLlegada(sbicicleta* this,int* int1)
{
    if(this != NULL)
    {
        *int1 = this->horaLlegada;
    }
    return *int1;
}

int getnombre(sbicicleta* this,char* char1)
{
    if(this != NULL)
    {
        strcpy(char1, this->nombre);
    }
    return char1;
}

int gettipo(sbicicleta* this,char* char1)
{
    if(this != NULL)
    {
        strcpy(char1, this->tipo);
    }
    return char1;
}


void showUnVuelo(LinkedList* pArrayListsbicicleta,int index)
{
    sbicicleta* aux;
    int idBike;
    int idAvion;
    int idPiloto;
    char nombre[50];
    char tipo[50];
    int cantPasajeros;
    int horaDespegue;
    int horaLlegada;
    char idPilotoText[50];

    aux = ll_get(pArrayListsbicicleta, index);
    getidBike(aux, &idBike);
    getIdAvion(aux,&idAvion);
    getIdPiloto(aux,&idPiloto);
    getnombre(aux, &nombre);
    gettipo(aux, &tipo);
    getCantPasajeros(aux,&cantPasajeros);
    getHoraDespegue(aux,&horaDespegue);
    getHoraLlegada(aux, &horaLlegada);
    switch(idPiloto)
    {
    case 1:
        strcpy(idPilotoText,"BMX");
        break;
    case 2:
        strcpy(idPilotoText,"PLAYERA");

        break;
    case 3:
        strcpy(idPilotoText,"MTB");

        break;
    case 4:
        strcpy(idPilotoText,"PASEO");

        break;
    case 5:
        strcpy(idPilotoText,"Stephen Coonts");

        break;

    }
    printf("%d--%d--%s--%s--%s--%d--%d--%d\n",idBike,idAvion,idPilotoText,nombre,tipo,cantPasajeros,horaDespegue,horaLlegada);
}


int filtrarVuelosCortos(void* p1)
{
    sbicicleta* unVuelo = (sbicicleta*)p1;
    int duracion = unVuelo->horaLlegada - unVuelo->horaDespegue;
    if(duracion > 50 && duracion < 120)
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
    sbicicleta* unVuelo = (sbicicleta*)p1;
    if(strcmp(unVuelo->tipo,"Portugal")==0)
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
    sbicicleta* unVuelo = (sbicicleta*)p1;
    if(unVuelo->idPiloto == 1)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

int contadorPasajerosTotal(void* p1)
{
    sbicicleta* unVuelo = (sbicicleta*)p1;
    return unVuelo->cantPasajeros;
}

int contadorPasajerosIrlanda(void* p1)
{
    sbicicleta* unVuelo = (sbicicleta*)p1;
    int r;
    if(strcmp(unVuelo->tipo, "Irlanda")==0)
    {
       r = unVuelo->cantPasajeros;
    }
    else
    {
        r=0;
    }
    return r;
}
