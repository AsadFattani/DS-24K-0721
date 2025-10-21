#include <iostream>
using namespace std;

class Runner {
public:
    string name;
    int time;

    Runner() {}
    Runner(string n, int t) {
        name = n;
        time = t;
    }

    void input(int idx) {
        cout << "Enter name and finish time for runner " << idx + 1 << ": ";
        cin >> name >> time;
    }
};

void merge(Runner arr[], int l, int m, int r) {
    int i = l, j = m + 1, k = l;
    Runner temp[10];
    while(i <= m && j <= r) {
        if(arr[i].time <= arr[j].time) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
        }
    }
    while(i <= m) {
        temp[k++] = arr[i++];
    }
    while(j <= r) {
        temp[k++] = arr[j++];
    }
    for(int s = l; s <= r; s++) {
        arr[s] = temp[s];
    }
}

void mergesort(Runner arr[], int l, int r) {
    if(l < r) {
        int m = l + (r - l) / 2;
        mergesort(arr, l, m);
        mergesort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

int main(){
    const int n = 10;
    Runner arr[n];
    for(int i = 0; i < n; ++i) {
        arr[i].input(i);
    }

    mergesort(arr, 0, n - 1);

    cout << "\nTop 5 fastest runners:\n";
    for(int i = 0; i < 5 && i < n; ++i) {
        cout << i + 1 << ". " << arr[i].name << " - " << arr[i].time << " seconds\n";
    }
}


