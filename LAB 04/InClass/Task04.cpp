#include <iostream>
using namespace std;

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

int main() {
    int arr[] = {10, 2, 0, 14, 43, 25, 18, 1, 5, 45};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Original array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << "  ";
    }
    bubbleSort(arr, n);
    cout << "\nSorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << "  ";
    }

}

