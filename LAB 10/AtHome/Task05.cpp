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

    void removeMax() {
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

    void updatePriority(int i, int newPriority) {
        if (i < 0 || i >= size) {
            cout << "Invalid index!" << endl;
            return;
        }
        int oldPriority = heap[i];
        heap[i] = newPriority;
        if (newPriority > oldPriority) {
            while (i != 0 && heap[parent(i)] < heap[i]) {
                swap(heap[i], heap[parent(i)]);
                i = parent(i);
            }
        } else if (newPriority < oldPriority) {
            maxHeapify(i);
        }
        printHeap();
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

    pq.insert(40);
    pq.insert(20);
    pq.insert(60);
    pq.insert(10);
    pq.insert(50);

    cout << "Processing (removing) highest priority task..." << endl;
    pq.removeMax();
    pq.printHeap();

    cout << "Updating priority of task at index 2 to 70..." << endl;
    pq.updatePriority(2, 70);

    cout << "Updating priority of task at index 1 to 5..." << endl;
    pq.updatePriority(1, 5);

    cout << "Final heap:" << endl;
    pq.printHeap();

    return 0;
}
