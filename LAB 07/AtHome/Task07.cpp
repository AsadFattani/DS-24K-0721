#include <iostream>
using namespace std;
const int MAX = 100;

class stack{
    int top;

    public:
        string a[MAX];
        stack() : top(-1) {}

        bool push(string x) {
            if (top >= MAX-1) {
                cout << "Stack Overflow";
                return false;
            } else {
                a[++top] = x;
                return true;
            }
        }

        string pop() {
            if (isEmpty()) {
                cout << "Stack Underflow";
                return "";
            } else {
                string x = a[top--];
                return x;
            }
        }

        string peek() {
            if (isEmpty()) {
                cout << "Stack Empty";
                return "";
            } else {
                string x = a[top];
                return x;
            }
        }

        bool isEmpty() {
            return(top < 0);
        }
};

class node{
    public:
        string url;
        node* next;
        node(string url = "") : url(url), next(nullptr) {}
};

class linkedList{
    public:
        node* head;
        node* tail;

        linkedList() : head(nullptr), tail(nullptr) {}

        void addNode(string url){
            node* temp = new node(url);
            if (head == nullptr) {
                head = temp;
                tail = temp;
                cout << "Visited " << head->url << endl;
                return;
            }
            temp->next = head;
            head = temp;
            cout << "Visited " << head->url << endl;
        }

        void removeNode(){
            if (head == nullptr) {
                cout << "list empty\n";
                return;
            }
            node* temp = head;
            cout << "Going Back From " << temp->url << " to ";
            head = head->next;
            cout << head->url << endl;
            delete temp;
        }
};
int main(){
    //Google -> Facebook -> Twitter -> LinkedIn -> Instagram.
    // AFTER TWO BACKS LAND AT TWITTER NOT AT FACEBOOK
    //Google -> Facebook -> Twitter <- LinkedIn <- Instagram.
    stack HistoryStack;
    linkedList HistoryList;

    HistoryStack.push("Google.com");
    HistoryList.addNode("Google.com");

    HistoryStack.push("Facebook.com");
    HistoryList.addNode("Facebook.com");

    HistoryStack.push("Twitter.com");
    HistoryList.addNode("Twitter.com");

    HistoryStack.push("LinkedIn.com");
    HistoryList.addNode("LinkedIn.com");

    HistoryStack.push("Instagram.com");
    HistoryList.addNode("Instagram.com");
    
    HistoryStack.pop();
    HistoryList.removeNode();

    HistoryStack.pop();
    HistoryList.removeNode();
    
}
