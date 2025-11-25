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

        void insert(int key) {
            int index = key % SIZE;
            while (table[index] != -1) {
                index = (index + 1) % SIZE;
            }
            table[index] = key;
            count++;
        }

        void display() {
            for (int i = 0; i < SIZE; i++) {
                cout << i << " -> " << table[i] << endl;
            }
        }

        void search(int key) {
            int index = key % SIZE;
            int startIndex = index;
            while (table[index] != -1) {
                if (table[index] == key) {
                    cout << "Key " << key << " found in the hash table." << endl;
                    return;
                }
                index = (index + 1) % SIZE;
                if (index == startIndex) break;
            }
            cout << "Key " << key << " not found in the hash table." << endl;
        }

        void remove(int key) {
            int index = key % SIZE;
            int startIndex = index;
            while (table[index] != -1) {
                if (table[index] == key) {
                    table[index] = -1;
                    count--;
                    return;
                }
                index = (index + 1) % SIZE;
                if (index == startIndex) break;
            }
        }
};


