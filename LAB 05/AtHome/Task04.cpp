#include <iostream>
using namespace std;

const int MAX_N = 25; // Maximum board size

void printBoard(char board[MAX_N][MAX_N], int N) {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

bool isSafe(char board[MAX_N][MAX_N], int row, int col, int N) {
    // Check column
    for (int i = 0; i < row; ++i)
        if (board[i][col] == 'Q')
            return false;
    // Check upper left diagonal
    for (int i = row-1, j = col-1; i >=0 && j >=0; --i, --j)
        if (board[i][j] == 'Q')
            return false;
    // Check upper right diagonal
    for (int i = row-1, j = col+1; i >=0 && j < N; --i, ++j)
        if (board[i][j] == 'Q')
            return false;
    return true;
}

bool solveNQueens(char board[MAX_N][MAX_N], int row, int N, bool &foundOne, int &solutionCount) {
    if (row == N) {
        solutionCount++;
        if (!foundOne) {
            cout << "One valid board configuration:\n";
            printBoard(board, N);
            foundOne = true;
        }
        return false;
    }
    for (int col = 0; col < N; ++col) {
        if (isSafe(board, row, col, N)) {
            board[row][col] = 'Q';
            solveNQueens(board, row+1, N, foundOne, solutionCount);
            board[row][col] = '.'; // backtrack
        }
    }
    return false;
}

int main() {
    int N;
    cout << "Enter the value of N (size of chessboard, max " << MAX_N << "): ";
    cin >> N;
    if (N < 1 || N > MAX_N) {
        cout << "Invalid N.\n";
        return 1;
    }

    char board[MAX_N][MAX_N];
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            board[i][j] = '.';

    bool foundOne = false;
    int solutionCount = 0;
    solveNQueens(board, 0, N, foundOne, solutionCount);

    cout << "Total number of distinct solutions for N = " << N << " is: " << solutionCount << endl;

    return 0;
}
