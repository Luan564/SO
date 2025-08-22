#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

int menu(void);

int main(void)
{
	int opcion;
	TipoDato dato;
	Nodo *cabecera, *nodo;	
	
	crearLista(&cabecera);
	do{
		opcion = menu();
		switch(opcion){
			case 1:
				printf("Ingrese: ");
				scanf("%d", &dato);
				nodo = crearNodo(dato);
				insertarOrden(&cabecera,nodo);
				break;
			case 2:
				printf("Ingrese: ");
				scanf("%d", &dato);
				nodo = extraer(&cabecera,dato);
				if(nodo!=NULL)
				{
					eliminar(nodo);
				}
				else
				{
					printf("Lista vacía o elemento no encontrado");
				}
				break;
			case 3:
				printf("Ingrese: ");
				scanf("%d", &dato);
				nodo = buscar(cabecera, dato);
				if(nodo != NULL)
					printf("\nSe encontró el dato en la lista.\n");
				else
					printf("\nNo está el dato en la lista.\n");
				break;
			case 4:
				printf("Ingrese: ");
				scanf("%d", &dato);
				nodo=copiar(cabecera, dato);	//Nodo encontrado y creado
				if(nodo!=NULL)
				{
					insertarOrden(&cabecera, nodo);		//Se incerta el nodo creado
				}
				else
				{
					printf("Elemento no copiado\n");
				}
				break;
			case 5:
				imprimir(cabecera);
				break;
			case 6:
				break;
			default:
				printf("\nOpción inválida.\n");
				break;
		}
		printf("\n");
	}while(opcion != 6);
	
	return 0;
}

int menu(void)
{
	int opcion;
	
	printf("MENÚ.\n");
	printf("--------\n");
	printf("1. Insertar en orden.\n");
	printf("2. Extraer elemento específico.\n");
	printf("3. Buscar.\n");
	printf("4. Copiar.\n");
	printf("5. Imprimir.\n");
	printf("6. Salir.\n");
	printf("--------\n");
	printf("Opción: ");
	scanf("%d", &opcion);
	
	return opcion;
}