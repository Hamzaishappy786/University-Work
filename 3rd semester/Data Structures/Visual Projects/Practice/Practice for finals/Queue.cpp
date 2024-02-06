////#include <iostream>
////using namespace std;
////class Queue {
////	int front;
////	int rear;
////	int* arr;
////	int size;
////public:
////	Queue(int size) {
////		this->size = size;
////		front = -1;
////		rear = -1;
////		arr = new int[size];
////		for (int i = 0; i < size; i++) {
////			arr[i] = 0;
////		}
////	}
////	bool isFull() { return (front == 0 && rear == size - 1); }
////	bool isEmpty() { return (front == -1 && rear == -1); }
////	void enqueue(int data) {
////		if ((rear + 1) % size == front) {
////			cout << "Queue already full, cannot enqueue more.\n";
////		}
////		else if (isEmpty()) {
////			front = 0;
////			rear = 0;
////		}
////		else {
////			rear = (rear + 1) % size;
////		}
////		arr[rear] = data;
////	}
////	int dequeue() {
////		if (isEmpty()) {
////			cout << "Queue is already empty. Cannot dequeue more.\n";
////			return -1;
////		}
////		int value = arr[front];
////		if (front == rear) {
////			front = -1;
////			rear = -1;
////		}
////		else {
////			front = (front + 1) % size;
////		}
////		return value;
////	}
////	void reverse() {
////		int i = front, j = rear;
////		while (i < j) {
////			int temp = arr[i];
////			arr[i] = arr[j];
////			arr[j] = temp;
////
////			i = (i + 1) % size;
////			j = (j - 1 + size) % size;
////		}
////	}
////	/*bool queue_palindrome() {
////		int* tempArr = new int[size];
////		int frontArr = -1, rearArr = -1;
////		if (isEmpty() == false) {
////			int value = dequeue();
////			tempArr[++rearArr] = value;
////			enqueue(value);
////		}
////		while (frontArr < rearArr) {
////			if (tempArr[frontArr++] != tempArr[rearArr--]) {
////				return false;
////			}
////		}
////		delete[] tempArr;
////		return true;
////	}*/
////	void display() {
////		int i = front;
////		while (i != rear) {
////			cout << arr[i] << " ";
////			i = (i + 1) % size;
////		}
////		if (!isEmpty()) {
////			cout << arr[rear];
////		}
////	}
////	~Queue() { delete[]arr; }
////};
////int main()
////{
////	Queue obj(5);
////	obj.display();	cout << endl;
////	obj.enqueue(12);	obj.enqueue(24);	obj.enqueue(36);	obj.enqueue(24);	obj.enqueue(12);
////	obj.display();	cout << endl;
////	obj.dequeue();	obj.dequeue();
////	obj.display();	cout << endl;
////	obj.enqueue(24);
////	obj.enqueue(36);
////	obj.display();	cout << endl;
////	obj.reverse();
////	obj.display();
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
//class Queue_using_linked_lists {
//	Node* front;
//	Node* rear;
//public:
//	Queue_using_linked_lists() {
//		front = nullptr;
//		rear = nullptr;
//	}
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
//	}
//	int dequeue() {
//		if (isEmpty()) {
//			cout << "Already empty.";
//			return - 1;
//		}
//		int data = front->data;
//		Node* temp = front;
//		if (front == rear) {
//			front = rear = nullptr;
//		}
//		else {
//			front = front->next;
//		}
//		delete temp;
//		return data;
//	}
//	void display() {
//		Node* temp = front;
//		while (temp != nullptr) {
//			cout << temp->data << " ";
//			temp = temp->next;
//		}
//		delete[]temp;
//	}
//	~Queue_using_linked_lists() {
//		delete[]front;
//		delete[]rear;
//	}
//};
//int main()
//{
//	Queue_using_linked_lists obj;
//	obj.enqueue(12);	obj.enqueue(24);	obj.enqueue(36);
//	obj.display();	cout << endl;
//	obj.dequeue();	obj.display();
//	return 0;
//}