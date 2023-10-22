#include <stdio.h>
#include <stdlib.h>

int main(void){
    // Declarando variáveis
    int n_alunos;
    float *notas, sum = 0;

    // Solicitando os dados
    printf("Digite a quantidade de alunos na turma CC10: ");
    scanf("%d", &n_alunos);

    // Alocando memória dinamicamente
    notas = (float *) malloc(n_alunos * sizeof(float));

    // Trantando o caso de erro da função malloc retornar NULL
    if (notas == NULL){
        printf("Erro de alocação");
        exit(1);
    }

    // Lendo o vetor
    for (int i = 0; i < n_alunos; i++){
        printf("Digite a nota do aluno %d: ", i+1);
        scanf("%f", &notas[i]);
        sum += notas[i];
    }

    // Imprime a média
    printf("A média da turma foi %.2f\n", sum / n_alunos);

    free(notas); // Libera a memória alocada

    return 0;
}