#include "pilha_vetor.h"
#include <stdio.h>
#include <stdlib.h>

struct _pilha {
  int dim;    // tamanho total do vetor
  float *vet; // ponteiro para o endereço do vetor
  int n;      // quantidade de elementos na pilha
};

Pilha *pilha_cria(void) {
  Pilha *p = (Pilha *)malloc(sizeof(Pilha));
  if (p == NULL)
    return p;

  p->dim = TAMANHO_BASE;
  p->n = 0;
  p->vet = (float *)malloc(p->dim * sizeof(float));
  return p;
}

int pilha_push(Pilha *p, float v) {
  if (p->n == p->dim) // todas as posições ocupadas
  {
    p->dim *= 2; // dobro o tamanho do vetor
    p->vet = (float *)realloc(p->vet, p->dim * sizeof(float));
    if (p->vet == NULL) // pode acontecer um erro
      return -1;
  }

  p->vet[p->n] = v;
  p->n++;

  return 0;
}

float pilha_pop(Pilha *p) // pop
{
  if (p->n == 0) // não há elementos
  {
    printf("\nWARNING: acesso a pilha_pop com pilha vazia\n");
    return 0;
  }
  p->n--; // desconsidera o último elemento
  return p->vet[p->n];
}

int pilha_vazia(Pilha *p) { return (p->n == 0); }

void pilha_libera(Pilha *p) {
  free(p->vet);
  free(p);
}

void pilha_exibe(Pilha *p) {
  printf("\nPilha: ");
  for (int i = 0; i < p->n; i++) {
    printf("%.2f ", p->vet[i]);
  }
  printf("\n");
}