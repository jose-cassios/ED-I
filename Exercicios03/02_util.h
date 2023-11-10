#include <stdio.h>

// Student structure, stores enrollment, name and grades.
typedef struct Student{
    char matricula[20], nome[20];
    float n1, n2, n3;
} student;

// a) Allows the user to enter the data of qtd students.
void read_aluno(student *alunos, int qtd){
    for (int i = 0; i < qtd; i++){
        printf("Enter the student's school enrollment: ");
        scanf("%s", alunos[i].matricula);

        printf("Enter the student's name: ");
        scanf("%s", alunos[i].nome);
        
        printf("Type the n1: ");
        scanf("%f", &alunos[i].n1);
        getchar();
        printf("Type the n2: ");
        scanf("%f", &alunos[i].n2);
        getchar();
        printf("Type the n3: ");
        scanf("%f", &alunos[i].n3);
        getchar();
        printf("\n");
    }
}

// b) Finds the student with the highest score on the first test.
void highest_n1(student *alunos, int qtd){
    int maior = 0;
    for (int i = 0; i < qtd; i++){
        if (alunos[i].n1 > maior){
            maior = alunos[i].n1;
        }
    }
    printf("The student(s) with the highest n1 grade was: ");
    for (int i = 0; i < qtd; i++){
        if (alunos[i].n1 == maior){
            printf("[ %s ] ", alunos[i].nome);
        }
    }
    printf("\n\n");
}

// c) Finds the student with the highest GPA.
void highest_average(student *alunos, int qtd){
    int media, maior = 0;

    for (int i = 0; i < qtd; i++){
        media = (alunos[i].n1 + alunos[i].n2 + alunos[i].n3) / 3;
        if (media > maior){
            maior = media;
        }
    }

    printf("The student(s) with the highest average was: ");
    for (int i = 0; i < qtd; i++){
        media = (alunos[i].n1 + alunos[i].n2 + alunos[i].n3) / 3;
        if (media == maior){
            printf("[ %s ] ", alunos[i].nome);
        }
    }
    printf("\n\n");
}

// d) Informs whether the student passed or failed.
void pass_rate(student *alunos, int qtd){
    for (int i = 0; i < qtd; i++){
        int media = (alunos[i].n1 + alunos[i].n2 + alunos[i].n3) / 3;
        if (media >= 7){
            printf("[ %s ] - Passed\n", alunos[i].nome);
        }
        else{
            printf("[ %s ] - Failed\n", alunos[i].nome);
        }
    }
    printf("\n\n");
}   