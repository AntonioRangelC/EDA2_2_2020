#include<stdio.h>
#include<stdlib.h>

typedef struct cor{
    int codCor;
    int frequencia;
}cor;

cor *tabelaHash;
int hash(int cor, int tamanho);
void criarTabelaHash(int tamTabelaHash);
void insereNaTabela(int cor, int tamTabelaHash);
void quickselect(int inicio,int fim,int posicao);
int main(){
    int quantidade, aux, cor, maiorFreq, elemMaiorFreq;
    int tamTabelaHash = 10001;
    criarTabelaHash(tamTabelaHash);
    scanf("%d", &quantidade);
    while(quantidade > 0){
        for(aux = 0; aux < quantidade; aux++){
            scanf("%d", &cor);

            insereNaTabela(cor, tamTabelaHash);

        }

        /*for(aux = 0; aux < tamTabelaHash; aux++){
            if(aux == 0){
                elemMaiorFreq = tabelaHash[aux].codCor;
                maiorFreq = tabelaHash[aux].frequencia;
            }
            else if(tabelaHash[aux].frequencia > maiorFreq){
                maiorFreq = tabelaHash[aux].frequencia;
                elemMaiorFreq = tabelaHash[aux].codCor;
            }
        }*/
        quickselect(0, 10000, 10000);
        /*quickselect(0, 10000, 9999);
        quickselect(0, 10000, 9998);
        printf("%d", tabelaHash[9999].frequencia);
        printf("%d", tabelaHash[9998].frequencia);*/
        elemMaiorFreq = tabelaHash[10000].codCor;
        printf("%d\n", elemMaiorFreq);


        scanf("%d", &quantidade);
    }

    free(tabelaHash);
    return 0;
}
int hash(int cor, int tamanho){
    return cor % tamanho;
}


void criarTabelaHash(int tamTabelaHash){
    int aux;
    tabelaHash = malloc(sizeof(cor) * tamTabelaHash);

    for(aux = 0; aux < tamTabelaHash; aux++){
        tabelaHash[aux].codCor = -1;
        tabelaHash[aux].frequencia = 0;
    }

}

void insereNaTabela(int cor, int tamTabelaHash){
    int codigoHash = hash(cor, tamTabelaHash);
    while(tabelaHash[codigoHash].codCor != cor && tabelaHash[codigoHash].codCor != -1){
        codigoHash = (codigoHash + 1) % tamTabelaHash;
    }
    tabelaHash[codigoHash].codCor = cor;
    tabelaHash[codigoHash].frequencia++;
}

int separa(int comeco, int fim){
    int pivo = tabelaHash[fim].frequencia;
    int j = comeco, aux;
    cor temp;
    for(aux=comeco; aux<fim; aux++){
        if(tabelaHash[aux].frequencia < pivo){
            temp = tabelaHash[aux];
            tabelaHash[aux] = tabelaHash[j];
            tabelaHash[j] = temp;
            j++;
        }

    }
    temp = tabelaHash[j];
    tabelaHash[j] = tabelaHash[fim];
    tabelaHash[fim] = temp;
    return j;

}

void quickselect(int inicio,int fim,int posicao){
    int i;
    if(fim <= inicio){
        return;
    }

    i=separa( inicio, fim);

    if(i > posicao){
        quickselect(inicio,i-1,posicao);
    }
    if(i < posicao){
        quickselect(i+1,fim,posicao);
    }
}
