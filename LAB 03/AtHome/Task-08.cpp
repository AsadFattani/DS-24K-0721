#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
    Node(int val) : data(val), prev(nullptr), next(nullptr) {}
};

class DoublyLinkedList {
private:
    Node* head;
    Node* tail;
public:
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}

    void insertAtEnd(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    void deleteAtFront() {
        if (!head) return;
        Node* temp = head;
        head = head->next;
        if (head) {
            head->prev = nullptr;
        } else {
            tail = nullptr;
        }
        delete temp;
    }

    bool search(int val) {
        Node* temp = head;
        while (temp) {
            if (temp->data == val) return true;
            temp = temp->next;
        }
        return false;
    }

    void display() {
        Node* temp = head;
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    DoublyLinkedList doubly;
    doubly.insertAtEnd(10);
    doubly.insertAtEnd(20);
    doubly.insertAtEnd(30);
    cout << "List: ";
    doubly.display();

    cout << "Search 20: " << (doubly.search(20) ? "Found" : "Not Found") << endl;
    cout << "Search 40: " << (doubly.search(40) ? "Found" : "Not Found") << endl;

    doubly.deleteAtFront();
    cout << "After deleting front: ";
    doubly.display();

    return 0;
}
