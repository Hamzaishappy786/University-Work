//#include <iostream>
//#include <Windows.h>
//using namespace std;
////{-------------}
////|====Stack====|
////{-------------}
//template<typename SQ>
//class Stack {
//private:
//	int top;
//	SQ* arr;
//	int capacity;
//public:
//	Stack(int size);	//constructor
//	bool isEmpty();	//checking if the stack is empty
//	bool isFull();	//checking if the stack is full
//	void push(SQ value);	//pusing value in stack
//	SQ pop();	//popping value from the stack
//	int getTop();	//getter for top
//	SQ* getArr();	//getter for array
//};
//template<typename SQ>
//Stack<SQ>::Stack(int size) { int top = -1;	capacity = size;	arr = new SQ[size]; }
//template<typename SQ>
//bool Stack<SQ>::isEmpty() { if (top == -1) { return true; }	return false; }
//template<typename SQ>
//bool Stack<SQ>::isFull() { if (top == capacity - 1) { return true; } return false; }
//template<typename SQ>
//void Stack<SQ>::push(SQ data) {
//	if (top >= capacity - 1) { cout << "\nStack already full.\n";	return; }
//	top++;
//	arr[top] = data;
//}
//template<typename SQ>
//SQ Stack<SQ>::pop() {
//	if (top < 0) { cout << "\nStack is empty.\n";	return 0; }
//	return arr[top--];
//}
//template<typename SQ>
//int Stack<SQ>::getTop() { return top; }
//template<typename SQ>
//SQ* Stack<SQ>::getArr() { return arr; }
//template<typename QS>
//class queueStack {
//private:
//	Stack<QS> stack1, stack2;
//public:
//	queueStack(int size);
//	bool isEmpty();
//	bool isFull();
//	void enqueue(QS data);
//	QS dequeue();
//	void display();
//	void clear();
//	~queueStack();
//};
//template<typename QS>
//queueStack<QS>::queueStack(int size) :stack1(size), stack2(size) {}
//template<typename QS>
//bool queueStack<QS>::isEmpty() {
//		if (stack1.isEmpty() && stack2.isEmpty()) { cout << "\nStack is empty.\n"; return true; }
//		cout << "\nStack is not empty.\n";	return false;
//}
//template<typename QS>
//bool queueStack<QS>::isFull() {
//	if (stack1.isFull()) { cout << "\nQueue is full.\n"; return true; }
//	cout << "\nStack is not full.\n";	return false;
//}
//template<typename QS>
//void queueStack<QS>::enqueue(QS data) {
//	stack1.push(data);		cout << endl << data << " has been enqueued.\n";
//}
//template<typename QS>
//QS queueStack<QS>::dequeue() {
//	if (isEmpty() == true) { cout << "\nQueue is already empty.\n"; return; }
//	if (stack2.isEmpty()) {
//		while (stack1.isEmpty() == false) {
//			stack2.push(stack1.pop());
//		}
//	}
//	return stack2.pop();
//}
//template<typename QS>
//void queueStack<QS>::display() {
//	if (isEmpty() == true) { cout << "\nQueue is empty.\n";	return; }
//	cout << "\nQueue: ";
//	//taking elements out of stack 2
//	for (int i = stack2.getTop(); i >= 0; i--) {
//		cout << stack2.getArr()[i] << " ";
//	}
//	//and adding in the stack 1
//	for (int i = 0; i <= stack1.getTop(); i++) {
//		cout << stack1.getArr()[i] << " ";
//	}
//	cout << endl;
//}
//template<typename QS>
//void queueStack<QS>::clear() {
//	while (isEmpty() == false) { dequeue(); }
//}
//template<typename QS>
//queueStack<QS>::~queueStack() {}
//int main()
//{
//	int size, choice;
//	string data;
//	cout << "Enter the size of the queue: ";	cin >> size;
//	queueStack<string> queue(size);
//	cout << "Wait a minute, clearing all garbage values: ";
//	Sleep(2000);
//	system("cls");
//	//queue.clear();
//	while (true) {
//		cout << "1. Enqueue\n";
//		cout << "2. Dequeue\n";
//		cout << "3. Queue is empty\n";
//		cout << "4. Queue is full\n";
//		cout << "5. Display\n";
//		cout << "0. Exit\n";
//		cout << "Enter your choice: ";	cin >> choice;
//		if (choice == 1) { cout << "Enter the data to be enqueued: ";	cin >> data;	queue.enqueue(data); }
//		else if (choice == 2) { queue.dequeue(); }
//		else if (choice == 3) { queue.isEmpty(); }
//		else if (choice == 4) { queue.isFull(); }
//		else if (choice == 5) { queue.display(); }
//		else if (choice == 0) { break; }
//		Sleep(2000);
//		system("cls");
//	}
//	return 0;
//}