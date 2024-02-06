//#include <iostream>
//#include <string>
//#include <Windows.h>
//using namespace std;
////{-------------}
////|====Stack====|
////{-------------}
//template<typename S>
//class Stack {
//private:
//	S* data;
//	S* redodata;
//	int max_size;
//	int top;
//	int redotop;
//public:
//	Stack(int size);	//constructor
//	bool isEmpty();	//checking if the stack is empty or not
//	bool isRedoEmpty();	//is redo possible
//	bool isFull();	//checking if the stack is full or not
//	void push(S value);	//pushing element in the stack
//	void undo();	//Ctrl-Y the task in the stack
//	void redo();	//Ctrl-Z the task in the stack
//	void display();	//displaying the stack
//	~Stack();			//destructor
//};
//template<typename S>
//Stack<S>::Stack(int size) {
//	top = -1;
//	redotop = -1;
//	max_size = size;
//	data = new string[size];
//	redodata = new string[size];
//}
//template<typename S>
//bool Stack<S>::isEmpty() { if (top == -1) { return true; }	return false; }
//template<typename S>
//bool Stack<S>::isRedoEmpty() { if (redotop == -1) { return true; }	return false; }
//template<typename S>
//bool Stack<S>::isFull() { if (top == max_size - 1) { return true; }	return false; }
//template<typename S>
//void Stack<S>::push(S value) {
//	if (isFull() == false) {
//		top++;
//		data[top] = value;
//		cout << endl << value << " has been entered in the stack.\n";
//		redotop = -1;
//	}
//	else {
//		cout << "\nStack is full.\n";
//	}
//}
//template<typename S>
//void Stack<S>::undo() {
//	if (top != -1) {	//if stack is not empty
//		redotop++;
//		redodata[redotop] = data[top];
//		top--;
//	}
//	else {
//		cout << "\nNothing to redo.\n";
//	}
//	cout << endl;
//	display();	//printing for checking stack
//	cout << endl;
//}
//template<typename S>
//void Stack<S>::redo() {
//	if (isRedoEmpty() == false) {
//		top++;
//		data[top] = redodata[redotop];
//		redotop--;
//	}
//	else { cout << "\nNothing to redo.\n"; }
//	cout << endl;
//	display();
//	cout << endl;
//}
//template<typename S>
//void Stack<S>::display() {
//	if (isEmpty() == true) { cout << "\nStack is empty.\n"; }
//	else {
//		cout << endl << "Stack: ";
//		for (int i = 0; i <= top; i++) {
//			cout << data[i] << " ";
//		}
//		cout << endl;
//	}
//}
//template<typename S>
//Stack<S>::~Stack() { delete[]data;	delete[]redodata; }
//int main()
//{
//	int size, choice;	string data;
//	cout << "Enter the size of the stack: ";	cin >> size;
//	Stack<string> stack(size);
//	while (true) {
//		cout << "1. Enter an element in stack\n";
//		cout << "2. Undo (<-)\n";
//		cout << "3. Redo (->)\n";
//		cout << "4. Display\n";
//		cout << "0. Exit\n";
//		cout << "Enter your option: ";	cin >> choice;
//		if (choice == 1) { cout << "Enter the data in your stack: "; cin >> data;	stack.push(data); }
//		else if (choice == 2) { stack.undo(); }
//		else if (choice == 3) { stack.redo(); }
//		else if (choice == 4) { stack.display(); cout << endl; Sleep(1000);  system("pause"); }
//		else if (choice == 0) { break; }
//		if (choice != 4) { Sleep(1000); }
//		system("cls");
//	}
//	return 0;
//}