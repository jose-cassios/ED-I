#include <iostream>
#include <iomanip>

using namespace std;

int main(void){
    // Declaring variables
    int num = 7, *nump;
    float dec = 1.57, *decp;
    char notnum = '1', *notnump;
    
    // Printing variables before modification
    cout << "num = " << num << ", dec = " << fixed << setprecision(2) << dec << ", notnum = " << notnum << endl;

    // Associating variables with pointers
    nump = &num;
    decp = &dec;
    notnump = &notnum;

    // Modifying the values
    *nump = num*2;
    *decp = dec*2;
    *notnump = '0';

    // Printing variables after modification
    cout << "num = " << num << ", dec = " << fixed << setprecision(2) << dec << ", notnum = " << notnum << endl;
    
    return 0;
}
