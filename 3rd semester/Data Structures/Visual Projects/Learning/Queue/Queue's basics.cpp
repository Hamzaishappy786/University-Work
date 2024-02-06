////#include <iostream>
////using namespace std;
////#define MAX_SIZE 4
////class Queue {
////private:
////	int front;
////	int rear;
////	int arr[MAX_SIZE];
////public:
////	Queue() :front(-1), rear(-1) {}
////	bool isEmpty() { return front == -1 && rear == -1; }
////	bool isFull() { return (rear + 1) % MAX_SIZE == front; }
////	void enqueue(int value) {
////		if (isFull()) {
////			return;
////		}
////		if (isEmpty()) {
////			front = 0;	rear = 0;
////		}
////		else {
////			rear = (rear + 1) % MAX_SIZE;
////		}
////		arr[rear] = value;
////	}
////	void display() {
////		if (isEmpty()) {
////			cout << "Queue is empty.\n";
////		}
////		else {
////			int i = front;
////			do {
////				cout << arr[i] << " ";
////				i = (i + 1) % MAX_SIZE;
////			} while (i != (rear + 1) % MAX_SIZE);
////		}
////	}
////	void dequeue() {
////		if (isEmpty()) {
////			cout << "Queue is already empty.\n";
////			return;
////		}
////		cout << "Dequeued value: " << arr[front] << endl;
////		if (front == rear) {
////			front = -1;	rear = -1;
////		}
////		else {
////			front = (front + 1) % MAX_SIZE;
////		}
////	}
////};
////int main()
////{
////	Queue obj;
////	cout << obj.isFull() << endl;
////	cout << obj.isEmpty() << endl;
////	obj.enqueue(12);	obj.enqueue(24);	obj.enqueue(36);	obj.enqueue(48);
////	obj.display();
////	cout << obj.isFull() << endl;
////	obj.dequeue();	cout << endl << "Queue: ";	obj.display();
////	obj.dequeue();	cout << endl << "Queue: ";	obj.display();
////	obj.dequeue();	cout << endl << "Queue: ";	obj.display();
////	obj.dequeue();	cout << endl << "Queue: ";	obj.display();
////	cout << obj.isEmpty();
////	return 0;
////}
//
//#include <iostream>
//using namespace std;
//struct Node {
//	int data;
//	Node* next;
//	Node(int data) :data(data), next(nullptr) {}
//};
//class Queue {
//private:
//	Node* front;
//	Node* rear;
//public:
//	Queue() :front(nullptr), rear(nullptr) {}
//	bool isEmpty() { return front == nullptr; }
//	void enqueue(int data) {
//		Node* newNode = new Node(data);
//		if (isEmpty()) {
//			front = newNode;
//			rear = newNode;
//		}
//		else {
//			rear->next = newNode;
//			rear = newNode;
//		}
//		cout << "Enqueued value: " << data << endl;
//	}
//	void dequeue() {
//		if (isEmpty()) {
//			cout << "Queue already empty.\n";
//			return;
//		}
//		else {
//			Node* temp = front;
//			front = front->next;
//			cout << "Dequeued element: " << temp->data << endl;
//			delete temp;
//			if (front == nullptr) {
//				rear = nullptr;
//			}
//		}
//	}
//	void display() {
//		if (isEmpty()) {
//			cout << "Queue is empty.\n";
//			return;
//		}
//		Node* current = front;
//		while (current != nullptr) {
//			cout << current->data << " ";
//			current = current->next;
//		}
//		cout << endl;
//	}
//	~Queue() {
//		delete front;
//		delete rear;
//	}
//	int size() {
//		int count = 0;
//		Node* current = front;
//		while (current != nullptr) {
//			++count;
//			current = current->next;
//		}
//		return count;
//	}
//};
//int main()
//{
//	Queue myQueue;
//	myQueue.enqueue(12);	myQueue.enqueue(24);	myQueue.enqueue(36);	myQueue.enqueue(48);
//	cout << myQueue.size() << endl;
//	myQueue.display();		myQueue.dequeue();
//	myQueue.display();		myQueue.dequeue();
//	cout << myQueue.size() << endl;
//	myQueue.display();		myQueue.dequeue();
//	myQueue.display();		myQueue.dequeue();
//	cout << myQueue.isEmpty() << endl;
//	return 0;
//}

