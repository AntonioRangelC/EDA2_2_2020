#include <stdio.h>
#include<stdlib.h>
typedef struct numeros{
    int numero;
    int frequencia;
}numeros;
int buscaBinaria(numeros *auxiliar, int qtd, int numero);
void mergeSort(numeros *vetor, int inicio, int fim);
void merge(numeros * vetor, int inicio, int meio, int fim);
int main(){
    int qtd,aux,num,maiorFreq=-1, maior, retornoBusca=0,i=1,j;
    numeros *vetor;
    scanf("%d", &qtd);
    vetor = malloc(sizeof(struct numeros) * (qtd+1));
    for(aux=1; aux <= qtd; aux++){
       vetor[aux].frequencia = 0;
       vetor[aux].numero = 0;
    }
    while(qtd != 0){
        for(aux = 1; aux <= qtd; aux++){
            scanf("%d", &num);
            vetor[aux].numero = num;
        }
        mergeSort(vetor, 1, qtd);

        vetor[i].frequencia++;
        for(aux = 2; aux <= qtd; aux++){
            if(vetor[aux].numero != vetor[aux-1].numero){
                i++;
                vetor[i].numero = vetor[aux].numero;
                vetor[i].frequencia = vetor[aux].frequencia + 1;
            }
            else{
                vetor[i].frequencia++;
            }
        }
        /*for(aux=1; aux <= qtd; aux++){
            printf("[%d][%d]  ", vetor[aux].numero, vetor[aux].frequencia);
        }
        printf("\n");*/
        for(aux=1; aux <= i; aux++){
            if(vetor[aux].frequencia > maiorFreq){
                maiorFreq = vetor[aux].frequencia;
                maior = vetor[aux].numero;
            }
        }
        printf("%d\n", maior);

        for(aux=1; aux <= qtd; aux++){
            if(vetor[aux].frequencia > 0){
                vetor[aux].frequencia = 0;
                vetor[aux].numero = 0;
            }
        }
        maiorFreq = -1;
        i = 1;
        scanf(" %d", &qtd);
        vetor = realloc(vetor, sizeof(struct numeros) * (qtd+1));
    }

    free(vetor);

    return 0;
}
int buscaBinaria(numeros *auxiliar, int qtd, int numero){
    int esquerda=0, direita=qtd+1,meio;
    while(esquerda < direita-1){  //se 'esquerda' estiver uma posicao atras de 'direita', sai do laco,
        meio = (esquerda + direita)/2;
        if(auxiliar[meio].numero < numero){   // se o elemento do meio for menor, preciso procurar no sub-vetor da direita
            esquerda = meio;
        }
        else{                      // se o elemento do meio for maior, preciso procurar no sub-vetor da esquerda
            direita = meio;
        }
    }
    if(auxiliar[direita].numero == numero){
        return direita;
    }
    else{
        return -1;
    }
}
void mergeSort(numeros *vetor, int inicio, int fim){
    int meio;
    if(inicio < fim){
        meio = (inicio + fim)/2;
        mergeSort(vetor, inicio, meio);
        mergeSort(vetor, meio+1, fim);
        merge(vetor, inicio, meio, fim);
    }
}
void merge(numeros *vetor, int inicio, int meio, int fim){
    int auxiliar1, auxiliar2, tamanho, i, j , k;
    numeros *temporario;
    tamanho = fim - inicio + 1;
    auxiliar1 = inicio;
    auxiliar2 = meio + 1;
    temporario = malloc(sizeof (struct numeros) * tamanho);
    if(temporario != NULL){
        for(i=0; i < tamanho; i++){
            if(auxiliar1 <= meio && auxiliar2 <= fim){
                if(vetor[auxiliar1].numero < vetor[auxiliar2].numero){
                    temporario[i].numero = vetor[auxiliar1].numero;
                    temporario[i].frequencia = vetor[auxiliar1].frequencia;
                    auxiliar1++;
                }
                else{
                    temporario[i].numero = vetor[auxiliar2].numero;
                    temporario[i].frequencia = vetor[auxiliar2].frequencia;
                    auxiliar2++;
                }
            }
            else{
                if(auxiliar1 > meio){
                    temporario[i].numero = vetor[auxiliar2].numero;
                    temporario[i].frequencia = vetor[auxiliar2].frequencia;
                    auxiliar2++;
                }
                else if(auxiliar2 > fim){
                    temporario[i].numero = vetor[auxiliar1].numero;
                    temporario[i].frequencia = vetor[auxiliar1].frequencia;
                    auxiliar1++;
                }
            }
        }
        for(j=0, k=inicio; j<tamanho; j++, k++){
            vetor[k].numero = temporario[j].numero;
            vetor[k].frequencia = temporario[j].frequencia;
        }
        free(temporario);
    }
}

