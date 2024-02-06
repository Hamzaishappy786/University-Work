#include <iostream>
#include <Windows.h>
using namespace std;
template<typename Q>
class deque {
private:
	int front;
	int rear;
	int capacity;
	Q* dequeArr;
public:
	deque(int size);
	~deque();
	bool isEmpty();
	bool isFull();
	void insert_from_front(Q data);
	void insert_from_back(Q data);
	void remove_from_front();
	void remove_from_back();
	void display();
	int size();
	void clear();
};
template<typename Q>
deque<Q>::deque(int size) {
	rear = -1;	front = -1;	capacity = size;
	dequeArr = new Q[size];
}
template<typename Q>
bool deque<Q>::isEmpty() {
	if (front == -1) { cout << "\nStatus: Queue is Empty.\n"; return true; }
	cout << "\nStatus: Queue is not Empty.\n";	return false;
}
template<typename Q>
bool deque<Q>::isFull() {
	if (front == capacity - 1) { cout << "\nQueue is Full.\n"; return true; }
	cout << "\nQueue is not Full.\n";	return false;
}
template<typename Q>
void deque<Q>::insert_from_front(Q data) {
	if (front == rear + 1) {
		cout << "Queue is already full.\n";
		return;
	}
	if (front == - 1) { front = capacity; }
	front--;
	dequeArr[front] = data;
	cout << data << " has been enqueued in from the front.\n";
}
template<typename Q>
void deque<Q>::insert_from_back(Q data) {
	if (front == rear + 1) {
		cout << "Queue is already full.\n";	return;
	}
	rear++;
	dequeArr[rear] = data;
	cout << data << " has been enqueued in from the back.\n";
}
template<typename Q>
void deque<Q>::remove_from_front() {
	if (front == capacity) { cout << "Queue is already empty.\n";	return; }
	else {
		Q val = dequeArr[front];
		cout << dequeArr[front] << " has been dequeued from the back.\n";
		dequeArr[front] = "0";
		front++;
	}
}
template<typename Q>
void deque<Q>::remove_from_back() {
	if (rear == -1) { cout << "Queue is already empty.\n";	return; }
	else {
		Q val = dequeArr[rear];
		cout << dequeArr[rear] << " has been dequeued from the front.\n";
		dequeArr[rear] = "0";
		rear--;
	}
}
template<typename Q>
void deque<Q>::display() {
	int element_count = 0;
	if (front == -1) { cout << "Status: Queue is empty.\n";	Sleep(1000); return; }
	cout << "\nYour queue: ";
	int i = front;
	do {
		cout << dequeArr[i] << " ";
		i = (i + 1) % capacity;
		element_count++;
	} while (i != (rear + 1) % capacity);
	Sleep(1000);
	cout << "\n\nStatus:\n";
	cout << "Total size of queue: " << size() << endl;
	cout << "Total elements in the queue: " << element_count << endl;
	system("pause");
}
template <typename Q>
void deque<Q>::clear() { front = -1;	rear = -1; }
template<typename Q>
int deque<Q>::size() { return capacity; }
template<typename Q>
deque<Q>::~deque() { delete[]dequeArr; }
int main() {
	int size, choice;
	string data;
	cout << "Enter the size of the queue: ";	cin >> size;
	deque<string> obj(size);
	while (true) {
		cout << "1. Insert element from front \n";
		cout << "2. Insert element from back\n";
		cout << "3. Remove element from front\n";
		cout << "4. Remove element from back\n";
		cout << "5. Display\n";
		cout << "6. Check if queue is empty\n";
		cout << "7. Check if queue is full\n";
		cout << "8. Size of the queue\n";
		cout << "9. Clear the queue\n";
		cout << "0. Exit\n";
		cout << "Enter the choice: ";	cin >> choice;

		if (choice == 1) { cout << "Enter the data to enqueue: ";	cin >> data;	obj.insert_from_front(data); }
		else if (choice == 2) { cout << "Enter the data to enqueue: ";	cin >> data;	obj.insert_from_back(data); }
		else if (choice == 3) { obj.remove_from_front(); }
		else if (choice == 4) { obj.remove_from_back(); }
		else if (choice == 5) { obj.display(); }
		else if (choice == 6) { obj.isEmpty(); }
		else if (choice == 7) { obj.isFull(); }
		else if (choice == 8) { cout << "The size of the queue: " << obj.size(); }
		else if (choice == 9) { obj.clear();	cout << "\nYour whole queue has been cleared.\nStatus: Queue is Empty.\n"; }
		else if (choice == 0) { break; }
		else { cout << "Invalid number. Try again in 2 seconds.\n"; }
		if (choice != 5) { Sleep(2000); }
		system("cls");
	}
}