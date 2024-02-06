//#include <iostream>
//#include <string>
//#include <random>
//using namespace std;
//struct KeyValue {
//    string key;
//    int value;
//
//    KeyValue() : key(""), value(-1) {}
//};
//
//class HashTable {
//private:
//    double TABLE_SIZE;
//    KeyValue* table;
//    double currentSize;
//
//public:
//    HashTable(int initialSize) : TABLE_SIZE(initialSize), currentSize(0) {
//        table = new KeyValue[TABLE_SIZE];
//    }
//
//    ~HashTable() {
//        delete[] table;
//    }
//    int hash(string key) {
//        int hashvalue = 0;
//        for (int i = 0; i < key.length(); i++) {
//            char ch = key[i];
//            hashvalue += ch;
//        }
//        return hashvalue % int(TABLE_SIZE);
//    }
//    void insert(string key, int value) {
//        double bf = currentSize / TABLE_SIZE;
//        cout << bf;
//        if (bf >= 0.7) {
//            rehash(TABLE_SIZE * 2);
//        }
//        int i = 0;
//        int index = hash(key);
//        while (!table[index].key.empty()) {
//            index = (index + i * i) % int(TABLE_SIZE);
//            i++;
//        }
//        table[index].key = key;
//        table[index].value = value;
//        ++currentSize;
//    }
//    int get(string key) {
//        int index = hash(key);
//        while (!table[index].key.empty()) {
//            if (table[index].key == key) {
//                return table[index].value;
//            }
//            index = (index + 1) % int(TABLE_SIZE);
//        }
//        return -1;
//    }
//    void display() const {
//        cout << "Hash Table Contents:" << endl;
//        for (int i = 0; i < TABLE_SIZE; ++i) {
//            if (!table[i].key.empty() || table[i].key.empty()) {
//                cout << "[" << i << "] " << table[i].key << ": " << table[i].value << endl;
//            }
//        }
//        cout << "-------------------------" << endl;
//    }
//    void rehash(int newSize) {
//        KeyValue* newTable = new KeyValue[newSize];
//        for (int i = 0; i < newSize; i++) {
//            newTable[i].key = "";
//            newTable[i].value = -1;
//        }
//        for (int i = 0; i < TABLE_SIZE; i++) {
//            if (!table[i].key.empty()) {
//                int newIndex = hash(table[i].key);
//                while (!newTable[newIndex].key.empty()) {
//                    newIndex = (newIndex + 1) % newSize;
//                }
//                newTable[newIndex] = table[i];
//            }
//        }
//        delete[] table;
//        table = newTable;
//        TABLE_SIZE = newSize;
//    }
//};
//
//int main() {
//    int expectedNumElements = 12;
//    HashTable myHashTable(expectedNumElements);
//    srand((time(NULL)));
//    for (int i = 0; i < 15; i++) {
//        int random_num = rand() % 10 + 1;
//        string key = "" + to_string(random_num);
//        myHashTable.insert(key, random_num);
//    }
//    cout << "1:" << myHashTable.get("1");
//    myHashTable.display();
//    return 0;
//}