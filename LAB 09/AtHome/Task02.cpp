#include <iostream>
using namespace std;

class Node {
    public:
        int data;
        Node* left;
        Node* right;

        Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

class AVLTree {
    public:
        Node *root;
        AVLTree() : root(nullptr) {}

        int height(Node* N) {
            if (N == nullptr)
                return 0;
            return 1 + max(height(N->left), height(N->right));
        }

        int getBalance(Node* N) {
            if (N == nullptr)
                return 0;
            return height(N->left) - height(N->right);
        }

        Node* leftRotate(Node* &x) {
            Node* y = x->right;
            Node* T2 = y->left;

            y->left = x;
            x->right = T2;

            return y;
        }

        Node* rightRotate(Node* &y) {
            Node* x = y->left;
            Node* T2 = x->right;

            x->right = y;
            y->left = T2;

            return x;
        }

        Node *insert(Node* node, int key) {
            if (node == nullptr) return new Node(key);
            if (key < node->data)
                node->left = insert(node->left, key);
            else if (key > node->data)
                node->right = insert(node->right, key);
            else
                return node;
            
            height(node);

            int balance = getBalance(node);
            // left left
            if (balance > 1 && key < node->left->data)
                return rightRotate(node);
                
            // right right
            if (balance < -1 && key > node->right->data)
            return leftRotate(node);

            // left right
            if (balance > 1 && key < node->left->data) {
                node->left = leftRotate(node->left);
                return rightRotate(node);
            }

            // right left
            if (balance < -1 && key > node->right->data) {
                node->right = rightRotate(node->right);
                return leftRotate(node);
            }
            return node;
        }

        void preOrder(Node* root) {
            if (root != nullptr) {
                cout << root->data << " ";
                preOrder(root->left);
                preOrder(root->right);
            }
        }
};

int main() {
    AVLTree tree;
    int keys[] = {50, 30, 70, 20, 40, 60, 80, 55};
    for (int i = 0; i < 8; ++i) {
        tree.root = tree.insert(tree.root, keys[i]);
        cout << "Balance: " << tree.getBalance(tree.root) << endl;
        tree.preOrder(tree.root);
        cout << endl;
    }
    cout << "\nHeight of Avl tree: " << tree.height(tree.root) << endl;
    cout << endl;
    
    return 0;
}



