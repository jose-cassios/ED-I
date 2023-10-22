#include <stdio.h>
#include <stdlib.h>
#include "listas_util.h"

int main(void){
    celula *lista = NULL;
    int opc, valor;
    celula *atual = NULL;

    printf("\nDigite a operação (0 - sair): \n[1] Inserir no inicio\t[2] Inserir no meio\n[3] Inserir no fim\t[4] Mostrar lista\n[5] Posição\t\t[6] Trocar um elemento com o proximo\n:");
    scanf("%d", &opc);
    getchar();

    while (opc != 0){
        switch (opc){
        case 1: // Inserir no inicio
            printf("\nQual valor você deseja inserir\n>: ");
            scanf("%d", &valor);
            getchar();
            inserir_no_inicio(valor, &lista);
            break;

        case 2: // Inserir no meio
            printf("\nQual valor você deseja inserir\n>: ");
            scanf("%d", &valor);
            getchar();
            inserir_no_meio(valor, &lista);
            break;

        case 3: // Inserir no fim
            printf("\nQual valor você deseja inserir\n>: ");
            scanf("%d", &valor);
            getchar();
            inserir_no_fim(valor, &lista);
            break;

        case 4: // Exibir lista
            mostrar_lista(&lista);
            break;

        case 5: // Exibir qual a posição de cada elemtento da
            posicao(&lista);
            break;

        case 6:
            trocar(&lista);
            break;

        default:
            printf("Opção inválida!\n");
            break;
        }
        printf("\nDigite a operação 0 - sair: \n[1] Inserir no inicio\n[2] Inserir no meio\n[3] Inserir no fim\n[4] Mostrar\n[5] Posição\n[6] Trocar de posição\n:");
        scanf("%d", &opc);
    }
        
    atual = lista;
    while (atual != NULL) {
        celula *temp = atual;
        atual = atual->prox;
        free(temp);
    }

    return 0;
}