//#include <iostream>
//using namespace std;
//class Queue {
//private:
//	int* arr;
//	int front;
//	int rear;
//	int size;
//public:
//	Queue(int space) :front(-1), rear(-1), size(space) { arr = new int[size]; }
//	bool isEmpty() {	//will tell when front and rear, both are -1
//		if (front == -1 && rear == -1) {
//			cout << "Queue is empty.\n";
//			return true;
//		}
//		return false;
//	}
//	bool isFull() {
//		if (rear == size - 1) {	//will tell if max size - 1 will be equal to front
//			cout << "Queue is full.\n";
//			return true;
//		}
//		return false;
//	}
//	void enqueue(int value) {
//		if (rear == size - 1) {
//			cout << "Not possible. Queue already full.\n";
//			return;	//a check for full queue
//		}
//		rear++;	//if not gonna increase size
//		arr[rear] = value;
//		if (front == -1) {
//			front++;	//this check is for only the beginning of queue
//		}
//	}
//	void dequeue() {
//		if (front == -1 || front > rear) {
//			cout << "Not possible. Queue already empty.\n";	//check for empty queue
//			return;
//		}
//		front++;	//else gonna move the front
//	}
//	void display() {
//		int current = front;
//		do {
//			cout << arr[current] << " ";	//passing the value of front to current
//			current = (current + 1) % size;			//and then moving it
//		} while (current != (rear + 1) % size);
//		cout << endl;
//	}
//	void driver() {
//		int choice = 0, enqueued_data;
//		while (true) {
//			cout << "1. For enqueuing\n";
//			cout << "2. For dequeuing\n";
//			cout << "3. Is full\n";
//			cout << "4. Is empty\n";
//			cout << "5. Display queue\n";
//			cout << "0. Exit\n";
//			cout << "Enter your choice: ";	cin >> choice;
//			if (choice == 1) {
//				cout << "Enter the data to enqueue: ";	 cin >> enqueued_data;	enqueue(enqueued_data);
//			}
//			else if (choice == 2) {
//				dequeue();
//			}
//			else if (choice == 3) {
//				if (isFull() == true) { cout << "Queue is true.\n"; }
//				else { cout << "Queue is not full.\n"; }
//			}
//			else if (choice == 4) {
//				if (isEmpty() == true) { cout << "Queue is empty.\n"; }
//				else { cout << "Queue not empty.\n"; }
//			}
//			else if (choice == 5) {
//				cout << "Queue: ";	display();	cout << endl;
//			}
//			else if (choice == 0) {
//				break;
//			}
//			else {
//				cout << "Invalid choice.\n";
//			}
//		}
//	}
//	~Queue() {
//		delete arr;
//	}
//};
//int main() {
//	int size;
//	cout << "Enter the size of queue: ";	cin >> size;
//	Queue my_queue(size);
//	my_queue.driver();
//	return 0;
//}