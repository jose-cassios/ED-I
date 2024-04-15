#include <stdio.h>
#include <stdlib.h>

/* Desenvolva um método que receba como parâmetro uma pilha cujos elementos são números
inteiros e retorne como resultado uma nova pilha cujos os elementos estão empilhados na
posição inversa à pilha original. */

typedef struct Stack
{
    int value;
    struct Stack *prox;

} stack;

stack *metodo(stack *pilha){
    stack *nova_pilha = NULL;
    stack *aux = pilha;

    if (pilha==NULL){
        printf("\nA pilha está vazia!\n");
        return NULL;
    }
 
    while (aux != NULL){
        stack *nova_celula = (stack *) malloc(sizeof(stack));

        nova_celula->value = aux->value;
        nova_celula->prox = nova_pilha;
        nova_pilha = nova_celula;

        aux=aux->prox;
    }

    return nova_pilha;
}

void push(stack **pilha){
    stack *celula = (stack *) malloc(sizeof(stack));

    printf("Digite um valor: ");
    scanf("%d", &celula->value);
    getchar();

    celula->prox = *pilha;
    *pilha = celula;

}

void free_stack(stack **pilha){
    stack *aux = *pilha;

    while (aux != NULL){
        stack *temp = aux;
        aux=aux->prox;
        free(temp);
    }
    
}

void mostrar(stack *pilha){
    stack *aux = pilha;

    while (aux!=NULL){
        printf("[ %d ] ", aux->value);
        aux=aux->prox;
    }
    printf("\n");
    
}

int main(void){
    stack *pilha = NULL;
    stack *pilha_invertida = NULL;
    int opc = -1;

    while (opc != 0){
        printf("\nDigite a operação: \n\
[ 1 ] - Inserir na pilha\n\
[ 2 ] - Mostrar:\n\
[ 0 ] - Sair\n");
        printf("Operação: ");
        scanf("%d", &opc);
        getchar();

        switch (opc){
        case 1:
            push(&pilha);
            break;

        case 2:
            int num;
            printf("\n1 - Pilha Normal\n2 - Pilha Invertida: ");
            scanf("%d", &num);
            getchar();

            if (num == 1){
                mostrar(pilha);
            }
            else if (num == 2){
                pilha_invertida = metodo(pilha);
                mostrar(pilha_invertida);
            }
            else{
                printf("\nOpção Inválida\n");
            }
            
            break;

        case 0:
            free_stack(&pilha);
            free_stack(&pilha_invertida);
            break;

        default:
            printf("\nOpção inválida!\n");
            break;
        }
    }
    return 0;
}