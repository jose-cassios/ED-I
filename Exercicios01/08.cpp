#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    // Declaring variables
    int n_students;
    float *grades, sum = 0;

    // Requesting the data
    cout << "Enter the number of students in the CC10 class: ";
    cin >> n_students;

    // Allocating memory dynamically
    grades = new float[n_students];

    // Treating the error case of the new operator returning NULL
    if (grades == nullptr){
        cout << "Allocation error";
        exit(1);
    }

    // Reading the vector
    for (int i = 0; i < n_students; i++){
        cout << "Enter student grade " << i+1 << ": ";
        cin >> grades[i];
        sum += grades[i];
    }

    // Print the average
    cout << "The class average was " << fixed << setprecision(2) << sum / n_students << endl;

    delete[] grades; // Frees allocated memory

    return 0;
}
