//#include <iostream>
//using namespace std;
//struct Node {
//	int data;
//	Node* next;
//	Node(int val) {
//		data = val;
//		next = nullptr;
//	}
//};
//void insert(Node*& head, int data) {
//	Node* newNode = new Node(data);
//	if (head == nullptr) { head = newNode; }
//	else {
//		newNode->next = head;
//		head = newNode;
//	}
//}
//Node* reverseLinkedList(Node* current, Node* previous = nullptr) {
//	if (current == nullptr) {
//		return previous;	//48......
//	}
//	Node* next = current->next;	//12 24 36	48 null
//	current->next = previous;	//null 12 24 36 48
//	return reverseLinkedList(next, current);
//}
//void printLinkedList(Node* head) {
//	while (head != nullptr) {	//Traversing
//		cout << head->data << " ";	//Printing
//		head = head->next;
//	}
//}
//int main() {
//	Node* node = nullptr;
//	int num, i = 0, value;
//	cout << "Enter the number of nodes: ";	cin >> num;
//	while (i != num) {
//		cout << "Enter the value at node " << i + 1 << ": ";
//		cin >> value;
//		insert(node, value);
//		i++;
//	}
//	cout << "Linked list: ";
//	printLinkedList(node);
//	cout << "\nReversed linked list: ";
//	Node* linkedlist = reverseLinkedList(node);
//	printLinkedList(linkedlist);
//	delete[]node;
//	return 0;
//}