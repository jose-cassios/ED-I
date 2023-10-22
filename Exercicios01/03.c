#include <stdio.h>

int main(void){
    // Declarando variáveis
    float notas[10];
    float maior = 0, menor = 0;

    // Lendo o vetor de notas
    for (int i = 0; i < 10; i++){
        printf("Digite a nota do aluno %d: ", i+1);
        scanf("%f", &notas[i]);
    }

    // Comparando se cada posição do vetor é a maior ou a menor nota
    for (int i = 0; i < 10; i++){
        if (i == 0){
            maior = menor = notas[i];
        }
        else {
            if (notas[i] > maior){
                maior = notas[i];
            }
            if (notas[i] < menor){
                menor = notas[i];
            }
        }
        
    }

    // Imprime o resultado
    printf("A maior nota foi %.1f e a menor foi %.1f!", maior, menor);
    
    return 0;
}
