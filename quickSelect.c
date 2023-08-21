#include<stdio.h>

// O objetivo do quickselect eh receber uma posicao que voce deseja estar ordenada
// sem a necessidade de ordenar o vetor inteiro. Exemplo: quero saber qual elemento estaria na posicao 2
// de um vetor, se ele estivesse ordenado. Basta chamar o quickselect passando a posicao 2, e o quickselect coloca
// o elemento na posicao 2. Entao eh so acessar o vetor na posicao 2 que voce tera o elemento na mesma posicao que ele
// estaria caso o vetor estivesse ordenado.

void quickselect(int *vetor,int inicio,int fim,int posicao);
int main(){
    int vetor[10] = {6,4,5,7,2,1,3,8,9,0};
    int i;
    quickselect(vetor, 0,9, 6);

    for(i=0; i<10; i++){
        printf("%d ", vetor[i]);
    }
    printf("\n");

    return 0;
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

void quickselect(int *vetor,int inicio,int fim,int posicao){
    int i;
    if(fim <= inicio){
        return;
    }

    i=separa(vetor, inicio, fim);

    if(i > posicao){
        quickselect(vetor,inicio,i-1,posicao);
    }
    if(i < posicao){
        quickselect(vetor,i+1,fim,posicao);
    }
}



