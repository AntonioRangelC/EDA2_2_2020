#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int dado;
    struct no *esq, *dir;
} no;

void preordem (no *raiz) {
    if (raiz != NULL) {
        printf ("%d ", raiz->dado);
        preordem (raiz->esq);
        preordem (raiz->dir);
    }
}

void emordem (no *raiz) {
    if (raiz != NULL) {
        emordem (raiz->esq);
        printf ("%d ", raiz->dado);
        emordem (raiz->dir);
    }
}

void posordem (no *raiz) {
    if (raiz != NULL) {
        posordem (raiz->esq);
        posordem (raiz->dir);
        printf ("%d ", raiz->dado);
    }
}

no *criar_arvore (int x, no *esq, no *dir) {
    no *raiz = malloc (sizeof (no));
    raiz->dado = x;
    raiz->esq = esq;
    raiz->dir = dir;
    return raiz;
}

no *insereOrdenado(no *novo, no *raiz){

    if(raiz == NULL){
        return novo;
    }
    if(novo->dado < raiz->dado){
        raiz->esq = insereOrdenado(novo, raiz->esq);
    }
    else{
        raiz->dir = insereOrdenado(novo, raiz->dir);
    }
    return raiz;
}

// esta busca retorna NULL se o elemento nao for achado, e retorna o no
// caso o elemento seja achado dentro de um no
no *busca(int elemento, no *raiz){
    if(raiz == NULL){
        return NULL;
    }
    if(raiz->dado == elemento){
        return raiz;
    }
    if(raiz->dado > elemento){
        return busca(elemento, raiz->esq);
    }
    else{
        return busca(elemento, raiz->dir);
    }


}

int contarElementos(no *raiz){
    if(!raiz){
        return 0;
    }
    return contarElementos(raiz->esq) + 1 + contarElementos(raiz->dir);

}

no *buscaNo(no *raiz, int elemento, no **pai){
    no *atual = raiz;
    *pai = NULL;
    while(atual){
        if(atual->dado == elemento){
            return atual;
        }
        *pai = atual;
        if(elemento < atual->dado){
            atual = atual->esq;
        }
        else{
            atual = atual->dir;
        }

    }
    return NULL;
}

no *removeNo(no *raiz, int elemento){
    no *pai, *no, *p, *q;
    no = buscaNo(raiz, elemento, &pai);
    if(no == NULL){
        return raiz;
    }
    if(!no->esq || !no->dir){    //tratando o caso do no removido ter no maximo um filho
        if(!no->esq){
            q = no->dir;
        }
        else{
            q = no->esq;
        }
    }
    else{               //tratando o caso do no removido ter dois filhos
        p = no;
        q = no->esq;
        while(q->dir){
            p = q;
            q = q->dir;
        }
        if(p != no){        //caso o pai do substituto ser ou nao o no removido
            p->dir = q->dir;
            q->esq = no->esq;
        }
        q->dir = no->dir;
    }
    if(!pai){       //tratando o caso do no removido ser a raiz
        free(no);
        return q;
    }
    if(elemento < pai->dado){  //tratando o caso do no removido nao ser a raiz
        pai->esq = q;
    }
    else{
        pai->dir = q;
    }
    free(no);
    return raiz;
}


int main(){
    int aux, quantidade, numero;
    no *raiz;
    printf("Digite a quantidade de elementos\n");
    scanf("%d", &quantidade);
    for(aux=0; aux < quantidade; aux++){
        if(aux == 0){
            scanf("%d", &numero);
            raiz = criar_arvore(numero, NULL, NULL);
        }
        else{
            scanf("%d", &numero);
            no *novo = criar_arvore(numero, NULL, NULL);
            raiz = insereOrdenado(novo, raiz);
        }
    }

    emordem(raiz);
    removeNo(raiz, 3);
    printf("\n");
    emordem(raiz);

    return 0;
}

