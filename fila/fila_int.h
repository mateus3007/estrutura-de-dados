#ifndef PILHA_LISTA_H_
#define PILHA_LISTA_H_

#define TAMANHO_BASE 4

typedef struct lista_no FilaNo;
typedef struct Lista Fila;

Fila *pilha_cria(void);
int pilha_push(Fila *p, float v);
float pilha_pop(Fila *p);
int pilha_vazia(Fila *p);
void pilha_libera(Fila *p);


#endif