//#include <iostream>
//using namespace std;
//class Queue {
//private:
//	int front;
//	int rear;
//	int arr[5];
//public:
//	Queue() :rear(-1), front(-1) {}
//	bool isempty() { return rear == -1 && front == -1; }
//	bool isFull() { return front == rear; }
//	void enqueue(int data) {
//		if (rear == 5 - 1) {
//			cout << "No more can be inserted.\n";
//			return;
//		}
//		rear++;
//		arr[rear] = data;
//		if (front == -1) {
//			front++;
//		}
//	}
//	void display() {
//		int i = front;
//		do {
//			cout << arr[i] << " ";
//			i = (i + 1) % 5;
//		} while (i != (rear + 1) % 5);
//		cout << endl;
//	}
//	void dequeue() {
//		if (front == -1 || front > rear) {
//			cout << "Nope";
//			return;
//		}
//		rear--;
//	}
//	void peek(int position) {
//		if (position == -1) {
//			return;
//		}
//		else {
//			cout << arr[front] << " ";
//		}
//	}
//};
//int main()
//{
//	Queue obj;
//	obj.enqueue(12);	obj.enqueue(24);	obj.enqueue(36);	obj.enqueue(48);	obj.enqueue(60);	obj.display();
//	obj.dequeue();
//	obj.display();
//	return 0;
//}

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
//		Node* newNode = new Node(data);
//		if (front == nullptr) {
//			front = newNode;
//			rear = newNode;
//			return;
//		}
//		rear->next = newNode;
//		rear = newNode;
//	}
//	void dequeue() {
//		if (front == nullptr) {
//			return;
//		}
//		Node* toDelete = front;
//		front = front->next;
//		delete toDelete;
//	}
//	void peek() {
//		if (front == nullptr) {
//			cout << "Not possible.\n";
//		}
//		else {
//			cout << front->data << endl;
//		}
//	}
//};
//int main()
//{
//	Queue myQueue;
//	myQueue.enqueue(12);	myQueue.enqueue(24);	myQueue.enqueue(36);
//	myQueue.peek();
//	myQueue.dequeue();
//	myQueue.peek();
//	return 0;
//}

//#include <iostream>
//using namespace std;
//class Queue {
//private:
//	int* arr;
//	int front;
//	int rear;
//	int size;
//public:
//	Queue(int space) :front(-1), rear(-1), size(space) {arr = new int[size];}
//	void enqueue(int value) {
//		if (rear == size - 1) {
//			return;
//		}
//		rear++;
//		arr[rear] = value;
//		if (front == -1) {
//			front++;
//		}
//	}
//	void dequeue() {
//		if (front == -1 || front > rear) {
//			cout << "Already empty.\n";
//			return;
//		}
//		front++;
//	}
//	~Queue() {
//		delete arr;
//	}
//	void display() {
//		int i = front;
//		do {
//			cout << arr[i] << " ";
//			i = (i + 1) % size;
//		} while (i != (rear + 1) % size);
//		cout << endl;
//	}
//	void reverse() {
//		if (front == -1 || front > rear) {
//			cout << "Queue is empty.\n";	return;
//		}
//		if (front == rear) { return; }
//		int frontElement = arr[front];
//		dequeue();
//		reverse();
//		enqueue(frontElement);
//	}
//};
//int main()
//{
//	Queue obj(4);
//	obj.enqueue(12);	obj.enqueue(24);
//	obj.enqueue(36);	obj.enqueue(48);
//	obj.display();
//	obj.dequeue();
//	obj.display();
//	obj.dequeue();
//	obj.display();
//	obj.dequeue();
//	obj.display();
//	return 0;
//}

#include <iostream>
using namespace std;
class Node {
public:
	int data;
	Node* next;
	Node(int data) :data(data), next(nullptr) {}
};
class CircularQueue {
private:
	Node* rear;
public:
	CircularQueue() :rear(nullptr) {}
	bool isEmpty() { return rear == nullptr; }
	void enqueue(int data) {
		Node* newNode = new Node(data);
		if (isEmpty()) {
			newNode->next = newNode;
			rear = newNode;
		}
		else {
			newNode->next = rear->next;
			rear->next = newNode;
			newNode = rear;
		}
	}
	void dequeue() {
		if (isEmpty()) {
			cout << "Already empty Queue.\n";
			return;
		}
		Node* front = rear->next;
		if (front == rear) {
			rear = nullptr;
		}
		else {
			rear->next = front->next;
		}
		delete front;
	}
	void display() {
		if (isEmpty()) {
			cout << "Queue is empty.\n";
			return;
		}
		else {
			Node* current = rear->next;
			do {
				cout << current->data << " ";
				current = current->next;
			} while (current != rear->next);
			cout << endl;
		}
	}
	void reverse() {
		if (isEmpty()) {
			return;
		}
		Node* current = rear->next;
		Node* prev = nullptr;
		Node* nextNode = nullptr;
		do {
			nextNode = current->next;
			current->next = prev;
			prev = current;
			current = nextNode;
		} while (current != rear->next);
	}
	~CircularQueue() {
		delete[] rear;
	}
};
int main()
{
	CircularQueue obj;
	obj.enqueue(12);	obj.enqueue(24);
		obj.enqueue(36);	obj.enqueue(48);
		obj.display();
		obj.dequeue();
		obj.display();
		obj.dequeue();
		obj.display();
		obj.dequeue();
		obj.display();
		obj.dequeue();
	return 0;
}