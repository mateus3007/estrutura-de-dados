#include "pilha_int.h"
#include <stdio.h>
#include <stdlib.h>



//

struct lista_no{
  int valor;
  Pilha* proximo;
};

struct lista{
  PilhaNo* inicio;
};

Pilha *pilha_cria(void) {
  Pilha *p = (Pilha *)malloc(sizeof(Pilha));
  p->inicio = NULL;
  return p;
}

int pilha_push(Pilha *p, float v) {
  PilhaNo *novo = (PilhaNo *)malloc(sizeof(PilhaNo));
  novo->valor = v;
  novo->proximo = p->inicio;
  p->inicio = novo;
}

float pilha_pop(Pilha *p) // pop
{
  PilhaNo *primeiro = p->inicio;
  if (primeiro == NULL)
    return 0;

  PilhaNo *segundo = primeiro->proximo;
  p->inicio = segundo;
  float valor = primeiro->valor;
  free(primeiro);
  return valor;
}

int pilha_vazia(Pilha *p) { 
  return (p->inicio == NULL);
}

void pilha_libera(Pilha *p) {
  PilhaNo *p_aux = p->inicio;
  while (p_aux != NULL) {
    PilhaNo *t = p_aux->inicio;
    free(p_aux);
    p_aux = t;
  }

  free(p);
}
