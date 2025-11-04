#include <iostream>
using namespace std;

class BSTNode {
    public:
    int data;
    BSTNode* left;
    BSTNode* right;

    BSTNode(int data) : data(data), left(nullptr), right(nullptr) {}
};

class BST {
    private:
        BSTNode* root;

    public:
        BST() : root(nullptr) {}

        BSTNode* insert(BSTNode* root, int data) {
            if (root == nullptr) {
                return new BSTNode(data);
            }
            if (data < root->data) {
                root->left = insert(root->left, data);
            } else if (data > root->data) {
                root->right = insert(root->right, data);
            }
            return root;
        }

        void PreOrderTraversal(BSTNode* node) {
            if (node != nullptr) {
                cout << node->data << " ";
                PreOrderTraversal(node->left);
                PreOrderTraversal(node->right);
            }
        }

        void inOrderTraversal(BSTNode* node) {
            if (node != nullptr) {
                inOrderTraversal(node->left);
                cout << node->data << " ";
                inOrderTraversal(node->right);
            }
        }

        void POSTOrderTraversal(BSTNode* node) {
            if (node != nullptr) {
                POSTOrderTraversal(node->left);
                POSTOrderTraversal(node->right);
                cout << node->data << " ";
            }
        }

        BSTNode* search(BSTNode* root, int key) {
            if (root == nullptr || root->data == key) {
                return root;
            }
            if (key < root->data) {
                return search(root->left, key);
            }
            return search(root->right, key);
        }

        BSTNode* minValueNode(BSTNode* node) {
            BSTNode* current = node;
            while (current && current->left != nullptr) {
                current = current->left;
            }
            return current;
        }

        BSTNode* deleteNode(BSTNode* root, int key) {
            if (root == nullptr) {
                return root;
            }
            if (key < root->data) {
                root->left = deleteNode(root->left, key);
            } else if (key > root->data) {
                root->right = deleteNode(root->right, key);
            } else {
                if (root->left == nullptr) {
                    BSTNode* temp = root->right;
                    delete root;
                    return temp;
                } else if (root->right == nullptr) {
                    BSTNode* temp = root->left;
                    delete root;
                    return temp;
                }
                BSTNode* temp = minValueNode(root->right);
                root->data = temp->data;
                root->right = deleteNode(root->right, temp->data);
            }
            return root;
        }


};

int main() {
    BST tree;
    BSTNode* root = nullptr;

    root = tree.insert(root, 50);
    tree.insert(root, 30);
    tree.insert(root, 20);
    tree.insert(root, 40);
    tree.insert(root, 70);
    tree.insert(root, 60);
    tree.insert(root, 80);

    cout << "In-order traversal: ";
    tree.inOrderTraversal(root);
    cout << endl;

    cout << "Pre-order traversal: ";
    tree.PreOrderTraversal(root);
    cout << endl;

    cout << "Post-order traversal: ";
    tree.POSTOrderTraversal(root);
    cout << endl;

    int key = 40;
    BSTNode* searchResult = tree.search(root, key);
    if (searchResult != nullptr) {
        cout << "Found node with key " << key << endl;
    } else {
        cout << "Node with key " << key << " not found" << endl;
    }

    root = tree.deleteNode(root, 20);
    cout << "In-order traversal after deleting 20: ";
    tree.inOrderTraversal(root);
    cout << endl;

    root = tree.deleteNode(root, 30);
    cout << "In-order traversal after deleting 30: ";
    tree.inOrderTraversal(root);
    cout << endl;

    root = tree.deleteNode(root, 50);
    cout << "In-order traversal after deleting 50: ";
    tree.inOrderTraversal(root);
    cout << endl;

    return 0;
}




