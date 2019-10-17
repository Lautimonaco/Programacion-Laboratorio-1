#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Equipos.h"

#define E 10
#define J 35
#define R 6
#define P 25

int validarSexo(char sexo)
{
    int r = -2;
    if(sexo == 102 || sexo == 109)
    {
        r = 0;
    }
    return r;
}


char* enterString(char* string1)
{
    fflush(stdin);
    gets(string1);
    return string1;
}

int enterInt(char mensaje[])
{
    int num1;
    printf(mensaje);
    scanf("%d", &num1);
    return num1;
}

float enterFloat(char mensaje[])
{
    float num1;
    printf(mensaje);
    scanf("%f", &num1);
    return num1;
}

int onlyLetters(char string1[])
{
    int i;
    int largo;
    int r = 0;
    largo = strlen(string1);
    for(i=1; i<largo; i++)
    {
        if(string1[i]==32 || string1[i]==64)
        {
            continue;
        }
        if(string1[i]==64)
        {
            continue;
        }
        if(((string1[i]<97 && string1[i]>90) || string1[i]>122) || string1[i]<65)
        {
            r = -2;
            return r;
        }
    }
    return r;
}

int inicializarEquipos(eEquipos list[], int cant)
{
    int i;
    int r=-1;
    if(cant > 0 && list != NULL)
    {
        r = 0;
        for(i=0; i<cant; i++)
        {
            list[i].estado = LIBRE;
        }
    }
    return r;
}

int inicializarJugadores(eJugadores list[], int cant)
{
    int i;
    int r=-1;
    if(cant > 0 && list != NULL)
    {
        r = 0;
        for(i=0; i<cant; i++)
        {
            list[i].estado = LIBRE;
        }
    }
    return r;
}

int inicializarReferees(eReferi list[], int cant)
{
    int i;
    int r=-1;
    if(cant > 0 && list != NULL)
    {
        r = 0;
        for(i=0; i<cant; i++)
        {
            list[i].estado = LIBRE;
        }
    }
    return r;
}

int inicializarPartidos(ePartidos list[], int cant)
{
    int i;
    int r=-1;
    if(cant > 0 && list != NULL)
    {
        r = 0;
        for(i=0; i<cant; i++)
        {
            list[i].estado = LIBRE;
        }
    }
    return r;
}

int buscarLibreEquipos(eEquipos list[],int cant)
{
    int i;
    int index = -1;
    for(i=0; i<cant; i++)
    {
        if(list[i].estado == LIBRE)
        {
            index = i;
            break;
        }
    }
    return index;
}

int buscarLibreJugadores(eJugadores list[],int cant)
{
    int i;
    int index = -1;
    for(i=0; i<cant; i++)
    {
        if(list[i].estado == LIBRE)
        {
            index = i;
            break;
        }
    }
    return index;
}

int buscarLibreReferees(eReferi list[],int cant)
{
    int i;
    int index = -1;
    for(i=0; i<cant; i++)
    {
        if(list[i].estado == LIBRE)
        {
            index = i;
            break;
        }
    }
    return index;
}

int buscarLibrePartidos(ePartidos list[],int cant)
{
    int i;
    int index = -1;
    for(i=0; i<cant; i++)
    {
        if(list[i].estado == LIBRE)
        {
            index = i;
            break;
        }
    }
    return index;
}

