//operaciones.h 
/* 
En los .h podemos incluir:
1.- Declaraciones de funciones      int func(int a, int b); 
2.- Definicion de una estructura    typedef struct {int x; int y;} Punto;
3.- Definicion de una macro         DEFINE PI 3.1416
*/
#include "operaciones.c"


int suma (int a, int b);
int resta (int a, int b);
int multiplicacion (int a, int b);
float division (float a, float b);

int pasoPorValor(int a);
int pasoPorReferencia(int *a);
