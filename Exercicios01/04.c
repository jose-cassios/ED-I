#include <stdio.h>

int main(void){
    // Declaring variables
    int num = 7, *nump;
    float dec = 1.57, *decp;
    char notnum = '1', *notnump;
    
    // Printing variables before modification
    printf("num = %d, dec = %.2f, notnum = %c\n", num, dec, notnum);

    // Associating variables with pointers
    nump = &num;
    decp = &dec;
    notnump = &notnum;

    // Modifying the values
    *nump = num*2;
    *decp = dec*2;
    *notnump = '0';

    // Printing variables after modification
    printf("num = %d, dec = %.2f, notnum = %c\n", num, dec, notnum);
    
    return 0;
}
