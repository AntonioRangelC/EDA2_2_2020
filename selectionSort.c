#include <stdio.h>
#include<stdlib.h>

int main(){
    int *vetor;
    vetor = malloc(sizeof(int) * 1001);
    int i,j, tmp, min, aux=0, numero;

    while(scanf("%d",&numero) != EOF){
        vetor[aux] = numero;
        aux++;
    }

    for(i = 0; i < aux-1; i++){
        min = i;
        for(j = i + 1; j < aux; j++){
            if(vetor[j] < vetor[min]){
                min = j;
            }
        }
        tmp = vetor[i];
        vetor[i] = vetor[min];
        vetor[min] = tmp;

    }

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

