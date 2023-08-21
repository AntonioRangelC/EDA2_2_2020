#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#include<string.h>

typedef struct cidade{
    char nome[28];
    struct cidade *prox;
} cidade;

cidade *cria_fila();
void enfileira(cidade **inicio, char *nome);
int desenfileira(cidade *inicio);
char pegarUltimaLetraNome(char *nome);
int main(){
    cidade *inicio = cria_fila();
    cidade *aux;
    cidade *temporario = malloc(sizeof(cidade) * 1);

    int i;
    char nome[28], primLetra, ultimaLetra;
    int desenfileirou = 1;
    while(scanf(" %s", nome) != EOF){
        enfileira(&inicio, nome);
    }
    /*for(i=0; i<3; i++){
        scanf(" %s", nome);
        enfileira(&inicio, nome);
    }*/
    aux = inicio->prox;
    while(aux != inicio && desenfileirou){
        ultimaLetra = pegarUltimaLetraNome(aux->nome);
        printf("%s\n", aux->nome);
        aux = aux->prox;
        desenfileirou = desenfileira(inicio);
        if(desenfileirou){
            primLetra = tolower(inicio->prox->nome[0]);

           if(primLetra == ultimaLetra){
                aux = aux->prox;
                strcpy(temporario->nome, inicio->prox->nome);
                desenfileirou = desenfileira(inicio);
                enfileira(&inicio, temporario->nome);
           }
        }


    }
    return 0;
}

cidade *cria_fila(){
    cidade *novo = malloc(sizeof(cidade));
    novo->prox =novo;
    return novo;
}

void enfileira(cidade **inicio, char *nome){
    struct cidade *novo = malloc(sizeof(cidade));
    novo->prox = (*inicio)->prox;
    (*inicio)->prox =novo;
    strcpy((*inicio)->nome, nome);
    *inicio= novo;
}

int desenfileira(cidade *inicio){
    cidade *lixo = inicio->prox;
    if(lixo->prox == lixo){
        return 0;
    }
    else{
        inicio->prox = lixo->prox;
        free(lixo);
        return 1;
    }

}

char pegarUltimaLetraNome(char *nome){
    int tamanho = strlen(nome);
    return nome[tamanho-1];
}

