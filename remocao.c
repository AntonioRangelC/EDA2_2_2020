#include<stdio.h>
#include<stdlib.h>

typedef struct celula{
    unsigned long int endereco;
    unsigned long int prox;
    unsigned long int ant;
}celula;

int buscaBinaria(celula *vetor, int qtdNum, unsigned long int numero);
void merge(celula * vetor, int inicio, int meio, int fim);
void mergeSort(celula *vetor, int inicio, int fim);
void imprimeElementosAntesPtr1(celula *vetor, int tamanho, celula ptr1, celula ptr2);
void preencheDump(celula *vetor, unsigned long int *dump, int tamanho, celula ptr1, celula ptr2);
void imprimeElementosDepoisPtr2(celula *vetor, int tamanho, celula ptr1, celula ptr2);
int main(){
    int aux=0, i=0;
    int *tamanhoDump=0;
    celula ptr1, ptr2;
    celula *vetor = malloc(sizeof(celula) * 250000);
    unsigned long int *dump = malloc(sizeof(unsigned long int) * 250000);
    while(scanf("%lx %lx %lx", &vetor[aux].endereco, &vetor[aux].ant, &vetor[aux].prox) != EOF){
        aux++;
    }

    ptr1 = vetor[0];
    ptr2 = vetor[1];

    mergeSort(vetor, 0, aux-1);


    imprimeElementosAntesPtr1(vetor, aux, ptr1, ptr2);

    preencheDump(vetor , dump, aux ,ptr1, ptr2);

    imprimeElementosDepoisPtr2(vetor, aux, ptr1, ptr2);
    printf("\n");
    while(dump[i] != 0){
        printf("%lx\n", dump[i]);
        i++;
    }
    /*for(i=0; i < aux; i++){
        printf("%lx %lx %lx\n", vetor[i].endereco, vetor[i].ant, vetor[i].prox);
    }*/
    free(vetor);
    free(dump);

    return 0;
}

void imprimeElementosDepoisPtr2(celula *vetor, int tamanho, celula ptr1, celula ptr2){
    unsigned long int elemento = ptr2.prox;
    int retornoBusca, continuarBuscando=1;

    celula *depoisPtr2 = malloc(sizeof(celula) * 250000);
    int aux=0,i;
    while(continuarBuscando){
        retornoBusca = buscaBinaria(vetor, tamanho, elemento);
        if(retornoBusca == -1){
            continuarBuscando = 0;
        }
        else{
            depoisPtr2[aux] = vetor[retornoBusca];
            aux++;
            elemento = vetor[retornoBusca].prox;        // setando proximo elemento a ser procurado
        }
    }

    for(i = 0; i < aux; i++){
        if(i == 0){
            printf("%lx %lx %lx", depoisPtr2[i].endereco, ptr1.ant, depoisPtr2[i].prox);
            printf("\n");
        }
        else{
            printf("%lx %lx %lx", depoisPtr2[i].endereco, depoisPtr2[i].ant, depoisPtr2[i].prox);
            printf("\n");
        }

    }

    free(depoisPtr2);
}


// esta funcao preenche um vetor com os elementos que serao eliminados, pois eles serao imprimidos na main
void preencheDump(celula *vetor, unsigned long int *dump, int tamanho, celula ptr1, celula ptr2){
    int  continuarBuscando=1, retornoBusca;
    int tamanhoDump = 1;
    dump[0] = ptr1.endereco;
    unsigned long int elemento = ptr1.prox;
    while(continuarBuscando){
        retornoBusca = buscaBinaria(vetor, tamanho, elemento);
        if(retornoBusca == -1){
            continuarBuscando = 0;
        }
        else if(vetor[retornoBusca].endereco == ptr2.endereco){
            dump[tamanhoDump] = vetor[retornoBusca].endereco;
            tamanhoDump = tamanhoDump + 1;
            continuarBuscando = 0;
        }
        else{
            dump[tamanhoDump] = vetor[retornoBusca].endereco;
            tamanhoDump = tamanhoDump + 1;
            elemento = vetor[retornoBusca].prox;
        }
    }

}

void imprimeElementosAntesPtr1(celula *vetor, int tamanho, celula ptr1, celula ptr2){
    unsigned long int elemento = ptr1.ant;
    int retornoBusca, continuarBuscando=1;

    celula *antesPtr1 = malloc(sizeof(celula) * 250000);
    int aux=0,i;
    while(continuarBuscando){
        retornoBusca = buscaBinaria(vetor, tamanho, elemento);
        if(retornoBusca == -1){
            continuarBuscando = 0;
        }
        else{
            antesPtr1[aux] = vetor[retornoBusca];
            aux++;
            elemento = vetor[retornoBusca].ant;        // setando proximo elemento a ser procurado
        }
    }

    for(i = aux-1; i >= 0; i--){
        if(i == 0){
            printf("%lx %lx %lx", antesPtr1[i].endereco, antesPtr1[i].ant, ptr2.prox);
            printf("\n");
        }
        else{
            printf("%lx %lx %lx", antesPtr1[i].endereco, antesPtr1[i].ant, antesPtr1[i].prox);
            printf("\n");
        }

    }

    free(antesPtr1);
}

int buscaBinaria(celula *vetor, int qtdNum, unsigned long int numero){
    int esquerda=-1, direita=qtdNum,meio;
    while(esquerda < direita-1){  //se 'esquerda' estiver uma posicao atras de 'direita', sai do laco,
        meio = (esquerda + direita)/2;
        if(vetor[meio].endereco < numero){   // se o elemento do meio for menor, preciso procurar no sub-vetor da direita
            esquerda = meio;
        }
        else{                      // se o elemento do meio for maior, preciso procurar no sub-vetor da esquerda
            direita = meio;
        }
    }
    if(vetor[direita].endereco == numero){
        return direita;
    }
    else if((vetor[direita].prox == 0 || vetor[direita].ant == 0) || vetor[direita].endereco != numero){
        return -1;                  // caso o numero nao seja achado ou proximo seja igual a zero ou anterior
    }                               // seja igual a zero, deve retornar -1
    return 0;
}


void mergeSort(celula *vetor, int inicio, int fim){
    int meio;
    if(inicio < fim){
        meio = (inicio + fim)/2;
        mergeSort(vetor, inicio, meio);
        mergeSort(vetor, meio+1, fim);
        merge(vetor, inicio, meio, fim);
    }
}


void merge(celula * vetor, int inicio, int meio, int fim){
    int  auxiliar1, auxiliar2, tamanho, i, j , k;
    celula *temporario;
    tamanho = fim - inicio + 1;
    auxiliar1 = inicio;
    auxiliar2 = meio + 1;
    temporario = malloc(sizeof (celula) * tamanho);
    if(temporario != NULL){
        for(i=0; i < tamanho; i++){
            if(auxiliar1 <= meio && auxiliar2 <= fim){
                if(vetor[auxiliar1].endereco < vetor[auxiliar2].endereco){
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



