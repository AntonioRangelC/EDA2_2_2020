#include<stdio.h>
#include<stdlib.h>
void merge(int * vetor, int inicio, int meio, int fim);
void mergeSort(int *vetor, int inicio, int fim);
int main(){
    int *vetor;
    int i, qtd;
    scanf("%d", &qtd);
    vetor = malloc(sizeof (int) * qtd);

    for(i=0; i<qtd; i++){
        scanf("%d", &vetor[i]);
    }
    mergeSort(vetor, 0, qtd-1);
    for(i=0; i<qtd; i++){
        if(i < qtd-1){
            printf("%d ", vetor[i]);
        }
        else{
            printf("%d", vetor[i]);
        }
    }
    printf("\n");
    free(vetor);
    return 0;
}


void mergeSort(int *vetor, int inicio, int fim){
    int meio;
    if(inicio < fim){
        meio = (inicio + fim)/2;
        mergeSort(vetor, inicio, meio);
        mergeSort(vetor, meio+1, fim);
        merge(vetor, inicio, meio, fim);
    }
}
void merge(int * vetor, int inicio, int meio, int fim){
    int *temporario, auxiliar1, auxiliar2, tamanho, i, j , k;
    tamanho = fim - inicio + 1;
    auxiliar1 = inicio;
    auxiliar2 = meio + 1;
    temporario = malloc(sizeof (int) * tamanho);
    if(temporario != NULL){
        for(i=0; i < tamanho; i++){
            if(auxiliar1 <= meio && auxiliar2 <= fim){
                if(vetor[auxiliar1] < vetor[auxiliar2]){
                    temporario[i] = vetor[auxiliar1];
                    auxiliar1++;
                }
                else{
                    temporario[i] = vetor[auxiliar2];
                    auxiliar2++;
                }
            }
            else{
                if(auxiliar1 > meio){
                    temporario[i] = vetor[auxiliar2];
                    auxiliar2++;
                }
                else if(auxiliar2 > fim){
                    temporario[i] = vetor[auxiliar1];
                    auxiliar1++;
                }
            }
        }
        for(j=0, k=inicio; j<tamanho; j++, k++){
            vetor[k] = temporario[j];
        }
        free(temporario);
    }
}


