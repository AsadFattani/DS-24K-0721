#include <iostream>
using namespace std;

#define SIZE 10

class HashTable {
    int *table, count;
    public:
        HashTable() {
            table = new int(SIZE);
            count = 0;
            for (int i = 0; i < SIZE; i++) {
                table[i] = -1;
            }
        }

        int hashFunction(int key) {
            return key % SIZE;
        }

        void insert(int key) {
            int index = hashFunction(key);
            while (table[index] != -1) {
                index = (index + 1) % SIZE;
            }
            table[index] = key;
            count++;
        }

        void display() {
            bool first = true;
            for (int i = 0; i < SIZE; i++) {
                if (table[i] != -1) {
                    if (!first) {
                        cout << " -> ";
                    }
                    cout << table[i];
                    first = false;
                }
            }
            cout << endl;
        }

        void Search(int key) {
            int index = hashFunction(key);
            int startIndex = index;
            while (table[index] != -1) {
                if (table[index] == key) {
                    cout << key << " found" << endl;
                    return;
                }
                index = (index + 1) % SIZE;
                if (index == startIndex) {
                    break;
                }
            }
            cout << key << " not found" << endl;
        }

        void remove(int key) {
            int index = hashFunction(key);
            int startIndex = index;
            while (table[index] != -1) {
                if (table[index] == key) {
                    table[index] = -1;
                    count--;
                    cout << "Removing " << key << endl;
                    return;
                }
                index = (index + 1) % SIZE;
                if (index == startIndex) {
                    cout << "Key " << key << " not found" << endl;
                    break;
                }
            }
        }
};


int main() {
    HashTable ht;
    ht.insert(1);
    ht.insert(3);
    ht.insert(4);
    ht.insert(5);
    ht.insert(7);
    ht.display();

    ht.remove(4);
    ht.display();

    ht.Search(5);
    ht.Search(6);
    return 0;
}