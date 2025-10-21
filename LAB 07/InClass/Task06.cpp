#include <iostream>
using namespace std;

#define MAX 1000

class Stack {
    int top;

    public:
        int arr[MAX];
        Stack() : top(-1) {}

        bool push (int x) {
            if (top >= MAX - 1) {
                cout << "Stack Overflow" << endl;
                return false;
            } else {
                arr[++top] = x;
                return true;
            }
        }

        int pop() {
            if (top < 0) {
                cout << "Stack Underflow" << endl;
                return 0;
            } else {
                int x = arr[top--];
                return x;
            }
        }

        int peek() {
            if (top < 0) {
                cout << "Stack is Empty" << endl;
                return 0;
            } else {
                int x = arr[top];
                return x;
            }
        }

        bool isEmpty() {
            return (top < 0);
        }
};

int main() {
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    cout << s.pop() << " Popped from stack" << endl;
    cout << "Top element is: " << s.peek() << endl;
    cout << "Stack empty: " << (s.isEmpty() ? "Yes" : "No") << endl;
    return 0;
}


