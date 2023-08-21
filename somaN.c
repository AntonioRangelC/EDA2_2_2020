#include<stdio.h>
int main(){
    int quantidade, aux, numero, resultado=0;
    scanf("%d", &quantidade);
    for(aux = 0; aux < quantidade; aux++){
        scanf("%d", &numero);
        resultado += numero;
    }
    printf("%d\n", resultado);
    return 0;
}

