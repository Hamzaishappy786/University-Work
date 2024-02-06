//#include <iostream>
//using namespace std;
//struct Node {
//	int data;
//	Node* next;
//	Node* prev;
//	Node(int data) :data(data), next(nullptr), prev(nullptr) {}
//};
//class LinkedList {
//	Node* head;
//public:
//	LinkedList() {
//		head = nullptr;
//	}
//	void insert_at_start(int data) {
//		Node* newNode = new Node(data);
//		if (head == nullptr) {
//			head = newNode;
//		}
//		else {
//			newNode->next = head;
//			head->prev = newNode;
//			head = newNode;
//		}
//	}
//	void insert_at_end(int data) {
//		Node* newNode = new Node(data);
//		if (head == nullptr) {
//			head = newNode;
//		}
//		else {
//			Node* last = head;
//			while (last->next != nullptr) {
//				last = last->next;
//			}
//			last->next = newNode;
//			newNode->prev = last;
//		}
//	}
//	void insert_at_middle(int data) {
//		Node* newNode = new Node(data);
//		if (head == nullptr) {
//			head = newNode;
//			return;
//		}
//		Node* slow = head, * fast = head, * prev = nullptr;
//		while (fast != nullptr && fast->next != nullptr) {
//			slow = slow->next;
//			fast = fast->next->next;
//		}
//		newNode->prev = slow;
//		newNode->next = slow->next;
//		if (slow->next != nullptr) {
//			slow->next->prev = newNode;
//		}
//		slow->next = newNode;
//	}
//	void deletion_from_start() {
//		if (head != nullptr) {
//			cout << "Already empty.";
//		}
//		Node* current = head;
//		if (head->next != nullptr) {
//			head = head->next;
//			head->prev = nullptr;
//		}
//		else {
//			head = nullptr;
//		}
//		
//		delete current;
//	}
//	void deletion_from_end() {
//		Node* end = head;
//		if (head->next == nullptr) {
//			delete head;
//			head = nullptr;
//			return;
//		}
//		while (end->next->next != nullptr) {
//			end = end->next;
//		}
//		delete end->next;
//		end->next = nullptr;
//		if (end != head) {
//			end->prev = nullptr;
//		}
//		else {
//			head->prev = nullptr;
//		}
//	}
//	void display() {
//		Node* list = head;
//		while (list != nullptr) {
//			cout << list->data << " ";
//			list = list->next;
//		}
//	}
//	void delete_from_linked_list(int data) {
//		if (head == nullptr) {
//			cout << "Linked list is empty.\n";
//			return;
//		}
//		if (head->data == data) {
//			deletion_from_start();
//			return;
//		}
//		Node* temp = head;
//		while (temp->next != nullptr && temp->next->data != data) {
//			temp = temp->next;
//		}
//		if (temp->next == nullptr) {
//			cout << "The element was not found.\n";
//			return;
//		}
//		Node* node_to_delete = temp->next;
//		temp->next = temp->next->next;
//		delete node_to_delete;
//	}
//	void reverse_linked_list() {
//		cout << "\nReverse: ";
//		Node* last = head;
//		Node* prev = nullptr;
//		Node* next = nullptr;
//		while (last != nullptr) {
//			next = last->next;
//			last->next = prev;
//			prev = last;
//			last = next;
//		}
//		head = prev;
//	}
//	void merge_linked_list(LinkedList& list) {
//		cout << "\nMerged: ";
//		Node* last_node = head;
//		while (last_node->next != nullptr) {
//			last_node = last_node->next;
//		}
//		last_node->next = list.head;
//		list.head = nullptr;
//	}
//	void intersection_in_linked_lists(LinkedList& list) {
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
//	~LinkedList() { 
//		Node* current = head;
//		while (current != nullptr) {
//			Node* next = current->next;
//			delete current;
//			current = next;
//		}
//	}
//};
//int main()
//{
//	LinkedList obj, obj2;
//	obj.insert_at_end(12);	obj.insert_at_end(24);	obj.insert_at_start(36);	obj.insert_at_end(48);	obj.insert_at_end(60);
//	obj2.insert_at_end(12);	obj2.insert_at_end(24);	obj2.insert_at_start(36);	obj2.insert_at_end(48);	obj2.insert_at_end(60);
//	obj.display();
//	obj.insert_at_middle(47);	cout << endl;
//	obj.display();
//	obj.deletion_from_start();	cout << endl;
//	obj.display();
//	obj.deletion_from_end();	cout << endl;
//	obj.display();
//	/*obj.delete_from_linked_list(47);	cout << endl;
//	obj.display();
//	obj.reverse_linked_list();	cout << endl;
//	obj.display();
//	obj.merge_linked_list(obj2);	cout << endl;
//	obj.display();
//	obj2.insert_at_end(12);	obj2.insert_at_end(24);	obj2.insert_at_end(36);
//	obj.intersection_in_linked_lists(obj2);
//	cout << endl << endl;
//	obj.display();	cout << endl;
//	obj2.display();*/
//	return 0;
//}