#include <iostream>
using namespace std;

#define SIZE 10

class Node {
public:
    string key, value;
    Node* next;

    Node(){}
};

class HashTable {
    Node* table[SIZE];
    public:
        HashTable() {
            for (int i = 0; i < SIZE; i++) {
                table[i] = nullptr;
            }
        }

        int hashFunction(string key) {
            int hash = 0;
            for (char c : key) {
                hash = (hash + c) % SIZE;
            }
            return hash;
        }

        void insert(string key, string value) {
            int index = hashFunction(key);
            Node* newNode = new Node;
            newNode->key = key;
            newNode->value = value;
            newNode->next = nullptr;

            if (table[index] == nullptr) {
                table[index] = newNode;
            } else {
                Node* temp = table[index];
                while (temp->next != nullptr) {
                    temp = temp->next;
                }
                temp->next = newNode;
            }
        }

        void display() {
            for (int i = 0; i < SIZE; i++) {
                cout << i << " -> ";
                Node* temp = table[i];
                while (temp != nullptr) {
                    cout << "( ";
                    cout << temp->key << ", ";
                    cout << temp->value << " ) -> ";
                    temp = temp->next;
                }
                cout << "nullptr" << endl;
            }
        }
};

int main() {
    HashTable myhash;

    myhash.insert("A", "aaaaa");
    myhash.insert("B", "bbbbb");
    myhash.insert("C", "ccccc");
    myhash.insert("A", "zzzzz");

    myhash.display();

    return 0;
}





