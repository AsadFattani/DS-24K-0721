#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    string title;
    Node *next;

    Node(string t) : title(t), next(nullptr) {}
};

class Playlist {
private:
    Node *head, *tail;
public:
    Playlist() : head(nullptr), tail(nullptr) {}

    void addSong(string title) {
        Node *newNode = new Node(title);
        if (!head) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
        cout << "Added: " << title << endl;
    }

    void deleteFront() {
        Node *temp = head;
        cout << "Deleted: " << temp->title << endl;
        head = head->next;
        delete temp;
    }

    void searchByTitle(string title) {
        Node *temp = head;
        while (temp) {
            if (temp->title == title) {
                cout << "Found \"" << title << endl;
                return;
            }
            temp = temp->next;
        }
        cout << "Song \"" << title << "\" not found.\n";
    }

    void searchByPosition(int position) {
        Node *temp = head;
        int pos = 1;
        while (temp && pos < position) {
            temp = temp->next;
            pos++;
        }
        if (temp && pos == position) {
            cout << "Song at position " << position << ": " << temp->title << endl;
        } else {
            cout << "No song at position " << position << endl;
        }
    }

    void display() {
        Node *temp = head;
        int pos = 1;
        cout << "Playlist:\n";
        while (temp) {
            cout << pos << ". " << temp->title << endl;
            temp = temp->next;
            pos++;
        }
        if (head == nullptr) cout << "(empty)\n";
    }

    ~Playlist() {
        while (head) {
            Node *temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main() {
    Playlist playlist;
    playlist.addSong("Song A");
    playlist.addSong("Song B");
    playlist.addSong("Song C");
    playlist.display();

    playlist.searchByTitle("Song B");
    playlist.searchByPosition(2);

    playlist.deleteFront();
    playlist.display();

    return 0;
}
