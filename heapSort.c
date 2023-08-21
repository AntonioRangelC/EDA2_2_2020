#include<stdio.h>
#include<stdlib.h>
void heapSort(int *vetor, int tamanho);
void empilhar(int *vetor, int tamanho, int i);
int main(){
    int *vetor;
    int i,aux=0, numero;

    vetor = malloc(sizeof(int) * 50001);

    while(scanf("%d",&numero) != EOF){
        vetor[aux] = numero;
        aux++;
    }

    heapSort(vetor, aux);

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


void empilhar(int *vetor, int tamanho, int i){

    int maior = i;
    int inicio = 2 * i + 1;
    int fim = 2 * i + 2;
    int temp;


    if (inicio < tamanho && vetor[inicio] > vetor[maior])
        maior = inicio;


    if (fim < tamanho && vetor[fim] > vetor[maior])
        maior = fim;


    if (maior != i) {
        temp = vetor[i];
        vetor[i] = vetor[maior];
        vetor[maior] = temp;


        empilhar(vetor, tamanho, maior);
    }
}

void heapSort(int *vetor, int tamanho){
    int temp;

    for (int i = tamanho / 2 - 1; i >= 0; i--)
        empilhar(vetor, tamanho, i);


    for (int i = tamanho - 1; i > 0; i--) {

        temp = vetor[i];
        vetor[i] = vetor[0];
        vetor[0] = temp;

        empilhar(vetor, i, 0);
    }
}

