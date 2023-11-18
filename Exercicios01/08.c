#include <stdio.h>
#include <stdlib.h>

int main(void){
    // Declaring variables
    int n_students;
    float *grades, sum = 0;

    // Requesting the data
    printf("Enter the number of students in the CC10 class: ");
    scanf("%d", &n_students);

    // Allocating memory dynamically
    grades = (float *) malloc(n_students * sizeof(float));

    // Treating the error case of the malloc function returning NULL
    if (grades == NULL){
        printf("Allocation error");
        exit(1);
    }

    // Reading the vector
    for (int i = 0; i < n_students; i++){
        printf("Enter student grade %d: ", i+1);
        scanf("%f", &grades[i]);
        sum += grades[i];
    }

    // Print the average
    printf("The class average was %.2f\n", sum / n_students);

    free(grades); // Frees allocated memory

    return 0;
}