#include <stdio.h>
#include <stdlib.h>
typedef struct no {
    int dado;
    struct no *esq, *dir;
} no;
void em_ordem(no *raiz){
    struct no pilha[1000];
    int topo=0;
    if(raiz == NULL){
        printf("\n");
        return;
    }
    pilha[topo].dado = raiz->dado;
    pilha[topo].esq = raiz->esq;
    pilha[topo].dir = raiz->dir;
    while(1) {
        while(raiz != NULL) {
            topo++;
            pilha[topo].dado = raiz->dado;
            pilha[topo].esq = raiz->esq;
            pilha[topo].dir = raiz->dir;
            raiz = raiz->esq;

        }
        if(topo == 0){
            printf("\n");
            return;
        }
        printf("%d ", pilha[topo].dado);
        topo--;
        raiz = pilha[topo+1].dir;
    }

}