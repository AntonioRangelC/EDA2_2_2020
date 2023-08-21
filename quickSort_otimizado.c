#include<stdio.h>
#include <stdlib.h>
int separa(int *vetor, int comeco, int fim);
void quicksortM3(int *vetor, int comeco, int fim);
void insertionSortV2(int *vetor, int tamanho);
void sort(int *vetor, int comeco, int fim);
int main(){
    int aux, quantidade;
    scanf("%d", &quantidade);
    int *vetor = malloc(sizeof(int) * quantidade);
    for(aux=0; aux < quantidade; aux++){
        scanf("%d", &vetor[aux]);
    }

    sort(vetor, 0 , quantidade-1);

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

void sort(int *vetor, int comeco, int fim){
    quicksortM3(vetor, comeco, fim);
    insertionSortV2(vetor, fim+1);
}

void quicksortM3(int *vetor, int comeco, int fim){
    int temp,j, meio = (fim+comeco)/2;
    if(fim - comeco <= 32){
        return;
    }
    temp = vetor[fim-1];
    vetor[fim-1] = vetor[meio];
    vetor[meio] = temp;


    if(vetor[fim-1] < vetor[comeco]){
        temp = vetor[fim-1];
        vetor[fim-1] = vetor[comeco];
        vetor[comeco] = temp;
        if( vetor[fim] < vetor[comeco]){
            temp = vetor[comeco];
            vetor[comeco] = vetor[fim];
            vetor[fim] = temp;
            if(vetor[fim] < vetor[fim-1]){
                temp = vetor[fim-1];
                vetor[fim-1] = vetor[fim];
                vetor[fim] = temp;
            }
        }
    }

    j = separa(vetor, comeco+1, fim-1);
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



