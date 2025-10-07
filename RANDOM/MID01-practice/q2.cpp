// question2 
// u have linked list, make sure all priority nodes are served before non priority nodes.
//  if linked list is closed then redirect nodes to open linked list(copy),
//  find max length of every list(compare function)


#include <iostream>
using namespace std;

class Node {
    public:
        int data;
        bool priority;
        Node* next;
        Node (int val, bool prio) : data(val), priority(prio), next(nullptr) {}
};

class LinkedList {
    private:
        Node* head;

    public:
        LinkedList() : head(nullptr) {}

        void addNode(int val, bool prio) {
            Node* newNode = new Node(val, prio);
            if (!head) {
                head = newNode;
                return;
            }
            Node* temp = head;
            while (temp->next && temp->next != head) temp = temp->next;
            temp->next = newNode;
            // If closed, maintain circularity
            if (temp->next && temp->next == head) newNode->next = head;
        }

        // Serve all priority nodes first, then non-priority nodes
        void serveNodes() {
            Node* temp = head;
            // Serve priority nodes
            while (temp) {
                if (temp->priority) cout << temp->data << " ";
                temp = temp->next;
                if (temp == head) break;
            }
            temp = head;
            // Serve non-priority nodes
            while (temp) {
                if (!temp->priority) cout << temp->data << " ";
                temp = temp->next;
                if (temp == head) break;
            }
            cout << endl;
        }

        // Check if list is closed (circular)
        bool isClosed() {
            if (!head) return false;
            Node* temp = head;
            while (temp->next && temp->next != head) temp = temp->next;
            return temp->next == head;
        }

        // Copy nodes to a new open (non-circular) list
        void copyToOpenList(LinkedList& newList) {
            if (!head) return;
            Node* temp = head;
            do {
            newList.addNode(temp->data, temp->priority);
            temp = temp->next;
            } while (temp && temp != head);
        }

        // Get length of list
        int length() {
            int count = 0;
            Node* temp = head;
            if (!head) return 0;
            do {
                count++;
                temp = temp->next;
            } while (temp && temp != head);
            return count;
        }

        // Find max length among multiple lists
        static int compare(LinkedList* lists[], int n) {
            int maxLen = 0;
            for (int i = 0; i < n; ++i) {
                int len = lists[i]->length();
                if (len > maxLen) maxLen = len;
            }
            return maxLen;
        }
};