#include <iostream>
#include <iomanip>

using namespace std;

#define size 3

int main(void){
    // Declaring variables
    float grades[size], larger = 0, smaller = 0;

    // Reading the grades to be stored in the vector
    for (int i = 0; i < size; i++){
        printf("Enter the grade of the student %d: ", i+1);
        cin >> grades[i];
    }

    // Comparing whether each position in the vector is the larger or smaller grade
    for (int i = 0; i < size; i++){
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
    cout << "The highest grade was " << fixed << setprecision(1) << larger << " and the lowest was " << smaller << endl;

    return 0;
}