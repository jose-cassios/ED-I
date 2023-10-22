#include <stdio.h>

int main(void){
    // Declarando variáveis
    int n;
    
    // Recebendo o número
    printf("Digite um número de 1 a 9: ");
    scanf("%d", &n);

    // Exibe as multiplicações
    for (int i = 0; i <= 10; i++){
        printf("%d x %d = %d\n", n, i, n*i);
    }
    

    return 0;
}
