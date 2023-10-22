#include <stdio.h>
#include <stdlib.h>

// Definindo as structs
typedef struct {
    int hora, minutos, segundos, validado;

} Horario;
typedef struct {
    int dia, mes, ano, validado;

} Data;

Horario *horario;
Data *data;

// Função que libera a memória alocada
void libera(void){
    free(horario);
    free(data);
}

int main(void){
    // Alocando memoria
    horario = (Horario *) malloc(sizeof(Horario));
    data = (Data *) malloc(sizeof(Data));

    // Tratando erro de alocação
    if (horario == NULL || data == NULL){
        printf("Erro!");
        exit(1);
    }    
    
    // Lendo os dados
    printf("Digite a data: ");
    scanf("%d %d %d", &(data->dia), &(data->mes), &(data->ano));
    printf("Digite o horário: ");
    scanf("%d %d %d", &(horario->hora), &(horario->minutos), &(horario->segundos));

    // Validando o horário
    if(horario->hora >= 0 && horario->hora <= 23 &&
       horario->minutos >= 0 && horario->minutos <= 59 &&
       horario->segundos >= 0 && horario->segundos <= 59) {
           horario->validado = 1;
    }
    else {
        horario->validado = 0;
    }

    // Validando a data
    if(data->dia >= 1 && data->dia <= 31 &&
       data->mes >= 1 && data->mes <= 12 &&
       data->ano >= 0 && data->ano <= 9999) {
           data->validado = 1;
    }
    else {
        data->validado = 0;
    }

    // Imprime a validação
    horario->validado ? printf("Horário Validado!\n") : printf("Horário Inválido!\n");
    data->validado ? printf("Data Validada!\n") : printf("Data Inválida!\n");
    
    // Ao fim do programa chama a função que libera a memória alocada
    atexit(libera);

    return 0;
}
