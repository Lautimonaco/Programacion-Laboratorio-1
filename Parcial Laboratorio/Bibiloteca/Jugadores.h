
typedef struct {
    int dia;
    int mes;
    int anio;
}eFecha;


typedef struct
{
    int CodigoJugadores;
    char apellido[31];
    char nombre[31];
    char localidad[31];
    char sexo;
    eFecha fechaNac;
}eJugadores;

