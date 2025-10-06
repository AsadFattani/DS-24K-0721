#include <iostream>
using namespace std;

void printArray(int arr[], int n){
    for (int i = 0; i < n; i++) {
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
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
            cout << "Step " << ++k << endl;
            printArray(arr, n);
        }
    }
}

int main(){
    int weights[] = {32, 25, 40, 12, 18, 50, 28};
    int n = sizeof(weights) / sizeof(weights[0]);
    
    cout << "Step 0" << endl;
    printArray(weights, n);
    shellSort(weights, n);

    return 0;
}