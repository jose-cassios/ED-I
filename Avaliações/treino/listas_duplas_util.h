#include <stdio.h>
#include <stdlib.h>

typedef struct Celula {
    int valor;
    struct Celula *prox;
    struct Celula *ante;

} celula;

void inserir_no_inicio(int valor, celula **lista){
    celula *novo = (celula *) malloc(sizeof(celula));

    if (novo == NULL){
        printf("Erro de alocação!\n");
        exit(1);
    }

    novo->valor = valor;
    novo->prox = *lista;
    novo->ante = NULL;
    *lista = novo;

}

void inserir_no_meio(int valor, celula **lista){
    celula *novo = (celula *) malloc(sizeof(celula));
    int num, valor_encontrado = 0;
    char inser;

    if (novo == NULL){
        printf("Erro!");
        exit(1);
    }

    printf("Escolha um valor de referencia na lista: ");
    scanf("%d", &num);
    getchar();

    celula *temp = *lista;
    celula *anterior = NULL; 

    // Percorre a lista em busca do valor de referência
    while (temp != NULL){
        if (temp->valor == num){
            valor_encontrado = 1; // Se o valor estiver na lista, saimos do loop e temp valera a celula do valor.
            break;
        }
        // Incremento
        anterior = temp; 
        temp = temp->prox;
    }
    

    printf("Você deseja inserir antes ou depois do valor [a/d]: ");
    scanf("%c", &inser);
    getchar();
    
    novo->valor = valor;

    if (!valor_encontrado){
        printf("O valor referenciado não pertence a lista\n");
        free(novo);
        return;
    }

    if (inser == 'a'){
        if (anterior == NULL){
            novo->prox = *lista;
            *lista = novo;
        }
        else {
            anterior->prox = novo;
            novo->prox = temp;
        }
    }
        
    else if (inser == 'd'){
        novo->prox = temp->prox;
        temp->prox = novo;
    }
    else{
        printf("Opção inválida!\n");
        free(novo);
        return;
    }

}

void inserir_no_fim(int valor, celula **lista){
    celula *novo = (celula *) malloc(sizeof(celula));

    if (novo == NULL){
        printf("Erro!");
        exit(1);
    }

    novo->valor = valor;
    novo->prox = NULL;

    if (*lista == NULL){
        *lista = novo;
    }

    else{
        celula *temp = *lista;
        while (temp->prox != NULL){
            temp = temp->prox;
        }
        novo->ante = temp;
        temp->prox = novo;
        
         
    }
    
}