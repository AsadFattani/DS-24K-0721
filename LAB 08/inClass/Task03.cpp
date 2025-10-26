#include <iostream>
using namespace std;

class BSTNode {
    public:
    int id;
    int stock;
    BSTNode* left;
    BSTNode* right;

    BSTNode(int id, int stock) : id(id), stock(stock), left(nullptr), right(nullptr) {}
};

class BST {
    private:
        BSTNode* root;
    
    public:
        BST() : root(nullptr) {}

        BSTNode* getRoot () {
            return root;
        }

        void insert(int id, int stock) {
            if (root == nullptr) {
                root = new BSTNode(id, stock);
                return;
            }
            BSTNode* curr = root;
            BSTNode* parent = nullptr;
            while (curr != nullptr) {
                parent = curr;
                if (id < curr->id) {
                    curr = curr->left;
                } else if (id > curr->id) {
                    curr = curr->right;
                }
            }
            if (id < parent->id) {
                parent->left = new BSTNode(id, stock);
            } else {
                parent->right = new BSTNode(id, stock);
            }
        }

        void updateStock(int id, int newStock) {
            BSTNode* curr = root;
            while (curr != nullptr) {
                if (id == curr->id) {
                    curr->stock = newStock;
                    cout << "Stock updated for ID " << id << " to " << newStock << endl;
                    return;
                } else if (id < curr->id) {
                    curr = curr->left;
                } else {
                    curr = curr->right;
                }
            }
            cout << "ID " << id << " not found in the tree." << endl;
        }

        void searchByID(int id){
            BSTNode* curr = root;
            while (curr != nullptr) {
                if (id == curr->id) {
                    cout << "ID: " << curr->id << ", Stock: " << curr->stock << endl;
                    return;
                } else if (id < curr->id) {
                    curr = curr->left;
                } else {
                    curr = curr->right;
                }
            }
            cout << "ID " << id << " not found in the tree." << endl;
        }

        void printInOrder(BSTNode* node) {
            if (node != nullptr) {
                printInOrder(node->left);
                cout << "ID: " << node->id << ", Stock: " << node->stock << endl;
                printInOrder(node->right);
            }
        }
        
        void largestQuantity() {
            if (root == nullptr) {
                cout << "Tree is empty." << endl;
                return;
            }
            BSTNode* maxNode = root;
            findLargestQuantity(root, maxNode);
            cout << "ID with largest quantity: " << maxNode->id << ", Stock: " << maxNode->stock << endl;
        }

        void findLargestQuantity(BSTNode* node, BSTNode*& maxNode) {
            if (node == nullptr) return;
            if (node->stock > maxNode->stock) {
                maxNode = node;
            }
            findLargestQuantity(node->left, maxNode);
            findLargestQuantity(node->right, maxNode);
        }
        
};
int main() {
    BST tree;
    tree.insert(1001, 10);
    tree.insert(2002, 20);
    tree.insert(3003, 30);
    tree.insert(4004, 40);

    cout << "In-order traversal of the BST:" << endl;
    tree.printInOrder(tree.getRoot());
    tree.updateStock(2002, 50);
    tree.searchByID(3003);
    tree.largestQuantity();

    return 0;
}





