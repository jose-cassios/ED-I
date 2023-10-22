#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "02_util.h"

// Number of students to be register
#define qtd 5

int main(void){
    student *alunos = (student *) malloc(qtd * sizeof(student));

    if (alunos == NULL){
        printf("Allocation Error!");
        exit(1);
    }

    // Reads students data.
    read_aluno(alunos, qtd);
    
    // Shows, on the screen, the name of the students with the highest n1
    highest_n1(alunos, qtd);

    // Shows, on the screen, the student with the highest overall average.
    highest_average(alunos, qtd);

    // Shows, on screen, students and their situations
    pass_rate(alunos, qtd);
    free(alunos);

    return 0;
}
