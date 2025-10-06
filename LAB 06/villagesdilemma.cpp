#include <iostream>
using namespace std;

class Node {
public:
    int val1, val2;
    string data;
    Node *next;
    Node(int x, int y, string t) : val1(x), val2(y), data(t), next(nullptr) {}
};

class Exchange {
    Node *head;
public:
    Exchange() : head(nullptr) {
        int coins[5][2] = {{2, 4}, {5, 3}, {2, 1}, {2, 2}, {3, 1}};
        head = new Node(coins[0][0], coins[0][1], "Villager 1");
        Node *curr = head;
        for (int i = 1; i < 5; ++i) {
            curr->next = new Node(coins[i][0], coins[i][1], "Villager " + to_string(i+1));
            curr = curr->next;
        }
        curr->next = nullptr;
    }

    void findAndSwapForFive() {
        Node *curr = head;
        int i = 1;
        bool swap = false;
        while (curr && !swap) {
            if (curr->val1 + curr->val2 == 5) {
                cout << curr->data << ": Swapped " << curr->val1 << " & " << curr->val2 << " for 5" << endl;
                swap = true;
                i++;
            }
            curr = curr->next;
        }
        if (!swap){
            cout << "No Village has the change! -- BURN THEM ALL" << endl;
        }
        
    }

    ~Exchange() {
        Node *curr = head;
        while (curr) {
            Node *temp = curr;
            curr = curr->next;
            delete temp;
        }
    }
};

int main() {
    Exchange ex;
    ex.findAndSwapForFive();
    return 0;
}