int cargarPartido(ePartidos listP[],eEquipos listE[],eReferi listR[],int cantP,int cantE,int cantR,int idNumber)
{
    int i;
    int r = -1;
    i = buscarLibrePartidos(listP, cantP);

    if(i != -1)
    {
        listP[i].codigoDeEquipoLocal = enterInt("Ingrese el codigo del equipo local : ");
        r = relacionPartidoEquipoLocal(listP[i],listE,cantE);
        while(r==-2)
        {
            listP[i].codigoDeEquipoLocal = enterInt("El codigo no pertenece a un equipo valido, reingrese el codigo : ");
            r = relacionPartidoEquipoLocal(listP[i],listE,cantE);
        }

        listP[i].codigoDeEquipoVisitante = enterInt("Ingrese el codigo del equipo visitante : ");
        r = relacionPartidoEquipoVisitante(listP[i],listE,cantE);
        while(r==-2 || listP[i].codigoDeEquipoVisitante == listP[i].codigoDeEquipoLocal)
        {
            listP[i].codigoDeEquipoVisitante = enterInt("El codigo no pertenece a un equipo valido, reingrese el codigo : ");
            r = relacionPartidoEquipoVisitante(listP[i],listE,cantE);
        }

        listP[i].codigoDeReferi = enterInt("Ingrese el codigo del referi : ");
        r = relacionPartidoReferi(listP[i], listR, cantR);
        while(r==-2)
        {
            listP[i].codigoDeReferi = enterInt("El codigo no pertenece a un equipo valido, reingrese el codigo : ");
            r = relacionPartidoReferi(listP[i], listR, cantR);
        }

        printf("Ingrese la fecha del partido \n");
        listP[i].fechaDePartido.dia = enterInt("Dia : ");
        while(listP[i].fechaDePartido.dia > 31 || listP[i].fechaDePartido.dia < 1)
        {
            listP[i].fechaDePartido.dia = enterInt("Dia invalido, reingrese : ");
        }

        listP[i].fechaDePartido.mes = enterInt("Mes : ");
        while(listP[i].fechaDePartido.mes > 12 || listP[i].fechaDePartido.mes < 1)
        {

            listP[i].fechaDePartido.mes = enterInt("Mes invalido, reingrese : ");
        }

        listP[i].fechaDePartido.anio = enterInt("Anio : ");
        while(listP[i].fechaDePartido.anio > 2019 || listP[i].fechaDePartido.anio < 1910)
        {
            listP[i].fechaDePartido.anio = enterInt("Anio invalido, reingrese : ");
        }
        listP[i].codigo = idNumber;
        listP[i].estado = OCUPADO;
        r = 0;
    }

    return r;
}

int cargarEquipo(eEquipos list[],int cant,int idNumber)
{
    int i;
    int r = -1;
    i = buscarLibreEquipos(list, cant);

    if(i != -1)
    {
        printf("Ingrese el nombre del equipo : ");
        enterString(list[i].nombre);
        r = onlyLetters(list[i].nombre);
        while(r==-2)
        {
            printf("Solo se aceptan letras y espacios, reingrese nombre: ");
            enterString(list[i].nombre);
            r = onlyLetters(list[i].nombre);
        }
        printf("Ingrese la localidad del equipo : ");
        enterString(list[i].localidad);
        r = onlyLetters(list[i].localidad);
        while(r==-2)
        {
            printf("Solo se aceptan letras y espacios, reingrese localidad: ");
            enterString(list[i].localidad);
            r = onlyLetters(list[i].localidad);
        }
        r = 0;
        list[i].codigo = idNumber;
        list[i].estado = OCUPADO;
    }

    return r;
}

