#include <stdio.h>
#include <stdlib.h>

// Função que recebe o vetor e a quantidade de elementos
int readWriter(int *v, int n){
    // Lê o vetor
    for (int i=0; i < n; i++){
        printf("Digite o elemento %d: ", i+1);
        scanf("%d", &v[i]);
    }

    // Escreve o vetor na tela
    for (int i = 0; i < n; i++){
        printf("%d ", v[i]);
    }
    printf("\n");

    return 0;
}

int main(void){
    // Declarando variáveis
    int n, *v;

    // Solicitando os dados
    printf("Digite a quantidade de elementos do vetor: ");
    scanf("%d", &n);

    v = (int *) malloc(n * sizeof(int)); // v armazena a primeira posição da memória alocada
    
    // Trantando o caso de erro da função malloc retornar NULL
    if (v == NULL){
        printf("Erro de alocação");
        exit(1);
    }
    
    // Chamando a função
    readWriter(v, n);

    // Libera a memória alocada
    free(v);

    return 0;
}
