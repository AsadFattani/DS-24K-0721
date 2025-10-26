#include <iostream>
using namespace std;

class BTNode {
    public:
    int data;
    BTNode* left;
    BTNode* right;

    BTNode(int data) : data(data), left(nullptr), right(nullptr) {}
};

class CompleteBT {
    public:
        BTNode* root;
    
        CompleteBT() : root(nullptr) {}

        BTNode* getRoot () {
            return root;
        }

        void insert(BTNode* &root, int val) {
            if (root == nullptr) {
                root = new BTNode(val);
                return;
            }
            BTNode* arr[100]; // assume a maximum of 100 nodes
            int front = 0, rear = 0;
            arr[rear++] = root;
            while (front < rear) {
                BTNode* curr = arr[front++];
                if (curr->left == nullptr) {
                    curr->left = new BTNode(val);
                    return;
                } else {
                    arr[rear++] = curr->left;
                }
                if (curr->right == nullptr) {
                    curr->right = new BTNode(val);
                    return;
                } else {
                    arr[rear++] = curr->right;
                }
            }
        }

        void printLevelOrder(BTNode* root) {
            if (!root) return;
            BTNode* arr[100];
            int front = 0, rear = 0;
            arr[rear++] = root;
            while (front < rear) {
                BTNode* curr = arr[front++];
                cout << curr->data << " ";
                if (curr->left) arr[rear++] = curr->left;
                if (curr->right) arr[rear++] = curr->right;
            }
            cout << endl;
        }
};

int main() {
    CompleteBT tree;
    tree.insert(tree.root, 1);
    tree.insert(tree.root, 2);
    tree.insert(tree.root, 3);
    tree.insert(tree.root, 4);
    tree.insert(tree.root, 5);

    cout << "Before insertion: ";
    tree.printLevelOrder(tree.root);

    tree.insert(tree.root, 6);

    cout << "After insertion: ";
    tree.printLevelOrder(tree.root);

    return 0;
}




