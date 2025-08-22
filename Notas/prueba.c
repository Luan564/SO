#include <stdio.h>
#include <stdlib.h>


typedef struct prueba{
    int id;
    struct prueba *sig;
} st;

void crearLista(st **cabecera){
	*cabecera = NULL;
    printf("Lista creada con exito\n");
}

st *crear(int valor){
    st *nuevo;

    nuevo = (st *)malloc(sizeof(nuevo));
    if(nuevo != NULL){
        nuevo->id = valor;
        nuevo->sig = NULL;
    }   
    //printf("%d -> %p\n", nuevo->id, nuevo->sig);
    return nuevo;
}

void insertarFinal(st **cabecera, st *nodo){
    
    if(*cabecera == NULL){
        *cabecera = nodo;
    }
    else{
        st *aux = *cabecera;
        while(aux->sig != NULL){
            aux = aux->sig;
        }
        aux->sig = nodo;
    }
}

void recorrer(st **cabecera){
    if(*cabecera != NULL){
        st *siguiente = *cabecera;
        while(siguiente->sig != NULL){
            printf("%d -> ", siguiente->id);
            siguiente = siguiente->sig;
        }
        printf("%d -> NULL\n", siguiente->id);
    }
}

void eliminar(st *nodo){
    free(nodo);
}

void remover(st **cabecera, int valor){
    if(*cabecera != NULL){
        st *anterior;
        st *aux = *cabecera;
        //caso donde se elimina la cabecera
        if(aux->id == valor){
            printf("Valor encontrado en la cabecera!\n");
            *cabecera = aux->sig;
            eliminar(aux);
            return;
        }
        while(aux->id != valor){
            if(aux->sig != NULL){
                anterior = aux;
                aux = aux->sig;
                continue;
            }
            else{
                printf("No se ha encontrado el elemento dentro de la lista!\n");
                return;
            }
        }
        if(aux->id == valor){
            printf("Valor encontrado!\n");
            anterior -> sig = aux -> sig;
            eliminar;
            return;
        }
    }
}

int main(){
    st *inicio;
    st *nodo;

    crearLista(&inicio);
    nodo = crear(4);
    insertarFinal(&inicio, nodo);
    printf("%d -> %p\n", inicio->id, inicio->sig);
    nodo = crear(1);
    insertarFinal(&inicio, nodo);
    printf("%d -> %p\n", inicio->id, inicio->sig);
    nodo = crear(7);
    insertarFinal(&inicio, nodo);
    printf("%d -> %p\n", inicio->id, inicio->sig);
    recorrer(&inicio);
    remover(&inicio, 1);
    recorrer(&inicio);

}