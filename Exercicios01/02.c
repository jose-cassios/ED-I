#include <stdio.h>

int main(void){
    // Declaring variables
    int n;
    
    // Reading the number
    printf("Enter a number from 1 to 9: ");
    scanf("%d", &n);

    // Display multiplications
    for (int i = 0; i <= 10; i++){
        printf("%d x %d = %d\n", n, i, n*i);
    }

    return 0;
}
