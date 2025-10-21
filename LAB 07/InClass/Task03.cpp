#include <iostream>
using namespace std;

class Products {
    string name;
    float price;
    string description;
    bool availability;

    public:
        Products(string n, float p, string d, bool a) : name(n), price(p), description(d), availability(a) {}

        float getPrice() const { return price; }

        void display() {
            cout << "Product Name: " << name << endl;
            cout << "Price: $" << price << endl;
            cout << "Description: " << description << endl;
            cout << "Availability: " << (availability ? "In Stock" : "Out of Stock") << endl;
        }
};

void quickSort(Products arr[], int left, int right){
    if (left >= right) return;

    float pivot = arr[right].getPrice();
    int i = left;

    for (int j = left; j < right; j++) {
        if (arr[j].getPrice() < pivot) {
            swap(arr[i], arr[j]);
            i++;
        }
    }
    swap(arr[i], arr[right]);

    quickSort(arr, left, i - 1);
    quickSort(arr, i + 1, right);
}

int main() {
    Products products[] = {
        Products("Product 1", 10.99, "This is product 1", true),
        Products("Product 2", 5.99, "This is product 2", true),
        Products("Product 3", 2.99, "This is product 3", true),
    };
    int n = sizeof(products) / sizeof(products[0]);

    cout << "Before sorting:\n";
    for (int i = 0; i < n; i++) {
        products[i].display();
        cout << endl;
    }

    quickSort(products, 0, n - 1);

    cout << "Products sorted by price:\n";
    for (int i = 0; i < n; i++) {
        cout << "Product " << i + 1 << " - $" << products[i].getPrice() << endl;
    }

    return 0;
}