int cargarJugador(eJugadores listJ[],eEquipos listE[],int cantJ,int cantE,int idNumber)
{
    int i;
    int r = -1;
    i = buscarLibreJugadores(listJ, cantJ);

    if(i != -1)
    {
        printf("\nIngrese el apellido del jugador : ");
        enterString(listJ[i].apellido);
        r = onlyLetters(listJ[i].apellido);
        while(r==-2)
        {
            printf("\nSolo se aceptan letras, reingrese apellido: ");
            enterString(listJ[i].apellido);
            r = onlyLetters(listJ[i].apellido);
        }

        printf("\nIngrese el nombre del jugador : ");
        enterString(listJ[i].nombre);
        r = onlyLetters(listJ[i].nombre);
        while(r==-2)
        {
            printf("\nSolo se aceptan letras, reingrese nombre: ");
            enterString(listJ[i].nombre);
            r = onlyLetters(listJ[i].nombre);
        }

        printf("\nIngrese el codigo de su equipo : ");
        scanf("%d", &listJ[i].codigoDeEquipo);
        r = relacionJugadorEquipo(listJ[i],listE,cantE);
        while(r==-2)
        {
            listJ[i].codigoDeEquipo = enterInt("El codigo no pertenece a un equipo valido, reingrese el codigo : ");
            r = relacionJugadorEquipo(listJ[i],listE,cantE);
        }

        fflush(stdin);
        printf("\nIngrese su sexo : ");
        listJ[i].sexo = getchar();
        r = validarSexo(listJ[i].sexo);
        while(r==-2)
        {
            fflush(stdin);
            printf("\nSexo invalido, reingrese : ");
            listJ[i].sexo = getchar();
            r = validarSexo(listJ[i].sexo);
        }

        printf("\nIngrese su fecha de nacimiento \n");
        listJ[i].fechaNacimiento.dia = enterInt("Dia : ");
        while(listJ[i].fechaNacimiento.dia > 31 || listJ[i].fechaNacimiento.dia < 1)
        {
            listJ[i].fechaNacimiento.dia = enterInt("Dia invalido, reingrese : ");
        }

        listJ[i].fechaNacimiento.mes = enterInt("Mes : ");
        while(listJ[i].fechaNacimiento.mes > 12 || listJ[i].fechaNacimiento.mes < 1)
        {

            listJ[i].fechaNacimiento.mes = enterInt("Mes invalido, reingrese : ");
        }

        listJ[i].fechaNacimiento.anio = enterInt("Anio : ");
        while(listJ[i].fechaNacimiento.anio > 2019 || listJ[i].fechaNacimiento.anio < 1910)
        {
            listJ[i].fechaNacimiento.anio = enterInt("Anio invalido, reingrese : ");
        }

        listJ[i].codigo = idNumber;
        listJ[i].estado = OCUPADO;
        r = 0;
    }

    return r;
}

int cargarReferi(eReferi list[],int cant,int idNumber)
{
    int i;
    int r = -1;
    i = buscarLibreReferees(list, cant);

    if(i != -1)
    {
        printf("Ingrese el apellido del referi : ");
        enterString(list[i].apellido);
        r = onlyLetters(list[i].apellido);
        while(r==-2)
        {
            printf("Solo se aceptan letras, reingrese apellido: ");
            enterString(list[i].apellido);
            r = onlyLetters(list[i].apellido);
        }

        printf("Ingrese el nombre del referi : ");
        enterString(list[i].nombre);
        r = onlyLetters(list[i].nombre);
        while(r==-2)
        {
            printf("Solo se aceptan letras, reingrese nombre: ");
            enterString(list[i].nombre);
            r = onlyLetters(list[i].nombre);
        }

        fflush(stdin);
        printf("\nIngrese su sexo : ");
        list[i].sexo = getchar();
        r = validarSexo(list[i].sexo);
        while(r==-2)
        {
            fflush(stdin);
            printf("\nSexo invalido, reingrese : ");
            list[i].sexo = getchar();
            r = validarSexo(list[i].sexo);
        }

        printf("Ingrese su eMail : ");
        enterString(list[i].eMail);

        printf("Ingrese su fecha de nacimiento \n");

        list[i].fechaNacimiento.dia = enterInt("Dia : ");
        while(list[i].fechaNacimiento.dia > 31 || list[i].fechaNacimiento.dia < 1)
        {
            list[i].fechaNacimiento.dia = enterInt("Dia invalido, reingrese : ");
        }

        list[i].fechaNacimiento.mes = enterInt("Mes : ");
        while(list[i].fechaNacimiento.mes > 12 || list[i].fechaNacimiento.mes < 1)
        {
            list[i].fechaNacimiento.mes = enterInt("Mes invalido, reingrese : ");
        }

        list[i].fechaNacimiento.anio = enterInt("Anio : ");
        while(list[i].fechaNacimiento.anio > 2019 || list[i].fechaNacimiento.anio < 1910)
        {
            list[i].fechaNacimiento.anio = enterInt("Anio invalido, reingrese : ");
        }

        list[i].codigo = idNumber;
        list[i].estado = OCUPADO;
    }

    return r;
}

void mostrarUnEquipo(eEquipos unEquipo)
{
    printf("%03d %20s \t %20s \n"
           , unEquipo.codigo
           , unEquipo.nombre
           , unEquipo.localidad);
}


