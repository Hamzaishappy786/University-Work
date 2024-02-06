//#include <iostream>
//using namespace std;
//class Node {
//public:
//	Node* next;
//	int data;
//	Node(int value) :data(value), next(nullptr) {}
//};
//class Queue {
//private:
//	Node* front;
//	Node* rear;
//public:
//	Queue() :front(nullptr), rear(nullptr) {}
//	void enqueue(int data) {
//		Node* newNode = new Node(data);	//allocating data
//		if (front == nullptr) {	//check for empty queue
//			front = newNode;	//passing the same adress for staring the queue
//			rear = newNode;
//			return;
//		}
//		rear->next = newNode;	//if that's not the case
//		rear = newNode;			//then attaching newly attached to the rear
//		cout << endl;
//	}
//	void dequeue() {
//		if (front == nullptr) {
//			return;	//check for empty
//		}
//		Node* toDelete = front;	//popping by moving value of front and
//		front = front->next;	//	deleting the pointer toDelete
//		delete toDelete;
//		cout << endl;
//	}
//	bool isEmpty() {
//		cout << endl;
//		if (front == nullptr) { return true; }
//		else { return false; }
//	}
//	void display() {
//		Node* current = front;
//		if (isEmpty()) {
//			cout << "Queue is empty.\n";	return;
//		}
//		do {	//simply not changing the pointing of front
//			cout << current->data << " ";	//and using current
//			current = current->next;
//		} while (current != rear->next);	//traversing
//		cout << endl << endl;
//	}
//	void driver() {	//driver function
//		int choice, enqueued_data;
//		while (true) {
//			cout << "1. Enqueue data\n";
//			cout << "2. Dequeue data\n";
//			cout << "3. Is queue empty\n";
//			cout << "4. Display data\n";
//			cout << "5. Exit\n";
//			cout << "Enter your choice: ";	cin >> choice;
//			//enqueing data
//			if (choice == 1) { cout << "Enter the enqueued data: ";	cin >> enqueued_data;	enqueue(enqueued_data); }
//			else if (choice == 2) { dequeue(); }	//dequeuing
//			else if (choice == 3) { cout << "(1 if empty/ -1 if full): " << isEmpty() << endl; }	//telling whether queue is empty or not
//			else if (choice == 4) { display(); }	//for displaying queue
//			else if (choice == 5) { break; }
//		}
//	}
//	//destructor
//	~Queue() { delete front; delete rear; }
//};
//int main()
//{
//	Queue my_queue;
//	my_queue.driver();
//	return 0;
//}