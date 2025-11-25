#include <iostream>
using namespace std;

#define SIZE 100

class Node {
public:
    string key;
    string value;
    Node* next;

    Node(){}
    Node(string k, string v) : key(k), value(v), next(nullptr) {}
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
        int sum = 0;
        for (char c : key) {
            sum += int(c);
        }
        return sum % SIZE;
    }

    void Add_Record(string key, string value) {
        int index = hashFunction(key);
        Node* newNode = new Node(key, value);

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

    void WordSearch(string key) {
        int index = hashFunction(key);
        Node* temp = table[index];
        while (temp != nullptr) {
            if (temp->key == key) {
                cout << "search key " << key << ": " << temp->value << endl;
                return;
            }
            temp = temp->next;
        }
        cout << "Word not found: " << key << endl;
    }

    void Delete_Record(string key) {
        int index = hashFunction(key);
        Node* temp = table[index];
        Node* prev = nullptr;
        while (temp != nullptr) {
            if (temp->key == key) {
                if (prev == nullptr) {
                    table[index] = temp->next;
                } else {
                    prev->next = temp->next;
                }
                delete temp;
                cout << "key " << key << " deleted successfully !" << endl;
                return;
            }
            prev = temp;
            temp = temp->next;
        }
        cout << "Word not found: " << key << endl;
    }

    void Print_Dictionary() {
        for (int i = 0; i < SIZE; i++) {
            Node* temp = table[i];
            if (temp != nullptr) {
                cout << "index " << i << ": ";
                while (temp != nullptr) {
                    cout << "(" << temp->key << ", " << temp->value << ")";
                    if (temp->next != nullptr) cout << " -> ";
                    temp = temp->next;
                }
                cout << endl;
            }
        }
    }
};

int main() {
    HashTable myhash;

    myhash.Add_Record("AB", "FASTNU");
    myhash.Add_Record("CD", "CS");
    myhash.Add_Record("EF", "AI");


    myhash.Print_Dictionary();

    myhash.WordSearch("AB");

    myhash.Delete_Record("EF");

    myhash.Print_Dictionary();

    return 0;
}