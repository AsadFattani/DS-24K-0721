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

        Node* search(int val) {
            Node* temp = head;
            while (temp) {
            if (temp->data == val) {
                return temp;
            }
            temp = temp->next;
            }
            return nullptr;
        }

        // void deleteAtValue(int target) {
        //     Node* temp = head;
        //     while (temp != nullptr && temp->data != target)
        //         temp = temp->next;

        //     if (temp == nullptr || temp->next == nullptr) {
        //         cout << "Target not found or no node after it\n";
        //         return;
        //     }

        //     Node* delNode = temp->next;
        //     temp->next = delNode->next;
        //     delete delNode;    
        // }

        void deleteByValue(int val) {
            Node *temp = head, *prev = nullptr;
            while (temp && temp->data != val) {
            prev = temp;
            temp = temp->next;
            }
            if (!temp) {
            cout << "Node with value \"" << val << "\" not found.\n";
            return;
            }
            if (!prev) { // deleting head
            head = head->next;
            } else {
            prev->next = temp->next;
            }
            delete temp;
            cout << "Deleted: " << val << endl;
        }

        void recprint(Node* temp){
            if (!temp)
                return;
            cout << temp->data << " ";
            recprint(temp->next);
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

    cout << "return value is: " << l1.search(18) << endl;

    l1.deleteByValue(18);
    l1.recprint(l1.getHead());
    return 0;
}




