#include <stdlib.h>
#include <stdio.h>
#include "achaClique.h"

int achaClique(int ** Matriz, int numVertices) {
    int maxSize = 0, i;
    TipoItem x;

    TipoLista * aux1 = (TipoLista *) malloc(sizeof(TipoLista)*numVertices);
    FLVazia(aux1);

    TipoLista * aux2 = (TipoLista *) malloc(sizeof(TipoLista)*numVertices);
    FLVazia(aux2);

    for(i = 0; i < numVertices; i++) {
        x.Chave = i;
        Insere(x, aux2);
    }

	maxSize = auxFunc(Matriz, aux1, aux2, numVertices, maxSize);

    liberaLista(aux1);
    liberaLista(aux2);
    free(aux1);
    free(aux2);

    return(maxSize);
}

int auxFunc(int ** Matriz, TipoLista * C, TipoLista * P, int numVertices, int maxSize) {
    int i, aux;
    TipoItem x;

    for(i = P->size - 1; i >= 0; i--) {
        if(C->size + P->size <= maxSize)
            continue;

        int v = P->Primeiro->Prox->Item.Chave;

        x.Chave = v;
        Insere(x, C);

        TipoLista * new = (TipoLista *) malloc(sizeof(TipoLista)*numVertices);
        FLVazia(new);

    	TipoApontador Aux;
      	Aux = P->Primeiro->Prox;
    	while (Aux != NULL) {
    	    if(Matriz[v][Aux->Item.Chave] == 1) {
                Insere(Aux->Item, new);
    	    }
    	    Aux = Aux->Prox;
    	}

        if(Vazia(* new) && C->size > maxSize)
            maxSize = C->size;

    	if(!Vazia(* new)) {
     		aux = auxFunc(Matriz, C, new, numVertices, maxSize);
    		if (aux > maxSize)
                maxSize = aux;
    	}

        x.Chave = v;
        Retira(C->Primeiro, C, &x);
        Retira(P->Primeiro, P, &x);
        liberaLista(new);
        free(new);
    }

    return maxSize;
}