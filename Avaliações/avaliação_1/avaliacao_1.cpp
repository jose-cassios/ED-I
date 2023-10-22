#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "avaliacao_util.h"

int main(void){
    livro *lista = NULL; // Define a lista dos livros disponíveis.
    int opc = -1; // Variável que será usada para o usuário definir qual operação realizar.
    
    // Cria um menu de operações.
    while (opc != 0){
      // Exibe o menu de operações
      printf("\n");
      printf("\
[ 1 ] - Registrar novo livro\n\
[ 2 ] - Retirar um livro\n\
[ 3 ] - Buscar por ISBN\n\
[ 4 ] - Buscar por Autor\n\
[ 5 ] - Listar Livros A - Z\n\
[ 6 ] - Listar Livros Z - A\n\
[ 0 ] - Sair\n");
      printf("Digite a operação: ");

      // Lê a operação a ser realizada.
      scanf("%d", &opc);
      getchar();
      printf("\n");

      // Verifica qual operação será realizada.
      switch (opc){
      case 1: // Lê e registra os dados do livro na lista.
        insere_livro(&lista);
        break;
      
      case 2: // Remove livros da lista.
        excluir_livro(&lista);
        break;
      
      case 3: // Faz uma busca por ISBN.
        buscar_isbn(&lista);
        break;

      case 4: // Faz uma busca por Autor.
        buscar_autor(&lista);
        break;

      case 5: // Exibindo os livros de A - Z.
        mostrar_livro(&lista, opc);
        break;

      case 6: // Exibindo os livros de Z - A.
        mostrar_livro(&lista, opc);
        break;

      case 0: // Sai do programa.
        printf("Saindo ...\n");
        break;

      default: // Tratamento de erro.
        printf("Opção Inválida!\n");
        break;
      } // switch
    } // while

    // Liberando a memoria.
    liberar_memoria(&lista);

    return 0;
} // main()
