//#include <iostream>
//using namespace std;
//struct Node {
//	int data;
//	Node* next;
//	Node(int data) :data(data), next(nullptr) {}
//};
//class CircularLinkedList {
//	Node* head;
//public:
//	CircularLinkedList() {
//		head = nullptr;
//	}
//	void insert_at_start(int data) {
//		Node* newNode = new Node(data);
//		if (head == nullptr) {
//			head = newNode;
//			head->next = head;
//		}
//		else {
//			newNode->next = head;
//			Node* last = head;
//			while (last->next != head) {
//				last = last->next;
//			}
//			last->next = newNode;
//			head = newNode;
//		}
//	}
//	void insert_at_end(int data) {
//		Node* newNode = new Node(data);
//		if (head == nullptr) {
//			head = newNode;
//			head->next = head;
//		}
//		else {
//			Node* last = head;
//			while (last->next != head) {
//				last = last->next;
//			}
//			last->next = newNode;
//			newNode->next = head;
//		}
//	}
//	void insert_at_middle(int data) {
//		Node* newNode = new Node(data);
//		if (head == nullptr) {
//			head = newNode;
//			head = head->next;
//			return;
//		}
//		else {
//			Node* prev = nullptr, * slow = head, * fast = head;
//			do {
//				prev = slow;
//				slow = slow->next;
//				fast = fast->next->next;
//			} while (fast != head && fast->next != head);
//			newNode->next = slow;
//			prev->next = newNode;
//		}
//	}
//	void deletion_from_start() {
//		if (head == nullptr) {
//			cout << "Already empty.";
//		}
//		Node* current = head;
//		while (current->next != head) {
//			current = current->next;
//		}
//		if (head == current) {
//			delete head;
//			head = nullptr;
//		}
//		else {
//			Node* temp = head;
//			current->next = head->next;
//			head = head->next;
//			delete temp;
//		}
//	}
//	void deletion_from_end() {
//		Node* end = head;
//		if (head->next == head) {
//			delete head;
//			head = nullptr;
//			return;
//		}
//		while (end->next->next != head) {
//			end = end->next;
//		}
//		delete end->next;
//		end->next = head;
//	}
//	void display() {
//		Node* list = head;
//		do {
//			cout << list->data << " ";
//			list = list->next;
//		} while (list != head);
//	}
//	void delete_from_linked_list(int data) {
//		if (head == nullptr) {
//			return;
//		}
//		if (head->data == data) {
//			deletion_from_start();
//			return;
//		}
//		Node* temp = head;
//		Node* prev = nullptr;
//		do {
//			prev = temp;
//			temp = temp->next;
//			if (temp->data == data) {
//				prev->next = temp->next;
//				delete[]temp;
//				return;
//			}
//		} while (temp != head);
//	}
//	void reverse_linked_list() {
//		cout << "Reverse: ";
//		Node* last = head;
//		Node* prev = nullptr;
//		Node* next = nullptr;
//		do {
//			next = last->next;
//			last->next = prev;
//			prev = last;
//			last = next;
//		} while (last != head);
//		head->next = prev;
//		head = prev;
//	}
//	void merge_linked_list(CircularLinkedList& list) {
//		cout << "Merged: ";
//		Node* last_node = head;
//		while (last_node->next != nullptr) {
//			last_node = last_node->next;
//		}
//		last_node->next = list.head;
//		list.head = nullptr;
//	}
//	void intersection_in_linked_lists(CircularLinkedList& list) {
//		Node* list1 = head;
//		Node* list2;
//		while (list1 != nullptr) {
//			list2 = list.head;
//			while (list2 != nullptr) {
//				if (list1->data == list2->data) {
//					cout << "Lists intersect at node with data: " << list1->data << endl;
//					break;
//				}
//				list2 = list2->next;
//			}
//
//			list1 = list1->next;
//		}
//
//		cout << "Lists do not intersect at any point." << endl;
//	}
//
//	~CircularLinkedList() { 
//		if (head != nullptr) {
//			Node* current = head;
//			Node* next = nullptr;
//			do {
//				next = current->next;
//				delete current;
//				current = next;
//			} while (current != head);
//			head = nullptr;
//		}
//	}
//};
//int main()
//{
//	CircularLinkedList obj, obj2;
//	obj.insert_at_end(12);	obj.insert_at_start(24);	obj.insert_at_end(36);	obj.insert_at_start(48);	obj.insert_at_start(60);
//	//obj2.insert_at_end(12);	obj2.insert_at_end(24);	obj2.insert_at_start(36);	obj2.insert_at_end(48);	obj2.insert_at_end(60);
//	obj.display();
//	obj.insert_at_middle(47);	cout << endl;
//	obj.display();
//	obj.deletion_from_start();	cout << endl;
//	obj.display();
//	obj.deletion_from_end();	cout << endl;
//	obj.display();
//	obj.delete_from_linked_list(24);	cout << endl;
//	obj.display();
//	obj.reverse_linked_list();	cout << endl;
//	obj.display();
//	/*obj.merge_linked_list(obj2);	cout << endl;
//	obj.display();
//	obj2.insert_at_end(12);	obj2.insert_at_end(24);	obj2.insert_at_end(36);
//	obj.intersection_in_linked_lists(obj2);
//	cout << endl << endl;
//	obj.display();	cout << endl;
//	obj2.display();*/
//	return 0;
//}