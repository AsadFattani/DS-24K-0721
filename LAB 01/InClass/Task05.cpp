#include <iostream>
#include <string>
using namespace std;

int main() {
    string name;
    int Id, xp;
    cout << "Enter librarian name: ";
    getline(cin, name);
    cout << "Enter librarian ID: ";
    cin >> Id;
    cout << "Enter years of experience: ";
    cin >> xp;

    cout << "\n--- Librarian Details ---\n";
    cout << "Name: " << name << endl;
    cout << "ID: " << Id << endl;
    cout << "Experience: " << xp << endl;

    const int fixedCount = 3;
    int fixedBookIDs[fixedCount] = {101, 102, 103};
    cout << "\n--- Fixed Book IDs ---\n";
    for (int i = 0; i < fixedCount; i++) {
        cout << fixedBookIDs[i] << " ";
    }
    cout << endl;

    int newBooks;
    cout << "\nHow many new books are being added? ";
    cin >> newBooks;

    int* newBookIDs = new int[newBooks];
    cout << "Enter IDs for new books:\n";
    for (int i = 0; i < newBooks; i++) {
        cout << "Book " << (i + 1) << " ID: ";
        cin >> newBookIDs[i];
    }

    cout << "\n--- New Book IDs ---\n";
    for (int i = 0; i < newBooks; i++) {
        cout << newBookIDs[i] << " ";
    }
    cout << endl;

    delete[] newBookIDs;
    return 0;
}
