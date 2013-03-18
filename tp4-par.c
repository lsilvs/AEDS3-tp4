/*
*   Problemas NP-Completo e Programacao Paralela
*       Autor: Lucas Silvestre (2010054665)
*       Data: 19/12/2012
*/

#include <stdio.h>
#include <stdlib.h>
#include "funcao.h"
#include "achaClique.h"
#include <pthread.h>

struct args {
    int ** valoresGrafo;
    int numVertices;
    int instancia;
};

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
int result[10000];

int main(int argc, char *argv[]) {
    // Inicializa variáveis
    char * inputFileName = argv[1];
    char * outputFileName = argv[2];
    int numVertices, numInstancias, numThreads, i, j;
    int ** valoresGrafo = NULL;

    // Seta o número de threads
    if (argv[3]) {
        numThreads = atoi(argv[3]);
    } else {
        numThreads = 1;
    }

    pthread_t thr[numThreads]; 
    void * entryPoint();

    // Abre arquivo de entrada
    FILE * inputFileOpen;
    if ((inputFileOpen = fopen(inputFileName, "r")) == NULL) {
        printf("Nao foi possivel abrir o arquivo.\n");
    }

    // Abre arquivo de saída
    FILE * outputFileOpen;
    if ((outputFileOpen = fopen(outputFileName, "w")) == NULL) {
        printf("Nao foi possivel abrir o arquivo.\n");
    }

    // Lê o número de instâncias
    fscanf(inputFileOpen, "%d", &numInstancias);

    // Percorre as instâncias do arquivo
    for (i = 0; i < numInstancias; i = i+j) {

        for(j = 0; j < numThreads; j++) {
            fscanf(inputFileOpen, "%d", &numVertices);
            valoresGrafo = leGrafo(numVertices, inputFileOpen);
            struct args *variaveis = malloc(sizeof(struct args));
            variaveis->valoresGrafo = valoresGrafo;
            variaveis->numVertices = numVertices;
            variaveis->instancia = i+j;
            pthread_create(&thr[j], NULL, entryPoint, variaveis);
        }

        for(j = 0; j < numThreads; j++) {
            pthread_join(thr[j], NULL);
        }
    }

    for (i = 0; i < numInstancias; ++i) {
        fprintf(outputFileOpen, "%d\n", result[i]);
    }

    // Retorna 0 se conseguiu fechar o arquivo com sucesso
    if(fclose(inputFileOpen) != 0) {
        printf("Erro ao tentar fechar o arquivo %s\n", inputFileName);
    }

    if(fclose(outputFileOpen) != 0) {
        printf("Erro ao tentar fechar o arquivo %s\n", inputFileName);
    }

    return 0;
}

void * entryPoint(struct args * var){
    
    int parcial = achaClique(var->valoresGrafo, var->numVertices);

    pthread_mutex_lock(&mutex);
    result[var->instancia] = parcial;
    // printf("Instancia %d: %d\n", var->instancia+1, parcial);
    pthread_mutex_unlock(&mutex);

    liberaGrafo(var->valoresGrafo, var->numVertices);
    free(var);
    pthread_exit(0);
}
