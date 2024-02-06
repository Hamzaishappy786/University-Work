//#include <iostream>
//#include <string>
//#include <fstream>
//using namespace std;
//struct Node {	//node for linked lists
//	string word;
//	int value;
//	Node* next;
//	Node(string k, int v) { word = k;	value = v;	next = nullptr; }
//};
//class HashTable {	//hashtable class for storing and structurizing our data
//private:
//	int TABLE_SIZE = 11;
//	Node* table[11];
//	int hashFunction(string str) {	//values are placed based on their length
//		return str.length() % TABLE_SIZE;
//	}
//
//public:
//	HashTable() {
//		for (int i = 0; i < TABLE_SIZE; i++) {	//nullifying all the slots of table
//			table[i] = nullptr;
//		}
//	}
//	void insert(string key, int value) {	//inserting words from dict to hashtable
//		int index = hashFunction(key);
//		Node* newNode = new Node(key, value);	//memory allocation because of linked list
//		if (table[index] == nullptr) {	//for starting chain
//			table[index] = newNode;
//		}
//		else {	//if the chain is already built
//			newNode->next = table[index];
//			table[index] = newNode;
//		}
//	}
//	void remove(string key) {	//for removing a word from hashtable
//		int index = hashFunction(key);	//finding index using hashtable function
//		Node* current = table[index];
//		Node* prev = nullptr;
//
//		while (current != nullptr && current->word != key) {	//for searching out the word
//			prev = current;
//			current = current->next;
//		}
//
//		if (current != nullptr) {	//deleting the node
//			if (prev == nullptr) {	//for starters of the chain
//				table[index] = current->next;
//			}
//			else {	//in between of the chains
//				prev->next = current->next;
//			}
//			delete current;
//		}
//	}
//	bool search(string key) {	//for searching in the hashtable
//		int index = hashFunction(key);	//finding index using hashtable function
//		Node* current = table[index];
//		while (current != nullptr) {	//traversing the chain if the word is not found
//			if (current->word == key) {
//				return true;
//			}
//			current = current->next;
//		}
//		return false;
//	}
//	void printTable() {	//for printing out the hashtable
//		for (int i = 1; i < TABLE_SIZE; ++i) {
//			cout << i << ": ";
//			Node* current = table[i];
//			while (current != nullptr) {
//				cout << "{" << current->word << ", " << current->value << "} ";
//				current = current->next;
//			}
//			cout << endl;
//		}
//	}
//};
//
//
//int main() {
//	HashTable hashTable;
//	ifstream file;
//	int choice, value;
//	string key;
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
//			cout << "\nPlease enter an accurate option.\n";
//		}
//	}
//	file.close();
//	return 0;
//}