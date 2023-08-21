#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct instrucao{
    int codigo;
    char nome[16];

} instrucao;
void ordena(instrucao *instrucoes, int quantidade);
void busca(int codigo, instrucao *instrucoes, int quantidade);
int main(){
    int quantidade, aux, codigo;
    char nome[16];
    scanf("%d", &quantidade);

    instrucao *instrucoes = malloc(sizeof(instrucao) * quantidade);


    for(aux = 0; aux < quantidade; aux++){
        scanf("%d %[^\n]", &instrucoes[aux].codigo, instrucoes[aux].nome);
    }

    ordena(instrucoes, quantidade);
    /*for(aux=0; aux<quantidade; aux++){
        printf("cod: %d\tinst:%s\n", instrucoes[aux].codigo, instrucoes[aux].nome);
    }*/
    while(scanf("%d", &codigo) != EOF){
        busca(codigo, instrucoes, quantidade);

    }



    free(instrucoes);
    return 0;
}

void ordena(instrucao *instrucoes, int quantidade){
    int i,j,min;
    instrucao tmp;
    for(i = 0; i < quantidade-1; i++){
        min = i;
        for(j = i + 1; j < quantidade; j++){
            if(instrucoes[j].codigo < instrucoes[min].codigo){
                min = j;
            }
        }
        tmp = instrucoes[i];
        instrucoes[i] = instrucoes[min];
        instrucoes[min] = tmp;

    }
}

void busca(int codigo, instrucao *instrucoes, int quantidade){


    int esquerda=-1, direita = quantidade,meio;
    while(esquerda < direita-1){  //se 'esquerda' estiver uma posicao atras de 'direita', sai do laco,
        meio = (esquerda + direita)/2;
        if(instrucoes[meio].codigo < codigo){   // se o elemento do meio for menor, preciso procurar no sub-vetor da direita
            esquerda = meio;
        }
        else{                      // se o elemento do meio for maior, preciso procurar no sub-vetor da esquerda
            direita = meio;
        }
    }
    if(instrucoes[direita].codigo == codigo){
        printf("%s\n", instrucoes[direita].nome);
    }
    else {
        printf("undefined\n");
    }
}

