#include <iostream>
using namespace std;

class Node {
    public:
        int data;
        Node* next;
        Node (int val): data(val), next(nullptr) {}

};

class list{
    private:
        Node* head;

    public:
        list() : head(nullptr) {}

        Node* getHead() const {
            return head;
        }

        void addFront(int val) {
            Node* n = new Node(val);
            n->next = head;
            head = n;
        }

        void print(){
            Node* temp = head;
            while (temp){
                cout << temp->data << " ";
                temp = temp->next;
            }
        }

        void recprint(Node* temp){
            if (!temp)
                return;
            cout << temp->data << " ";
            recprint(temp->next);
        }
};

int main(){
    list l;
    l.addFront(10);
    l.addFront(30);
    l.addFront(20);
    l.addFront(5);
    l.print();
    cout << endl;
    l.recprint(l.getHead());
    return 0;
}
