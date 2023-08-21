#include<stdio.h>
#include<stdlib.h>
int cmpfunc (const void * a, const void * b);
int buscaBinaria(int *numerosProibidos, int qtd, int numero);
int main(){
    int qtd, *numerosProibidos, numero,aux,flag=0, resultado;
    scanf("%d", &qtd);
    numerosProibidos = malloc(sizeof (int) * qtd);
    for(aux = 0; aux < qtd; aux++){
        scanf("%d", &numerosProibidos[aux]);
    }

    qsort(numerosProibidos, qtd, sizeof(int), cmpfunc);
    while(scanf("%d", &numero) != EOF){
        resultado = buscaBinaria(numerosProibidos, qtd, numero);
        if(resultado == 1){
            printf("sim\n");
        }
        else{
            printf("nao\n");
        }
    }

    return 0;
}

int cmpfunc (const void * a, const void * b) {
    return ( *(int*)a - *(int*)b );
}
int buscaBinaria(int *numerosProibidos, int qtd, int numero){
    int esquerda=-1, direita=qtd,meio;
    while(esquerda < direita-1){  //se 'esquerda' estiver uma posicao atras de 'direita', sai do laco,
        meio = (esquerda + direita)/2;
        if(numerosProibidos[meio] < numero){   // se o elemento do meio for menor, preciso procurar no sub-vetor da direita
            esquerda = meio;
        }
        else{                      // se o elemento do meio for maior, preciso procurar no sub-vetor da esquerda
            direita = meio;
        }
    }
    if(numerosProibidos[direita] == numero){
        return 1;
    }
    else{
        return -1;
    }
}

