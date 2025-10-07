#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

// Card class
class Card {
public:
    int rank; // 2-14
    char suit; // 'h', 'd', 'c', 's'
    Card(int r = 2, char s = 'c') : rank(r), suit(s) {}
    void print() {
        string rankStr;
        if (rank >= 2 && rank <= 10) rankStr = to_string(rank);
        else if (rank == 11) rankStr = "J";
        else if (rank == 12) rankStr = "Q";
        else if (rank == 13) rankStr = "K";
        else if (rank == 14) rankStr = "A";
        cout << rankStr << suit;
    }
};

// Node for linked list
struct Node {
    Card card;
    Node* next;
    Node(Card c) : card(c), next(nullptr) {}
};

// Linked list for player's hand
class CardList {
public:
    Node* head;
    CardList() : head(nullptr) {}
    // Add card to end
    void addCard(Card c) {
        Node* n = new Node(c);
        if (!head) head = n;
        else {
            Node* temp = head;
            while (temp->next) temp = temp->next;
            temp->next = n;
        }
    }
    // Remove and return first card
    Card removeFirst() {
        if (!head) return Card();
        Node* temp = head;
        Card c = temp->card;
        head = head->next;
        delete temp;
        return c;
    }
    // Add card to front
    void addFront(Card c) {
        Node* n = new Node(c);
        n->next = head;
        head = n;
    }
    // Count cards
    int count() {
        int cnt = 0;
        Node* temp = head;
        while (temp) {
            cnt++;
            temp = temp->next;
        }
        return cnt;
    }
    // Print all cards
    void print() {
        Node* temp = head;
        while (temp) {
            temp->card.print();
            cout << " ";
            temp = temp->next;
        }
        cout << endl;
    }
    // Destructor
    ~CardList() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

// Suit ranking: Clubs > Spades > Hearts > Diamonds
int suitRank(char suit) {
    switch (suit) {
        case 'c': return 4;
        case 's': return 3;
        case 'h': return 2;
        case 'd': return 1;
        default: return 0;
    }
}

// Generate a random card
Card randomCard() {
    int rank = rand() % 13 + 2; // 2-14
    char suits[4] = {'h', 'd', 'c', 's'};
    char suit = suits[rand() % 4];
    return Card(rank, suit);
}

int main() {
    srand(time(0));
    CardList player1, player2;
    int points1 = 0, points2 = 0;

    // Generate 7 unique cards for each player
    for (int i = 0; i < 7; ++i) {
        player1.addCard(randomCard());
        player2.addCard(randomCard());
    }

    cout << "Player 1 cards: "; player1.print();
    cout << "Player 2 cards: "; player2.print();

    for (int round = 1; round <= 7; ++round) {
        cout << "\nRound " << round << ":\n";
        Card c1 = player1.removeFirst();
        Card c2 = player2.removeFirst();
        cout << "Player 1 plays: "; c1.print(); cout << endl;
        cout << "Player 2 plays: "; c2.print(); cout << endl;

        // If any Ace played
        if (c1.rank == 14) {
            cout << "Player 1 played Ace! +5 points\n";
            points1 += 5;
        }
        if (c2.rank == 14) {
            cout << "Player 2 played Ace! +5 points\n";
            points2 += 5;
        }

        if (c1.rank == 14 || c2.rank == 14) continue; // skip rest if Ace played

        if (c1.suit == c2.suit) {
            // Same suit: lowest rank plays next, highest gets 2 points
            if (c1.rank > c2.rank) {
                cout << "Player 1 wins suit match! +2 points\n";
                points1 += 2;
            } else if (c2.rank > c1.rank) {
                cout << "Player 2 wins suit match! +2 points\n";
                points2 += 2;
            } else {
                cout << "Ranks equal, no points.\n";
            }
        } else {
            // Different suits: highest suit rank collects all three cards, loses points
            int sr1 = suitRank(c1.suit), sr2 = suitRank(c2.suit);
            if (sr1 > sr2) {
                cout << "Player 1 wins suit rank, collects both cards, -1 point\n";
                player1.addCard(c1);
                player1.addCard(c2);
                points1 -= 1;
            } else if (sr2 > sr1) {
                cout << "Player 2 wins suit rank, collects both cards, -1 point\n";
                player2.addCard(c1);
                player2.addCard(c2);
                points2 -= 1;
            } else {
                cout << "Suit ranks equal, no points.\n";
            }
        }
    }

    // After 7 rounds, player with more cards loses 3 points
    int cnt1 = player1.count(), cnt2 = player2.count();
    cout << "\nPlayer 1 cards left: " << cnt1 << endl;
    cout << "Player 2 cards left: " << cnt2 << endl;
    if (cnt1 > cnt2) {
        cout << "Player 1 has more cards, -3 points\n";
        points1 -= 3;
    } else if (cnt2 > cnt1) {
        cout << "Player 2 has more cards, -3 points\n";
        points2 -= 3;
    }

    cout << "\nFinal Points:\nPlayer 1: " << points1 << "\nPlayer 2: " << points2 << endl;
    if (points1 > points2) cout << "Player 1 wins!\n";
    else if (points2 > points1) cout << "Player 2 wins!\n";
    else cout << "It's a tie!\n";
}
