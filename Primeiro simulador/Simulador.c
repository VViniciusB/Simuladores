#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double aleatorio(){
    double u = rand() / ((double) RAND_MAX + 1);
    //limitando entre (0,1]
    u = 1.0 - u;
    return (u);
}

double minimo(double num1, double num2){
    if(num1 < num2){
        return num1;
    }
    return num2;
}

int main(){
    double chegada;
    double servico;

    double tempo_simulacao;
    double tempo_decorrido = 0.0;

    double intervalo_medio_chegada;
    double tempo_medio_servico;

    unsigned long int fila = 0;

    printf("Informe o tempo de simulacao (segundos):");
    scanf("%lF",&tempo_simulacao);

    printf("Informe o intervalo medio entre chegadas (segundos):");
    scanf("%lF",&intervalo_medio_chegada);

    printf("Informe o tempo medio de serviço (segundos):");
    scanf("%lF",&tempo_medio_servico);

    //gerando o tempo de chegada da primeira requisicao
    chegada = (-1.0 / (1.0/intervalo_medio_chegada)) * log(aleatorio());

    while(tempo_decorrido <= tempo_simulacao){
        tempo_decorrido = !fila ? chegada : minimo(chegada, servico);

        if(tempo_decorrido == chegada){
            printf("Chegada em %lF.\n", tempo_decorrido);
            if(!fila){
                servico = tempo_decorrido + (-1.0 / (1.0/tempo_medio_servico)) * log(aleatorio());
                
            }
            fila++;
            chegada = tempo_decorrido + (-1.0 / (1.0/intervalo_medio_chegada)) * log(aleatorio());

        }else{
            printf("Saida  em %lF.\n", tempo_decorrido);
            fila--;

            if(fila){
                servico = tempo_decorrido + (-1.0 / (1.0/tempo_medio_servico)) * log(aleatorio());
            }
        }
    }
    return 0;

}