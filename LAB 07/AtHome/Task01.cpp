#include <iostream>
using namespace std;

class node {
    public:
        int score;
        string name;
        node* next;
        
        node(string name = "", int score = 0) : name(name), score(score), next(NULL) {}

};
class linkedList{
    public:
        node* head;

        linkedList() : head(NULL) {}

        void addNode(string name, int score){
            node* temp = new node(name, score);
            if (head == NULL)
            {
                head = temp;
                return;
            }
            temp->next = head;
            head = temp;
        }

        int getMax() {
            int mx = head->score;
            node* temp = head->next;
            while (temp) {
                if (temp->score > mx)
                    mx = temp->score;
                temp = temp->next;
            }
            return mx;
        }

        void countSort(int n, int exp) {
            string* names = new string[n];
            int* scores = new int[n];
            string* outputNames = new string[n];
            int* outputScores = new int[n];
            int count[10] = {0};
            node* temp = head;
            int tempCount = 0;
            while (temp != NULL) {
                names[tempCount] = temp->name;
                scores[tempCount] = temp->score;
                temp = temp->next;
                tempCount++;
            }

            for (int i = 0; i < n; i++)
                count[(scores[i] / exp) % 10]++;
                
            for (int i = 1; i < 10; i++)
                count[i] += count[i - 1];

            
            for (int i = n - 1; i >= 0; i--) {
                int digit = (scores[i] / exp) % 10;
                outputScores[count[digit] - 1] = scores[i];
                outputNames[count[digit] - 1] = names[i];
                count[digit]--;
            }

            temp = head;
            for (int i = 0; i < n; i++) {
                temp->score = outputScores[i];
                temp->name = outputNames[i];
                temp = temp->next;
            }
        }

        void radixSort(int n) {
            int m = getMax();
            for (int exp = 1; m / exp > 0; exp *= 10)
                countSort(n, exp);
        }

        void display(){
            node *temp = head;
            while (temp != NULL) {
                cout << temp->name << " " << temp->score << endl;
                temp= temp->next;
            }
        }
};

int main(){
    linkedList s;

    s.addNode("Ayan",90);
    s.addNode("Ali",60);
    s.addNode("Sara",70);
    s.addNode("Zara",50);
    s.addNode("Jeena",40);

    s.radixSort(5);

    cout<<"Sorted student records: \n";
    s.display();
}
