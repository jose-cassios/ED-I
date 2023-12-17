#include <iostream>

using namespace std;

int main(void){
    // Declaring variables
    int n;

    // Reading the number
    cout << "Enter a number from 1 to 9: ";
    cin >> n;

    // Display multiplications
    for (int i = 1; i < 10; i++){
        cout << n << " x " << i << " = " << n * i << endl;
    }

    return 0;
}