#include <iostream>
#include <ctime>
using namespace std;

class Card {
public:
    int rank; // 2-14
    char suit; // 'h', 'd', 'c', 's'
    Card(int r = 2, char s = 'h') : rank(r), suit(s) {}
    void print() const {
        if (rank >= 2 && rank <= 10) cout << rank;
        else if (rank == 11) cout << "J";
        else if (rank == 12) cout << "Q";
        else if (rank == 13) cout << "K";
        else if (rank == 14) cout << "A";
        cout << suit;
    }
};

struct Node {
    Card card;
    Node* next;
    Node(Card c) : card(c), next(nullptr) {}
};

class LinkedList {
public:
    Node* head;
    Node* tail;
    LinkedList() : head(nullptr), tail(nullptr) {}
    void addCard(Card c) {
        Node* n = new Node(c);
        if (!head) head = tail = n;
        else { tail->next = n; tail = n; }
    }
    Card removeFront() {
        if (!head) return Card();
        Node* temp = head;
        Card c = temp->card;
        head = head->next;
        delete temp;
        if (!head) tail = nullptr;
        return c;
    }
    bool isEmpty() { return head == nullptr; }
    void print() {
        Node* curr = head;
        while (curr) {
            curr->card.print();
            cout << " ";
            curr = curr->next;
        }
        cout << endl;
    }
    int size() {
        int cnt = 0;
        Node* curr = head;
        while (curr) { cnt++; curr = curr->next; }
        return cnt;
    }
};

Card deck[52];
int deckIndex = 0;

void initDeck() {
    int idx = 0;
    char suits[4] = {'h', 'd', 'c', 's'};
    for (int s = 0; s < 4; s++) {
        for (int r = 2; r <= 14; r++) {
            deck[idx++] = Card(r, suits[s]);
        }
    }
}

void shuffleDeck() {
    srand(time(0));
    for (int i = 0; i < 52; i++) {
        int j = rand() % 52;
        Card tmp = deck[i];
        deck[i] = deck[j];
        deck[j] = tmp;
    }
    deckIndex = 0;
}

Card getRandomCard() {
    return deck[deckIndex++];
}

int main() {
    initDeck();
    shuffleDeck();

    LinkedList player1, player2;
    for (int i = 0; i < 5; i++) {
        player1.addCard(getRandomCard());
        player2.addCard(getRandomCard());
    }

    cout << "Player 1 initial hand: "; player1.print();
    cout << "Player 2 initial hand: "; player2.print();

    bool turn = true; // true: player1's turn, false: player2's turn
    while (!player1.isEmpty() && !player2.isEmpty()) {
        Card c1, c2;
        if (turn) {
            c1 = player1.removeFront();
            c2 = player2.removeFront();
            cout << "Player 1 plays: "; c1.print(); cout << " | Player 2 plays: "; c2.print(); cout << endl;
            if (c1.suit == c2.suit) {
                if (c1.rank >= c2.rank) turn = true;
                else turn = false;
            } else {
                // Both cards go to player 1
                player1.addCard(c1);
                player1.addCard(c2);
                turn = true;
            }
        } else {
            c2 = player2.removeFront();
            c1 = player1.removeFront();
            cout << "Player 2 plays: "; c2.print(); cout << " | Player 1 plays: "; c1.print(); cout << endl;
            if (c1.suit == c2.suit) {
                if (c2.rank >= c1.rank) turn = false;
                else turn = true;
            } else {
                // Both cards go to player 2
                player2.addCard(c2);
                player2.addCard(c1);
                turn = false;
            }
        }  
    }

    if (player1.isEmpty()) cout << "Player 1 wins!\n";
    else cout << "Player 2 wins!\n";
}
