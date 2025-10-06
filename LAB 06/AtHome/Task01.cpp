#include <iostream>
using namespace std;

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

void shellSort(int arr[], int n) {
    int k = 0;
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            int temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j -gap];
            }
            arr[j] = temp;
            cout << "Step " << ++k << endl;
            printArray(arr, n);
        }
    }
}

int main() {
    int bookID[] = {205, 102, 310, 450, 120, 90};
    int n = sizeof(bookID) / sizeof(bookID[0]);

    cout << "Step 0" << endl;
    printArray(bookID, n);
    shellSort(bookID, n);
    return 0;
    
}

