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

};

int main() {
    AVLTree tree;
    tree.root = new Node(10);
    tree.root = new Node(20);
    tree.root = new Node(30);
    tree.root = new Node(40);
    tree.root = new Node(50);
    tree.root = tree.insert(tree.root, 15);

    return 0;

}



