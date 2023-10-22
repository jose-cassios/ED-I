#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define tam 2 // Quantidade de pacientes

// Definindo as estruturas
typedef struct {
    int dia, mes, ano;

} Data;

typedef struct {
    int cpf[12];
    char nome[50];
    Data nascimento;
    int idade;

} Paciente;

// Função que recebe a data de nascimento e retorna a idade.
int CalculaIdade(Data hoje, Data nascimento){
    int idade = hoje.ano - nascimento.ano;

    if (hoje.mes < nascimento.mes || hoje.mes == nascimento.mes && hoje.dia < nascimento.dia){
        idade--;
    }

    return idade;
}

int main(void){
    printf("\nDigite os Dados dos Pacientes:\n");

    Paciente *paciente = (Paciente *) malloc(tam * sizeof(Paciente)); // Alocando a estrutura que armazena os pacientes

    // Tratando erro de alocação
    if(paciente == NULL){
        printf("Erro!");
        exit(1);
    }

    // Define a data de hoje.
    time_t mytime;
    mytime = time(NULL);
    struct tm tm = *localtime(&mytime);
    Data hoje = {tm.tm_mday, tm.tm_mon+1, tm.tm_year+1900};
    
    // Lendo os dados dos pacientes
    for(int i = 0; i < tam; i++){
        printf("\nPaciente %d:\n", i+1);
        // Lendo o CPF como um vetor de inteiros
        printf("CPF: ");
        for (int j = 0; j < 11; j++) {
            scanf("%1d", &paciente[i].cpf[j]);
        }
        getchar();

        printf("Nome: ");
        fgets(paciente[i].nome, sizeof(paciente[i].nome), stdin);
        paciente[i].nome[strcspn(paciente[i].nome, "\n")] = '\0'; // Troca o \n do enter lido no final do nome por \0.

        printf("Data de nascimento [dd mm aaaa]: ");
        scanf("%d %d %d", &(paciente[i].nascimento.dia), &(paciente[i].nascimento.mes), &(paciente[i].nascimento.ano));
        getchar();
        paciente[i].idade = CalculaIdade(hoje, paciente[i].nascimento); // Calcula a idade e armazena na estrutura paciente.
        printf("\n");

    }

    // Verifica para cada paciente qual a maior idade.
    int maior_idade = paciente[0].idade;
    for (int i=0; i<tam; i++){
        if (paciente[i].idade > maior_idade){
            maior_idade = paciente[i].idade;
        }
    }
    
    // Mostra o(s) paciente(s) mais velho(s)
     printf("\nPaciente(s) mais velho(s): \n");
    for (int i=0; i<tam; i++){
        if (paciente[i].idade == maior_idade){
            printf(" [ %s ] ", paciente[i].nome);
        }    
    }

    // Mostra todos os pacientes com seus dados e diz se são maior ou menor de idade.
    printf("\n\nPacientes: \n");
    for (int i = 0; i < tam; i++){
        printf("\nPaciente %d:\n", i+1);
        printf("CPF: ");
        for (int j = 0; j < 11; j++){
            printf("%d", paciente[i].cpf[j]);
        }
        printf("\n");
        printf("Nome: %s\n", paciente[i].nome);
        printf("Idade: %d\n", CalculaIdade(hoje, paciente[i].nascimento));
        
        paciente[i].idade >= 18 ? printf("Maior de idade\n") : printf("Menor de idade\n");
        
    }

    free(paciente); // Libera a memoria alocada.

    return 0;
} 
