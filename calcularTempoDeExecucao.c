#include<time.h>
#include<stdio.h>
int main(){
    double tempo;
    time_t t_ini, t_final;   // declarando as variaveis de tempo
    t_ini = time(NULL);      // pegando o tempo inicial
    for(int aux = 0; aux < 100000; aux++);
    t_final = time(NULL);    // pegando o tempo final
    tempo = difftime(t_final, t_ini);   // calculando o intervalo do tempo pela diferença do final - inicial
    return 0;
}

