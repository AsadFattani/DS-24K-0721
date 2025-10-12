#include <iostream>
using namespace std;

struct Orders {
    string name;
    int value;
    int hanger = 0;
};

void shellSort(Orders arr[], int n){
    for (int gap = n/2; gap > 0; gap /= 2){
        for (int i = gap; i < n; i++){
            Orders temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap].value > temp.value; j -= gap){
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
    }
}

int binarySearch(Orders arr[], int n, int target){
    int left = 0, right = n - 1;
    while (left <= right){
        int mid = left + (right - left) / 2;
        if (arr[mid].hanger == target) return mid;
        else if (arr[mid].hanger < target) left = mid + 1;
        else right = mid - 1;
    }
    return -1;
}

int main() {
    //  we will be using 13th september - 0913 where first 2 digits are months and last 2 are days
    Orders arr[] = { {"joseph", 913}, {"anabella", 814}, {"amna", 1010}, {"omer", 510}, {"usman", 820} };
    int n = sizeof(arr) / sizeof(arr[0]);

    shellSort(arr, n);

    cout << "Sorted array by value:\n";
    for (int i = 0; i < n; ++i) {
        cout << arr[i].name << " " << arr[i].value << endl;
        arr[i].hanger = i + 1;
    }

    int target = 5;
    int idx = binarySearch(arr, n, target);
    if (idx != -1)
        cout << "Hanger " << target << " at index " << idx << " (name: " << arr[idx].name << ")\n";
    else
        cout << "Value " << target << " not found\n";
}


