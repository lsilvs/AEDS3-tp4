#ifndef FUNCAO_H_INCLUDED
#define FUNCAO_H_INCLUDED

#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

// Aloca memória para o grafo
int ** alocaGrafo (int numVertices);

// Lê o grafo
int ** leGrafo (int numVertices, FILE * file);

// Libera a memória do grafo
void liberaGrafo(int ** grafo, int numVertices);

#endif // FUNCAO_H_INCLUDED