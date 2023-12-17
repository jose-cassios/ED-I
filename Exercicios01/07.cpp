#include <iostream>
using namespace std;

// Function that receives the vector and the number of elements
int readWriter(int *v, int n){
    // Reads the vector
    for (int i = 0; i < n; i++){
        cout << "Enter element " << i+1 << ": ";
        cin >> v[i];
    }

    // Display the vector on the screen
    for (int i = 0; i < n; i++){
        cout << v[i] << " ";
    }
    cout << endl;

    return 0;
}

int main(){
    // Declaring variables
    int n, *v;

    // Requesting the data
    cout << "Enter the number of elements in the vector: ";
    cin >> n;

    v = new int[n]; // v stores the first memory location allocated

    // Treating the error case of the new operator returning NULL
    if (v == nullptr){
        cout << "Allocation error";
        exit(1);
    }

    // Calling the function
    readWriter(v, n);

    // Frees allocated memory
    delete[] v;

    return 0;
}
