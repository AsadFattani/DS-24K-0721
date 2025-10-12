#include <iostream>
using namespace std;

class Node {
    public:
        int data;
        Node* next;

        Node (int val) : data(val), next(nullptr) {}
};

class list {
    private:
        Node* head;

    public:
        list() : head(nullptr) {}

        Node* getHead ()const {
            return head;
        }

        void addFront(int val){
            Node *n = new Node(val);
            n->next = head;
            head = n;
        }

        void recprintReverse(Node* temp){
            if (!temp)
                return;
            cout << temp->data << " ";
            recprintReverse(temp->next);
        }
};


int main(){
    list l1;
    l1.addFront(10);
    l1.addFront(30);
    l1.addFront(20);
    l1.addFront(5);
    l1.recprintReverse(l1.getHead());
}


