#include <iostream>
using namespace std;

#define capacity 100

class MaxHeap {
    public:
        int heap[capacity];
        int size;

        MaxHeap() : size(0) {}

        int parent(int i) {return (i - 1)/2;}
        int leftChild(int i) {return 2*i + 1;}
        int rightChild(int i) {return 2*i + 2;}


    void maxHeapify(int i) {
        int largest = i;
        int left = leftChild(i);
        int right = rightChild(i);

        if (left < size && heap[left] > heap[largest]) {
            largest = left;
        }
        if (right < size && heap[right] > heap[largest]) {
            largest = right;
        }

        if (largest != i) {
            swap(heap[i], heap[largest]);
            maxHeapify(largest);
        }
    }

    void insert(int value) {
        if (size == capacity) {
            cout << "Heap is full!!" << endl;
            return;
        }

        cout << "Inserting value: " << value << endl;

        heap[size] = value;
        size++;
        
        int i = size - 1;
        while (i != 0 && heap[parent(i)] < heap[i]) {
            swap(heap[i], heap[parent(i)]);
            i = parent(i);
        }
        printHeap();
    }

    void removeRoot() {
        if (size <= 0) {
            cout << "Heap is empty!!" << endl;
            return;
        }
        if (size == 1) {
            size--;
            return;
        }
        heap[0] = heap[size - 1];
        size--;

        maxHeapify(0);
    }

    void printHeap() {
        cout << "Heap elements: ";
        for (int i = 0; i < size; i++) {
            cout << heap[i] << " ";
        }
        cout << endl;
    }

};

int main() {
    MaxHeap pq;

    pq.insert(50);
    pq.insert(30);
    pq.insert(20);
    pq.insert(15);
    pq.insert(10);
    pq.insert(8);
    pq.insert(16);

    cout << "Removing root (highest priority)..." << endl;
    pq.removeRoot();

    pq.printHeap();

    return 0;
}
