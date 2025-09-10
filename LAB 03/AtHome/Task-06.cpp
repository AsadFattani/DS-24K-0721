#include <iostream>
using namespace std;

class Node {
public:
    string data;
    Node *next;

    Node(string t) : data(t), next(nullptr) {}
};

class TaskList {
public:
    Node *head;
    Node *tail;

    TaskList() : head(nullptr), tail(nullptr) {}

    void addTask(const string &task) {
        Node *newNode = new Node(task);
        if (!head) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    void print() {
        Node *temp = head;
        int pos = 1;
        while (temp) {
            cout << pos << ": " << temp->data << endl;
            temp = temp->next;
            pos++;
        }
        cout << endl;
    }
};

TaskList mergeTaskLists(TaskList &list1, TaskList &list2) {
    TaskList merged;
    Node *temp = list1.head;
    while (temp) {
        merged.addTask(temp->data);
        temp = temp->next;
    }
    temp = list2.head;
    while (temp) {
        merged.addTask(temp->data);
        temp = temp->next;
    }
    return merged;
}

int main() {
    TaskList list1, list2;
    list1.addTask("assignment");
    list1.addTask("code");
    list1.addTask("grocery");

    list2.addTask("laundry");
    list2.addTask("cleaning");

    cout << "-- List 1 --\n";
    list1.print();
    cout << "-- List 2 --\n";
    list2.print();

    TaskList mergedList = mergeTaskLists(list1, list2);
    cout << "\n--- Merged List ---\n";
    mergedList.print();

    return 0;
}
