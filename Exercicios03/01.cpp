#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Car struct
struct Car {
    string brand;
    int year;
    float price;
};

int main() {
    // Declaring variables
    float value;
    vector<Car> cars(5);

    // Getting car details from the user
    for (int i = 0; i < 5; i++) {
        cout << "\nEnter the car brand: ";
        getline(cin, cars[i].brand);

        cout << "Enter the year of the car: ";
        cin >> cars[i].year;
        cin.ignore();

        cout << "Enter the price of the car: ";
        cin >> cars[i].price;
        cin.ignore();
    }

    // Getting a search value for price
    cout << "\nEnter a search value: ";
    cin >> value;
    cout << "\nAvailable cars by price range: \n";
    for (const auto &car : cars) {
        if (value > car.price) {
            cout << " [ " << car.brand << " - " << car.year << " ] ";
        }
    }

    return 0;
}
