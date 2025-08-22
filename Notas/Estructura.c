#include <stdio.h>
#include <string.h>
#include "operaciones.h"

struct contacto{
    char nombre[10];
    int numero;
};

typedef struct simon{
    int id;
} a;


int main(){
    struct contacto a1;
    char *name = "Luan";
    strcpy(a1.nombre, name);
    a1.numero = 44;

    printf("Valores del alumno No.1\n");
    printf("Nombre: %s\n",a1.nombre);
    printf("Numero: %d\n\n",a1.numero);
    
    //ahora lo modificaremos con punteros

    struct contacto *apt;

    apt = &a1;

    pasoPorReferencia(&apt->numero);

    printf("Valores del alumno con apuntador\n");
    printf("Nombre: %s\n",apt->nombre);
    printf("Numero: %d\n",apt->numero);

    a alumno;

    alumno.id;
    




    return 0;
}