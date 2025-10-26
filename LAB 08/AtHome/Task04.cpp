#include <iostream>
using namespace std;

#define N 20

class Queue {
    int front, rear;
    int arr[N];

    public:
    Queue() : front(-1), rear(-1) {}
    
        bool isEmpty() {
            return (front == -1 || front > rear);
        }

        bool isFull() {
            return (rear == N - 1);
        }

        void enqueue(int x) {
            if (isFull()) {
                cout << "Queue Overflow" << endl;
            }
            if (front == -1) {
                front = 0;
            }
            arr[++rear] = x;
            cout << x << " enqueued to queue" << endl;
        }

        int dequeue() {
            if (isEmpty()) {
                cout << "Queue Underflow" << endl;
                return 0;
            }
            cout << arr[front] << " dequeued from queue" << endl;
            return arr[front++];
        }

        int peek() {
            if (isEmpty()) {
                cout << "Queue is empty" << endl;
                return 0;
            }
            return arr[front];
        }
};

int main() {
    Queue q;
    q.enqueue(101);
    q.enqueue(102);
    q.enqueue(103);
    q.enqueue(104);
    
    cout << "Peeked at the first value: " << q.peek() << endl;
    q.dequeue();
    cout << "Peeked at the first value: " << q.peek() << endl;


    return 0;
}

