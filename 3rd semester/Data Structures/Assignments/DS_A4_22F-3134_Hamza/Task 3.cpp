//#include <iostream>
//using namespace std;
//
//class HashTable {
//private:
//    int* table;
//    int capacity;
//    int size;
//    float load_factor = 0.7;
//
//public:
//    HashTable() {
//        capacity = 15;  // initial capacity
//        size = 0;       // size set to 0
//        table = new int[capacity];  // memory allocation
//        for (int i = 0; i < capacity; i++) {
//            table[i] = -1;  // setting all areas to not visited status
//        }
//    }
//
//    int hashFunction(int key) {  // for finding out index
//        return key % capacity;
//    }
//
//    int linearProbing(int index) {  // for linear probing
//        int index_i = 1;
//        while (table[(index_i + index) % capacity] != -1) {
//            index_i++;
//        }
//        return (index_i + index) % capacity;
//    }
//
//    int quadraticProbing(int index) {  // for quadratic probing
//        int index_i = 1;
//        while (table[(index + index_i * index_i) % capacity] != -1) {
//            index_i++;
//        }
//        return (index + index_i * index_i) % capacity;
//    }
//
//    int doubleHashing(int index) {  // used for double hashing
//        int hash2 = 7 - (index % 7);
//        int index_i = 1;
//        while (table[(index + index_i * hash2) % capacity] != -1) {
//            index_i++;
//        }
//        return (index + index_i * hash2) % capacity;
//    }
//
//    void insertion_linearProbing(int key) {  // for insertion in the hashtable
//        float loadFactor = float(size / capacity);
//        if (loadFactor >= load_factor) {
//            rehash();  // rehashing due to 2d data
//        }
//
//        int index = hashFunction(key);
//        if (table[index] == -1) {
//            table[index] = key;  // putting data after seeing the graph
//        }
//        else {
//            index = linearProbing(index);
//            table[index] = key;  // same here
//        }
//        size++;
//    }
//
//    void insertion_quadraticProbing(int key) {  // for insertion with quadratic probing
//        float loadFactor = float(size / capacity);
//        if (loadFactor >= load_factor) {
//            rehash();  // rehashing due to 2d data
//        }
//
//        int index = hashFunction(key);
//        if (table[index] == -1) {
//            table[index] = key;  // putting data after seeing the graph
//        }
//        else {
//            index = quadraticProbing(index);
//            table[index] = key;  // same here
//        }
//        size++;
//    }
//
//    void insertion_doubleHashing(int key) {  // for insertion with double hashing
//        float loadFactor = float(size / capacity);
//        if (loadFactor >= load_factor) {
//            rehash();  // rehashing due to 2d data
//        }
//
//        int index = hashFunction(key);
//        if (table[index] == -1) {
//            table[index] = key;  // putting data after seeing the graph
//        }
//        else {
//            index = doubleHashing(index);
//            table[index] = key;  // same here
//        }
//        size++;
//    }
//
//    void rehash() {
//        int oldCapacity = capacity;
//        capacity = capacity * 2;
//        int* oldTable = table;
//        table = new int[capacity];
//        for (int i = 0; i < capacity; i++) {
//            table[i] = -1;
//        }
//
//        for (int i = 0; i < oldCapacity; i++) {
//            if (oldTable[i] != -1) {
//                insertion_linearProbing(oldTable[i]);
//            }
//        }
//
//        delete[] oldTable;
//    }
//
//    void display() {  //for displaying our hash function
//        for (int i = 0; i < capacity; i++) {  //printing till we reach maximum capacity
//            if (table[i] != -1) {  //till we get unvisited node of our table start printing
//                cout << i << ": " << table[i] << endl;
//            }
//        }
//    }
//};
//
//int main() {
//    HashTable hashTableLinear;
//    HashTable hashTableQuadratic;
//    HashTable hashTableDoubleHashing;
//
//    int keys[] = { 17, 26, 15, 9, 11, 43, 75, 19, 35, 45, 55, 9, 10, 21, 61, 23 };
//
//    for (int i = 0; i < 15; i++) {
//        hashTableLinear.insertion_linearProbing(keys[i]);            //linear probing
//        hashTableQuadratic.insertion_quadraticProbing(keys[i]);      //quadratic probing
//        hashTableDoubleHashing.insertion_doubleHashing(keys[i]);      //double hashing
//    }
//
//    cout << "Linear Probing:" << endl;
//    hashTableLinear.display();
//    cout << "\nQuadratic Probing:" << endl;
//    hashTableQuadratic.display();
//    cout << "\nDouble Hashing:" << endl;
//    hashTableDoubleHashing.display();
//    return 0;
//}