void mostrarListadoDeEquipos(eEquipos list[], int cant)
{
    int i;
    printf("CODIGO \t\tNOMBRE   \t\t     LOCALIDAD\n\n");
    for(i=0; i<cant; i++)
    {
        if(list[i].estado == OCUPADO)
        {
            mostrarUnEquipo(list[i]);
        }

    }
}

void mostrarUnJugador(eJugadores unJugador)
{
    printf("%03d %20s \t %20s \t %03d \t\t %c  %02d/%02d/%4d\n", unJugador.codigo
           , unJugador.nombre
           , unJugador.apellido
           , unJugador.codigoDeEquipo
           , unJugador.sexo
           , unJugador.fechaNacimiento.dia
           , unJugador.fechaNacimiento.mes
           , unJugador.fechaNacimiento.anio);
}
void mostrarListadoDeJugadores(eJugadores list[], int cant)
{
    int i;
    printf("CODIGO \t\t  NOMBRE  \t\t   APELLIDO  \t COD EQUIPO \t SEXO          FECHA NACIMIENTO \n\n");
    for(i=0; i<cant; i++)
    {
        if(list[i].estado == OCUPADO)
        {
            mostrarUnJugador(list[i]);
        }

    }
}

void mostrarUnReferee(eReferi unReferi)
{
    printf("%03d %20s \t %20s \t %c \t %20s \t %02d/%02d/%4d\n", unReferi.codigo
           , unReferi.nombre
           ,unReferi.apellido
           ,unReferi.sexo
           ,unReferi.eMail
           , unReferi.fechaNacimiento.dia
           , unReferi.fechaNacimiento.mes
           , unReferi.fechaNacimiento.anio);
}

void mostrarListadoDeReferees(eReferi list[], int cant)
{
    int i;
    printf("CODIGO \t   NOMBRE  \t APELLIDO  \t SEXO    EMAIL \t   FECHA DE NACIMIENTO\n\n");
    for(i=0; i<cant; i++)
    {
        if(list[i].estado == OCUPADO)
        {
            mostrarUnReferee(list[i]);
        }

    }
}

void mostrarUnPartido(ePartidos unPartido)
{
    printf("%03d \t\t %03d \t\t %03d \t\t %03d \t\t %02d/%02d/%4d\n", unPartido.codigo
           ,unPartido.codigoDeEquipoLocal
           ,unPartido.codigoDeEquipoVisitante
           ,unPartido.codigoDeReferi
           , unPartido.fechaDePartido.dia
           , unPartido.fechaDePartido.mes
           , unPartido.fechaDePartido.anio);
}

void mostrarListadoDePartidos(ePartidos list[], int cant)
{
    int i;
    printf("CODIGO \t   CODIGO LOCAL    CODIGO VISITANTE     CODIGO REFEREE     FECHA \n\n");
    for(i=0; i<cant; i++)
    {
        if(list[i].estado == OCUPADO)
        {
            mostrarUnPartido(list[i]);
        }

    }
}

int ordenarJugadoresPorApellido(eJugadores list[],int cant)
{
    eJugadores auxJugador;
    int i;
    int j;
    int r = -1;
    if(cant > 0 && list != NULL)
    {
        for(i=0; i<cant-1; i++)
        {
            for(j=i+1; j<cant; j++)
            {
                if(strcmp(list[i].apellido, list[j].apellido) > 0)
                {
                    //De A - Z
                    auxJugador = list[i];
                    list[i] = list[j];
                    list[j] = auxJugador;
                }
            }

        }
        r = 0;
    }
    return r;
}

int ordenarEquiposPorNombre(eEquipos list[],int cant)
{
    eEquipos auxEquipo;
    int i;
    int j;
    int r = -1;
    if(cant > 0 && list != NULL)
    {
        for(i=0; i<cant-1; i++)
        {
            for(j=i+1; j<cant; j++)
            {
                if(strcmp(list[i].nombre, list[j].nombre) > 0)
                {
                    //De A - Z
                    auxEquipo = list[i];
                    list[i] = list[j];
                    list[j] = auxEquipo;
                }
            }

        }
        r = 0;
    }
    return r;
}

