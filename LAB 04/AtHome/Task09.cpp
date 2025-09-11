#include <iostream>
using namespace std;

void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int temp = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > temp) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp;
    }
}


int interpolationSearch(int arr[], int size, int x) {
    int low = 0, high = size - 1;

    while (low <= high && x >= arr[low] && x <= arr[high]) {
        if (low == high) {
            if (arr[low] == x) return low;
            return -1;
        }
        int pos = low + ((x - arr[low]) * (high - low)) / (arr[high] - arr[low]);

        if (arr[pos] == x) return pos;
        if (arr[pos] < x) low = pos + 1;
        else high = pos - 1;
    }
    return -1;
}

int main() {
    int arr[] = {10, 50, 30, 20, 40};
    int size = sizeof(arr) / sizeof(arr[0]);
    
    insertionSort(arr, size);
    int x = 30;
    int result = interpolationSearch(arr, size, x);
    if (result != -1)
        cout << "Element found at index: " << result << endl;
    else
        cout << "Element not found in array" << endl;
    return 0;
}
