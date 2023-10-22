#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Funções:
1. insere_livro     - Recebe os dados do livro
2. registra_livro   - Armazena os dados do livro na lista em ordem alfabética.
3. excluir_livro    - Remove um ou mais livros da lista.
4. buscar_isbn      - Realiza uma busca completa por ISBN
5. buscar_autor     - Exibe os títulos das obras escritas por um autor
4. mostrar_livro    - Recebe uma lista e exibe seus elementos de A-Z ou de Z-A.
5. liberar_memoria  - Recebe uma lista e libera seus elementos.

*/

// Struct que define os dados de cada livro.
typedef struct Livro {
    char titulo[20];
    char isbn[14];
    char nome_autor[20];
    int ano;
    int exemplares;

    // Define os ponteiros para o anterior e para o próximo livro.
    struct Livro *ant;
    struct Livro *prox;

} livro;

// Função da parte A
// Recebe os dados do livro e armazena na lista em ordem alfabética.
void registra_livro(char titulo[20], char nome_autor[20], char isbn[14], int ano, int exemplares, livro **lista){
    // Alocando dinamicamente um livro que será adicionado na lista posteriormente.
    livro *novo_livro = (livro *) malloc(sizeof(livro));

    if (novo_livro == NULL){
        printf("Erro de alocação!");
        return;
    }

    strcpy(novo_livro->titulo, titulo); // Nome do livro
    strcpy(novo_livro->nome_autor, nome_autor); // Nome do autor do livro
    strcpy(novo_livro->isbn, isbn); // ISBN do livro
    novo_livro->ano = ano; // Ano de lançamento
    novo_livro->exemplares = exemplares; // Número de exemplares do livro
    
    // Inicializando os ponteiros para que não haja problemas
    novo_livro->ant = NULL;
    novo_livro->prox = NULL;
    
    //Verifica se a lista está vazia.
    //Se estiver, não há necessidade de organiza-la em ordem alfabética.
    if (*lista == NULL){
        *lista = novo_livro; // Define o novo livro como o primeiro.
    }
    // Caso não esteja vazia.
    else{
        // Define atual como a cabeça da lista.
        livro *atual = *lista;
        livro *anterior = NULL;

        // Percorre a lista.
        while (atual != NULL){

            // r armazena inteiro negativo caso o novo livro deva ficar antes do atual.
            int r = strcmp(novo_livro->titulo, atual->titulo);

            if (r < 0){
                // Define os ponteiros do novo livro
                novo_livro->ant = anterior;
                novo_livro->prox = atual;

                // Verifica se o anterior ao atual é nulo.
                if (anterior == NULL){
                    *lista = novo_livro; // Atribui o novo livro à cabeça da lista, uma vez que o atual é o 1° elemento.
                }
                else{
                    anterior->prox = novo_livro; // Define o proximo do anterior como o novo livro.
                }

                // Define o anterior do atual como o novo livro.
                atual->ant = novo_livro; 
                return; // Sai da função. 
            }

            // Atualiza o atual e o anterior.
            anterior = atual;
            atual = atual->prox;
        }

        /*
        O código apenas chegará aqui se a comparação do nome do novo livro com todos da lista
        resultar sempre em r > 0. Ou seja, o novo livro deve ser inserido no final da lista
        pois é o ultimo em ordem alfabética.
        */

        // Uma vez que o atual agora é nulo, o ultimo da lista é o anterior ao atual.
        anterior->prox = novo_livro; // O sucessor do ultimo é o novo livro
        novo_livro->ant = anterior; // O anterior ao novo livro é o ultimo da lista.
        return;       
    }
} // registra_livro()

// Recebe os dados do livro
void insere_livro(livro **lista){
  int ano, exemplares;
  char titulo[20], isbn[14], nome_autor[20];

  // Lê o nome do livro
  printf("Nome do livro: ");
  fgets(titulo, 20, stdin);
  titulo[strcspn(titulo, "\n")] = '\0';

  livro *aux = *lista;

  // Verifica se o livro já existe na lista
  //em caso afirmativo, apenas soma os novos exemplares aos existentes.
    while (aux != NULL){
        if((strcmp(titulo, aux->titulo) == 0)){
            // Lê o número de exemplares do livro
            printf("Número de exemplares: ");
            scanf("%d", &exemplares);
            getchar();
            
            aux->exemplares += exemplares; // Incrementa os livros

            printf("\nNúmero de exemplares atualizado!\n");
            return;
        }

        aux = aux->prox;
    } //while

    // Lê o código IBSM do livro
    printf("Código IBSM do livro: ");
    fgets(isbn, 14, stdin);
    isbn[strcspn(isbn, "\n")] = '\0'; // Troca o \n do enter lido no final do nome por \0.

    aux = *lista;
    while (aux != NULL){
        // Caso o IBSN ja exista na lista e os livros não sejam os mesmos.
        if((strcmp(isbn, aux->isbn) == 0)){
            printf("\nLivros diferentes não podem possuir o mesmo IBSN!\n");
            return;
        }

        aux = aux->prox;
    } // while

  // Lê o nome do autor do livro
  printf("Nome do autor: ");
  fgets(nome_autor, 20, stdin);
  nome_autor[strcspn(nome_autor, "\n")] = '\0';

  // Lê o ano de laçamento do livro
  printf("Ano de publicação: ");
  scanf("%d", &ano);
  getchar();

  // Lê o número de exemplares do livro
  printf("Número de exemplares: ");
  scanf("%d", &exemplares);
  getchar();

  // Função que fará o registro do livro em ordem alfabética.
  registra_livro(titulo, nome_autor, isbn, ano, exemplares, &(*lista));

}//insere_livro()

