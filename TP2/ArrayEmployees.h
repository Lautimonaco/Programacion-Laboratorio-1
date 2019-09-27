#define MAX 1000

typedef struct{
    char name[MAX];
    char lastname[MAX];
    float salario;
    int sector;
    int estaVacio;
    int ID;
}Employee;

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




/** \brief To indicate that all position in the array are empty,
 * this function put the flag (isEmpty) in TRUE in all
 * position of the array
 * \param list Employee* Pointer to array of employees
 * \param len int Array length
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*/
void initEmployees(Employee arrayEmployees[],int cantidadDeElementos,int valor);



/** \brief add in a existing list of employees the values received as parameters
 * in the first empty position
 * \param list employee*
 * \param len int
 * \param id int
 * \param name[] char
 * \param lastName[] char
 * \param salary float
 * \param sector int
 * \return int Return (-1) if Error [Invalid length or NULL pointer or without
free space] - (0) if Ok
*/
int addEmployees(Employee arrayEmployees[],int cantidad,int valor);


//void CargarEmpleados(Employee arrayPersonas[], int cantidad);

