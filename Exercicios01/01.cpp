#include <iostream>

using namespace std;

int main(void){
    // Declaring variables
    string name;
    char gender;

    // Requesting the data
    cout << "Enter your name: ";
    cin >> name;
    cout << "Enter your gender (M/F): ";
    cin >> gender;

    // compares whether the sex is male or female
    if (gender == 'm' || gender == 'M'){
        cout << "Welcome, Sir " + name + "\n";
    }
    else if (gender == 'f' || gender == 'F'){
        cout << "Welcome, Miss " + name + "\n";
    }
    else {
        cout << "Not computable!\n"; // Because programs only recognize binary
    }
    

    return 0;
}