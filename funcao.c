#include "funcao.h"
#include <stdlib.h>
#include <stdio.h>

int ** alocaGrafo (int numVertices) {
    int i;
    int ** grafo;
    grafo = (int**) malloc(numVertices*sizeof(int*));
    for (i = 0; i < numVertices; i++) {
        grafo[i] = (int*) malloc(numVertices*sizeof(int));
    }
    return grafo;
}

int ** leGrafo (int numVertices, FILE * file) {
    int i, j;
    int ** grafo;

    grafo = alocaGrafo(numVertices);

    for(i = 0; i < numVertices; i++) {
        for(j = 0; j < numVertices; j++){
          fscanf(file, "%d", &grafo[i][j]);
       }
    }
    return grafo;
}

void liberaGrafo(int ** grafo, int numVertices){
    int i;
    for (i = 0; i < numVertices; i++) {
        free(grafo[i]);
    }
    free (grafo);
}