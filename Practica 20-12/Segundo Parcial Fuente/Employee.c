#include "Employee.h"
#include <malloc.h>


Employee* employee_new()
{
    return (Employee*)(malloc(sizeof(Employee)));
}

/////////////
/////////////
/////////////   PARAMETROS, SETTERS Y GETTERS.
/////////////
/////////////


Employee* employee_newParametros(char* idVueloStr,char* idAvionStr,char* idPilotoStr,char* fechaStr,char* destinoStr,char* cantPasajerosStr, char* horaDespegueStr, char* horaLlegadaStr)
{
    Employee* oneEmployee = employee_new();
    if(oneEmployee!=NULL)
    {
        setIdVuelo(oneEmployee,atoi(idVueloStr));
        setIdAvion(oneEmployee,atoi(idAvionStr));
        setIdPiloto(oneEmployee,atoi(idPilotoStr));
        setCantPasajeros(oneEmployee,atoi(cantPasajerosStr));
        setHoraDespegue(oneEmployee,atoi(horaDespegueStr));
        setHoraLlegada(oneEmployee,atoi(horaLlegadaStr));
        setFecha(oneEmployee,fechaStr);
        setDestino(oneEmployee,destinoStr);
    }
    return oneEmployee;
}


int setIdVuelo(Employee* this,int int1)
{
    int r = -1;
    if(this != NULL && int1>0)
    {
        this->idVuelo=int1;
        r = 0;
    }
    return r;
}

int setIdAvion(Employee* this,int int1)
{
    int r = -1;
    if(this != NULL && int1>0)
    {
        this->idAvion=int1;
        r = 0;
    }
    return r;
}

int setIdPiloto(Employee* this,int int1)
{
    int r = -1;
    if(this != NULL && int1>0)
    {
        this->idPiloto=int1;
        r = 0;
    }
    return r;
}

int setCantPasajeros(Employee* this,int int1)
{
    int r = -1;
    if(this != NULL && int1>0)
    {
        this->cantPasajeros=int1;
        r = 0;
    }
    return r;
}

int setHoraDespegue(Employee* this,int int1)
{
    int r = -1;
    if(this != NULL && int1>0)
    {
        this->horaDespegue=int1;
        r = 0;
    }
    return r;
}

int setHoraLlegada(Employee* this,int int1)
{
    int r = -1;
    if(this != NULL && int1>0)
    {
        this->horaLlegada=int1;
        r = 0;
    }
    return r;
}



int setDestino(Employee* this,char* char1)
{
    int r = -1;
    if(this != NULL && char1>0)
    {
        strcpy(this->destino,char1);
        r = 0;
    }
    return r;
}

int setFecha(Employee* this,char* char1)
{
    int r = -1;
    if(this != NULL && char1>0)
    {
        strcpy(this->fecha,char1);
        r = 0;
    }
    return r;
}

int getIdVuelo(Employee* this,int* int1)
{
    if(this != NULL)
    {
        *int1 = this->idVuelo;
    }
    return *int1;
}

int getIdAvion(Employee* this,int* int1)
{
    if(this != NULL)
    {
        *int1 = this->idAvion;
    }
    return *int1;
}

int getIdPiloto(Employee* this,int* int1)
{
    if(this != NULL)
    {
        *int1 = this->idPiloto;
    }
    return *int1;
}

int getCantPasajeros(Employee* this,int* int1)
{
    if(this != NULL)
    {
        *int1 = this->cantPasajeros;
    }
    return *int1;
}

int getHoraDespegue(Employee* this,int* int1)
{
    if(this != NULL)
    {
        *int1 = this->horaDespegue;
    }
    return *int1;
}

int getHoraLlegada(Employee* this,int* int1)
{
    if(this != NULL)
    {
        *int1 = this->horaLlegada;
    }
    return *int1;
}

int getFecha(Employee* this,char* char1)
{
    if(this != NULL)
    {
        strcpy(char1, this->fecha);
    }
    return char1;
}

int getDestino(Employee* this,char* char1)
{
    if(this != NULL)
    {
        strcpy(char1, this->destino);
    }
    return char1;
}

/////////////
/////////////
///////////// LISTADO
/////////////
/////////////

void employee_showOneEmployee(LinkedList* pArrayListEmployee,int index)
{
    Employee* aux;
    int idVuelo;
    int idAvion;
    int idPiloto;
    char fecha[50];
    char destino[50];
    int cantPasajeros;
    int horaDespegue;
    int horaLlegada;
    char idPilotoText[50];

    aux = (Employee*)ll_get(pArrayListEmployee, index);
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

/////////////
/////////////
///////////// FILTRADOS
/////////////
/////////////

/*int filtrar(void* p1)
{
    Employee* oneEmployee = (Employee*)p1;
    if(oneEmployee->sueldo == 12000)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}*/

/////////////
/////////////
///////////// COMPARACIONES
/////////////
/////////////

/*int compararInts(void* p1, void* p2)
{
    Employee* empleado1 = (Employee*)p1;
    Employee* empleado2 = (Employee*)p2;
    return intCmp(empleado1->CAMBIAR,empleado2->CAMBIAR);

}

int compararChars(void* p1, void* p2)
{
    Employee* empleado1 = (Employee*)p1;
    Employee* empleado2 = (Employee*)p2;
    return strcmp(empleado1->CAMBIAR,empleado2->CAMBIAR);
}*/

/////////////
/////////////
/////////////
/////////////
/////////////

/*int employee_findById(Employee* listEmployees,LinkedList* pArrayListEmployee)
{
    int i;
    int idEmployee;
    int id;
    int r = -1;
    printf("Ingrese el ID del empleado : ");
    scanf("%d",&id);

    for(i=0;i<ll_len(pArrayListEmployee);i++)
    {
       listEmployees = ll_get(pArrayListEmployee,i);
       employee_getId(listEmployees,&idEmployee);
       if(idEmployee==id)
       {
           return i;
       }
    }
    return r;
}*/
