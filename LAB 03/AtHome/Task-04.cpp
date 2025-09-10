#include <iostream>
using namespace std;

class Node {
    public:
        string data;
        Node *next;

        Node(string t) : data(t), next(nullptr) {}
};

class PhotoGallery {
    private:
        Node *head, *tail;
    
    public:
        PhotoGallery() : head(nullptr), tail(nullptr) {}

        void addPhoto(string title) {
            Node *newNode = new Node(title);
            if (!head) {
                head = tail = newNode;
            } else {
                tail->next = newNode;
                tail = newNode;
            }
            cout << "Added photo: " << title << endl;
        }

        void reverseList() {
            Node* prev = nullptr;
            Node* curr = head;
            tail = head;
            while (curr) {
                Node* next = curr->next;
                curr->next = prev;
                prev = curr;
                curr = next;
            }
            head = prev;
        }

        void display() {
            reverseList();
            int pos = 1;
            Node* temp = head;
            cout << "\n--- Photo Gallery ---\n";
            if (!head) {
                cout << "(empty)\n";
                return;
            }
            while (temp) {
                cout << pos << ". " << temp->data << endl;
                temp = temp->next;
                pos++;
            }
        }
};

int main() {
    PhotoGallery gallery;
    gallery.addPhoto("Vacation");
    gallery.addPhoto("Birthday");
    gallery.addPhoto("Graduation");
    gallery.display();
    return 0;
}
