#include <iostream>
using namespace std;

int getMax(int arr[], int n) {
    int maxVal = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > maxVal)
            maxVal = arr[i];
    return maxVal;
}

void countingSort(int arr[], int n, int exp) {
    int output[20];
    int count[10] = {0};

    for (int i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;

    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];

    for (int i = n - 1; i >= 0; i--) {
        int digit = (arr[i] / exp) % 10;
        output[count[digit] - 1] = arr[i];
        count[digit]--;
    }

    for (int i = 0; i < n; i++)
        arr[i] = output[i];
}

void radixSort(int arr[], int n) {
    int maxVal = getMax(arr, n);
    for (int exp = 1; maxVal / exp > 0; exp *= 10)
        countingSort(arr, n, exp);
}

int main() {
    int arr1[10] = {25, 47, 3, 19, 8, 18, 89, 2, 54, 33};
    int arr2[10] = {11, 76, 92, 41, 5, 60, 7, 100, 55, 13};
    int combined[20];

    for (int i = 0; i < 10; i++)
        combined[i] = arr1[i];
    for (int i = 0; i < 10; i++)
        combined[i + 10] = arr2[i];

    radixSort(combined, 20);

    cout << "Sorted array using Radix Sort:\n";
    for (int i = 0; i < 20; i++)
        cout << combined[i] << " ";
    cout << endl;

    return 0;
}
