#include <stdio.h>

// Atribui o dobro de A e B em seus endereços e retorna a soma dos novos A e B
int somadobro(int *p, int *b){
    *p = (*p) * 2;
    *b = (*b) * 2;

    return *p + *b;
}

int main(void){
    // Declarando variáveis
    int A, B;

    // Solicitando os valores
    printf("Digite o valor de 2 inteiros: ");
    scanf("%d %d", &A, &B);

    // Chamando a função dentro do printf que exibirá a soma do dobro
    printf("A soma entre %d e %d é %d\n", A, B, somadobro(&A, &B));

    return 0;
}
