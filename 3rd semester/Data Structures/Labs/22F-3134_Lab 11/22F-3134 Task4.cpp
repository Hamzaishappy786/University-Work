#include <iostream>
using namespace std;
class MinHeap {
private:
    int* heap;
    int capacity;
    int size;
public:
    MinHeap(int capacity) {
        this->capacity = capacity + 1;
        heap = new int[this->capacity];
        size = 0;
    }
    void heapifyDown_smallest(int i) {  //heapifying down for the smallest
        int smallest_index = i;
        int left_child = 2 * i;
        int right_child = 2 * i + 1;
        if (left_child <= size && heap[left_child] < heap[smallest_index]) {    //will compare the left child from smallest index
            smallest_index = left_child;
        }
        if (right_child <= size && heap[right_child] < heap[smallest_index]) {  //will compare the right child from smallest index
            smallest_index = right_child;
        }
        if (i != smallest_index) {
            int temp = heap[i];
            heap[i] = heap[smallest_index];
            heap[smallest_index] = temp;
            heapifyDown_smallest(smallest_index);   //doing it till it anything isn't swapped at all
        }
    }
    void heapifyDown_largest(int i) {   //this is the exact opposite of smallest
        int smallest_index = i;
        int left_child = 2 * i;
        int right_child = 2 * i + 1;
        if (left_child <= size && heap[left_child] > heap[smallest_index]) {    //will compare the left child from largest index
            smallest_index = left_child;
        }
        if (right_child <= size && heap[right_child] > heap[smallest_index]) {      //will compare the left child from largest index
            smallest_index = right_child;
        }
        if (i != smallest_index) {
            int temp = heap[i];
            heap[i] = heap[smallest_index];
            heap[smallest_index] = temp;
            heapifyDown_largest(smallest_index);
        }
    }
    int getMini() { //will just gonna return value from top index
        return heap[1];
    }
    void insert(int data) { //will insert the value
        if (size == capacity - 1) {    //if the heap is full
            cout << "Heap is full.\n";
            return;
        }
        size++;
        int index = size;
        heap[index] = data;
        while (index > 1 && heap[index / 2] > heap[index]) {    //when the parent index is greater than children, it will keep going on
            int temp = heap[index];
            heap[index] = heap[index / 2];  //swapping values for minheap
            heap[index / 2] = temp;
            index = index / 2;  //changing the parent node
        }
    }
    int extractMin() {  //taking out the first value from the heap
        if (size == 0) {
            cout << "Heap is empty.\n";
            return 0;
        }
        int min_element = heap[1];
        heap[1] = heap[size];
        size--; //when the indexes are reversed size becomes small
        heapifyDown_smallest(1); //choosing the smallest by extraction of smallest upward
        return min_element;
    }
    void display() {
        cout << "Heap: ";
        for (int i = 1; i <= size; i++) {
            cout << heap[i] << " ";
        }
        cout << endl;
    }
    void conversionToMaxHeap() {
        for (int i = size / 2; i >= 1; i--) {   //conversion from MaxHeap will happen here
            heapifyDown_largest(i);
        }
    }
    ~MinHeap() {
        delete[]heap;
    }
};
int main() {
    int size, choice;
    int index = 1;
    cout << "Enter the size: "; cin >> size;
    int* arr = new int[size];
    MinHeap heap(size);
    while (true) {
        cout << "\n1.Insert\n";
        cout << "2.Display in MinHeap\n";
        cout << "3.Convert in MaxHeap\n";
        cout << "4.Display in MaxHeap\n";
        cout << "0.Exit\n";
        cout << "Enter your choice: ";  cin >> choice;
        if (choice == 1) {
            if (index <= size) {
                cout << "Enter the data: "; cin >> arr[index];
                heap.insert(arr[index]);
                index++;
            }
            else {
                cout << "Heap is already full.\n";
            }
        }
        else if (choice == 2) {
            heap.display();
        }
        else if (choice == 3) {
            heap.conversionToMaxHeap();
        }
        else if (choice == 4) {
            heap.display();
        }
        else if (choice == 0) {
            cout << "Thank you for using our program.\n";
            break;
        }
    }
	return 0;
}