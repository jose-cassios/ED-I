#include <stdio.h>
#include <stdlib.h>
#include "listas_duplas_util.h"

int main(void){
    celula *lista = NULL;

    inserir_no_inicio(10, &lista);
    inserir_no_fim(20, &lista);

    celula *aux = lista;
    while (aux != NULL){
        printf("[ %d ] ", aux->valor);
        aux = aux->prox;
    }
    
    aux = lista;
    while (aux != NULL){
        celula *temp = aux;
        aux = aux->prox;
        free(temp);
    }
    printf("\n");
    return 0;
}