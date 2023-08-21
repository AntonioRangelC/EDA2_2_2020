#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct registro{
    int id;
    char nome[21];

}registro;


void ordenaPorId(registro *pessoas, int tamanho);
void ordenaPorNome(registro *pessoas, int tamanho);
int main(){
    int aux, i,j;
    registro pessoas[5];
    pessoas[0].id = 87;
    strcpy(pessoas[0].nome, "Andre");

    pessoas[1].id = 12;
    strcpy(pessoas[1].nome, "Junior");

    pessoas[2].id = 88;
    strcpy(pessoas[2].nome, "Agatha");

    pessoas[3].id = 89;
    strcpy(pessoas[3].nome, "Diego");

    pessoas[4].id = 5;
    strcpy(pessoas[4].nome, "Julia");


    ordenaPorNome(pessoas, 5);
    for(aux = 0; aux < 5; aux++){
        printf("%d\t\t%s\n", pessoas[aux].id, pessoas[aux].nome);
    }


    return 0;
}


void ordenaPorNome(registro *pessoas, int tamanho){
    int i, min,j;
    registro tmp;
    for(i = 0; i < tamanho-1; i++){
        min = i;
        for(j = i + 1; j < tamanho; j++){
            if(strcmp(pessoas[j].nome, pessoas[min].nome) < 0){
                min = j;
            }
        }
        tmp = pessoas[i];
        pessoas[i] = pessoas[min];
        pessoas[min] = tmp;
    }


}

void ordenaPorId(registro *pessoas, int tamanho){
    int i,j,min;
    registro tmp;
    for(i = 0; i < tamanho-1; i++){
        min = i;
        for(j = i + 1; j < tamanho; j++){
            if(pessoas[j].id < pessoas[min].id){
                min = j;
            }
        }
        tmp = pessoas[i];
        pessoas[i] = pessoas[min];
        pessoas[min] = tmp;

    }

}

