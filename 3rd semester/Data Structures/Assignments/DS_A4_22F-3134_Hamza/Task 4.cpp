#include <iostream>
using namespace std;

struct Node {
    int key;
    Node* next;

    Node(int k) { key = k;  next = nullptr; }
};

class ChainingHashTable {
private:
    Node** table;
    int capacity;
    int size;
    float load_factor = 0.7;

public:
    ChainingHashTable() {
        capacity = 10;
        size = 0;
        table = new Node * [capacity] { nullptr };
    }

    int hashFunction(int key) {
        return key % capacity;
    }

    void insert(int key) {
        float loadFactor = float(size / capacity);
        if (loadFactor >= load_factor) {
        }

        int index = hashFunction(key);
        if (table[index] == nullptr) {
            table[index] = new Node(key);
        }
        else {
            Node* newNode = new Node(key);
            newNode->next = table[index];
            table[index] = newNode;
        }
        size++;
    }
    void display() {
        for (int i = 0; i < capacity; i++) {
            cout << i << ": ";
            Node* current = table[i];
            while (current != nullptr) {
                cout << current->key;
                if (current->next != nullptr) {
                    cout << " -> ";
                }
                current = current->next;
            }
            cout << " -> EMPTY" << endl;
        }
    }
};

class BucketingHashTable {
private:
    int** table;
    int capacity;
    int size;
    float load_factor = 0.7;
    int num_buckets = 3;

public:
    BucketingHashTable() {
        capacity = 15;
        size = 0;
        table = new int* [capacity];
        for (int i = 0; i < capacity; i++) {
            table[i] = new int[num_buckets] { -1, -1, -1 };
        }
    }

    int hashFunction(int key) {
        return key % capacity;
    }

    void insert(int key) {
        float loadFactor = float(size) / capacity;
        if (loadFactor >= load_factor) {
            rehash();
        }

        int index = hashFunction(key);
        int* bucket = table[index];
        int i = 0;
        bucket[i] = key;

        size++;
    }

    void rehash() {
        int oldCapacity = capacity;
        capacity = capacity * 2;
        int** oldTable = table;
        table = new int* [capacity];
        for (int i = 0; i < capacity; i++) {
            table[i] = new int[num_buckets];
            for (int j = 0; j < num_buckets; ++j) {
                table[i][j] = -1;
            }
        }

        for (int i = 0; i < oldCapacity; i++) {
            int* currentBucket = oldTable[i];
            int j = 0;
            while (currentBucket[j] != -1) {
                insert(currentBucket[j]);
                j++;
            }
            delete[] currentBucket;
        }

        delete[] oldTable;
    }

    void display() {
        for (int i = 0; i < capacity; i++) {
            bool nonEmptyBucket = false;
            cout << i << ": ";
            int* bucket = table[i];
            int j = 0;
            while (j < num_buckets) {
                if (bucket[j] != -1) {
                    cout << bucket[j] << " ";
                    nonEmptyBucket = true;
                }
                j++;
            }
            if (nonEmptyBucket) {
                cout << endl;
            }
        }
    }
};

int main() {
    ChainingHashTable chainingHashTable;
    BucketingHashTable bucketingHashTable;

    int keys[] = { 17, 26, 15, 9, 11, 43, 75, 19, 35, 45, 55, 9, 10, 21, 61, 23 };

    for (int i = 0; i < 15; i++) {
        chainingHashTable.insert(keys[i]);
        bucketingHashTable.insert(keys[i]);
    }

    cout << "Chaining Hash Table:" << endl;
    chainingHashTable.display();
    cout << "\nBucketing Hash Table:" << endl;
    bucketingHashTable.display();
    return 0;
}