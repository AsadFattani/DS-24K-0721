#include <iostream>
using namespace std;

void merge(int mymarra[], int l, int m, int r){
    int i = l, j = m + 1, k = l;
    int temp[5];
    while(i <= m && j <= r){
        if(mymarra[i] < mymarra[j]){
            temp[k++] = mymarra[i++];
        }
        else{
            temp[k++] = mymarra[j++];
        }
    }
    while(i <= m){
        temp[k++] = mymarra[i++];
    }
    while(j <= r){
        temp[k++] = mymarra[j++];
    }
    for(int s = l; s <= r; s++){
        mymarra[s] = temp[s];
    }
}

void mergesort(int mymarra[], int l, int r){
    if(l < r){
        int mid = l + (r - l) / 2;
        mergesort(mymarra, l, mid);
        mergesort(mymarra, mid + 1, r);
        merge(mymarra, l, mid, r);
    }
}

int main() {
    int mymarra[] = {38, 27, 43, 3, 9, 82, 10};
    int arrsize = sizeof(mymarra) / sizeof(mymarra[0]);
    mergesort(mymarra, 0, arrsize - 1);
    cout << "Sorted array: ";
    for(int i = 0; i < arrsize; i++){
        cout << mymarra[i] << " ";
    }
    cout << endl;
}




