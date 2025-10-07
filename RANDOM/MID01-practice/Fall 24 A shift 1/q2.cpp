#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    string data; // can be number, operator, or bracket
    Node* next;
    Node* prev;
    Node(string d) : data(d), next(nullptr), prev(nullptr) {}
};

class LinkedList {
public:
    Node* head;
    LinkedList() : head(nullptr) {}

    void append(string d) {
        Node* n = new Node(d);
        if (!head) {
            head = n;
            return;
        }
        Node* curr = head;
        while (curr->next) curr = curr->next;
        curr->next = n;
        n->prev = curr;
    }

    // Evaluate the linked list expression
    int evaluate() {
        return eval(head, nullptr);
    }

private:
    // Helper to evaluate from 'start' to 'end' (exclusive)
    int eval(Node* start, Node* end) {
        // First, handle brackets recursively
        Node* curr = start;
        while (curr != end) {
            if (curr->data == "(") {
                // Find matching ')'
                Node* open = curr;
                int cnt = 1;
                Node* close = curr->next;
                while (close != end && cnt > 0) {
                    if (close->data == "(") cnt++;
                    else if (close->data == ")") cnt--;
                    close = close->next;
                }
                int val = eval(open->next, close->prev);
                // Replace bracketed part with value
                open->data = to_string(val);
                // Remove nodes between open and close
                Node* temp = open->next;
                while (temp != close) {
                    Node* del = temp;
                    temp = temp->next;
                    delete del;
                }
                open->next = close;
                if (close) close->prev = open;
                curr = open;
            }
            curr = curr->next;
        }
        // Now, evaluate *, then +/-
        // First pass: multiplication
        curr = start;
        while (curr != end) {
            if (curr->data == "multiply" || curr->data == "*") {
                int left = stoi(curr->prev->data);
                int right = stoi(curr->next->data);
                int res = left * right;
                curr->prev->data = to_string(res);
                // Remove curr and curr->next
                Node* del1 = curr;
                Node* del2 = curr->next;
                curr->prev->next = del2->next;
                if (del2->next) del2->next->prev = curr->prev;
                curr = curr->prev;
                delete del1;
                delete del2;
            } else {
                curr = curr->next;
            }
        }
        // Second pass: addition and subtraction
        curr = start;
        while (curr != end) {
            if (curr->data == "add" || curr->data == "+") {
                int left = stoi(curr->prev->data);
                int right = stoi(curr->next->data);
                int res = left + right;
                curr->prev->data = to_string(res);
                Node* del1 = curr;
                Node* del2 = curr->next;
                curr->prev->next = del2->next;
                if (del2->next) del2->next->prev = curr->prev;
                curr = curr->prev;
                delete del1;
                delete del2;
            } else if (curr->data == "minus" || curr->data == "-") {
                int left = stoi(curr->prev->data);
                int right = stoi(curr->next->data);
                int res = left - right;
                curr->prev->data = to_string(res);
                Node* del1 = curr;
                Node* del2 = curr->next;
                curr->prev->next = del2->next;
                if (del2->next) del2->next->prev = curr->prev;
                curr = curr->prev;
                delete del1;
                delete del2;
            } else {
                curr = curr->next;
            }
        }
        // Only one node left with the result
        return stoi(start->data);
    }
};

int main() {
    // Example: 10 -> add -> ( -> 12 -> multiply -> ( -> 2 -> minus -> 2 -> ) -> ) -> NULL
    LinkedList ll;
    ll.append("10");
    ll.append("add");
    ll.append("(");
    ll.append("12");
    ll.append("multiply");
    ll.append("(");
    ll.append("2");
    ll.append("minus");
    ll.append("2");
    ll.append(")");
    ll.append(")");
    cout << "Answer: " << ll.evaluate() << endl;
    return 0;
}
