#ifndef _LISTA_H_
#define _LISTA_H_

typedef int TipoDato;

typedef struct nodo
{
	TipoDato dato;
	struct nodo *siguiente;
}Nodo;


void crearLista(Nodo **);
Nodo *crearNodo(TipoDato);
void insertarOrden(Nodo **, Nodo *);
Nodo *extraer(Nodo **,TipoDato);
void eliminar(Nodo *);
Nodo *buscar(Nodo *, TipoDato);
Nodo *copiar(Nodo *, TipoDato);
void imprimir(Nodo *);

#endif