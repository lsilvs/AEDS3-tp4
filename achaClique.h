#ifndef FINDMAX_H_INCLUDED
#define FINDMAX_H_INCLUDED

#include "list.h"

int achaClique(int ** Matriz, int numVertices);

int auxFunc(int ** Matriz, TipoLista* C, TipoLista* P, int numVertices, int maxSize);

#endif // FINDMAX_H_INCLUDED
