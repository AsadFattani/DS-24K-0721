#include <iostream>
using namespace std;

class Node {
    public:
        int data;
        Node* next;

        Node (int val) : data(val), next(nullptr){}

};

class list {
    private:
        Node *head;

    public:
        list() : head(nullptr) {}

        Node* getHead () const {
            return head;
        }

        void addFront(int val) {
            Node *n = new Node(val);
            n->next = head;
            head = n;
        }

        int recursiveLength(Node *temp){
            if (!temp)
                return 0;
            return 1 + recursiveLength(temp->next);
        }

        
};

int main() {
    list l1;
    l1.addFront(15);
    l1.addFront(25);
    l1.addFront(12);
    l1.addFront(5);
    l1.addFront(18);
    l1.addFront(6);
    l1.addFront(6);
    int l = 0;

    cout << "Length of list is: " << l1.recursiveLength(l1.getHead()) << endl;
}




