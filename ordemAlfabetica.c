#include<stdio.h>
#include<string.h>


int main(){
    char nomes[5][21]={};
    char tmp[21]={};
    int linhas, colunas, i ,j, min, aux = 21;
    strcpy(nomes[0], "Jose");
    strcpy(nomes[1], "Alvaro");
    strcpy(nomes[2], "Cesar");
    strcpy(nomes[3], "Diego");
    strcpy(nomes[4], "Ana");

    for(i = 0; i < 4; i++){
        min = i;
        for(j = i + 1; j < 5; j++){
            if(strcmp(nomes[j], nomes[min]) < 0){
                min = j;
            }
        }
        strcpy(tmp, nomes[i]);
        strcpy(nomes[i], nomes[min]);
        strcpy(nomes[min], tmp);
    }


    int acabou = 0;
    for(linhas = 0; linhas < 5; linhas++){
        for(colunas = 0; colunas < 21 && acabou == 0; colunas++){
            if(nomes[linhas][colunas] == '\0'){
                acabou = 1;
            }
            else{
                printf("%c", nomes[linhas][colunas]);
            }

        }
        printf("\n");
        acabou = 0;
    }

    return 0;
}

