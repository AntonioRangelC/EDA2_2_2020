#include <stdio.h>
#include <stdlib.h>
int main(){
    int qtd,aux,numero, contador=0;
    int *vetor;
    scanf("%d", &qtd);
    vetor = malloc(sizeof (int) * 1000001);

    for(aux = 0; aux < qtd; aux++){
        vetor[aux] = 0;
    }
    for(aux=0; aux < qtd; aux++){
        scanf("%d", &numero);
        vetor[numero] = vetor[numero] + 1;
    }
    for(aux = 0; aux < 1000001; aux++){
        if(vetor[aux] > 0){
            contador++;
        }
    }


    printf("%d\n", contador);
    free(vetor);

    return 0;
}



