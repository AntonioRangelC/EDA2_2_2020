#include <stdio.h>
#include <stdlib.h>
void merge(int *vetor, int inicio, int meio, int fim);
void mergeSort(int *vetor, int inicio, int fim);
int main(){
    int aux, qtd1, inicio, fim, *vetor,i, j, novoTam;
    for(aux = 0; aux < 8; aux++){
        if(aux == 0){                  // se for a primeira iteracao, eh preciso fazer um malloc
            scanf("%d", &qtd1);
            if(qtd1 > 0){               // caso a quantidade seja 0, nada deve acontecer
                vetor = malloc(sizeof(int) * qtd1);     // alocando o vetor
                for(i = 0; i < qtd1; i++){              // preenchendo o vetor
                    scanf("%d", &vetor[i]);
                }
                fim = qtd1 - 1;               // o fim eh a posicao do ultimo elemento
            }
        }
        else{                        // caso nao seja a primeira iteracao, eh preciso fazer um realloc
            scanf("%d", &qtd1);
            if(qtd1 > 0){
                if(vetor == NULL){                   // caso o vetor nao tenha sido alocado ainda, eh preciso usar o malloc
                    vetor = malloc(sizeof(int) * qtd1);                 // este bloco de codigo existe pois eh possivel
                    for(i = 0; i < qtd1; i++){                          //  que o for esteja em alguma iteracao maior que zero
                        scanf("%d", &vetor[i]);                         //  e o vetor ainda nao tenha sido alocado
                    }
                    fim = qtd1 - 1;

                }
                else{                                 // caso o vetor ja tenha sido alocado
                    novoTam = fim + 1 + qtd1;
                    vetor = realloc(vetor , novoTam * sizeof(int));
                    for(i = fim + 1; i <= fim + qtd1; i++){
                        scanf("%d", &vetor[i]);
                    }
                    fim = fim + qtd1;
                }

            }
        }

    }
    mergeSort(vetor, 0, fim);
    for(j=0; j<=fim; j++){
        printf("%d ", vetor[j]);
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
void merge(int *vetor, int inicio, int meio, int fim){
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

