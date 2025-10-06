#include <iostream>
#include <ctime>
using namespace std;


void playGame(int secretNumber, int player) {
    int guess;
    cout << "Player " << player << ", enter your guess (1-100): ";
    cin >> guess;

    if (guess == secretNumber) {
        cout << "Congratulations! Player " << player << " wins!" << endl;
        return;
    } else if (guess < secretNumber) {
        cout << "Too low!" << endl;
    } else {
        cout << "Too high!" << endl;
    }
    playGame(secretNumber, player == 1 ? 2 : 1);
}


int main() {
    srand(time(0));
    int secretNumber = rand() % 100 + 1;
    cout << "Welcome to the Number Guessing Game!" << endl;
    playGame(secretNumber, 1);
    return 0;
}