int ordenarPartidosPorFecha(ePartidos list[],int cant)
{
    ePartidos auxPartido;
    int i;
    int j;
    int r = -1;
    if(cant > 0 && list != NULL)
    {
        for(i=0; i<cant-1; i++)
        {
            for(j=i+1; j<cant; j++)
            {
                if(list[i].fechaDePartido.anio > list[j].fechaDePartido.anio)
                {
                    //De A - Z
                    auxPartido = list[i];
                    list[i] = list[j];
                    list[j] = auxPartido;
                }
            }

        }

        r = 0;
    }
    return r;
}

int relacionJugadorEquipo(eJugadores unJugador,eEquipos listE[],int cantE)
{
    int i;
    int r=-2;
    for(i=0; i<cantE; i++)
    {
        if(listE[i].estado == OCUPADO && unJugador.codigoDeEquipo == listE[i].codigo)
        {
            r = 0;
            break;
        }
    }
    return r;
}

int relacionPartidoEquipoLocal(ePartidos unPartido, eEquipos listE[], int cantE)
{
    int i;
    int r=-2;
    for(i=0; i<cantE; i++)
    {
        if(listE[i].estado == OCUPADO && unPartido.codigoDeEquipoLocal == listE[i].codigo)
        {
            r = 0;
            break;
        }
    }
    return r;
}

int relacionPartidoEquipoVisitante(ePartidos unPartido, eEquipos listE[], int cantE)
{
    int i;
    int r=-2;
    for(i=0; i<cantE; i++)
    {
        if(listE[i].estado == OCUPADO && unPartido.codigoDeEquipoVisitante == listE[i].codigo)
        {
            r = 0;
            break;
        }
    }
    return r;
}

int relacionPartidoReferi(ePartidos unPartido, eReferi listR[], int cantR)
{
    int i;
    int r=-2;
    for(i=0; i<cantR; i++)
    {
        if(listR[i].estado == OCUPADO && unPartido.codigoDeReferi == listR[i].codigo)
        {
            r = 0;
            break;
        }
    }
    return r;
}

int flagJugadores(eJugadores list[], int cant)
{
    int r = -1;
    int i;

    for(i=0; i<cant; i++)
    {
        if(list[i].estado == OCUPADO)
        {
            r = 0;
            break;
        }
    }

    return r;
}

int flagEquipos(eEquipos list[], int cant)
{
    int r = -1;
    int i;

    for(i=0; i<cant; i++)
    {
        if(list[i].estado == OCUPADO)
        {
            r = 0;
            break;
        }
    }

    return r;
}


int flagPartidos(ePartidos list[], int cant)
{
    int r = -1;
    int i;

    for(i=0; i<cant; i++)
    {
        if(list[i].estado == OCUPADO)
        {
            r = 0;
            break;
        }
    }

    return r;
}

void hardcodeoEquipos(eEquipos list[], int cant)
{
    int i;
    char equipos[][51] = {"CAI","FCA","Talleres","San Lorenzo","Club Moron"};
    char localidades[][33] = {"Lomas de Zamora","Moron","Lanus","Adrogue","CABA"};
    for(i=0; i<cant; i++)
    {
        strcpy(list[i].nombre, equipos[i]);
        strcpy(list[i].localidad, localidades[i]);
        list[i].codigo = i;
        list[i].estado = OCUPADO;
    }
}

void hardcodeoJugadores(eJugadores list[], int cant)
{
    int i;

    char Nombres[][50]= {"AGUSTIN","FERNANDO","LAURA","LUIS","FELIPE"};
    char Sexo[]= {'m','m','m','f','f'};
    char Apellido[][50]= {"Gonzalez","Rodriguez","Gomez","Fernandez","Lopez","Diaz"};
    int codigoEquipos[] = { 1,2,3,4,5};
    int anios[]= {2000,2002,1991,1993,1990};
    int mes[]= {3,1,4,6,9,12};
    int dia[]= {1,3,8,7,4};
    for(i=0; i<cant; i++)
    {
        strcpy(list[i].nombre, Nombres[i]);
        list[i].sexo = Sexo[i];
        strcpy(list[i].apellido, Apellido[i]);
        list[i].codigoDeEquipo = codigoEquipos[i];
        list[i].fechaNacimiento.anio = anios[i];
        list[i].fechaNacimiento.mes = mes[i];
        list[i].fechaNacimiento.dia = dia[i];
        list[i].codigo = i;
        list[i].estado = OCUPADO;
    }
}

