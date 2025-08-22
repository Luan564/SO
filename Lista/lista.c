#include <stdlib.h>
#include <stdio.h>
#include "lista.h"

void crearLista(Nodo **cabecera)
{
	*cabecera = NULL;
}

Nodo *crearNodo(TipoDato dato)
{
	Nodo *nuevo;
	
	nuevo = (Nodo *) malloc(sizeof(Nodo));
	if(nuevo != NULL){
		nuevo -> dato = dato;
		nuevo -> siguiente = NULL;
	}
	
	return nuevo;
}

void insertarOrden(Nodo **cabecera, Nodo *nodo)
{
	Nodo *anterior, *actual;
	
	if(*cabecera == NULL)
		*cabecera = nodo;
	else if( (nodo->dato) < (*cabecera) -> dato){	//Inserción por la izquierda
		nodo -> siguiente = *cabecera;
		*cabecera = nodo;
	}
	else{ // Búsqueda del nodo anterior a partir del que se debe insertar.		
		anterior = actual = *cabecera;
		while((actual -> siguiente != NULL) && (nodo -> dato > actual -> dato)){
			anterior = actual;
			actual = actual -> siguiente;
		}
		if(nodo->dato > actual -> dato) // Inserta por el final.
			anterior = actual;
		// Se procede al enlace del nodo nodo.
		nodo -> siguiente = anterior -> siguiente;
		anterior -> siguiente = nodo;
	}
}

Nodo *extraer(Nodo **cabecera, TipoDato dato)
{
	Nodo *actual, *anterior;
	int encontrado = 0;
	
	anterior = NULL;
	actual = *cabecera;
	// Búsqueda del nodo y del anterior.
	while((actual != NULL) && (!encontrado)){	//Si lo encuentra, actual estará en el nodo buscado 
		encontrado = (actual -> dato == dato);
		if(!encontrado){
			anterior = actual;
			actual = actual -> siguiente;
		}
	}

	// Enlace del nodo anterior con el siguiente.
	if(actual != NULL){
		// Distingue si el nodo es el cabecera u otro del resto de la lista.
		if(actual == *cabecera)
			{
				*cabecera = actual -> siguiente;
				actual->siguiente=NULL;
			}
		else
			{
				anterior -> siguiente = actual -> siguiente;
				actual->siguiente=NULL;
			}
		return actual;
	}
	else
	{
		return NULL;	//Si no hay nodos o no se encontró el dato 
	}
} 

void eliminar(Nodo *nodo)
{
	free(nodo);
}

// Devuelve el nodo que coincide con el dato o devuelve nulo si no lo encuentra.
Nodo* buscar(Nodo *cabecera, TipoDato dato)
{
	Nodo *indice;	//Nodo a eliminar		//YA NO SE EXTRAE POR MEDIO DE LA FUNCION BUSCAR O SI??
	
	for(indice = cabecera; indice != NULL; indice = indice -> siguiente){
		if(dato == indice -> dato)
		{
			return indice;
		}
	}
	return NULL;
}

Nodo *copiar(Nodo *cabecera, TipoDato dato)
{
	Nodo *nodo;
	
	nodo=buscar(cabecera,dato);		//Busca el nodo a copiar 
	if(nodo!= NULL)				//Indica que si se encontró el elemento en la lista
	{
		nodo=crearNodo(nodo->dato);	//Se crea el nuevo nodo
		return nodo;
	}
	else
	{
		return NULL;
	}
}

void imprimir(Nodo *cabecera)
{
	while(cabecera != NULL){
		printf("%d -> ", cabecera -> dato);
		cabecera = cabecera -> siguiente;
	}
	printf("NULL");
}