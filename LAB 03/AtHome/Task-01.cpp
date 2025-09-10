#include <iostream>
using namespace std;

class Node {
    public:
        string data;
        Node *next;

        Node(string t) : data(t), next(nullptr) {}
};

class RollCallSystem {
    private:
        Node *head, *tail;
    
    public:
        RollCallSystem() : head(nullptr), tail(nullptr) {}

        void addStudent(string name) {
            Node *newNode = new Node(name);
            if (!head) {
                head = tail = newNode;
            } else {
                tail->next = newNode;
                tail = newNode;
            }
            cout << "Added: " << name << endl;
        }

        void deleteStudentByName(string name) {
            Node *temp = head, *prev = nullptr;
            while (temp && temp->data != name) {
                prev = temp;
                temp = temp->next;
            }
            if (!temp) {
                cout << "Student with name \"" << name << "\" not found.\n";
                return;
            }
            if (!prev) { 
                head = head->next;
                if (temp == tail) tail = head;
            } else {
                prev->next = temp->next;
                if (temp == tail) tail = prev;
            }
            delete temp;
            cout << "Deleted: " << name << endl;
        }

        void display() {
            Node *temp = head;
            int pos = 1;
            cout << "\n--- Students ---\n";
            while (temp) {
                cout << pos << ". " << temp -> data << endl;
                temp = temp -> next;
                pos++;
            }
            if (head == nullptr) cout << "(empty)\n";
        }

        ~RollCallSystem() {
            while (head) {
                Node *temp = head;
                head = head -> next;
                delete temp;
            }
        }
};

int main() {
    RollCallSystem classroom;

    classroom.addStudent("Harry");
    classroom.addStudent("Ron");
    classroom.addStudent("Hermione");
    classroom.addStudent("Draco");
    classroom.addStudent("Neville");

    classroom.display();

    classroom.deleteStudentByName("Draco");
    classroom.display();

    classroom.deleteStudentByName("Luna");
    classroom.display();

    return 0;
}
