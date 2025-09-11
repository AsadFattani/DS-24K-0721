#include <iostream>
using namespace std;

void shellSort(int arr[], int n) {
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++){
            int temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
    }
}

int binarySearch(int arr[], int size, int key) {
    int left = 0, right = size - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == key) {
            return mid;
        } else if (arr[mid] < key) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;
}


int main() {
    int size;
    cout << "Enter the number of elements: ";
    cin >> size;
    int* arr = new int[size];
    cout << "Enter the elements:-\n";
    for (int i = 0; i < size; i++) {
        cout << "Element " << i + 1 << ": ";
        cin >> arr[i];
    }
    shellSort(arr, size);
    cout << "Sorted array: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << "\nEnter the element to search: ";
    int key;
    cin >> key;
    int result = binarySearch(arr, size, key);
    if (result != -1)
        cout << "Element found at index: " << result << endl;
    else
        cout << "Element not found in array" << endl;
    
    delete[] arr;
    return 0;
}


