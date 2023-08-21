#include<stdio.h>
#include<stdlib.h>

void quickselect(int *vetor,int inicio,int fim,int posicao);
int separa(int *vetor, int comeco, int fim);
void mergeSort(int *vetor, int inicio, int fim);
void merge(int * vetor, int inicio, int meio, int fim);

int main(){
    int qtdTotalProdutos, pagina, qtdProdPorPag, aux;
    scanf("%d %d %d", &qtdTotalProdutos, &pagina, &qtdProdPorPag);
    int *vetor = malloc(sizeof(int) * qtdTotalProdutos);

    for(aux=0; aux < qtdTotalProdutos; aux++){
        scanf("%d", &vetor[aux]);
    }

    int comecoPagina = pagina * qtdProdPorPag;

    int finalPagina = comecoPagina + qtdProdPorPag - 1;

    if(finalPagina > qtdTotalProdutos -1){
        finalPagina = qtdTotalProdutos -1;
    }

    quickselect(vetor, 0, qtdTotalProdutos-1, comecoPagina);
    quickselect(vetor, comecoPagina, qtdTotalProdutos-1, finalPagina);
    mergeSort(vetor, comecoPagina, finalPagina-1);

    for(aux = comecoPagina; aux <= finalPagina; aux++){
        printf("%d\n", vetor[aux]);
    }

    free(vetor);

    return 0;
}

void quickselect(int *vetor,int inicio,int fim,int posicao){
    int i;
    if(fim <= inicio){
        return;
    }

    i = separa(vetor, inicio, fim);

    if(i > posicao){
        quickselect(vetor,inicio,i-1,posicao);
    }
    if(i < posicao){
        quickselect(vetor,i+1,fim,posicao);
    }
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




