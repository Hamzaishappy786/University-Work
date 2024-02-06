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
//Node* reverseLinkedList(Node* current, Node* previous = nullptr) {
//	if (current == nullptr) {
//		return previous;
//	}
//	// Remaining Code
//	else {
//		Node* next = current->next;
//		current->next = previous;
//		return reverseLinkedList(next, current);
//	}
//}
//void printLinkedList(Node* head) {
//	while (head != nullptr) {
//		//Code
//		cout << head->data << " ";
//		head = head->next;
//	}
//	cout << endl;
//}
//int main() {
//	Node* head = new Node(12);
//	head->next = new Node(24);
//	head->next->next = new Node(36);
//	printLinkedList(head);
//	Node* rev = reverseLinkedList(head);
//	printLinkedList(rev);
//	return 0;
//}