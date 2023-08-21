#include <stdio.h>
#include <stdlib.h>

//Definicao dos elementos que vao compor a fila
typedef struct paciente{
    int prioridade;
} paciente;


paciente* criarFilaPrio(int tamMaximo);
int inserirFilaPrio(paciente *fila, int novoElemento, int *tamFila, int tamMaximo);
void promoverElemento(paciente *fila, int posicaoFilho);
int removerFilaPrio(paciente *fila, int *tamFila);
void rebaixarElemento(paciente *fila, int pai, int tamFila);
int consultarFilaPrio(paciente *fila, int tamanho);

//A logica desta fila eh que os maiores numeros tem a maior prioridade, mas isso eh so uma escolha de projeto.
int main(){
    const int tamMaximo = 10;
    int aux;
    paciente *fila = criarFilaPrio(tamMaximo);
    int tamFila = 1;

    aux = inserirFilaPrio(fila, 4, &tamFila, tamMaximo);
    aux = inserirFilaPrio(fila, 1, &tamFila, tamMaximo);
    aux = inserirFilaPrio(fila, 9, &tamFila, tamMaximo);
    aux = inserirFilaPrio(fila, 8, &tamFila, tamMaximo);

    aux = removerFilaPrio(fila, &tamFila);
    aux = removerFilaPrio(fila, &tamFila);
    aux = removerFilaPrio(fila, &tamFila);
    for(int i = 1; i <= tamFila; i++){
        printf("%d ", fila[i].prioridade);
    }
    printf("\n");
    return 0;
}

//O tamanho eh (tamMaximo + 1) pois o vetor comeca na posicao 1, e seus filhos estarao nas posicoes [2 * i] e [(2 * i)+1]
// Se o vetor comecar em 0 os filhos deverao ser armazenados em [(2 * i) + 1] e  [(2 * i) + 2]
paciente* criarFilaPrio(int tamMaximo){
    paciente *fila = malloc(sizeof(paciente) * (tamMaximo+1));
    return fila;
}

//Esta funcao insere o elemento na heap. Retorna 1 se a insercao foi realizada, e 0 caso contrario
int inserirFilaPrio(paciente *fila, int novoElemento, int *tamFila, int tamMaximo){
    if(fila == NULL){
        return 0;
    }
    if(*tamFila - 1 == tamMaximo){ //Fila cheia
        return 0;
    }
    fila[*tamFila].prioridade = novoElemento;
    int posicaoFilho = *tamFila;
    promoverElemento(fila, posicaoFilho);
    *tamFila = *tamFila + 1;

    return 1;

}

//Esta funcao promove o elemento mais abaixo na raiz para cima na raiz, caso ele tenha maior prioridade que seus pais.
//Ela tambem pode ser chamada de "fixUP" ou "swim"
void promoverElemento(paciente *fila, int posicaoFilho){
    int pai;
    paciente temp;
    pai = posicaoFilho/2;

    while((posicaoFilho > 1) && fila[pai].prioridade < fila[posicaoFilho].prioridade){
        temp = fila[posicaoFilho];
        fila[posicaoFilho] = fila[pai];
        fila[pai] = temp;

        posicaoFilho = pai;
        pai = pai/2;
    }

}

//Esta funcao remove o elemento com maior prioridade. A logica eh mover o ultimo elemento para a primeira posica
// e depois rebaixa-lo, para que a heap nao tenha filhos com menos prioridade que os pais. Ela retorna 1 se a operacao
// for bem sucedida e 0 caso contrario
int removerFilaPrio(paciente *fila, int *tamFila){
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

//Esta funcao rebaixa o elemento mais abaixo na raiz para baixo na raiz, caso ele tenha menos prioridade que seus filhos.
//Ela tambem pode ser chamada de "fixDown" ou "sink"
void rebaixarElemento(paciente *fila, int pai, int tamFila){
    paciente temp;
    int filho = 2 * pai;
    while(filho <= tamFila){
        if(filho < tamFila-1 && fila[filho].prioridade < fila[filho+1].prioridade){ //pai tem dois filhos? Quem eh o maior?
            filho++;
        }
        if(fila[pai].prioridade >= fila[filho].prioridade){ //pai >= filho? terminar processo
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

// Esta funcao retorna -1 se a fila nao estiver alocada ou vazia, ou retorna o elemento no topo da arvore/inicio da fila
int consultarFilaPrio(paciente *fila, int tamanho){
    if(fila == NULL || tamanho == 0){
        return -1;
    }
    return fila[0].prioridade;
}

