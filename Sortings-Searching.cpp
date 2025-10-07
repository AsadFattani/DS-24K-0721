#include <iostream>
using namespace std;

// ========================= SORTING ALGORITHMS =========================

// 1. Bubble Sort
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        bool swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if (!swapped) break;
    }
}

// 2. Insertion Sort
void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// 3. Selection Sort
void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex])
                minIndex = j;
        }
        swap(arr[i], arr[minIndex]);
    }
}

// 4. Comb Sort
void combSort(int arr[], int n) {
    int gap = n;
    bool swapped = true;

    while (gap > 1 || swapped) {
        gap = max(1, (gap * 10) / 13); // shrink factor 1.3
        swapped = false;

        for (int i = 0; i + gap < n; i++) {
            if (arr[i] > arr[i + gap]) {
                swap(arr[i], arr[i + gap]);
                swapped = true;
            }
        }
    }
}

// 5. Shell Sort
void shellSort(int arr[], int n) {
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            int temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
                arr[j] = arr[j - gap];
            arr[j] = temp;
        }
    }
}

// ========================= SEARCHING ALGORITHMS =========================

// 1. Linear Search
int linearSearch(int arr[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == key)
            return i;
    }
    return -1;
}

// 2. Binary Search (works only on sorted array)
int binarySearch(int arr[], int n, int key) {
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == key)
            return mid;
        else if (arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

// 3. Interpolation Search (sorted & uniformly distributed array)
int interpolationSearch(int arr[], int n, int key) {
    int low = 0, high = n - 1;
    while (low <= high && key >= arr[low] && key <= arr[high]) {
        if (low == high) {
            if (arr[low] == key) return low;
            return -1;
        }
        int pos = low + ((double)(key - arr[low]) * (high - low)) /
                          (arr[high] - arr[low]);
        if (arr[pos] == key)
            return pos;
        if (arr[pos] < key)
            low = pos + 1;
        else
            high = pos - 1;
    }
    return -1;
}

// ========================= HELPER FUNCTION =========================
void display(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

// ========================= MAIN FUNCTION =========================
int main() {
    int arr[] = {64, 25, 12, 22, 11};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array: ";
    display(arr, n);

    // ======== Sorting Example ========
    shellSort(arr, n); // you can replace with any: bubbleSort, insertionSort, etc.

    cout << "Sorted array: ";
    display(arr, n);

    // ======== Searching Example ========
    int key = 22;

    int index1 = linearSearch(arr, n, key);
    cout << "Linear Search -> ";
    if (index1 != -1) cout << "Found at index " << index1 << endl;
    else cout << "Not found" << endl;

    int index2 = binarySearch(arr, n, key);
    cout << "Binary Search -> ";
    if (index2 != -1) cout << "Found at index " << index2 << endl;
    else cout << "Not found" << endl;

    int index3 = interpolationSearch(arr, n, key);
    cout << "Interpolation Search -> ";
    if (index3 != -1) cout << "Found at index " << index3 << endl;
    else cout << "Not found" << endl;

    return 0;
}
