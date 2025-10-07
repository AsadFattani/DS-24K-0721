#include <iostream>
using namespace std;

#define N 5

bool isPalindrome(const string& s) {
    int l = 0, r = s.size() - 1;
    while (l < r) {
        if (s[l] != s[r]) return false;
        l++; r--;
    }
    return s.size() == 5; // Only consider length >= 3
}

// Collect all palindromes in right and down directions
void searchAll(char arr[N][N], int x, int y, int dx, int dy, string curr, string palindromes[], int& count) {
    if (x < 0 || x >= N || y < 0 || y >= N) return;
    curr += arr[x][y];
    if (isPalindrome(curr)) {
        palindromes[count++] = curr;
    }
    searchAll(arr, x + dx, y + dy, dx, dy, curr, palindromes, count);
}

int main() {
    char arr[N][N] = {
        {'G','R','O','O','T'},
        {'B','A','R','R','O'},
        {'W','D','D','B','S'},
        {'R','A','D','A','R'},
        {'W','E','S','T','G'}
    };

    int dir[2][2] = {
        {0, 1}, // right
        {1, 0}  // down
    };

    string palindromes[10];
    int count = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            for (int d = 0; d < 2; ++d) {
                searchAll(arr, i, j, dir[d][0], dir[d][1], "", palindromes, count);
            }
        }
    }

    if (count > 0) {
        cout << "Palindromes found:\n";
        for (int i = 0; i < count; ++i)
            cout << palindromes[i] << endl;
    } else {
        cout << "no palindromes" << endl;
    }
}