// Remove um ou mais livros da lista.
void excluir_livro(livro **lista){
  char isbn[14];
  int exemplares;

  // Lê o código do livro para busca-lo na lista 
  printf("ISBN do livro: ");
  fgets(isbn, 14, stdin);
  isbn[strcspn(isbn, "\n")] = '\0'; // Troca o \n do enter lido no final do nome por \0.

  // Percorre a lista
  livro *aux = *lista;
  livro *anterior = NULL;

  while (aux != NULL){
    // Verifica se o ISBN pentence a algum livro da lista
    if (strcmp(aux->isbn, isbn) == 0){

    // Lê a quantidade de livros que serão excluidos
    printf("Informe a quantidade de exemplares a serem removidos: ");
    scanf("%d", &exemplares);
    getchar();

      //Verifica se a quantidade de exemplares a ser removida é maior que a existente na lista
      if(aux->exemplares > exemplares){ 
        aux->exemplares -= exemplares;

        printf("\nNúmero de exemplares do livro [ %s ] atualizado!\n", aux->titulo);
        return;
      }

      if(anterior == NULL){ // Se o livro for o primeiro
        *lista = aux->prox;
      }
      else if(aux->prox == NULL){ // Se o livro for o último
        anterior->prox = NULL;
      }
      else{ // Se o livro estiver no meio da lista
        anterior->prox = aux->prox;
        aux->prox->ant = anterior;
      }
      
      printf("\nRemovendo o livro: ");
      printf("\n[ %s ]\n", aux->titulo);
      free(aux);
      return;

    } // if(strcmp(aux->isbn, isbn) == 0)

    anterior = aux;
    aux = aux->prox;

  }//while
  printf("\nO ISBN informado não pertence a lista!\n");
}//excluir_livro()

// Realiza uma busca completa por ISBN
void buscar_isbn(livro **lista){
  livro *aux = *lista;
  char isbn[14];

  // Lê o ISBN
  printf("Informe o ISBN da obra: ");
  fgets(isbn, 14, stdin);
  isbn[strcspn(isbn, "\n")] = '\0'; // Troca o \n do enter lido no final do nome por \0.

  // Percorre a lista
  while (aux != NULL){
    // Se o ISBN estive na lista exibe as informações
    if (strcmp(isbn, aux->isbn) == 0){
      printf("\n---------------------------------------\n");
      printf("\
Título       - %s\n\
Autor        - %s\n\
Lançamento   - %d\n\
Exemplares   - %d\n", aux->titulo, aux->nome_autor, aux->ano, aux->exemplares);
      printf("---------------------------------------\n");
      return;
    }

    aux = aux->prox;
  }

  // Se o ISBN não estiver na lista.
  printf("\nO ISBN informado não pertence a nenhuma obra resgistrada!\n");
  
} // buscar_isbn

// Exibe os títulos das obras escritas por um autor
void buscar_autor(livro **lista){
  livro *aux = *lista;
  char nome_autor[20];
  int obra_encontrada = 0;

  // Lê o nome do autor.
  printf("Nome do autor: ");
  fgets(nome_autor, 20, stdin);
  nome_autor[strcspn(nome_autor, "\n")] = '\0';

  printf("\nObras escritas por %s:\n", nome_autor);

  while (aux != NULL){
    if (strcmp(nome_autor, aux->nome_autor) == 0){
      obra_encontrada = 1;
      printf("\n----------------------------\n");
      printf("%s\n", aux->titulo);
      printf("------------------------------\n");

    }
    if (!obra_encontrada){
        printf("\nNão há obras do autor registradas\n");
    }
    aux = aux->prox;
  } // while
} // buscar_autor

// Recebe uma lista e exibe seus elementos de A-Z ou de Z-A.
void mostrar_livro(livro **lista, int opc){
    livro *aux = *lista;
    livro *anterior = NULL;
    int A_Z = 5, Z_A = 6;

    // Verifica se a lista está vazia
    if(aux == NULL){
        printf("Não há livros registrados!");
    }

    // Percorre a lista toda, independente da opc escolhida.
    while (aux != NULL){
        if (opc == A_Z){ // Caso a opção escolhida tenha sido de A-Z, imprime os livros na ida. 
            printf("\n---------------------------------------\n");
            printf("\
Título       - %s\n\
Autor        - %s\n\
Lançamento   - %d\n\
Exemplares   - %d\n\
ISBN         - %s\n", aux->titulo, aux->nome_autor, aux->ano, aux->exemplares, aux->isbn);
            printf("---------------------------------------\n");
        }
        anterior = aux;
        aux = aux->prox;
    
    // Ao fim desse while, aux será nulo e anterior será o último livro.

    }// while

    // Caso a opção tenha sido de Z-A, o anterior retornará imprimindo cada livro na volta.
    while ((anterior != NULL) && (opc == Z_A)){
        printf("\n---------------------------------------\n");
        printf("\
Título       - %s\n\
Autor        - %s\n\
Lançamento   - %d\n\
Exemplares   - %d\n\
ISBN         - %s\n", anterior->titulo, anterior->nome_autor, anterior->ano, anterior->exemplares, anterior->isbn);
        printf("---------------------------------------\n");

        anterior = anterior->ant; // Retornando o anterior.
    } // while
    
    printf("\n");
}//mostrar_livro()

// Recebe uma lista e libera seus elementos.
void liberar_memoria(livro **lista){
  livro *aux = *lista;
    while (aux != NULL){
      livro *temp = aux;
      aux = aux->prox;
      free(temp);
    }
    *lista == NULL;
}//liberar_memoria
