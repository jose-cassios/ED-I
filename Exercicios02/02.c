#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define Num 10 // Number of patients

// Defining the structures
typedef struct {
    int day, month, year;

} Date;

typedef struct {
    int cpf[12];
    char name[50];
    Date birth;
    int age;

} Patient;

// Function that receives the date of birth and returns the age.
int CalculatesAge(Date today, Date birth){
    int age = today.year - birth.year;

    if (today.month < birth.month || today.month == birth.month && today.day < birth.day){
        age--;
    }

    return age;
}

int main(void){
    printf("\nEnter Patient Data:\n");

    Patient *patient = (Patient *) malloc(Num * sizeof(Patient)); // Allocating the structure that stores patients

    // Handling allocation error
    if(patient == NULL){
        printf("Error!");
        exit(1);
    }

    // Sets today's date.
    time_t mytime;
    mytime = time(NULL);
    struct tm tm = *localtime(&mytime);
    Date today = {tm.tm_mday, tm.tm_mon+1, tm.tm_year+1900};
    
    // Reading patient data
    for(int i = 0; i < Num; i++){
        printf("\nPatient %d:\n", i+1);
        // Reading the CPF as a vector of integers
        printf("CPF: ");
        for (int j = 0; j < 11; j++) {
            scanf("%1d", &patient[i].cpf[j]);
        }
        getchar();

        printf("Name: ");
        fgets(patient[i].name, sizeof(patient[i].name), stdin);
        patient[i].name[strcspn(patient[i].name, "\n")] = '\0'; // Changes the \n of the enter read at the end of the name to \0.

        printf("Date of birth [dd mm yyyy]: ");
        scanf("%d %d %d", &(patient[i].birth.day), &(patient[i].birth.month), &(patient[i].birth.year));
        getchar();
        patient[i].age = CalculatesAge(today, patient[i].birth); // Calculates age and stores it in the patient structure.
        printf("\n");

    }

    // Check the oldest age for each patient.
    int older_age = patient[0].age;
    for (int i=0; i<Num; i++){
        if (patient[i].age > older_age){
            older_age = patient[i].age;
        }
    }
    
    // Shows the oldest patient(s)
     printf("\nOlder patient(s): \n");
    for (int i=0; i<Num; i++){
        if (patient[i].age == older_age){
            printf(" [ %s ] ", patient[i].name);
        }    
    }

    //It shows all patients with their data and says whether they are older or younger.
    printf("\n\nPatients: \n");
    for (int i = 0; i < Num; i++){
        printf("\nPatient %d:\n", i+1);
        printf("CPF: ");
        for (int j = 0; j < 11; j++){
            printf("%d", patient[i].cpf[j]);
        }
        printf("\n");
        printf("Name: %s\n", patient[i].name);
        printf("Age: %d\n", CalculatesAge(today, patient[i].birth));
        
        patient[i].age >= 18 ? printf("Over Eighteen\n") : printf("Under Age\n");
        
    }

    free(patient); // Frees the allocated memory.

    return 0;
} 
