#include <stdio.h>
#include <stdlib.h>
void insertionSortV1(int *vetor, int tamanho);
void insertionSortV2(int *vetor, int tamanho);
int main(){
    int *vetor;
    int i,aux=0, numero;

    vetor = malloc(sizeof(int) * 50001);

    while(scanf("%d",&numero) != EOF){
        vetor[aux] = numero;
        aux++;
    }

    insertionSortV2(vetor, aux);
    for(i = 0; i < aux; i++){
        if(i != aux-1){
            printf("%d ", vetor[i]);
        }
        else if(i == aux-1){
            printf("%d", vetor[i]);
        }
    }
    printf("\n");
    free(vetor);
    return 0;
}

// implementação mais simples, que é ineficiente
void insertionSortV1(int *vetor, int tamanho){
    int i,j, tmp;
    for(i = 1; i < tamanho; i++){
        for(j = i; j > 0; j--){
            if(vetor[j] < vetor[j-1]){
                tmp = vetor[j];
                vetor[j] = vetor[j-1];
                vetor[j-1] = tmp;
            }
        }
    }
}

// implementação mais eficiente
void insertionSortV2(int *vetor, int tamanho){
    int i,j, tmp;
    for(i = tamanho-1; i > 0; i--){           //levando o menor numero para a primeira posicao do vetor
        if(vetor[i] < vetor[i-1]){
            tmp = vetor[i-1];
            vetor[i-1] = vetor[i];
            vetor[i] = tmp;
        }
    }


    for(i = 2; i <= tamanho-1; i++){
        j = i;
        tmp = vetor[j];
        while(tmp < vetor[j-1]){       //comparando se o numero armazenado em tmp é menor que os seus
            vetor[j] = vetor[j-1];     // vizinhos a esquerda, e movendo os vizinhos maiores para a direita
            j--;
        }
        vetor[j] = tmp;                //caso o loop ache um numero menor que tmp, tmp é armazenado uma posicao a direita
    }                                  // desse numero

}

