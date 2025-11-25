#include <iostream>
#include <list>
using namespace std;


#define SIZE 10

class Hash {
    list<int> table[SIZE];
public:
    int hashFunction(int key) {
        return key % SIZE;
    }

    // push_back: Adds an element to the end of the list
    void insert(int key) {
        int index = hashFunction(key);
        table[index].push_back(key);
    }

    // begin/end: Get iterators to start/end of the list
    // erase: Removes the element at the given iterator position
    void deleteKey(int key) {
        int index = hashFunction(key);
        auto& chain = table[index];
        bool found = false;
        for (auto node = chain.begin(); node != chain.end(); ++node) {
            if (*node == key) {
                chain.erase(node);
                cout << "Key " << key << " deleted from the hash table." << endl;
                found = true;
                break;
            }
        }
        if (!found) {
            cout << "Key " << key << " not found for deletion." << endl;
        }
    }

    // begin/end: Used to iterate through the list
    void search(int key) {
        int index = hashFunction(key);
        auto& chain = table[index];
        bool found = false;
        for (auto node = chain.begin(); node != chain.end(); ++node) {
            if (*node == key) {
                cout << "Key " << key << " found in the hash table." << endl;
                found = true;
                break;
            }
        }
        if (!found) {
            cout << "Key " << key << " not found in the hash table." << endl;
        }
    }

    // Range-based for: Iterates through all elements in the list
    void display() {
        for (int i = 0; i < SIZE; i++) {
            cout << i << " -> ";
            for (int val : table[i]) {
                cout << val << " -> ";
            }
            cout << "nullptr" << endl;
        }
    }
};

int main() {
    Hash hashTable;

    hashTable.insert(10);
    hashTable.insert(22);
    hashTable.insert(15);
    hashTable.insert(25);
    hashTable.insert(30);

    cout << "Hash Table:" << endl;
    hashTable.display();

    hashTable.search(15);
    hashTable.search(99);

    hashTable.deleteKey(22);
    hashTable.deleteKey(99);

    cout << endl;
    cout << "Hash Table after deletions:" << endl;
    hashTable.display();

    return 0;
}






