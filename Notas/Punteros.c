#include <stdio.h>
#include "operaciones.h"

//El * se usa para acceder al valor almacenado e la direccion de memoria a la que apunta el puntero.
//El & se utiliza para obtener la direccion de memoria de una variable.
int main(){
    
    int valor = 444;
    int *puntero = &valor; 
    printf("%d\n", *puntero);   //Devolvera el valor almacenado de la direccion de memoria a la que apunta en este caso 10
    printf("%p\n", puntero);    //Devolvera la direccion a la que apunta ya que puntero no esta guardando un valor, si no una dirección de memoria

    /*
    Haremos un breve ejemplo de paso por referencia y paso por valor
    
    Recordemos que paso por valor es cuando se hace una copia del valor de la variable y se pasa a la funcion. Cualquier cambio realizado dentro de la función no afecta a la variable original.
    Paso por referencia se pasa la direccion de memoria de la variable, lo que significa que la funcion puede acceder y modificar directamente la variable original.
    */

    int original = 777;
    printf("Paso por valor = %d\n",pasoPorValor(original));
    printf("Print de \"original\" = %d\n\n", original);

    printf("Paso por referencia = %d\n",pasoPorReferencia(&original));  //Aqui le pasamos la direccion de memoria de esta manera
    printf("Print de \"original\" = %d\n\n", original);

    printf("Print de \"valor\" = %d\n", valor);
    printf("Paso por referencia = %d\n",pasoPorReferencia(puntero));    ////Aqui le pasamos la direccion de memoria mediante un puntero
    printf("Print de \"valor\" = %d\n", valor);

    return 0;
}


