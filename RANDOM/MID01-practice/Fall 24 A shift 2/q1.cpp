#include <iostream>
using namespace std;

void replaceElement(int arr[], int size){
    int temp[size];
    for (int i = 0; i < size; i++) temp[i] = arr[i];

    // Sort temp array
    for (int i = 0; i < size-1; i++) {
        for (int j = i+1; j < size; j++) {
            if (temp[i] > temp[j]) {
                int t = temp[i];
                temp[i] = temp[j];
                temp[j] = t;
            }
        }
    }

    // Assign ranks
    int ranks[size];
    int rank = 0;
    ranks[0] = rank;
    for (int i = 1; i < size; i++) {
        if (temp[i] != temp[i-1]) rank++;
        ranks[i] = rank;
    }

    // Replace elements in arr with their rank
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (arr[i] == temp[j]) {
                arr[i] = ranks[j];
                break;
            }
        }
    }
}

int main(){
    int arr[] = {12, 5, 8, 5, 15, 8};
    int size = sizeof(arr)/sizeof(arr[0]);
    replaceElement(arr, size);
    for (int i = 0; i < size; i++){
        cout << arr[i] << " ";
    }
    return 0;
}