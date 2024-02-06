//#include <iostream>
//using namespace std;
//
//class MinHeap {
//private:
//    int capacity;
//    int size;
//    int* heap;
//
//public:
//    explicit MinHeap(int size) : size(0), capacity(size) {
//        heap = new int[size + 1]; // +1 for 1-based indexing
//    }
//
//    void insert(int data) {
//        if (size == capacity) {
//            cout << "Heap full.\n";
//            return;
//        }
//        size++;
//        heap[size] = data;
//        heapifyUp(size);
//    }
//
//    void heapifyUp(int index) {
//        while (index > 1) {
//            int parent_index = index / 2;
//            if (heap[index] < heap[parent_index]) {
//                int temp = heap[index];
//                heap[index] = heap[parent_index];
//                heap[parent_index] = temp;
//                index = parent_index;
//            }
//            else {
//                break;
//            }
//        }
//    }
//
//    void heapifyDown(int index) {
//        int left_child = 2 * index;
//        int right_child = 2 * index + 1;
//        int smallest = index;
//
//        if (left_child <= size && heap[left_child] < heap[smallest]) {
//            smallest = left_child;
//        }
//
//        if (right_child <= size && heap[right_child] < heap[smallest]) {
//            smallest = right_child;
//        }
//
//        if (index != smallest) {
//            int temp = heap[index];
//            heap[index] = heap[smallest];
//            heap[smallest] = temp;
//            heapifyDown(smallest);
//        }
//    }
//
//    int extractMin() {
//        if (size == 0) {
//            cout << "Heap is empty.";
//            return 0;
//        }
//        int min = heap[1];
//        heap[1] = heap[size];
//        size--;
//        heapifyDown(1);
//        return min;
//    }
//
//    void display() {
//        for (int i = 1; i <= size; i++) {
//            cout << heap[i] << " ";
//        }
//        cout << endl;
//    }
//
//    ~MinHeap() {
//        delete[] heap;
//    }
//};
//
//int main() {
//    MinHeap minheap(5);
//    minheap.insert(2);  minheap.insert(4);  minheap.insert(6);  minheap.insert(8);  minheap.insert(10);
//    minheap.display();
//    return 0;
//}
//class MaxHeap {
//private:
//    int size;
//    int capacity;
//    int* heap;
//
//    void heapifyUp(int index) {
//        while (index > 1) {
//            int parent_index = index / 2;
//            if (heap[index] < heap[parent_index]) {
//                int temp = heap[index];
//                heap[index] = heap[parent_index];
//                heap[parent_index] = temp;
//                index = parent_index;
//            }
//            else {
//                break;
//            }
//        }
//    }
//    void heapifyDown(int index) {
//        int left_child = 2 * index;
//        int right_child = 2 * index + 1;
//        int largest = index;
//
//        if (left_child <= largest && heap[left_child] > heap[largest]) {
//            left_child = largest;
//        } else if (right_child <= largest && heap[right_child] > heap[largest]) {
//            right_child = largest;
//        }
//
//        while (largest != index) {
//            int temp = heap[largest];
//            heap[largest] = heap[index];
//            heap[index] = temp;
//            heapifyDown(largest);
//        }
//    }
//
//public:
//    MaxHeap(int cap) : size(0), capacity(cap) {
//        heap = new int[capacity + 1]; // +1 for 1-based indexing
//    }
//
//    ~MaxHeap() {
//        delete[] heap;
//    }
//
//    void insert(int data) {
//        if (size == capacity) {
//            cout << "Heap already full." << endl;
//            return;
//        }
//
//        size++;
//        heap[size] = data;
//        heapifyUp(size);
//    }
//
//    void display() {
//        for (int i = 1; i <= size; i++) {
//            cout << heap[i] << " ";
//        }
//        cout << endl;
//    }
//
//    int extractMax() {
//        if (size == 0) {
//            cout << "Heap is empty." << endl;
//            return -1;
//        }
//
//        int max = heap[1];
//        heap[1] = heap[size];
//        size--;
//        heapifyDown(1);
//        return max;
//    }
//};
//
//int main() {
//    MaxHeap maxheap(5);
//    maxheap.insert(2);  maxheap.insert(4);  maxheap.insert(6);  maxheap.insert(8);  maxheap.insert(10);
//    maxheap.display();
//    int extractedMax = maxheap.extractMax();
//    cout << "Extracted Max: " << extractedMax << endl;
//    maxheap.display();
//
//    return 0;
//}