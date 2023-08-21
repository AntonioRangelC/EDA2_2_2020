#include<stdio.h>
#include <stdlib.h>
//Este algoritmo descobre qual é o elemento que ocorre mais vezes em um array. Existe uma pagina que mostra o algoritmo
// funcionando e explicando seu funcionamento: https://afteracademy.com/blog/find-the-most-frequent-element-in-an-array
// Uma das aplicações deste algoritmo é a contagem de votos.
void heapSort(int *vetor, int tamanho);
void empilhar(int *vetor, int tamanho, int i);
int main(){
    int vetor[10] = {0,1,2,4,4,4,5,6,6,7};
    int contador=0, candidato, aux, tamanho = 10, resultado=-1;
    heapSort(vetor, tamanho);
    int max_freq = 0;
    int i = 0;
    while (i < tamanho)
    {
        int curr_freq = 1;
        while (i+1 < tamanho && vetor[i+1] == vetor[i])
        {
            curr_freq = curr_freq + 1;
            i = i + 1;
        }

        if (max_freq < curr_freq)
        {
            max_freq = curr_freq;
            resultado = vetor[i];
        }

        i = i + 1;
    }


    printf("%d\n", resultado);

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

