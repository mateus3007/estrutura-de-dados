#ifndef LISTA_INT_H_
#define LISTA_INT_H_

typedef  struct lista Lista;
typedef  struct lista_no Lista_No;

// Interface das funções
Lista* criar_lista(void);
Lista_No* Inserir(Lista *listinha, int valor);
void imprimir(Lista *listinha);
Lista_No* Buscar (Lista *listinha, int valor);
void retira(Lista *listinha, int valor);
void liberar(Lista *listinha);

#endif