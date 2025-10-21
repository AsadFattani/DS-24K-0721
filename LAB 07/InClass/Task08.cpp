#include <iostream>
#include <string>
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

int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    if (op == '^') return 3;
    return -1;
}

string infixToPostfix(string infix) {
    string postfix = "";
    Stack s; // Use default constructor

    for (int i = 0; i < infix.length(); i++) {
        char c = infix[i];

        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
            postfix += c;
        } else if (c == '(') {
            s.push(c);
        } else if (c == ')') {
            while (!s.isEmpty() && s.peek() != '(') {
                postfix += (char)s.pop();
            }
            if (!s.isEmpty() && s.peek() == '(') {
                s.pop();
            }
        } else {
            while (!s.isEmpty() && precedence(c) <= precedence(s.peek()) && s.peek() != '(') {
                postfix += (char)s.pop();
            }
            s.push(c);
        }
    }
    while (!s.isEmpty()) {
        postfix += (char)s.pop();
    }
    return postfix;
}

int main() {
    string expr = "(A+B/C*(D+C)-F)";
    cout << "Infix: " << expr << endl;
    cout << "Postfix: " << infixToPostfix(expr) << endl;
    return 0;
}
