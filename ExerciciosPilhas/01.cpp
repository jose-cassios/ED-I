#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct reg_site{
    char nome[50];
    char link[100];

} site;

typedef struct Stack{
    site Site;

    struct Stack *prox;

} stack;

void novo_link(stack **pilha){
    stack *novo = (stack *) malloc(sizeof(stack));

    printf("\nDigite o nome do site: ");
    fflush(stdin);
    fgets(novo->Site.nome, 50, stdin);
    novo->Site.nome[strcspn(novo->Site.nome, "\n")] = '\0';

    printf("Digite o link do site: ");
    fflush(stdin);
    fgets(novo->Site.link, 100, stdin);
    novo->Site.link[strcspn(novo->Site.link, "\n")] = '\0';

    novo->prox = *pilha;
    *pilha = novo;
    return;

}

stack *voltar(stack *p, int n){
    for (int i = 0; i < n; i++){
        if (p == NULL){
            printf("\nNão há mais sites a serem retornados!\n");
            return NULL;
        }
        stack *aux = p;
        p = p->prox;
        free(aux);

    }
    return p;
}

void mostrar(stack **pilha){
    stack *aux = *pilha;
    while (aux != NULL){
        printf("\nNome: [ %s ]\n", aux->Site.nome);
        printf("Link: [ %s ]\n", aux->Site.link);
        aux = aux->prox;
    }
}

int main(void){
    stack *pilha= NULL;
    int opc = -1;

    while (opc != 0){
        printf("\nDigite a operação:\n\
[ 1 ] - Abrir novo link\n\
[ 2 ] - Voltar\n\
[ 3 ] - Mostrar\n\
[ 0 ] - Sair do navegador\n\
opção: ");
        scanf("%d", &opc);
        getchar();

        switch (opc){
        case 1:
            novo_link(&pilha);
            break;

        case 2:
            int n;
            printf("Digite quantos sites devemos voltar: ");
            scanf("%d", &n);
            pilha = voltar(pilha, n);
            break;

        case 3:
            mostrar(&pilha);
            break;

        case 0:
            printf("\nVolte sempre\n");
            break;

        default:
            printf("Opção Inválida");
            break;
        }

    }
    
    while (pilha != NULL){
        stack *aux = pilha;
        pilha = pilha->prox;
        free(aux);
    }
    

    return 0;
}