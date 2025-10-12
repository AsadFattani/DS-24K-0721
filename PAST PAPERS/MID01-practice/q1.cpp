// quertion1
// u are given array , apply selection sort and binary search

#include <iostream>
using namespace std;

void selectionSort(int arr[], int n){
    for (int i = 0; i < n - 1; i++){
        int minIdx = i;
        for (int j = i + 1; j < n; j++){
            if (arr[j] < arr[minIdx])
                minIdx = j;
        }
        if (minIdx != i)
            swap(arr[i], arr[minIdx]);
    }
}

int main() {
    int arr[] = {10, 5, 4, 9, 6, 25, 1, 8};
    int length = sizeof(arr)/sizeof(arr[0]);
    selectionSort(arr, length);

    for (int i = 0; i < length; i++){
        cout << arr[i] << ' ';
    }

    return 0;
}

