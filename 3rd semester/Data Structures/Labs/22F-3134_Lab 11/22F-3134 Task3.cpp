#include <iostream>
using namespace std;
class MaxHeap {
private:
    int* heap;
    int size;
    int capacity;

public:
    //default constructor
    MaxHeap() { //it was displaying error, therefore i made it
        heap = nullptr;
        size = 0;
        capacity = 0;
    }
    //parameterized constructor
    MaxHeap(int capacity) { //this was the actual one required for the job done
        this->capacity = capacity + 1;
        heap = new int[this->capacity];
        size = 0;
    }
    void insert(int data) { //insertion
        if (size == capacity - 1) { //full check
            cout << "Heap is full.\n";
            return;
        }
        size++; //index increment
        int index = size;
        heap[index] = data;
        while (index > 1 && heap[index / 2] < heap[index]) {    //comparing parent and child elements
            int temp = heap[index];
            heap[index] = heap[index / 2];
            heap[index / 2] = temp;
            index = index / 2;  //going towards parents
        }
    }
    int get_size() {    //will return size
        return size;
    }
    void display() {    //will print out heap
        for (int i = 1; i <= size; i++) {
            cout << heap[i] << " ";
        }
        cout << endl;
    }
};

struct BST {
    int data;
    BST* left;
    BST* right;

    BST(int data) {
        this->data = data;
        left = nullptr;
        right = nullptr;
    }
};
class Tree {
    BST* root;
    MaxHeap heap;
public:
    Tree() {
        root = nullptr;
    }
    BST* getRoot() {
        return root;
    }
    void insertNode(int data) { //insertion in trees
        BST* newNode = new BST(data);   //will start from here
        BST* temp = root;
        if (temp == nullptr) {
            root = newNode;
        }
        else {
            while (true) {
                if (data > temp->data) {    //will go to right
                    if (temp->right) {
                        temp = temp->right;
                    }
                    else {
                        temp->right = newNode;
                        break;
                    }
                }
                else {
                    if (temp->left) {   //else will go to left
                        temp = temp->left;
                    }
                    else {
                        temp->left = newNode;
                        break;
                    }
                }
            }
        }
    }
    void printInOrder(BST* temp, MaxHeap& heap) {
        if (temp == nullptr) {
            return;
        }
        else {
            printInOrder(temp->left, heap);
            heap.insert(temp->data);
            printInOrder(temp->right, heap);
        }
    }

    void convertBSTtoMaxHeap(int size) {
        MaxHeap heap(size);  //initializing MaxHeap with specific capacity sent by user himself
        cout << "BST elements (inorder traversal): ";
        printInOrder(root, heap);
        cout << endl;
        cout << "Max-Heap elements: ";
        heap.display(); //lastly displaying elements in MaxHeap
    }
};
int main() {
    int choice, size;
    Tree myBST;
    cout << "Enter the size of the heap: ";
    cin >> size;

    while (true) {
        cout << "\nMain Menu:\n";
        cout << "1. Insert element into BST\n";
        cout << "2. Convert BST to Max Heap\n";
        cout << "0. Quit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            int data;
            cout << "Enter an element for the BST: ";
            cin >> data;
            myBST.insertNode(data);
        }
        else if (choice == 2) {
            myBST.convertBSTtoMaxHeap(size);
        }
        else if (choice == 0) {
            cout << "Exiting the program." << endl;
            break;
        }
        else {
            cout << "Invalid choice. Please try again." << endl;
        }
    }
    return 0;
}