void hardcodeoReferees(eReferi list[], int cant)
{
    int i;
    char Nombres[][50]= {"Jose","Luis","Fernando","Sebastian","Fernanda"};
    char Apellido[][50]= {"Franche","Masa","Sireno","Bustos","Gucci","Martinez"};
    char Sexo[]= {'m','m','m','m','f'};
    int anios[]= {1965,1990,1978,1972,1990,1987};
    int mes[]= {3,4,6,8,1,1};
    int dia[]= {1,3,15,12,7,4};

    for(i=0; i<cant; i++)
    {
        strcpy(list[i].nombre, Nombres[i]);
        list[i].sexo = Sexo[i];
        strcpy(list[i].apellido, Apellido[i]);
        list[i].fechaNacimiento.anio = anios[i];
        list[i].fechaNacimiento.mes = mes[i];
        list[i].fechaNacimiento.dia = dia[i];
        list[i].codigo = i;
        list[i].estado = OCUPADO;
    }
}

void hardcodeoPartidos(ePartidos list[], int cant)
{
    int i;
    int visitante[] = {1,2,3,4,5,6,7,8,9};
    int local[]= {10,9,8,7,6,4,3,2,1};
    int dia[]= {12,17,20,5,6,9,2,11};
    int mes[]= {1,2,3,4,5,6,7,8,91};
    int anio[]= {2019,2019,2019,2019,2019,2019,2019,2019,2019};
    int referi[]= {2,5,2,9,2,3,4,5,6};


    for(i=0; i<cant; i++)
    {
        list[i].codigoDeEquipoLocal = local[i];
        list[i].codigoDeEquipoVisitante = visitante[i];
        list[i].fechaDePartido.dia = dia[i];
        list[i].fechaDePartido.mes = mes[i];
        list[i].fechaDePartido.anio = anio[i];
        list[i].codigoDeReferi = referi[i];
        list[i].codigo = i;
        list[i].estado = OCUPADO;
    }
}

int modificarEquipo(eEquipos list[],int cant)
{
    int i;
    int opcion;
    int r = -1;
    mostrarListadoDeEquipos(list, cant);
    i = buscarEquipoPorCodigo(list, cant);
    if(i != -1)
    {
        mostrarUnEquipo(list[i]);
        printf("\n\n¿Que desea modificar?\n\n");
        printf("1. Nombre.\n");
        printf("2. Localidad.\n");
        printf("Ingrese una opcion: ");
        scanf("%d", &opcion);
        switch(opcion)
        {
        case 1:
            printf("\nIngrese el nuevo nombre : ");
            enterString(list[i].nombre);
            r = 0;
            break;
        case 2:
            printf("Ingrese la nueva localidad : ");
            enterString(list[i].localidad);
            r = 0;
            break;
        default:
            r = 1;
        }
    }
    return r;
}

int buscarEquipoPorCodigo(eEquipos list[],int cant)
{
    int i;
    int index = -1;
    int codigo;
    codigo = enterInt("\nIngrese el codigo del equipo : ");
    for(i=0; i<cant; i++)
    {
        if(list[i].codigo == codigo)
        {
            index = i;
            break;
        }
    }
    return index;
}

int buscarJugadorPorCodigo(eJugadores list[], int cant)
{
    int i;
    int index = -1;
    int codigo;
    codigo = enterInt("\nIngrese el codigo del jugador : ");
    for(i=0; i<cant; i++)
    {
        if(list[i].codigo == codigo)
        {
            index = i;
            break;
        }
    }
    return index;
}

int bajarEquipo(eEquipos list[], int cant)
{
    int r = -1;
    int i;
    char respuesta;
    mostrarListadoDeEquipos(list, cant);
    i = buscarEquipoPorCodigo(list, cant);
    if(i != -1)
    {
        mostrarUnEquipo(list[i]);
        printf("\nIngrese s para confirmar la accion : ");
        fflush(stdin);
        respuesta = getchar();
        if(respuesta == 's')
        {
            list[i].estado=LIBRE;
            r = 0;
        }
        else
        {
            r = 1;
        }
    }
    return r;
}

