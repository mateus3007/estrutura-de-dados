#include<stdio.h>
#include<stdlib.h>
#include"arvore.h"


#define DIST 2

typedef struct arvno ArvNo;
struct arvno {
    char info;
    ArvNo* esq;
    ArvNo* dir;
};

typedef struct arv Arv;
struct arv {
    ArvNo *raiz;
};

ArvNo* arv_criano(char c, ArvNo* esq, ArvNo* dir)
{
    ArvNo* p = (ArvNo*) malloc(sizeof(ArvNo));
    p->info = c;
    p->esq = esq;
    p->dir = dir;
    return p;
}

Arv* arv_cria (ArvNo* r)
{
    Arv* a = (Arv*) malloc(sizeof(Arv));
    a->raiz = r;
    return a;
}


void imprime(ArvNo* r)
{
    printf("<");
    if (r != NULL)
    {
        printf("%c ", r->info); // mostra info
        // chama função imprime para filho à esquerda
        imprime(r->esq);
        // chama função imprime para filho à direita
        imprime(r->dir);
    }
    printf(">");
}

void arv_imprime(Arv* a)
{
    // imprime recursivamente a partir da raiz
    imprime(a->raiz);
}


void imprime_2D(ArvNo* r, int espaco)
{
    if (r == NULL)
        return;
    
    espaco += DIST;
    imprime_2D(r->dir, espaco);

    // Imprime o nó atual depois do espaço
    printf("\n");
    for (int i = DIST; i < espaco; i++)
        printf(" ");
    printf("%c", r->info);

    imprime_2D(r->esq, espaco);
}

void libera(ArvNo* r)
{
    if (r != NULL)
    {
        libera(r->esq);
        libera(r->dir);
        free(r);
    }
}

void arv_libera(Arv* a)
{
    libera(a->raiz);
    free(a);
}

int pertence(ArvNo* r, char c)
{
    if (r == NULL)
        return 0;
    else
    {
        int exp = c == r->info
            || pertence(r->esq, c)
            || pertence(r->dir, c);
        return exp;
    }
}

int arv_pertence(Arv* a, char c)
{
    return pertence(a->raiz, c);
}

ArvNo* busca(ArvNo* r, char c)
{
    if (r == NULL)
        return NULL;
    else if (c == r->info)
        return r;
    else
    {
        ArvNo *p = busca(r->esq, c);
        if (p != NULL)
            return p;
        else
            return busca(r->dir, c);
    }
}