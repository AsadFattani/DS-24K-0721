#include <iostream>
#include <string>
using namespace std;

#define d 256

void rabinKarp(string text, string pattern, int q) {
    int m = pattern.length();
    int n = text.length();

    int p = 0; // hash value for pattern
    int t = 0; // hash value for text
    int h = 1; // multiplier for removing left most digit

    // STEP 1: Calculate h = (d^(m-1)) % q
    // Example for m = 3, d = 256, q = 101
    for (int i = 0; i < m - 1; i++) {
        h = (h * d) % q;
    }

    // STEP 2: Calculate initial hash values for pattern 
    // and first window of text

    for (int i = 0; i < m; i++){
        p = (d * p + pattern[i]) % q;
        t = (d * t + text[i]) % q;
    }

    // STEP 3: Slide the pattern across the text

    for (int i = 0; i <= n - m; i++) {
        if (p == t) {
            int j;
            for (j = 0; j < m; j++) {
                if (text[i + j] != pattern[j]) {
                    break;
                }
            }
            if (j == m) {
                cout << "Pattern found at index " << i << endl;
            }
        }

        // STEP 4: Compute hash value for next window
        // Remove leftmost digit, add rightmost digit

        if (i < n - m) {
            t = (d * (t - text[i] * h) + text[i + m]) % q;
            if (t < 0) {
                t = t + q;
            }
        }
    }
}
