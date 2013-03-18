#include <stdlib.h>
#include <stdio.h>
#include "list.h"

void FLVazia(TipoLista *Lista) {
  Lista->Primeiro = (TipoApontador) malloc(sizeof(TipoCelula));
  Lista->Ultimo = Lista->Primeiro;
  Lista->Primeiro->Prox = NULL;
  Lista->size = 0;
}

int Vazia(TipoLista Lista) {
  return (Lista.Primeiro == Lista.Ultimo);
}

void Insere(TipoItem x, TipoLista *Lista) { 
  Lista->Ultimo->Prox = (TipoApontador) malloc(sizeof(TipoCelula));
  Lista->Ultimo = Lista->Ultimo->Prox;
  Lista->Ultimo->Item = x;
  Lista->Ultimo->Prox = NULL;
  Lista->size += 1;
}

void Retira(TipoApontador p, TipoLista *Lista, TipoItem *Item) {
  TipoApontador q;
  if (Vazia(*Lista) || p == NULL || p->Prox == NULL) {
    printf("Error\n");
    return;
  }
  q = p->Prox;
  *Item = q->Item;
  p->Prox = q->Prox;
  if (p->Prox == NULL) Lista->Ultimo = p;
  free(q);
  Lista->size -= 1;
}

void Find(TipoApontador p, TipoLista *Lista, int pagina) {
  p = Lista->Primeiro;

  while (p != NULL) {
    if (p->Item.Chave == pagina) {
        break;
    } else {
      p = p->Prox;
    }
  }
}

void Imprime(TipoLista Lista) {
  TipoApontador Aux;
  Aux = Lista.Primeiro->Prox;
  while (Aux != NULL) {
    printf("%d\n", Aux->Item.Chave);
    Aux = Aux->Prox;
  }
}

void liberaLista(TipoLista *a) {
	struct TipoCelula *tmp,*aux;
	tmp = a->Primeiro;
	while (tmp != NULL) {
		aux=tmp->Prox;
		free(tmp);
		tmp = aux;
	}
}