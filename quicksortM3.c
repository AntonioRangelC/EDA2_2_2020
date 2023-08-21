#include<stdio.h>
#include <stdlib.h>
int separa(int *vetor, int comeco, int fim);
void quicksortM3(int *vetor, int comeco, int fim);
int main(){
    int aux, quantidade;
    scanf("%d", &quantidade);
    int *vetor = malloc(sizeof(int) * quantidade);
    for(aux=0; aux < quantidade; aux++){
        scanf("%d", &vetor[aux]);
    }

    quicksortM3(vetor, 0 , quantidade-1);

    for(aux=0; aux<quantidade; aux++){
        if(aux == quantidade -1){
            printf("%d", vetor[aux]);
        }
        else{
            printf("%d ", vetor[aux]);
        }

    }
    printf("\n");
    free(vetor);
    return 0;
}

void quicksortM3(int *vetor, int comeco, int fim){
    int temp,j, meio = (fim+comeco)/2;
    if(fim<=comeco){
        return;
    }
    temp = vetor[fim-1];
    vetor[fim-1] = vetor[meio];
    vetor[meio] = temp;

    if(vetor[fim] < vetor[meio]){
        temp = vetor[fim];
        vetor[fim] = vetor[meio];
        vetor[meio] = temp;
        if( vetor[meio] < vetor[comeco]){
            temp = vetor[comeco];
            vetor[comeco] = vetor[meio];
            vetor[meio] = temp;
            if(vetor[meio] < vetor[fim]){
                temp = vetor[fim];
                vetor[fim] = vetor[meio];
                vetor[meio] = temp;
            }
        }
    }


    j = separa(vetor, comeco, fim);
    quicksortM3(vetor, comeco, j-1);
    quicksortM3(vetor, j+1, fim);
}

int separa(int *vetor, int comeco, int fim){
    int pivo = vetor[fim];
    int j = comeco, aux,temp;
    for(aux=comeco; aux<fim; aux++){
        if(vetor[aux] < pivo){
            temp = vetor[aux];
            vetor[aux] = vetor[j];
            vetor[j] = temp;
            j++;
        }

    }
    temp = vetor[j];
    vetor[j] = vetor[fim];
    vetor[fim] = temp;
    return j;

}

