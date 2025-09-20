#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct tarea{
    int id;
    char desc[150];
    int hr;
    struct tarea *sig;
}Nodo;

void menuMain();
void crearNodoUsuario(Nodo **inicio);
void editarNodoUsuario(Nodo **inicio);
void eliminarNodoUsuario(Nodo **inicio);

Nodo *crearNodo(int identificador, char *descripcion, int hora);
void agregarNodo(Nodo **inicio, Nodo *nodo);
void mostrar(Nodo **inicio);
Nodo *buscar(Nodo **incio, int id);
void editar(Nodo **incio, int id);
void eliminar(Nodo **incio, int id);

int id = 0;

int main(){
    
    Nodo *cabecera, *nuevo ;
    cabecera = nuevo = NULL;
    
    // nuevo = crearNodo(1, "Simon", 7);
    // agregarNodo(&cabecera, nuevo);
    // nuevo = crearNodo(1, "Simon", 9);
    // agregarNodo(&cabecera, nuevo);
    // nuevo = crearNodo(1, "Simon", 3);
    // agregarNodo(&cabecera, nuevo);
    // nuevo = crearNodo(1, "Simon", 6);
    // agregarNodo(&cabecera, nuevo);
    // nuevo = crearNodo(1, "Simon", 13);
    // agregarNodo(&cabecera, nuevo);
    // nuevo = crearNodo(1, "Simon", 10);
    // agregarNodo(&cabecera, nuevo);
    // nuevo = crearNodo(1, "Simon", 1);
    // agregarNodo(&cabecera, nuevo);
    // mostrar(&cabecera);
    // eliminar(&cabecera, 7);
    // mostrar(&cabecera);
    // eliminar(&cabecera, 8);
    // eliminar(&cabecera, 1);
    // mostrar(&cabecera);
    // eliminar(&cabecera, 13);
    // mostrar(&cabecera);
    // editar(&cabecera, 9);

    // mostrar(&cabecera);




    int op, *ptr;
    ptr = &id;
    do{
        menuMain();
        scanf("%d",&op);
        getchar();
        switch (op)
        {
        case 1:
            system("clear");
            crearNodoUsuario(&cabecera);
            break;
        case 2:
            system("clear");
            editarNodoUsuario(&cabecera);
            break;
        case 3:
            system("clear");
            eliminarNodoUsuario(&cabecera);
            break;
        case 4:
            system("clear");
            mostrar(&cabecera);
            break;
        case 5:
            system("clear");
            printf("Le falta un leve\n");
            exit(0);
            break;
        default:
            printf("Opcion no reconocida\n");
            break;
        }
    }while(1);

    return 0;
}

void menuMain(){
    system("clear");
    printf("----Agenda de tareas----\n");
    printf("1. Agregar\n");
    printf("2. Editar\n");
    printf("3. Completar\n");
    printf("4. Mostrar\n");
    printf("5. Salir\n");
    printf("Seleccione una opcion: ");
}

void crearNodoUsuario(Nodo **inicio){
    char descripcion[150];
    int hrs;
    
    printf("Ingrese una descripcion: ");
    scanf("%[^\n]",descripcion);
    printf("Ingrese la hora: ");
    scanf("%d",&hrs);
    if(hrs > 0 && hrs < 24){
        agregarNodo(inicio, crearNodo(id++, descripcion, hrs));
        system("clear");
        printf("Nodo agregado correctamente...\nPresiona ENTER para continuar\n");
        getchar();
        getchar();
    }else{
        printf("Horario no valido\n");
    }
}

void editarNodoUsuario(Nodo **inicio){
    int id;

    printf("id de la tarea a editar: ");
    scanf("%d",&id);
    getchar();
    editar(inicio, id);
    system("clear");
    printf("Nodo editado correctamente...\nPresiona ENTER para continuar\n");
    getchar();
    getchar();
}

void eliminarNodoUsuario(Nodo **inicio){
    int id;

    printf("id de la tarea completada: ");
    scanf("%d",&id);
    eliminar(inicio, id);
    system("clear");
    printf("Nodo eliminado correctamente...\nPresiona ENTER para continuar\n");
    getchar();
    getchar();
}

Nodo *crearNodo(int identificador, char *descripcion, int hora){
    Nodo *nuevo;
    
    nuevo = (Nodo *) malloc(sizeof(Nodo));
    if(nuevo != NULL){
        nuevo->id = identificador;
        strcpy(nuevo->desc, descripcion);
        nuevo->hr = hora;
        nuevo->sig = NULL;
    }
    return nuevo;
}

void agregarNodo(Nodo **inicio, Nodo *nodo){
    Nodo *actual;
    actual = *inicio;
    if(*inicio == NULL){
        *inicio = nodo;
    }
    else if(nodo->hr <= actual->hr){
        nodo->sig = actual;
        *inicio = nodo;    
    }
    else{
        Nodo *anterior;
        anterior = *inicio;
        while(actual != NULL){
            if(nodo->hr <= actual->hr){
                nodo->sig = actual;
                break;
            }
            else{
                anterior = actual;
                actual = actual->sig;
                continue;
            }
        }
        anterior->sig=nodo;
    }
}

void mostrar(Nodo **inicio){
    Nodo *actual = *inicio;
    if(actual == NULL){
        printf("La agenda esta vacia\n");
        return;
    }else{
        while(actual->sig != NULL){
            printf("[%d: %s, %d] -> ",actual->id, actual->desc, actual->hr);
            actual = actual->sig;
        }
        printf("[%d: %s, %d] -> NULL\n",actual->id, actual->desc, actual->hr);
        printf("Presiona ENTER para continuar\n");
        getchar();
    }
}

Nodo *buscar(Nodo **incio, int id){
    Nodo *anterior, *actual;
        actual = *incio;
        if(id == actual->id){       //cambiar hr por id 
            *incio = actual->sig;
            actual->sig = NULL;
            return actual;
        }
        else{
            while(actual->sig != NULL){
                anterior = actual;
                actual = actual->sig;
                if(id == actual->id){       //cambiar hr por id 
                    anterior->sig = actual->sig;
                    actual->sig = NULL;
                    return actual;
                }
            }
        }
        return NULL;
}

void editar(Nodo **incio, int id){
    Nodo *edit = NULL;
    char descripcion[150];
    int hrs;

    edit = buscar(incio, id);
    if(edit != NULL){
        printf("Descripcion: ");
        scanf("%[^\n]",descripcion);
        printf("Horas: ");
        scanf("%d",&hrs);

        agregarNodo(incio, crearNodo(edit->id, descripcion, hrs));
        free(edit); //No uso eliminar porque ya encontre el nodo que necesito eliminar
    }
}

void eliminar(Nodo **incio, int id){
    free(buscar(incio, id));
}
