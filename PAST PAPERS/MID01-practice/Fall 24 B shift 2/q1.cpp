#include <iostream>
using namespace std;

// Helper function to sort an array in descending order
void sortDesc(int arr[], int n) {
    for (int i = 0; i < n-1; ++i) {
        for (int j = i+1; j < n; ++j) {
            if (arr[i] < arr[j]) {
                int tmp = arr[i];
                arr[i] = arr[j];
                arr[j] = tmp;
            }
        }
    }
}

// Helper function to sort an array in ascending order
void sortAsc(int arr[], int n) {
    for (int i = 0; i < n-1; ++i) {
        for (int j = i+1; j < n; ++j) {
            if (arr[i] > arr[j]) {
                int tmp = arr[i];
                arr[i] = arr[j];
                arr[j] = tmp;
            }
        }
    }
}

// arr1: input array, n1: size of arr1
// arr2: frequency array, n2: size of arr2
void customSort(int arr1[], int n1, int arr2[], int n2, int result[], int &resSize) {
    bool used[7] = {false}; // 7 is the size of arr1 in main
    int arr2Sorted[3];      // 3 is the size of arr2 in main
    for (int i = 0; i < n2; ++i) arr2Sorted[i] = arr2[i];
    sortDesc(arr2Sorted, n2);

    resSize = 0;

    // For each value in sorted arr2, copy all its occurrences from arr1
    for (int i = 0; i < n2; ++i) {
        int val = arr2Sorted[i];
        for (int j = 0; j < n1; ++j) {
            if (arr1[j] == val && !used[j]) {
                result[resSize++] = val;
                used[j] = true;
            }
        }
    }

    // Collect remaining values from arr1 not in arr2
    int remaining[7], remSize = 0;
    for (int j = 0; j < n1; ++j) {
        if (!used[j]) {
            remaining[remSize++] = arr1[j];
        }
    }
    // Sort remaining values in ascending order
    sortAsc(remaining, remSize);

    // Add remaining values to result
    for (int i = 0; i < remSize; ++i) {
        result[resSize++] = remaining[i];
    }
}

int main() {
    int arr1[7] = {5, 3, 5, 2, 3, 4, 2};
    int arr2[3] = {3, 5, 2};
    int n1 = 7, n2 = 3;
    int result[7], resSize;

    customSort(arr1, n1, arr2, n2, result, resSize);
    cout << "Output 1: ";
    for (int i = 0; i < resSize; ++i) cout << result[i] << " ";
    cout << endl;

    int arr3[7] = {5, 3, 5, 2, 3, 4, 2};
    int arr4[2] = {5, 2};
    int n3 = 7, n4 = 2;
    int result2[7], resSize2;

    customSort(arr3, n3, arr4, n4, result2, resSize2);
    cout << "Output 2: ";
    for (int i = 0; i < resSize2; ++i) cout << result2[i] << " ";
    cout << endl;

    return 0;
}
