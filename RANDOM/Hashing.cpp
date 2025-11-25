#include <iostream>
using namespace std;

#define SIZE 10

class Node {
public:
    int data;
    Node* next;

    Node(int k) : data(k), next(nullptr) {}
};

class HashTable {
    Node* table[SIZE];
    public:
        HashTable() {
            for (int i = 0; i < SIZE; i++) {
                table[i] = nullptr;
            }
        }

        int hashFunction(int key) {
            return key % SIZE;
        }

        void insert(int key) {
            int index = hashFunction(key);
            Node* newNode = new Node(key);

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

        void deleteKey(int key) {
            int index = hashFunction(key);
            Node* temp = table[index];
            Node* prev = nullptr;

            while (temp != nullptr && temp->data != key) {
                prev = temp;
                temp = temp->next;
            }

            if (temp == nullptr) {
                cout << "Key " << key << " not found for deletion." << endl;
                return;
            }

            if (prev == nullptr) {
                table[index] = temp->next;
            } else {
                prev->next = temp->next;
            }
            delete temp;
            cout << "Key " << key << " deleted from the hash table." << endl;
        }

        void search(int key) {
            int index = hashFunction(key);
            Node* temp = table[index];
            while (temp != nullptr) {
                if (temp->data == key) {
                    cout << "Key " << key << " found in the hash table." << endl;
                    return;
                }
                temp = temp->next;
            }
            cout << "Key " << key << " not found in the hash table." << endl;
        }

        void display() {
            for (int i = 0; i < SIZE; i++) {
                cout << i << " -> ";
                Node* temp = table[i];
                while (temp != nullptr) {
                    cout << temp->data << " -> ";
                    temp = temp->next;
                }
                cout << "nullptr" << endl;
            }
        }
};





