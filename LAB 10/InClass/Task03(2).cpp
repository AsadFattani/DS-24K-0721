#include <iostream>
using namespace std;

#define capacity 100

class MinHeap {
    public:
        int heap[capacity];
        int size;

        MinHeap() : size(0) {}

        int parent(int i) {return (i - 1)/2;}
        int leftChild(int i) {return 2*i + 1;}
        int rightChild(int i) {return 2*i + 2;}


    void minHeapify(int i) {
        int smallest = i;
        int left = leftChild(i);
        int right = rightChild(i);

        if (left < size && heap[left] < heap[smallest]) {
            smallest = left;
        }
        if (right < size && heap[right] < heap[smallest]) {
            smallest = right;
        }

        if (smallest != i) {
            swap(heap[i], heap[smallest]);
            minHeapify(smallest);
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
        while (i != 0 && heap[parent(i)] > heap[i]) {
            swap(heap[i], heap[parent(i)]);
            i = parent(i);
        }
        printHeap();
    }

    void deleteVal(int val) {
        int i;
        for (i = 0; i < size; i++) {
            if (val == heap[i])
                break;
        }

        if (i == size) {
            cout << "Value not found in heap!" << endl;
            return;
        }

        heap[i] = heap[size - 1];
        size--;
        minHeapify(i);
    }

    void removeMin() {
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

        minHeapify(0);
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
    MinHeap minheap;
    minheap.insert(25);
    minheap.insert(30);
    minheap.insert(35);
    minheap.insert(11);
    minheap.insert(15);
    minheap.insert(19);
    minheap.insert(18);
    minheap.insert(55);
    minheap.insert(78);
    minheap.insert(36);

    minheap.deleteVal(18);
    minheap.printHeap();

    return 0;
}
