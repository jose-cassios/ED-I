#include <stdio.h>
#include <stdlib.h>

// Defining the structures
typedef struct {
    int hour, minutes, seconds, validated;

} Time;

typedef struct {
    int day, month, year, validated;

} Date;

Time *time;
Date *date;
 
// Function that frees allocated memory
void freeMemory(void){
    free(time);
    free(date);
}

int main(void){
    // Allocating memory
    time = (Time *) malloc(sizeof(Time));
    date = (Date *) malloc(sizeof(Date));

    // Handling allocation error
    if (time == NULL || date == NULL){
        printf("Error!");
        exit(1);
    }    
    
    // Reading the data
    printf("Enter the date: ");
    scanf("%d %d %d", &(date->day), &(date->month), &(date->year));
    printf("Enter the time: ");
    scanf("%d %d %d", &(time->hour), &(time->minutes), &(time->seconds));

    // Validating the time
    if(time->hour >= 0 && time->hour <= 23 &&
       time->minutes >= 0 && time->minutes <= 59 &&
       time->seconds >= 0 && time->seconds <= 59) {
           time->validated = 1;
    }
    else {
        time->validated = 0;
    }

    // Validating the date
    if(date->day >= 1 && date->day <= 31 &&
       date->month >= 1 && date->month <= 12 &&
       date->year >= 0 && date->year <= 9999) {
           date->validated = 1;
    }
    else {
        date->validated = 0;
    }

    // Print validation
    time->validated ? printf("Validated Time!\n") : printf("Invalid Time!\n");
    date->validated ? printf("Validated Date!\n") : printf("Invalid Date!\n");
    
    // At the end of the program, call the function that frees the allocated memory
    atexit(freeMemory);

    return 0;
}