int bajarJugador(eJugadores list[], int cant)
{
    int r = -1;
    int i;
    char respuesta;
    mostrarListadoDeJugadores(list, cant);
    i = buscarJugadorPorCodigo(list, cant);
    if(i != -1)
    {
        mostrarUnJugador(list[i]);
        printf("\nEsta seguro que desea dar de baja el jugador?: SI---'s'    NO---'n' ");
        fflush(stdin);
        respuesta = getchar();
        if(respuesta == 's')
        {
            list[i].estado=LIBRE;
            r = 0;
        }
        else
        {
            r = 1;
        }
    }
    return r;
}

int mostrarJugadoresPorEquipo(eJugadores listJ[], eEquipos listE[], int cantJ,int cantE)
{
    int i;
    int r = -1;
    int j;
    mostrarListadoDeEquipos(listE, cantE);
    j = buscarEquipoPorCodigo(listE, cantE);
    if(j!=-1)
    {
        for(i=0; i<cantJ; i++)
        {
            if(listJ[i].codigoDeEquipo == listE[j].codigo)
            {
                mostrarUnJugador(listJ[i]);
            }
        }
        r = 0;
    }
    return r;
}

int mostrarJugadoresPorNombre(eJugadores list[],int cant)
{
    int i;
    char nombre[51];
    int r = -1;
    int r1;
    printf("Ingrese nombre del jugador : ");
    enterString(nombre);
    r1 = onlyLetters(nombre);
    while(r1==-2)
    {
        printf("\nSolo se aceptan letras, reingrese nombre: ");
        enterString(nombre);
        r1 = onlyLetters(nombre);
    }
    for(i=0; i<cant; i++)
    {
        if(stricmp(list[i].nombre, nombre)==0)
        {
            mostrarUnJugador(list[i]);
            r = 0;
        }
    }
    return r;
}

/*void mostrarEquipoMasLargo(eEquipos list[], int cant)
{
    int largo;
    int maximo;
    int j;
    int flag = 0;
    int i;
    for(i=0; i<cant-1; i++)
    {
        if(flag == 0 || largo[i] > largo)
        {
            flag = 1;
        }
    }
}*/

int mostrarPartidosPorFecha(ePartidos list[], int cant)
{
    int dia;
    int mes;
    int anio;
    int i;
    int r=-1;
    printf("Ingresar fecha del partido\n");
    dia = enterInt("Dia : ");
    mes = enterInt("Mes : ");
    anio = enterInt("Anio : ");

    for(i=0; i<cant; i++)
    {
        if(list[i].fechaDePartido.dia == dia && list[i].fechaDePartido.mes == mes && list[i].fechaDePartido.anio == anio)
        {
            mostrarUnPartido(list[i]);
            r = 0;
        }
    }
    return r;
}

void promedioEdadesPorEquipo(eJugadores listJ[],eEquipos listE[],int cantJ, int cantE)
{
    int i;
    int j;
    int contador = 0;
    int acumulador = 0;
    int maximoCodigo = 0;
    float promedio = 0;
    float maximoPromedio = 0;
    int flag = 0;
    for(i=0; i<cantE; i++)
    {
        for(j=0; j<cantJ; j++)
        {
            if(listE[i].codigo == listJ[j].codigoDeEquipo)
            {
                acumulador = acumulador + listJ[j].fechaNacimiento.anio;
                contador ++;
            }
        }
        promedio = acumulador / contador;
        if(flag == 0 || promedio > maximoPromedio)
        {
            maximoCodigo = listE[i].codigo;
            maximoPromedio = promedio;
            flag = 1;
        }
        acumulador = 0;
        contador = 0;
        promedio = 0;
    }
    printf("El equipo mas joven es : \n");
    for(i=0;i<cantE;i++)
    {
        if(maximoCodigo == listE[i].codigo)
        {
            mostrarUnEquipo(listE[i]);
        }
    }
}
