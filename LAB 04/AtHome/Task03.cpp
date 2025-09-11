#include <iostream>
#include <ctime>
using namespace std;

void PrintArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void bubbleSort(int arr[], int n) {
    int comparisons = 0;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1; j++) {
            comparisons++;
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
    cout << "\nNumber of comparisons: " << comparisons << endl;
    cout << "Sorted array (Bubble Sort): ";
    PrintArray(arr, n);
}

void insertionSort(int arr[], int n) {
    int comparisons = 0;
    for (int i = 1; i < n; i++) {
        int temp = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > temp) {
            comparisons++;
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp;
    }
    cout << "\nNumber of comparisons: " << comparisons << endl;
    cout << "Sorted array (Insertion Sort): ";
    PrintArray(arr, n);
}

void selectionSort(int arr[], int n) {
    int comparisions = 0;
    for (int i = 0; i < n - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < n; j++) {
            comparisions++;
            if (arr[j] < arr[minIdx])
                minIdx = j;
        }
        if (minIdx != i)
            swap(arr[i], arr[minIdx]);
    }
    cout << "\nNumber of comparisons: " << comparisions << endl;
    cout << "Sorted array (Selection Sort): ";
    PrintArray(arr, n);
}

void shellSort(int arr[], int n) {
    int comparisons = 0;
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++){
            int temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                comparisons++;
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
    }
    cout << "\nNumber of comparisons: " << comparisons << endl;
    cout << "Sorted array (Shell Sort): ";
    PrintArray(arr, n);
}

int main() {
    srand(time(0));
    const int size = 20;
    int array1[size];
    for (int i = 0; i < size; i++) {
        array1[i] = rand() % 100;
    }
    cout << "Original array: ";
    PrintArray(array1, size);
    int arr1[size], arr2[size], arr3[size], arr4[size];
    copy(array1, array1 + size, arr1);
    copy(array1, array1 + size, arr2);
    copy(array1, array1 + size, arr3);
    copy(array1, array1 + size, arr4);
    bubbleSort(arr1, size);
    insertionSort(arr2, size);
    selectionSort(arr3, size);
    shellSort(arr4, size);
    
    cout << "\n\n";
    
    const int size2 = 100;
    int array2[size2];
    for (int i = 0; i < size2; i++) {
        array2[i] = rand() % 100;
    }
    cout << "Original array: ";
    PrintArray(array2, size2);
    int arr5[size2], arr6[size2], arr7[size2], arr8[size2];
    copy(array2, array2 + size2, arr5);
    copy(array2, array2 + size2, arr6);
    copy(array2, array2 + size2, arr7);
    copy(array2, array2 + size2, arr8);
    bubbleSort(arr5, size2);
    insertionSort(arr6, size2);
    selectionSort(arr7, size2);
    shellSort(arr8, size2);
    
    
    return 0;
}





