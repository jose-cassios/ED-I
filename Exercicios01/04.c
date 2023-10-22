#include <stdio.h>

int main(void){
    // Declarando variáveis
    int num = 7, *nump;
    float dec = 1.57, *decp;
    char notnum = '1', *notnump;
    
    // Imprimindo as variáveis antes da modificação
    printf("num = %d, dec = %.2f, notnum = %c\n", num, dec, notnum);

    // Associando as variáveis aos ponteiros
    nump = &num;
    decp = &dec;
    notnump = &notnum;

    //  Modificando os valores
    *nump = num*2;
    *decp = dec*2;
    *notnump = '0';

    // Imprimindo as variáveis após a modificação    
    printf("num = %d, dec = %.2f, notnum = %c\n", num, dec, notnum);
    
    return 0;
}
