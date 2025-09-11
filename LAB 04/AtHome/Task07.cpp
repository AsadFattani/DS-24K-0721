#include <iostream>
using namespace std;

void combSort(int arr[], int n) {
    float shrink = 1.3;
    int gap = n;
    bool swapped = true;

    while (gap > 1 || swapped) {
        gap = (int)gap / shrink;
        if (gap < 1) gap = 1;
        swapped = false;
        for (int i = 0; i + gap < n; i++) {
            if (arr[i] > arr[i + gap]) {
                swap(arr[i], arr[i + gap]);
                swapped = true;
            }
        }
    }
}

int main() {
    int arr[] = { 2, 4, 5, 1, 6, 9, 7, 3, 8 };
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Original array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    combSort(arr, n);
    cout << "\nSorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
}




