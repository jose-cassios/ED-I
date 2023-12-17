#include <iostream>

using namespace std;

int main(void) {
    // Declaring variables
    int v[4] = {0, 1, 2, 3};
    int *pointer;

    pointer = v; // Passing the vector head address

    for (int i = 0; i < 4; i++){
        *pointer += 1; // Add 1 to the value of v[i]
        pointer++; // Sum 1 at vector address
    }

    // Print the vector with the sum
    for (int i = 0; i < 4; i++) {
        cout << v[i] << " ";
    }
    cout << endl;

    return 0;
}
