#include <stdio.h>

int main(void){
    // Declarando variáveis
    int v[4] = {0,1,2,3}; 
    int *ponteiro;

    ponteiro = v; // Passando o endereço da primeira posição do vetor 

    for (int i = 0; i < 4; i++){
        *ponteiro += 1; // Soma 1 no valor de v[i]
        ponteiro++; // Soma 1 no endereço do vetor
    }

    //Imprime o vetor com a soma
    for (int i = 0; i<4; i++){
        printf("%d ", v[i]);
    }
    printf("\n");

    return 0;
}
