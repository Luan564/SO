#ifndef ENTRADA_H
#define ENTRADA_H

#include "include/controlador.h"

int extraerComando(buffer *bufferC);
void leerComando(char *comando);
void limpiarBuffer(buffer *bufferC);

void reiniciarRegistros();
void igualarRegistros(PCB *nodo);
void interprete(char *comando);

int kbhito(void);


#endif