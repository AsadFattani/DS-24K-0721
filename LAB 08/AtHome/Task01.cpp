#include <iostream>
using namespace std;

class BSTNode {
    public:
    int ISBN;
    string name;
    BSTNode* left;
    BSTNode* right;

    BSTNode(int ISBN, string name) : ISBN(ISBN), name(name), left(nullptr), right(nullptr) {}
};

class Library {
    private:
        BSTNode* root;
    
    public:
        Library() : root(nullptr) {}

        BSTNode* getRoot () {
            return root;
        }

        void insert(int ISBN, string name) {
            if (root == nullptr) {
                root = new BSTNode(ISBN, name);
                return;
            }
            BSTNode* curr = root;
            BSTNode* parent = nullptr;
            while (curr != nullptr) {
                parent = curr;
                if (ISBN < curr->ISBN) {
                    curr = curr->left;
                } else if (ISBN > curr->ISBN) {
                    curr = curr->right;
                }
            }
            if (ISBN < parent->ISBN) {
                parent->left = new BSTNode(ISBN, name);
            } else {
                parent->right = new BSTNode(ISBN, name);
            }
        }

        void printPreOrder(BSTNode* node){
            if (node != nullptr) {
                cout << "ISBN: " << node->ISBN << ", name: " << node->name << endl;
                printPreOrder(node->left);
                printPreOrder(node->right);
            }
        }

        void printInOrder(BSTNode* node) {
            if (node != nullptr) {
                printInOrder(node->left);
                cout << "ISBN: " << node->ISBN << ", name: " << node->name << endl;
                printInOrder(node->right);
            }
        }
        
        void printPostOrder(BSTNode* node) {
            if (node != nullptr) {
                printPostOrder(node->left);
                printPostOrder(node->right);
                cout << "ISBN: " << node->ISBN << ", name: " << node->name << endl;
            }
        }    
    };
int main() {
    Library lib;
    lib.insert(10, "Harry Potter & the Philosopher's Stone");
    lib.insert(5, "Guliver's Travels");
    lib.insert(15, "Wuthering Heights");
    lib.insert(3, "Oliver Twist");

    cout << "In-order Traversal:" << endl;
    lib.printInOrder(lib.getRoot());
    cout << "\nPre-order Traversal:" << endl;
    lib.printPreOrder(lib.getRoot());
    cout << "\nPost-order Traversal:" << endl;
    lib.printPostOrder(lib.getRoot());

    return 0;
}

