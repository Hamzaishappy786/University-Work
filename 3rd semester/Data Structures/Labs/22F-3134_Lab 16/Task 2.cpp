//#include <iostream>
//#include <string>
//#include <fstream>
//using namespace std;
//struct Node {
//	string word;
//	int value;
//	Node() {}
//	Node(string k, int v) { word = k, value = v; }
//};
//
//class HashTable_Linear_Probing {
//private:
//	int TABLE_SIZE = 31;
//	Node* table;
//
//	int hashFunction_probing(string word, int attempt) {
//		int index = (word.length() + attempt) % TABLE_SIZE;
//		return index;
//	}
//
//public:
//	HashTable_Linear_Probing() {
//		table = new Node[TABLE_SIZE];
//	}
//	void insert(string word, int value) {
//		int attempt = 0;
//		int index;
//		do {
//			index = hashFunction_probing(word, attempt);
//			attempt++;
//		} while (table[index].word != "" && table[index].word != word);
//		Node word_node(word, value);
//		table[index] = word_node;
//	}
//	void remove(string word) {
//		int attempt = 0;
//		int index;
//		do {
//			index = hashFunction_probing(word, attempt);
//			attempt++;
//		} while (table[index].word != "" && table[index].word != word);
//		Node removed_word("", 0);
//		if (table[index].word == word) {
//			table[index] = removed_word;
//		}
//	}
//
//	bool search(string key) {
//		int attempt = 0;
//		int index;
//		do {
//			index = hashFunction_probing(key, attempt);
//			attempt++;
//		} while (table[index].word != "" && table[index].word != key);
//		return (table[index].word == key);
//	}
//
//	void printTable() {
//		for (int i = 0; i < TABLE_SIZE; i++) {
//			cout << i << " ";
//			if (table[i].word != "") {
//				cout << "{" << table[i].word << ", " << table[i].value << "}";
//			}
//			else {
//				cout << "empty";
//			}
//			cout << endl;
//		}
//	}
//	~HashTable_Linear_Probing() { delete[]table; }
//};
//
//int main() {
//	HashTable_Linear_Probing hashTable;
//	ifstream file;
//	int choice;
//	string key;
//	int value;
//	file.open("Data.txt");
//	while (!file.eof()) {
//		getline(file, key);
//		hashTable.insert(key, key.length());
//	}
//	file.close();
//	while (true) {
//		cout << "\n\t Menu:\n";
//		cout << "1. Deletion in HashTable\n";
//		cout << "2. Searching in HashTable\n";
//		cout << "3. Print HashTable\n";
//		cout << "0. Exit\n";
//		cout << "Enter your choice: ";
//		cin >> choice;
//		if (choice == 1) {
//			cout << "Enter key to delete: ";
//			cin >> key;
//			hashTable.remove(key);
//		}
//		else if (choice == 2) {
//			cout << "Enter key to search: ";
//			cin >> key;
//			if (hashTable.search(key)) {
//				cout << "Key: '" << key << "' found at index " << key.length() % 10;
//			}
//			else {
//				cout << "'" << key << "' not found";
//			}
//		}
//		else if (choice == 3) {
//			hashTable.printTable();
//		}
//		else if (choice == 0) {
//			break;
//		}
//		else {
//			cout << "\nPlease enter an accurate choice.\n";
//		}
//	}
//	return 0;
//}