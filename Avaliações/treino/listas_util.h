#include <stdio.h>
#include <stdlib.h>

// Estrutura
typedef struct Celula {
    int valor;
    struct Celula *prox;
    
} celula;

// Inserir no inicio
void inserir_no_inicio(int valor, celula **lista){
    celula *novo = (celula *) malloc(sizeof(Celula));

    if (novo == NULL){
        printf("Erro!");
        exit(1);
    }

    novo->valor = valor;
    novo->prox = *lista;
    *lista = novo;

}

// Inserir no Meio
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

    while (temp != NULL){
        if (temp->valor == num){
            valor_encontrado = 1;
            break;
        }
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

// Inserir no fim
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
        temp->prox = novo;
         
    }
    
}

void mostrar_lista(celula **lista){
    celula *aux = *lista;

    if (aux == NULL) {
        printf("A lista está vazia.\n");
        return;
    }

    printf("Elementos da lista:\n ");
    while (aux != NULL){
        printf(" [ %d ] ", aux->valor);
        aux = aux->prox;
    }
    printf("\n");

}

void posicao(celula **lista){
    int pos = 1;

    celula *aux = *lista;
    while (aux != NULL){
        printf("[ %d ] - %d°\n", aux->valor, pos++);
        aux = aux->prox;
    }
}

void trocar(celula **lista){
    int valor, valor_encontrado = 0;
    printf("\nQual valor você deseja trocar de lugar com o proximo\n>: ");
    scanf("%d", &valor);
    getchar();

    celula *aux = *lista;
    celula *ant = NULL;

    if (aux == NULL) {
        printf("A lista está vazia. Nada para trocar.\n");
        return;
    }

    // Verifica se o valor esta na lista
    while (aux != NULL){
        if (aux->valor == valor){
            valor_encontrado = 1;
            break;
        }
        ant = aux;
        aux = aux->prox;
    } // aux agora vale o endereco que armazena o valor
    
    celula *prox = aux->prox;

    if (aux->prox == NULL){
        printf("Não existe um proximo elemento para ser trocado!\n");
        return;
    }

    if (!valor_encontrado){
        printf("O valor referenciado não pertence a lista\n");
        return;
    }

    if (ant != NULL) {
        ant->prox = prox;
        aux->prox = prox->prox;
        prox->prox = aux;
    }

    else {
        *lista = prox;
        aux->prox = prox->prox;
        prox->prox = aux;
    }
}