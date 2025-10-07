#include <iostream>
using namespace std;

// ==========================
// NODE CLASS
// ==========================
class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};

// ==========================
// LINKED LIST CLASS
// ==========================
class LinkedList {
private:
    Node* head;

public:
    LinkedList() {
        head = nullptr;
    }

    // ----- INSERT OPERATIONS -----
    void insertAtStart(int val) {
        Node* newNode = new Node(val);
        newNode->next = head;
        head = newNode;
    }

    void insertAtEnd(int val) {
        Node* newNode = new Node(val);

        if (head == nullptr) {
            head = newNode;
            return;
        }

        Node* temp = head;
        while (temp->next != nullptr)
            temp = temp->next;

        temp->next = newNode;
    }

    void insertAtPosition(int val, int pos) {
        Node* newNode = new Node(val);

        if (pos == 1) {
            newNode->next = head;
            head = newNode;
            return;
        }

        Node* temp = head;
        for (int i = 1; temp != nullptr && i < pos - 1; i++)
            temp = temp->next;

        if (temp == nullptr) {
            cout << "Position out of range\n";
            delete newNode;
            return;
        }

        newNode->next = temp->next;
        temp->next = newNode;
    }

    void insertAfterValue(int target, int val) {
        Node* temp = head;
        while (temp != nullptr && temp->data != target)
            temp = temp->next;

        if (temp == nullptr) {
            cout << "Target not found\n";
            return;
        }

        Node* newNode = new Node(val);
        newNode->next = temp->next;
        temp->next = newNode;
    }

    // ----- DELETE OPERATIONS -----
    void deleteFromStart() {
        if (head == nullptr) {
            cout << "List is empty\n";
            return;
        }

        Node* temp = head;
        head = head->next;
        delete temp;
    }

    void deleteFromEnd() {
        if (head == nullptr) {
            cout << "List is empty\n";
            return;
        }

        if (head->next == nullptr) {
            delete head;
            head = nullptr;
            return;
        }

        Node* temp = head;
        while (temp->next->next != nullptr)
            temp = temp->next;

        delete temp->next;
        temp->next = nullptr;
    }

    void deleteAtPosition(int pos) {
        if (head == nullptr) {
            cout << "List is empty\n";
            return;
        }

        if (pos == 1) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        Node* temp = head;
        for (int i = 1; temp != nullptr && i < pos - 1; i++)
            temp = temp->next;

        if (temp == nullptr || temp->next == nullptr) {
            cout << "Position out of range\n";
            return;
        }

        Node* delNode = temp->next;
        temp->next = delNode->next;
        delete delNode;
    }

    void deleteAfterValue(int target) {
        Node* temp = head;
        while (temp != nullptr && temp->data != target)
            temp = temp->next;

        if (temp == nullptr || temp->next == nullptr) {
            cout << "Target not found or no node after it\n";
            return;
        }

        Node* delNode = temp->next;
        temp->next = delNode->next;
        delete delNode;
    }

    // ----- SEARCH -----
    bool search(int key) {
        Node* temp = head;
        while (temp != nullptr) {
            if (temp->data == key)
                return true;
            temp = temp->next;
        }
        return false;
    }

    // ----- DISPLAY -----
    void display() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
};

// ==========================
// MAIN FUNCTION
// ==========================
int main() {
    LinkedList list;

    // Insert elements
    list.insertAtEnd(10);
    list.insertAtEnd(20);
    list.insertAtStart(5);
    list.insertAtPosition(15, 3);
    list.insertAfterValue(10, 12);

    cout << "Linked List: ";
    list.display();

    // Search
    cout << "Searching 15: " << (list.search(15) ? "Found\n" : "Not Found\n");

    // Deletions
    list.deleteFromStart();
    list.deleteFromEnd();
    list.deleteAtPosition(2);
    list.deleteAfterValue(10);

    cout << "After deletions: ";
    list.display();

    return 0;
}
