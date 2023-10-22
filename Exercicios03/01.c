/*Faça um programa que leia um vetor com os dados de 5 carros: marca, ano e preço. Em
seguida, leia um determinado valor e mostre as informações de todos os carros com preço
menor que o valor informado.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Carro{
    char marca[20];
    int ano;
    float preco;
    
} carro;


int main(void){
    float valor;
    carro *vetor = (carro *) malloc(5 * sizeof(carro));

    for (int i = 0; i < 5; i++){
        printf("Digite a marca do carro: ");
        fgets(vetor[i].marca, sizeof(vetor[i].marca), stdin);
        vetor[i].marca[strlen(vetor[i].marca) - 1] = '\0';

        printf("Digite o ano do carro: ");
        scanf("%d", &vetor[i].ano);
        getchar();

        printf("Digite o valor do carro: ");
        scanf("%f", &vetor[i].preco);
        getchar();

    }

    printf("\nDigite um valor de busca: ");
    scanf("%f", &valor);
    printf("\nCarros disponíveis pela faixa de preço: \n");
    for (int i = 0; i < 5; i++){
        if (valor > vetor[i].preco){
            printf(" [ %s - %d ] ", vetor[i].marca, vetor[i].ano);
        }
    }
    
    free(vetor);

    return 0;
}