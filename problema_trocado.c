#include <stdio.h>
 int main(){
    int acabou = 0, numero;
    while(scanf("%d", &numero) != EOF){
        if(numero == 42){
            acabou = 1;
        }
        if(acabou == 0){
            printf("%d\n", numero);
        }



    }



    return 0;
}

