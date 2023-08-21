#include<stdio.h>
#include<stdlib.h>
void bubbleSortV1(int vetor[], int tamanho);
void bubbleSortV2(int vetor[], int tamanho);
// IMPORTANTE: bubbleSortV2 É SUPERIOR À bubbleSortV1
int main(){
    int *vetor;
    int numero, aux=0, i;
    vetor = malloc(sizeof(int) * 1001);

    while(scanf("%d",&numero) != EOF){
        vetor[aux] = numero;
        aux++;
    }

    bubbleSortV2(vetor, aux);

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
void bubbleSortV2(int *vetor, int tamanho){


    int i,j, tmp;

    for(i = tamanho-2; i >= 0; i--){
        for(j = 0; j <= i; j++){
            if(vetor[j] > vetor[j+1]){
                tmp = vetor[j+1];
                vetor[j+1] = vetor[j];
                vetor[j] = tmp;
            }
        }
    }

}

void bubbleSortV1(int vetor[], int tamanho){

    int i,j, tmp;

    for(i=0; i < tamanho; i++){
        for(j=1; j <= tamanho; j++){
            if(vetor[j] < vetor[j-1]){
                tmp = vetor[j-1];
                vetor[j-1] = vetor[j];
                vetor[j] = tmp;
            }
        }
    }


}
