#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"arvore.h"

#define NUM_ALF 26 

char gera_letra_alfabeto()
{
    // a = 97, z = 122
    // geramos valor entre 0 e 25 e somamos 97
    int valor = rand() % (NUM_ALF - 1);
    valor += 97;
    return (char) valor;
}


int main(int argc, char const *argv[])
{
    // para fazer a seed do gerador aleatória
    srand(time(0));

    // Cria todos os nós
    ArvNo* i = arv_criano('i', NULL, NULL);
    ArvNo* h = arv_criano('h', NULL, NULL);
    ArvNo* g = arv_criano('g', NULL, NULL);
    ArvNo* f = arv_criano('f', NULL, NULL);
    ArvNo* e = arv_criano('e', i, NULL);
    ArvNo* d = arv_criano('d', h, NULL);
    ArvNo* c = arv_criano('c', f, g);
    ArvNo* b = arv_criano('b', d, e);
    ArvNo* a = arv_criano('a', b, c);

    // Cria a arvore
    Arv* arvore = arv_cria(a);
    arv_imprime_2D(arvore);

    for (int i = 0; i < 3; i++)
    {
        char c = gera_letra_alfabeto();
        int encontrado = arv_pertence(arvore, c);
        printf("Letra procurada: %c\n", c);
        printf("Letra encontrada: %d\n", encontrado);
    }
    
    return 0;
}
