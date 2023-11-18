#include <stdio.h>

int main(void){
    // Declaring variables
    char name[20];
    char gender;

    // Requesting the data
    printf("Enter your name: ");
    fgets(name, 20, stdin);
    printf("Enter your gender (M/F): ");
    scanf(" %c", &gender);

    // compares whether the sex is male or female
    if (gender == 'm' || gender == 'M'){
        printf("Welcome, Sir %s", name);
    }
    else if (gender == 'f' || gender == 'F'){
        printf("Welcome, Miss %s", name);
    }
    else {
        printf("Not computable!"); // Because programs only recognize binary
    }
    

    return 0;
}