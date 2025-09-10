#include <iostream>
using namespace std;

class Node {
    public:
        string data;
        Node *next;

        Node(string t) : data(t), next(nullptr) {}
};

class InventoryManagement {
    private:
        Node *head, *tail;
    
    public:
        InventoryManagement() : head(nullptr), tail(nullptr) {}

        void addItemInOrder(string item) {
            Node *newNode = new Node(item);
            if (!head) {
                head = tail = newNode;
            } else {
                Node *temp = head, *prev = nullptr;
                while (temp && temp->data < item) {
                    prev = temp;
                    temp = temp->next;
                }
                if (!prev) {
                    newNode->next = head;
                    head = newNode;
                } else {
                    prev->next = newNode;
                    newNode->next = temp;
                    if (!temp) tail = newNode;
                }
            }
            cout << "Added item: " << item << endl;
        }

        void display() {

            int pos = 1;
            Node* temp = head;
            cout << "\n--- Inventory Items ---\n";
            if (!head) {
                cout << "(empty)\n";
                return;
            }
            while (temp) {
                cout << pos << ". " << temp->data << endl;
                temp = temp->next;
                pos++;
            }
        }
};

int main() {
    InventoryManagement inventory;
    inventory.addItemInOrder("100");
    inventory.addItemInOrder("104");
    inventory.addItemInOrder("102");
    inventory.addItemInOrder("101");
    inventory.display();
    return 0;
}


