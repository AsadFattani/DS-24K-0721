#include <iostream>
using namespace std;

#define N 5

class SongsQueue {
    int front, rear;
    string arr[N];

    public:
        SongsQueue() : front(-1), rear(-1) {}

        bool isEmpty() {
            return (front == -1 && rear == -1);
        }

        bool isFull() {
            return ((rear + 1) % N == front);
        }

        void addSong(string x) {
            if (isFull()) {
                front = (front + 1) % N;
                rear = (rear + 1) % N;
                arr[rear] = x;
                cout << "Queue Full. Overwriting oldest song with: " << x << endl;
            } else {
                if (isEmpty()) {
                    front = rear = 0;
                } else {
                    rear = (rear + 1) % N;
                }
                arr[rear] = x;
                cout << "Added to queue: " << x << endl;
            }
            displayPlaylist();
        }

        string playNext() {
            if (isEmpty()) {
                cout << "No songs in the queue" << endl;
                return "";
            }
            string x = arr[front];
            cout << "Skipped: " << x << endl;
            if (front == rear) {
                front = rear = -1;
            } else {
                front = (front + 1) % N;
            }
            displayPlaylist();
            return x;
        }

        string seeCurrent() {
            if (isEmpty()) {
                cout << "No songs in the queue" << endl;
                return "";
            } else {
                return arr[front];
            }
        }

        void displayPlaylist() {
            cout << "Current Playlist: ";
            if (isEmpty()) {
                cout << "No songs in the queue" << endl;
                return;
            }
            int i = front;
            while (true) {
                cout << arr[i];
                if (i == rear) break;
                cout << " | ";
                i = (i + 1) % N;
            }
            cout << endl << endl;
        }
};

int main() {
    SongsQueue s;
    s.addSong("The World Smallest Violin");
    s.addSong("Believer");
    s.addSong("Viva La Vida");
    s.addSong("As It Was");
    s.addSong("Thunder");
    s.addSong("Counting Stars");

    cout << "Now playing: " << s.seeCurrent() << endl;
    s.playNext();
    cout << "Now Playing: " << s.seeCurrent() << endl;

    return 0;
}

