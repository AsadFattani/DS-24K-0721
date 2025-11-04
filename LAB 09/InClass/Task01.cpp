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

        void AVLsearch(Node* node, int key) {
            if (node == nullptr) {
                cout << "Key " << key << " not found in the AVL tree." << endl;
                return;
            }
            if (key == node->data) {
                cout << "Key " << key << " found in the AVL tree." << endl;
                return;
            }
            if (key < node->data)
                AVLsearch(node->left, key);
            else
                AVLsearch(node->right, key);
        }

        Node* deleteNode(Node* root, int key) {
            if (root == nullptr)
                return root;

            if (key < root->data)
                root->left = deleteNode(root->left, key);
            else if (key > root->data)
                root->right = deleteNode(root->right, key);
            else {
                if ((root->left == nullptr) || (root->right == nullptr)) {
                    Node* temp = root->left ? root->left : root->right;

                    if (temp == nullptr) {
                        temp = root;
                        root = nullptr;
                    } else
                        *root = *temp;
                    delete temp;
                } else {
                    Node* temp = minValueNode(root->right);
                    root->data = temp->data;
                    root->right = deleteNode(root->right, temp->data);
                }
            }

            if (root == nullptr)
                return root;

            height(root);

            int balance = getBalance(root);

            // left left
            if (balance > 1 && getBalance(root->left) >= 0)
                return rightRotate(root);

            // left right
            if (balance > 1 && getBalance(root->left) < 0) {
                root->left = leftRotate(root->left);
                return rightRotate(root);
            }

            // right right
            if (balance < -1 && getBalance(root->right) <= 0)
                return leftRotate(root);

            // right left
            if (balance < -1 && getBalance(root->right) > 0) {
                root->right = rightRotate(root->right);
                return leftRotate(root);
            }

            return root;
        }

        void preOrder(Node* root) {
            if (root != nullptr) {
                cout << root->data << " ";
                preOrder(root->left);
                preOrder(root->right);
            }
        }

        Node* minValueNode(Node* node) {
            Node* current = node;
            while (current && current->left != nullptr)
                current = current->left;
            return current;
        }
};

int main() {
    AVLTree tree;
    int keys[] = {10, 20, 30, 40, 50, 15};
    for (int i = 0; i < 6; ++i) {
        tree.root = tree.insert(tree.root, keys[i]);
        cout << "Balance: " << tree.getBalance(tree.root) << endl;
        tree.preOrder(tree.root);
        cout << endl;
    }
    cout << "\nHeight of Avl tree: " << tree.height(tree.root) << endl;
    cout << endl;
    
    tree.AVLsearch(tree.root, 25);
    cout << endl;

    cout << "Preorder traversal before deletion:" << endl;
    tree.preOrder(tree.root);
    tree.root = tree.deleteNode(tree.root, 20);
    cout << "\nPreorder traversal after deletion of 20:" << endl;
    tree.preOrder(tree.root);


    return 0;
}



