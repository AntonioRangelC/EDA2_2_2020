#include <stdio.h>
#include <stdlib.h>
void tiraRepetidos(int *auxiliar, int *entrada, int qtd, int *qtdAux);
void merge(int *vetor, int inicio, int meio, int fim);
void mergeSort(int *vetor, int inicio, int fim);
int buscaBinaria(int *auxiliar, int qtd, int numero);
void intercala(int *auxiliar, int la, int ra, int *somas, int lb, int rb, int *novoTam);
int main(){
    int qtd,qtdAux=0,aux,*entrada,*auxiliar, novoTam, *somas,tamSoma,j=0;
    scanf("%d", &qtd);

    entrada = malloc(sizeof(int) * qtd);
    auxiliar = malloc(sizeof(int) * qtd);


    for(aux = 0; aux < qtd; aux++){
        scanf("%d", &entrada[aux]);          // lendo a entrada
    }


    mergeSort(entrada, 0, qtd-1);    // ordenando
    tiraRepetidos(auxiliar, entrada, qtd, &qtdAux);   // o vetor auxiliar contem todos os numeros sem repeticao
                                           // a variavel qtdAux contem a quantidade de numeros desse vetor auxiliar
    novoTam = qtdAux + 1;       // novo tamanho do vetor auxiliar, caso ele tenha um tamanho impar
    if(qtdAux % 2 != 0){
        auxiliar = realloc(auxiliar, sizeof(int) * novoTam);
        auxiliar[qtdAux] = 1000000000;
        qtdAux++;
    }


    tamSoma = qtdAux/2;           // tamanho do vetor de somas
    somas = malloc(sizeof(int) * tamSoma);
    for(aux = 0; aux < qtdAux; aux+=2){
        somas[j] = auxiliar[aux] + auxiliar[aux+1];         // preenchendo o vetor de somas
        j++;
    }

    /*for(aux = 0; aux < j; aux ++){
        printf("%d ", somas[aux]);
    }
    printf("\n");*/

    novoTam = qtdAux + tamSoma;    // novo tamanho do vetor auxiliar, que vai receber o seu tamanho + somas
    auxiliar = realloc(auxiliar, novoTam * sizeof(int));

    intercala(auxiliar, 0, qtdAux-1, somas, 0, tamSoma-1, &novoTam);
    // no final dessa execucao, j tem a quantidade de elementos do vetor resultante
    /*for(aux = 0; aux <= novoTam-1; aux ++){
        printf("%d ", auxiliar[aux]);
    }
    printf("\n");*/
    //printf("NovoTam: %d\n", novoTam-2);
    //mergeSort(auxiliar, 0, j - 1);
    /*for(aux = 0; aux < j; aux ++){
        printf("%d ", auxiliar[aux]);
    }
    printf("\n");*/

    for(aux = 0; aux < novoTam; aux += 4){
        printf("%d\n", auxiliar[aux]);
    }
    printf("Elementos: %d\n", novoTam);

    free(entrada);
    free(auxiliar);
    free(somas);
    return 0;
}

void intercala(int *auxiliar, int la, int ra, int *somas, int lb, int rb, int *novoTam){
    int ta = ra - la + 1;
    int tb = rb - lb + 1;
    int *temporario = malloc(sizeof(int) * (ta + tb));

    int lc = 0;
    int rc = (ta + tb - 1);

    int ia = la;
    int ib = lb;
    int ic = 0;
    int aux;

    while (ia <= ra && ib <= rb){
        if(buscaBinaria(auxiliar, ra+1, somas[ib]) == -1){
            if (auxiliar[ia] <= somas[ib]){
                temporario[ic++] = auxiliar[ia++];
            }
            else{
                temporario[ic++] = somas[ib++];
            }
        }
        else{
            ib++;
        }

    }

    while (ia <= ra){
        temporario[ic++] = auxiliar[ia++];
    }

    while (ib <= rb){
        if(buscaBinaria(auxiliar, ra+1, somas[ib]) == -1){
            temporario[ic++] = somas[ib++];
        }
        else{
            ib++;
        }
    }
    *novoTam = ic;
    for(aux=0; aux<= (ta+tb-1); aux++){
        auxiliar[aux] = temporario[aux];
    }
    free(temporario);

}

void tiraRepetidos(int *auxiliar, int *entrada, int qtd, int *qtdAux){
    int aux;
    for(aux = 0; aux < qtd; aux++){
        if(aux == 0){
            auxiliar[*qtdAux] = entrada[aux];
            *qtdAux = *qtdAux + 1;
        }
        else{
            if(entrada[aux] != entrada[aux - 1]){
                auxiliar[*qtdAux] = entrada[aux];
                *qtdAux = *qtdAux + 1;
            }
        }
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



int buscaBinaria(int *auxiliar, int qtd, int numero){
    int esquerda=-1, direita=qtd,meio;
    while(esquerda < direita-1){  //se 'esquerda' estiver uma posicao atras de 'direita', sai do laco,
        meio = (esquerda + direita)/2;
        if(auxiliar[meio] < numero){   // se o elemento do meio for menor, preciso procurar no sub-vetor da direita
            esquerda = meio;
        }
        else{                      // se o elemento do meio for maior, preciso procurar no sub-vetor da esquerda
            direita = meio;
        }
    }
    if(auxiliar[direita] == numero){
        return 1;
    }
    else{
        return -1;
    }
}

