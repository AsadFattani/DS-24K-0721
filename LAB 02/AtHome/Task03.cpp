#include <iostream>
using namespace std;

class fruitShopInventory {
    private:
        int* quantity;
        int* price;
        int size;
    public:
        fruitShopInventory(int numFruits, int initialQuantity, int initialPrice) : size(numFruits) {
            quantity = new int[size];
            price = new int[size];
            for (int i = 0; i < size; ++i) {
                quantity[i] = initialQuantity;
                price[i] = initialPrice;
            }
        }

        fruitShopInventory(const fruitShopInventory& other) : size(other.size) {
            quantity = new int[size];
            price = new int[size];
            for (int i = 0; i < size; ++i) {
                quantity[i] = other.quantity[i];
                price[i] = other.price[i];
            }
        }

        ~fruitShopInventory() {
            delete[] quantity;
            delete[] price;
        }

        int getQuantity(int index) {
            if (index < 0 || index >= size) {
                cout << "Error: Quantity index out of bounds!!" << endl;
                return -1;
            }
            return quantity[index];
        }

        int getPrice(int index) {
            if (index < 0 || index >= size) {
                cout << "Error: Price index out of bounds!!" << endl;
                return -1;
            }
            return price[index];
        }

        void setQuantity(int index, int value) {
            if (index < 0 || index >= size) {
                cout << "Error: Quantity index out of bounds!!" << endl;
                return;
            }
            quantity[index] = value;
        }

        void setPrice(int index, int value) {
            if (index < 0 || index >= size) {
                cout << "Error: Price index out of bounds!!" << endl;
                return;
            }
            price[index] = value;
        }

        void displayInventory() {
            cout << "--- Fruit Shop Inventory ---" << endl;
            for (int i = 0; i < size; ++i) {
                cout << "Fruit " << i + 1 << ": Quantity = " << quantity[i] << ", Price = $" << price[i] << endl;
            }
        }
};

int main() {
    fruitShopInventory shop(3, 10, 5);

    shop.displayInventory();

    fruitShopInventory copiedShop = shop;

    shop.setQuantity(1, 20);
    shop.setPrice(1, 8);

    cout << "\nAfter modification (Original):" << endl;
    shop.displayInventory();

    cout << "\nCopied Inventory (Should be unchanged):" << endl;
    copiedShop.displayInventory();

    return 0;
}


