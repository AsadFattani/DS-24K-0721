// You are working on a project to develop a library management system. The system has a bookshelf that
// can hold a maximum of 20 books. The books are to be stored in the shelf based on their names, which
// are a combination of two uppercase letters (e.g., AB, CD, EF, etc.). However, you cannot place two or
// more books with the same name in the same position of the shelf, as that would cause a collision. To
// avoid collisions, you have decided to create a separate shelf for each unique position in the shelf.
// Whenever a new book needs to be added to the shelf, the system checks if the position corresponding
// to the book's name is already occupied. If it is, the system creates a new shelf and adds the book to the
// new shelf. The system can efficiently retrieve a book from the shelf by searching for the book in the
// appropriate shelf.

#include <iostream>
#include <string>
using namespace std;

#define SIZE 20 // bookshelf can hold a maximum of 20 books

class Node {
public:
    string bookName;
    Node* next;

    Node(string name) : bookName(name), next(nullptr) {}
};

class HashTable {
    Node* table[SIZE];
public:
    HashTable() {
        for (int i = 0; i < SIZE; i++) {
            table[i] = nullptr;
        }
    }

    // Hash function for two uppercase letters (e.g., "AB")
    int hashFunction(const string& bookName) {
        if (bookName.length() != 2) return 0;
        int idx = (bookName[0] - 'A') * 26 + (bookName[1] - 'A');
        return idx % SIZE;
    }

    void insert(const string& bookName) {
        int index = hashFunction(bookName);
        Node* newNode = new Node(bookName);

        if (table[index] == nullptr) {
            table[index] = newNode;
        } else {
            Node* temp = table[index];
            while (temp != nullptr) {
                if (temp->bookName == bookName) {
                    cout << "Book " << bookName << " already exists in shelf " << index << "." << endl;
                    delete newNode;
                    return;
                }
                if (temp->next == nullptr) break;
                temp = temp->next;
            }
            temp->next = newNode;
        }
        cout << "Book " << bookName << " inserted at shelf " << index << "." << endl;
    }

    void search(const string& bookName) {
        int index = hashFunction(bookName);
        Node* temp = table[index];
        while (temp != nullptr) {
            if (temp->bookName == bookName) {
                cout << "Book " << bookName << " found in shelf " << index << "." << endl;
                return;
            }
            temp = temp->next;
        }
        cout << "Book " << bookName << " not found in the library." << endl;
    }

    void display() {
        for (int i = 0; i < SIZE; i++) {
            cout << "Shelf " << i << " -> ";
            Node* temp = table[i];
            while (temp != nullptr) {
                cout << temp->bookName << " -> ";
                temp = temp->next;
            }
            cout << "nullptr" << endl;
        }
    }
};

int main() {
    HashTable ht;

    ht.insert("AB");
    ht.insert("CD");
    ht.insert("EF");
    ht.insert("GH");
    ht.insert("AB");

    ht.display();

    ht.search("CD");
    return 0;
}





