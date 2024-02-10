#include <iostream>

using namespace std;

struct Product
{
    int code;
    char name[15];
    float price;
    int qty;

};

void read(Product* vector, int numProducts){
    for (int i = 0; i<numProducts; i++){
        cout << "\nProducut code: ";
        cin >> vector[i].code;

        cout << "Product's name: ";
        cin.ignore();
        cin.getline(vector[i].name, sizeof(vector[i].name)); 

        cout << "Price of the product: ";
        cin >> vector[i].price;

        cout << "Units: ";
        cin >> vector[i].qty;
    }

}

void pedido(Product *vector, int numProducts){
    char opt;
    int code;
    int qty;

    cout << "Product code to be purchased: ";
    cin >> code;
    cout << "Quantity to be purchased: ";
    cin >> qty;

    for (int i=0; i < numProducts; i++){
        if (code == vector[i].code && qty <= vector[i].qty){
            cout << "\nThe Code provided is equivalent to the product " << vector[i].name << "\n";
            cout << "Order price: " << qty * vector[i].price << "\n\n";
            cout << "Confirm purchase [Y/N]: ";
            cin >> opt;

            if (opt == 'Y'){
                cout << "Buying " << qty << " units of the " << vector[i].name << "\n";
                vector[i].qty -= qty;
                return;

            }
            else {
                return;
            }
        }
    }
    cout << "\nProduct out of stock\n";
}

void calcula(Product *vector, int numProducts){
    float total = 0;
    cout << "____________Stock____________\n";
    for (int i = 0; i<numProducts; i++){
        total += vector[i].price * vector[i].qty;
        cout << "\nProduct code: ";
        cout << vector[i].code << "\n";
        cout << "Product's name: ";
        cout << vector[i].name << "\n";
        cout << "Price of the product: ";
        cout << vector[i].price << "\n";
        cout << "Units: ";
        cout << vector[i].qty << "\n";
    }
    cout << "\nThe total in reais of available products is R$" << total << "\n\n";
}

int main(){
    int numProducts;
    cout << "Enter the quantity of products: ";
    cin >> numProducts;

    Product* vector = new Product[numProducts];

    read(vector, numProducts);

    pedido(vector, numProducts);

    calcula(vector, numProducts);

    delete[] vector;

    return 0;
}