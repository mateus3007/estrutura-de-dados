#ifndef PILHA_VETOR_H_
#define PILHA_VETOR_H_

#define TAMANHO_BASE 4

typedef struct _pilha Pilha;

Pilha* pilha_cria(void);
int pilha_push(Pilha* p, float v);
float pilha_pop(Pilha* p);
int pilha_vazia(Pilha *p);
void pilha_libera(Pilha *p);
void pilha_exibe(Pilha *p);

#endif