
#include <iostream>
using namespace std;

const int SIZE = 1009;
struct Pair {
    int a, b;
    bool valid;
    Pair() : a(0), b(0), valid(false) {}
};

int hashFunc(int sum) {
    return (sum % SIZE + SIZE) % SIZE;
}

void findPairsWithEqualSum(const int arr[], int n) {
    Pair hashTable[SIZE];
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            int sum = arr[i] + arr[j];
            int idx = hashFunc(sum);
            while (hashTable[idx].valid && (hashTable[idx].a + hashTable[idx].b != sum)) {
                idx = (idx + 1) % SIZE;
            }
            if (hashTable[idx].valid) {
                if (hashTable[idx].a != arr[i] && hashTable[idx].a != arr[j] && hashTable[idx].b != arr[i] && hashTable[idx].b != arr[j]) {
                    cout << "(" << hashTable[idx].a << ", " << hashTable[idx].b << ") and (" << arr[i] << ", " << arr[j] << ")\n";
                    return;
                }
            } else {
                hashTable[idx].a = arr[i];
                hashTable[idx].b = arr[j];
                hashTable[idx].valid = true;
            }
        }
    }
    cout << "No pairs found\n";
}

int main() {
    int arr1[] = {3, 4, 7, 1, 2, 9, 8};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    findPairsWithEqualSum(arr1, n1);

    int arr2[] = {3, 4, 7, 1, 12, 9};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    findPairsWithEqualSum(arr2, n2);

    int arr3[] = {65, 30, 7, 90, 1, 9, 8};
    int n3 = sizeof(arr3) / sizeof(arr3[0]);
    findPairsWithEqualSum(arr3, n3);
}

