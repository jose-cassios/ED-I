#include <iostream>

using namespace std;

// takes the double values of *p and *b, then returns the sum of the new values.
int sumDoubled(int *p, int *b){
    *p = (*p) * 2;
    *b = (*b) * 2;

    return *p + *b;
}

int main(void) {
    // Declaring variables
    int A, B;

    cout << "Enter the value of 2 integers: ";
    cin >> A >> B;

    // Calling the function inside printf that will display the sum of double
    cout << "The sum of " << A << " and " << B << " is " << sumDoubled(&A, &B) << endl;

    return 0;
}

