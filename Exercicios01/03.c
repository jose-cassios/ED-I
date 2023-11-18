#include <stdio.h>

int main(void){
    // Declaring variables
    float grades[10];
    float larger = 0, smaller = 0;

    // Reading the grades to be stored in the vector
    for (int i = 0; i < 10; i++){
        printf("Enter student grade %d: ", i+1);
        scanf("%f", &grades[i]);
    }

    // Comparing whether each position in the vector is the larger or smaller grade
    for (int i = 0; i < 10; i++){
        if (i == 0){
            larger = smaller = grades[i];
        }
        else {
            if (grades[i] > larger){
                larger = grades[i];
            }
            if (grades[i] < smaller){
                smaller = grades[i];
            }
        }    
    }

    // Print the result
    printf("The highest grade was %.1f and the lowest was %.1f!", larger, smaller);
    
    return 0;
}
