#include<stdio.h>
#include<stdlib.h>

typedef struct semente{
    long long int codigo;
    int notaQualidade;
}semente;

semente* criarFilaPrio(int tamMaximo);
int consultarFilaPrio_nota(semente *fila, int tamanho);
long long int consultarFilaPrio_cod(semente *fila, int tamanho);
int removerFilaPrio(semente *fila, int *tamFila);
void promoverElemento(semente *fila, int posicaoFilho);
void rebaixarElemento(semente *fila, int pai, int tamFila);
int inserirFilaPrio(semente *fila, long long int novoCodigo, int novaNota, int *tamFila, int tamMaximo);
void quicksortM3(semente *vetor, int comeco, int fim);
int separa(semente *vetor, int comeco, int fim);

int main(){
    int tamanhoMaxFila,notaSemente, aux=0, tamanhoFila = 1;
    long long int codigoSemente;
    scanf("%d", &tamanhoMaxFila);

    semente *fila = criarFilaPrio(tamanhoMaxFila);
    while(scanf("%lld %d", &codigoSemente, &notaSemente) != EOF){
        if(aux < tamanhoMaxFila){
            inserirFilaPrio(fila, codigoSemente, notaSemente, &tamanhoFila, tamanhoMaxFila);

        }
        else if((notaSemente < consultarFilaPrio_nota(fila, tamanhoFila)) ||
        (notaSemente == consultarFilaPrio_nota(fila, tamanhoFila) && codigoSemente < consultarFilaPrio_cod(fila, tamanhoFila)))
        {

            fila[1].notaQualidade = notaSemente;
            fila[1].codigo = codigoSemente;
            rebaixarElemento(fila, 1, tamanhoFila);
        }
        aux++;
    }

    quicksortM3(fila, 1, tamanhoFila-1);
    for(aux = 1; aux < tamanhoFila; aux++ ){
        printf("%lld %d\n",fila[aux].codigo, fila[aux].notaQualidade);
    }


    free(fila);

    return 0;
}

semente* criarFilaPrio(int tamMaximo){
    semente *fila = malloc(sizeof(semente) * (tamMaximo+1));
    return fila;
}

int consultarFilaPrio_nota(semente *fila, int tamanho){
    if(fila == NULL || tamanho == 0){
        return -1;
    }
    return fila[1].notaQualidade;
}

long long int consultarFilaPrio_cod(semente *fila, int tamanho){
    if(fila == NULL || tamanho == 0){
        return -1;
    }
    return fila[1].codigo;
}


int inserirFilaPrio(semente *fila, long long int novoCodigo, int novaNota, int *tamFila, int tamMaximo){
    if(fila == NULL){
        return 0;
    }
    if(*tamFila - 1 == tamMaximo){ //Fila cheia
        return 0;
    }
    fila[*tamFila].notaQualidade = novaNota;
    fila[*tamFila].codigo = novoCodigo;
    int posicaoFilho = *tamFila;
    promoverElemento(fila, posicaoFilho);
    *tamFila = *tamFila + 1;

    return 1;

}

int removerFilaPrio(semente *fila, int *tamFila){
    if(fila == NULL){
        return 0;
    }
    if(*tamFila == 0){
        return 0;
    }
    fila[1] = fila[*tamFila-1];
    *tamFila = *tamFila - 1;
    int tamanho = *tamFila;
    rebaixarElemento(fila, 1, tamanho);
    return 1;
}

void promoverElemento(semente *fila, int posicaoFilho){
    int pai;
    semente temp;
    pai = posicaoFilho/2;

    while((posicaoFilho > 1) && fila[pai].notaQualidade < fila[posicaoFilho].notaQualidade){
        temp = fila[posicaoFilho];
        fila[posicaoFilho] = fila[pai];
        fila[pai] = temp;

        posicaoFilho = pai;
        pai = pai/2;
    }

}

void rebaixarElemento(semente *fila, int pai, int tamFila){
    semente temp;
    int filho = 2 * pai;
    while(filho <= tamFila){
        if(filho < tamFila-1 && fila[filho].notaQualidade < fila[filho+1].notaQualidade){ //pai tem dois filhos? Quem eh o maior?
            filho++;
        }
        //pai >= filho? terminar processo
        if(fila[pai].notaQualidade > fila[filho].notaQualidade ||
        (fila[pai].notaQualidade == fila[filho].notaQualidade && fila[pai].codigo > fila[filho].codigo)){
            break;
        }

        temp = fila[pai];           //troca pai e filho de lugar
        fila[pai] = fila[filho];
        fila[filho] = temp;

        pai = filho;               //filho vira pai
        filho = 2 * pai;           // calcula novo filho
        if(filho == tamFila){
            filho = tamFila - 1;
        }
    }
}

void quicksortM3(semente *vetor, int comeco, int fim){
    int j, meio = (fim+comeco)/2;
    semente temp;
    if(fim<=comeco){
        return;
    }
    temp = vetor[fim-1];
    vetor[fim-1] = vetor[meio];
    vetor[meio] = temp;

    if(vetor[fim].codigo < vetor[meio].codigo){
        temp = vetor[fim];
        vetor[fim] = vetor[meio];
        vetor[meio] = temp;
        if( vetor[meio].codigo < vetor[comeco].codigo){
            temp = vetor[comeco];
            vetor[comeco] = vetor[meio];
            vetor[meio] = temp;
            if(vetor[meio].codigo < vetor[fim].codigo){
                temp = vetor[fim];
                vetor[fim] = vetor[meio];
                vetor[meio] = temp;
            }
        }
    }


    j = separa(vetor, comeco, fim);
    quicksortM3(vetor, comeco, j-1);
    quicksortM3(vetor, j+1, fim);
}

int separa(semente *vetor, int comeco, int fim){
    semente pivo = vetor[fim];
    int j = comeco, aux;
    semente temp;
    for(aux=comeco; aux<fim; aux++){
        if(vetor[aux].codigo < pivo.codigo){
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
