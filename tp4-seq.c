/*
*   Problemas NP-Completo e Programacao Paralela
*       Autor: Lucas Silvestre (2010054665)
*       Data: 19/12/2012
*/

#include <stdio.h>
#include <stdlib.h>
#include "funcao.h"
#include "achaClique.h"

int main(int argc, char *argv[]) {
    // Inicializa variáveis
    char * inputFileName = argv[1];
    char * outputFileName = argv[2];
    int numVertices, numInstancias, i;
    int ** valoresGrafo = NULL;

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
    for (i = 0; i < numInstancias; i++) {
		fscanf(inputFileOpen, "%d", &numVertices);

    	valoresGrafo = leGrafo(numVertices, inputFileOpen);

    	fprintf(outputFileOpen, "%d\n", achaClique(valoresGrafo, numVertices));
    	liberaGrafo(valoresGrafo, numVertices);
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

