
typedef struct{
    int ID;
    char nombre[51];
    char apellido[51];
    float salario;
    int sector;
    int estaVacio;
}Persona;

int TomarEntero(char mensaje[]);

float getFloat(char mensaje[]);  //Tomar decimal

char getChar(char mensaje[]);  //Tomar char

char getNumeroAleatorio(int desde , int hasta, int iniciar);

int esNumerico(char str[]);

int esTelefono(char str[]);

int esAlfaNumerico(char str[]);

int esSoloLetras(char str[]);

void getString(char mensaje[],char input[]);

int getStringLetras(char mensaje[],char input[]);

int getStringNumeros(char mensaje[],char input[]);
