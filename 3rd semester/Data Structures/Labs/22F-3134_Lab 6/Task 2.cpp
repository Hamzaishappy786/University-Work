//#include <iostream>
//using namespace std;
//const int MAX_SIZE = 100;
//class Queue {
//private:
//	int front;
//	int rear;
//	int arr[MAX_SIZE + 1];
//public:
//	Queue();
//	void enqueue(int item);
//	int dequeue();
//	bool isEmpty();
//	bool isFull();
//	void driver();
//	~Queue();
//};
////Constructor
//Queue::Queue() { front = 0;	rear = 0; }
//void Queue::enqueue(int item) {
//	if (isFull()) {
//		cout << "Queue is full. Cannot enqueue more.\n";
//		return;
//	}
//	arr[rear] = item;
//	rear = (rear + 1) % (MAX_SIZE + 1);
//}
//int Queue::dequeue() {
//	if (isFull()) {
//		cout << "Queue is already empty.\n";
//		return -1;
//	}
//	int item = arr[front];
//	front = (front + 1) % (MAX_SIZE + 1);
//	return item;
//}
//bool Queue::isEmpty() {
//	if (front == rear) { return true; }
//	else { return false; }
//}
//bool Queue::isFull() {
//	if ((rear + 1) % (MAX_SIZE + 1) == front) { return true; }
//	else { return false; }
//}
//void Queue::driver() {
//	int choice;
//	while (true) {
//		cout << "1. Enqueuing a new element\n";
//		cout << "2. Dequeuing an element\n";
//		cout << "3. To check whether the queue is empty\n";
//		cout << "4. To check whether the queue is full\n";
//		cout << "0. Exit\n";
//		cout << "Enter your choice: ";	cin >> choice;
//		if (choice == 1) {
//			int data;
//			cout << "Enter the new data to enqueue: ";	cin >> data;	enqueue(data);
//		}
//		else if (choice == 2) {
//			dequeue();
//		}
//		else if (choice == 3) {
//			cout << "(1 = Full / 0 = Not Full): " << isEmpty() << endl;
//		}
//		else if (choice == 4) {
//			cout << "(1 = Empty / 0 = Not Empty): " << isFull() << endl;
//		}
//		else if (choice == 0) {
//			break;
//		}
//		else {
//			cout << "Invalid choice.\n";
//		}
//	}
//}
////Destructor
//Queue::~Queue() {} //empty, because no need to delete anything
//int main() {
//	Queue queue;
//	cout << "You have an empty queue of 100 spaces, what do you want to do?\n";
//	queue.driver();
//	return 0;
//}