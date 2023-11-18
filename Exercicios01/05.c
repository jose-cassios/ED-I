#include <stdio.h>

// takes the double values of *p and *b, then returns the sum of the new values.
int sumDoubled(int *p, int *b){
    *p = (*p) * 2;
    *b = (*b) * 2;

    return *p + *b;
}

int main(void){
    // Declaring variables
    int A, B;

    // Requesting values
    printf("Enter the value of 2 integers: ");
    scanf("%d %d", &A, &B);

    // Calling the function inside printf that will display the sum of double
    printf("The sum of %d and %d is %d\n", A, B, sumDoubled(&A, &B));

    return 0;
}
