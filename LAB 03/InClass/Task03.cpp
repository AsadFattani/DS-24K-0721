#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    string data;
    Node *next;

    Node(string t) : data(t), next(nullptr) {}
};

class CustomerQueueSystem {
private:
    Node *head, *tail;
public:
    CustomerQueueSystem() : head(nullptr), tail(nullptr) {}

    void addCustomer(string name) {
        Node *newNode = new Node(name);
        if (!head) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
        cout << "Added: " << name << endl;
    }

    void deleteFront() {
        Node *temp = head;
        cout << "Deleted: " << temp->data << endl;
        head = head->next;
        delete temp;
    }

    void deleteEnd() {
        if (!head) return;
        if (head == tail) {
            cout << "Deleted: " << head->data << endl;
            delete head;
            head = tail = nullptr;
            return;
        }
        Node *temp = head;
        while (temp->next != tail) {
            temp = temp->next;
        }
        cout << "Deleted: " << tail->data << endl;
        delete tail;
        tail = temp;
        tail->next = nullptr;
    }

    void DeleteAtPos(int pos) {
        if (pos <= 0 || !head) {
            cout << "Not possible" << endl;
            return;
        }
        if (pos == 1) { 
            deleteFront(); 
            return; 
        }
        Node *prev = head;
        for (int i = 2; prev->next && i < pos; i++)
            prev = prev->next;
        Node *cur = prev->next;
        if (!cur) { 
            cout << "Position out of bounds.\n"; 
            return; 
        }
        prev->next = cur->next;
        if (cur == tail) tail = prev;
        cout << "Deleted: " << cur->data << endl;
        delete cur;
    }

    void display() {
        Node *temp = head;
        int pos = 1;
        cout << "CustomerQueueSystem:\n";
        while (temp) {
            cout << pos << ". " << temp->data << endl;
            temp = temp->next;
            pos++;
        }
        if (head == nullptr) cout << "(empty)\n";
    }

    ~CustomerQueueSystem() {
        while (head) {
            Node *temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main() {
    CustomerQueueSystem TicketCounter;
    TicketCounter.addCustomer("Alice");
    TicketCounter.addCustomer("Bob");
    TicketCounter.addCustomer("Charlie");
    TicketCounter.display();

    TicketCounter.deleteFront();
    TicketCounter.display();

    TicketCounter.deleteEnd();
    TicketCounter.display();

    TicketCounter.DeleteAtPos(1);
    TicketCounter.display();

    TicketCounter.DeleteAtPos(1); // Attempt to delete from empty list
    TicketCounter.display();

    return 0;
}

