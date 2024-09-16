#include "fila_int.h"
#include <stdio.h>
#include <stdlib.h>

//
struct lista_no{
  int valor;
  Fila* proximo;
};

struct lista{
  FilaNo* inicio;
  FilaNo* fim;
};

lista *pilha_cria(void) {
  lista *p = (lista *)malloc(sizeof(lista));
  p->inicio = NULL;
  return p;
}

int pilha_push(Fila *p, float v) {
  FilaNo *novo = (FilaNo *)malloc(sizeof(FilaNo));
  novo->valor = v;
  novo->proximo = p->inicio;
  p->inicio = novo;
}

float pilha_pop(Fila *p) // pop
{
  FilaNo *primeiro = p->inicio;
  if (primeiro == NULL)
    return 0;

  FilaNo *segundo = primeiro->proximo;
  p->inicio = segundo;
  float valor = primeiro->valor;
  free(primeiro);
  return valor;
}

int pilha_vazia(Fila *p) { 
  return (p->inicio == NULL);
}

void pilha_libera(Fila *p) {
  FilaNo *p_aux = p->inicio;
  while (p_aux != NULL) {
    FilaNo *t = p_aux->inicio;
    free(p_aux);
    p_aux = t;
  }

  free(p);
}
