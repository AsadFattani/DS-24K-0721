#include <iostream>
using namespace std;

class BSTNode {
    public:
    int data;
    string info;
    BSTNode* left;
    BSTNode* right;

    BSTNode(int data, string info) : data(data), info(info), left(nullptr), right(nullptr) {}
};

class CustomerInfo {
    private:
        BSTNode* root;
    
    public:
        CustomerInfo() : root(nullptr) {}

        BSTNode* getRoot () {
            return root;
        }

        void insert(int data, string info) {
            if (root == nullptr) {
                root = new BSTNode(data, info);
                return;
            }
            BSTNode* curr = root;
            BSTNode* parent = nullptr;
            while (curr != nullptr) {
                parent = curr;
                if (data < curr->data) {
                    curr = curr->left;
                } else if (data > curr->data) {
                    curr = curr->right;
                } else {
                    return;
                }
            }
            if (data < parent->data) {
                parent->left = new BSTNode(data, info);
            } else {
                parent->right = new BSTNode(data, info);
            }
        }

        void printInOrder(BSTNode* node) {
            BSTNode* stack[100];
            int top = -1;
            BSTNode* curr = node;
            while (curr != nullptr || top != -1) {
                while (curr != nullptr) {
                    stack[++top] = curr;
                    curr = curr->left;
                }
                curr = stack[top--];
                cout << "data: " << curr->data << ", info: " << curr->info << endl;
                curr = curr->right;
            }
        }

        void printPreOrder(BSTNode* node) {
            if (!node) return;
            BSTNode* stack[100];
            int top = -1;
            stack[++top] = node;
            while (top != -1) {
                BSTNode* curr = stack[top--];
                cout << "data: " << curr->data << ", info: " << curr->info << endl;
                if (curr->right) stack[++top] = curr->right;
                if (curr->left) stack[++top] = curr->left;
            }
        }

        void printPostOrder(BSTNode* node) {
            if (!node) return;
            BSTNode* stack[100];
            int top = -1;
            BSTNode* out[100];
            int outTop = -1;
            stack[++top] = node;
            while (top != -1) {
                BSTNode* curr = stack[top--];
                out[++outTop] = curr;
                if (curr->left) stack[++top] = curr->left;
                if (curr->right) stack[++top] = curr->right;
            }
            while (outTop != -1) {
                BSTNode* curr = out[outTop--];
                cout << "data: " << curr->data << ", info: " << curr->info << endl;
            }
        }
};

int main() {
    CustomerInfo lib;
    lib.insert(5, "Harry");
    lib.insert(3, "Ron");
    lib.insert(7, "Hermione");
    lib.insert(2, "Draco");
    lib.insert(4, "Luna");
    cout << "InOrder Traversal:" << endl;
    lib.printInOrder(lib.getRoot());
    cout << "PreOrder Traversal:" << endl;
    lib.printPreOrder(lib.getRoot());
    cout << "PostOrder Traversal:" << endl;
    lib.printPostOrder(lib.getRoot());

    return 0;
}

