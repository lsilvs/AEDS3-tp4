#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED

typedef int TipoChave;

typedef struct {
  int Chave;
} TipoItem;

typedef struct TipoCelula * TipoApontador;

typedef struct TipoCelula {
  TipoItem Item;
  TipoApontador Prox;
} TipoCelula;

typedef struct {
  TipoApontador Primeiro, Ultimo;
  int size;
} TipoLista;

void FLVazia(TipoLista * Lista);

int Vazia(TipoLista Lista);

void Insere(TipoItem x, TipoLista * Lista);

void Retira(TipoApontador p, TipoLista * Lista, TipoItem * Item);

void Find(TipoApontador p, TipoLista * Lista, int pagina);

void Imprime(TipoLista Lista);

void liberaLista(TipoLista *a);

#endif // LIST_H_INCLUDED
