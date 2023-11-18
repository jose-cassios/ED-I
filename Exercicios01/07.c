#include <stdio.h>
#include <stdlib.h>

// Function that receives the vector and the number of elements
int readWriter(int *v, int n){
    // Reads the vector
    for (int i=0; i < n; i++){
        printf("Enter element %d: ", i+1);
        scanf("%d", &v[i]);
    }

    // Display the vector on the screen
    for (int i = 0; i < n; i++){
        printf("%d ", v[i]);
    }
    printf("\n");

    return 0;
}

int main(void){
    // Declaring variables
    int n, *v;

    // Requesting the data
    printf("Enter the number of elements in the vector: ");
    scanf("%d", &n);

    v = (int *) malloc(n * sizeof(int)); // v stores the first memory location allocated
    
    // Treating the error case of the malloc function returning NULL
    if (v == NULL){
        printf("Allocation error");
        exit(1);
    }
    
    // Calling the function
    readWriter(v, n);

    // Frees allocated memory
    free(v);

    return 0;
}
