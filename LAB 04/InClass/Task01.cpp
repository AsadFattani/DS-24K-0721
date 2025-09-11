#include <iostream>
using namespace std;

void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIdx])
                minIdx = j;
        }
        if (minIdx != i)
            swap(arr[i], arr[minIdx]);
    }
}

int main() {
    int n;
    cout << "Enter number of crates: ";
    cin >> n;
    int* crates = new int[n];
    cout << "Enter shipping times for each crate:\n";
    for (int i = 0; i < n; ++i) {
        cout << "Crate " << (i + 1) << ": ";
        cin >> crates[i];
    }

    selectionSort(crates, n);

    cout << "Crates sorted by shipping time:\n";
    for (int i = 0; i < n; ++i) {
        cout << crates[i] << " ";
    }
    cout << endl;

    delete[] crates;
    return 0;
}