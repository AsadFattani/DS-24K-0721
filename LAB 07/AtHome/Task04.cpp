#include <iostream>
using namespace std;

class node{
public:
    int data;
    node* next;

    node(int data){
        this->data=data;
        next =nullptr;
    }
};

class linkedList{
public:
    node* head;
    node* tail;

    linkedList() : head(nullptr), tail(nullptr) {}

    void addnode(int val){
        node* newnode =new node(val);
        if (head==nullptr) {
            head =tail =newnode;
        } else {
            tail->next =newnode;
            tail =newnode;
        }
    }

    void printList(){
        node* temp =head;
        while (temp!=nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    void swapNodes(node* node1, node* node2){
        int temp = node1->data;
        node1->data = node2->data;
        node2->data = temp;
    }

    node* partition(node* low, node* high){
        int pivot = high->data;
        node* i = low;
        node* j = low;

        while(j != high){
            if (j->data < pivot){
                swapNodes (i,j);
                i = i->next;
            }
            j = j->next;
        }
        swapNodes(i, high);
        return i;
    }

    void quickSortRecursive(node* low, node* high){
        if (low == nullptr|| low == high || high == nullptr){
            return;
        }
        node* pivot = partition(low, high);

        if (low != pivot){
            node* temp = low;
            while (temp->next != pivot){
                temp = temp->next;
            }
            quickSortRecursive(low, temp);
        }
        if (pivot->next != nullptr) {
            quickSortRecursive(pivot->next, high);
        }
    }

    void quickSort() {
        quickSortRecursive(head, tail);
    }
};

int main(){
    linkedList list;
    list.addnode(10);
    list.addnode(7);
    list.addnode(8);
    list.addnode(9);
    list.addnode(1);
    list.addnode(5);
    list.addnode(3);

    cout<<"original list: ";
    list.printList();
    list.quickSort();
    cout <<"sorted list: ";
    list.printList();
}
