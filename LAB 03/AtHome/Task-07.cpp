#include <iostream>
using namespace std;

class Node {
    public:
        string data;
        Node *next;

        Node(string t) : data(t), next(nullptr) {}
};  

class RideManagement {
    Node *head;
    Node *tail;
    int totalSeats;

public:
    RideManagement(int n) : head(nullptr), tail(nullptr), totalSeats(n) {
        if (n <= 0) return;
        head = new Node("Seat 1: Available");
        Node *curr = head;
        for (int i = 2; i <= n; ++i) {
            curr->next = new Node("Seat " + to_string(i) + ": Available");
            curr = curr->next;
        }
        tail = curr;
        tail->next = head;
    }

    ~RideManagement() {
        if (!head) return;
        Node *curr = head->next;
        while (curr != head) {
            Node *temp = curr;
            curr = curr->next;
            delete temp;
        }
        delete head;
        tail = nullptr;
    }

    bool reserveSeat(int seatNum) {
        if (!head || seatNum < 1 || seatNum > totalSeats) return false;
        Node *curr = head;
        for (int i = 1; i <= totalSeats; ++i) {
            if (i == seatNum) {
                if (curr->data.find("Available") != string::npos) {
                    curr->data = "Seat " + to_string(seatNum) + ": Reserved";
                    return true;
                } else {
                    return false;
                }
            }
            curr = curr->next;
        }
        return false;
    }

    bool cancelReservation(int seatNum) {
        if (!head || seatNum < 1 || seatNum > totalSeats) return false;
        Node *curr = head;
        for (int i = 1; i <= totalSeats; ++i) {
            if (i == seatNum) {
                if (curr->data.find("Reserved") != string::npos) {
                    curr->data = "Seat " + to_string(seatNum) + ": Available";
                    return true;
                } else {
                    return false;
                }
            }
            curr = curr->next;
        }
        return false;
    }

    void displaySeats() {
        if (!head) {
            cout << "No seats available.\n";
            return;
        }
        Node *curr = head;
        cout << "\n--- Ride Seat Reservations ---\n";
        for (int i = 1; i <= totalSeats; ++i) {
            cout << curr->data << endl;
            curr = curr->next;
        }
    }
};

int main() {
    int n;
    cout << "Enter number of ride seats: ";
    cin >> n;
    RideManagement ride(n);

    int choice, seatNum;
    do {
        cout << "\n1. Reserve Seat\n2. Cancel Reservation\n3. Display Seats\n0. Exit\nEnter choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Enter seat number to reserve: ";
                cin >> seatNum;
                if (ride.reserveSeat(seatNum))
                    cout << "Seat reserved successfully.\n";
                else
                    cout << "Seat reservation failed.\n";
                ride.displaySeats();
                break;
            case 2:
                cout << "Enter seat number to cancel reservation: ";
                cin >> seatNum;
                if (ride.cancelReservation(seatNum))
                    cout << "Reservation cancelled.\n";
                else
                    cout << "Cancellation failed.\n";
                ride.displaySeats();
                break;
            case 3:
                ride.displaySeats();
                break;
            case 0:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice.\n";
        }
    } while (choice != 0);

    return 0;
}



