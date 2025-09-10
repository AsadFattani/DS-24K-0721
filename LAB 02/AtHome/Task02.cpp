#include <iostream>
using namespace std;

class ProductStockManager {
    private:
        int* stock;
        int size;
    public:
        ProductStockManager(int numProducts, int initialStock) : size(numProducts) {
            stock = new int[size];
            for (int i = 0; i < size; ++i)
                stock[i] = initialStock;
        }

        ProductStockManager(const ProductStockManager& other) : size(other.size) {
            stock = new int[size];
            for (int i = 0; i < size; ++i)
                stock[i] = other.stock[i];
        }

        ProductStockManager& operator=(const ProductStockManager& other) {
            if (this != &other) {
                delete[] stock;
                size = other.size;
                stock = new int[size];
                for (int i = 0; i < size; ++i)
                    stock[i] = other.stock[i];
            }
            return *this;
        }

        ~ProductStockManager() {
            delete[] stock;
        }

        void setStock(int index, int quantity) { // assuming index is valid
            stock[index] = quantity;
        }

        void printStock() const {
            for (int i = 0; i < size; ++i)
                cout << "Product " << i + 1 << " stock: " << stock[i] << endl;
        }
};

int main() {
    ProductStockManager manager(3, 50);

    cout << "Original manager stock:" << endl;
    manager.printStock();

    ProductStockManager copiedManager = manager;

    copiedManager.setStock(1, 100);

    cout << "\nAfter modifying copied manager:" << endl;
    cout << "Original manager stock:" << endl;
    manager.printStock();

    cout << "Copied manager stock:" << endl;
    copiedManager.printStock();

    return 0;
}



