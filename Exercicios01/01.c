#include <stdio.h>

int main(void){
    // Declarando variáveis
    char nome[20];
    char sexo;

    // Solicitando os dados
    printf("Digite seu nome: ");
    fgets(nome, 20, stdin);
    printf("Digite seu sexo (M/F): ");
    scanf(" %c", &sexo);

    // Compara se o sexo é masculino ou feminino
    if (sexo == 'm' || sexo == 'M'){
        printf("Bem-vindo %s", nome);
    }
    else if (sexo == 'f' || sexo == 'F'){
        printf("Bem-vinda %s", nome);
    }
    else {
        printf("Não computável!"); // Pois programas só reconhecem binário
    }
    

    return 0;
}