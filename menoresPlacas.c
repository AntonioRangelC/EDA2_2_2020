#include<stdio.h>
#include<stdlib.h>

int separa(int *vetor, int comeco, int fim);

void quickselect(int *vetor, int inicio, int fim, int posicao);

void heapSort(int *vetor, int tamanho);

void empilhar(int *vetor, int tamanho, int i);
void quicksortM3(int *vetor, int comeco, int fim);
void insertionSortV2(int *vetor, int tamanho);
void sort(int *vetor, int comeco, int fim);
int main() {
    int escolha, numero, aux = 0, i, primeiraVez = 1, tamanho = 0, posMaior=0;
    int *vetor = malloc(sizeof(int) * 101);
    //int *menores = malloc(sizeof(int) * 101);
    while (scanf("%d %d", &escolha, &numero) != EOF) {
        if (escolha == 1) {

            if (tamanho < 100) {
                if(numero > vetor[posMaior]){
                    posMaior = tamanho;
                }
                vetor[tamanho] = numero;
                tamanho++;
            } else if (tamanho == 100 && numero < vetor[posMaior]) {
                vetor[posMaior] = numero;
                sort(vetor, 0 , tamanho-1);
                posMaior = tamanho-1;
            }


        }
        else if (escolha == 2) {

            sort(vetor, 0, tamanho-1);
            posMaior = tamanho-1;

            for (i = 0; i < numero; i++) {
                if (i == 0) {
                    printf("%d", vetor[i]);
                } else {
                    printf(" %d", vetor[i]);
                }

            }
            printf("\n");
        }

    }


    free(vetor);
    //free(menores);


    return 0;
}

int separa(int *vetor, int comeco, int fim) {
    int pivo = vetor[fim];
    int j = comeco, aux, temp;
    for (aux = comeco; aux < fim; aux++) {
        if (vetor[aux] < pivo) {
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

void quickselect(int *vetor, int inicio, int fim, int posicao) {
    int i;
    if (fim <= inicio) {
        return;
    }

    i = separa(vetor, inicio, fim);

    if (i > posicao) {
        quickselect(vetor, inicio, i - 1, posicao);
    }
    if (i < posicao) {
        quickselect(vetor, i + 1, fim, posicao);
    }
}

void empilhar(int *vetor, int tamanho, int i) {

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

void heapSort(int *vetor, int tamanho) {
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





