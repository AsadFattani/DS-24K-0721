#include <iostream>
using namespace std;

class Shop {
private:
    string productName;
    int* quantities;
    int numBranches;
public:
    Shop(const string& name, int branches)
        : productName(name), numBranches(branches) {
        quantities = new int[numBranches];
        for (int i = 0; i < numBranches; ++i)
            quantities[i] = 0;
    }

    ~Shop() {
        delete[] quantities;
    }

    Shop(const Shop& other)
        : productName(other.productName), numBranches(other.numBranches) {
        quantities = new int[numBranches];
        for (int i = 0; i < numBranches; ++i)
            quantities[i] = other.quantities[i];
    }

    Shop& operator=(const Shop& other) {
        if (this != &other) {
            delete[] quantities;
            productName = other.productName;
            numBranches = other.numBranches;
            quantities = new int[numBranches];
            for (int i = 0; i < numBranches; ++i)
                quantities[i] = other.quantities[i];
        }
        return *this;
    }

    void setQuantity(int branch, int quantity) {
        if (branch >= 0 && branch < numBranches)
            quantities[branch] = quantity;
    }

    void display() const {
        cout << "Product: " << productName << endl;
        cout << "Quantities: ";
        for (int i = 0; i < numBranches; ++i)
            cout << quantities[i] << " ";
        cout << endl;
    }
};

int main() {
    Shop s1("Laptop", 3);
    s1.setQuantity(0, 10);
    s1.setQuantity(1, 20);
    s1.setQuantity(2, 15);
    cout << "Original Shop:" << endl;
    s1.display();

    Shop s2 = s1; 
    s2.setQuantity(1, 99);
    cout << "\nCopied Shop (after modification):" << endl;
    s2.display();

    Shop s3("Phone", 2);
    s3 = s1;
    s3.setQuantity(0, 77);
    cout << "\nAssigned Shop (after modification):" << endl;
    s3.display();

    return 0;
}
