#include"lista_int.h"
#include<stdlib.h>
#include<stdio.h>

struct lista_no{
  int valor;
  Lista* proximo;
};

struct lista{
  Lista_No* inicio;
};

Lista* criar_lista(){
  Lista *listinha = (Lista *)malloc(sizeof(Lista));
  listinha->inicio = NULL;
  return listinha;
};

Lista_No* Inserir(Lista *listinha, int valor){
Lista_No* novo_valor = (Lista_No *)malloc(sizeof(Lista_No));
  novo_valor->valor = valor;
  novo_valor->proximo = listinha;
  listinha->inicio = novo_valor;
  return novo_valor;
};

void imprimir(Lista* listinha){
  Lista_No* pecorrer;
  for(pecorrer = listinha->inicio; pecorrer!=NULL; pecorrer= pecorrer->proximo){
    printf("Info: %d\n",pecorrer->valor);
  }
  
};

int lista_vazia(Lista* listinha){
  if(listinha == NULL){
    return 1;
  }else{
    return 0;
  }
  
};

Lista_No* Buscar(Lista* listinha,int valor){
  Lista_No* pecorrer;
  for(pecorrer = listinha->inicio; pecorrer!=NULL; pecorrer= pecorrer->proximo){
   if(pecorrer->valor == valor){
     return pecorrer;
   }
  }
  return NULL;
}

Lista* retirar(Lista* listinha,int valor){
   Lista_No* anterior = NULL;
   Lista_No* pecorrer = listinha->inicio;
  while(pecorrer != NULL && pecorrer->valor == valor){
    anterior = pecorrer;
    pecorrer = pecorrer->proximo;
  }

if(pecorrer == NULL){
  return listinha;
}
  if(anterior == NULL){
    listinha = pecorrer->proximo;
  }else{
    anterior->proximo = pecorrer->proximo;
  }
  free(pecorrer);
  return listinha;
};

void liberar(Lista* listinha){
   Lista_No* pecorrer = listinha->inicio;
  while(pecorrer !=NULL){
    Lista_No* proximo = pecorrer->proximo;
    free(pecorrer);
    pecorrer = proximo;
  }
  free(listinha);
}
