//#include <iostream>
//#include <string>
//using namespace std;
////{------------}
////|====Node====|
////{------------}
//template<typename S>
//struct Node {
//	S data;
//	Node* next;
//	Node(S data) :data(data), next(nullptr) {}
//};
////{-------------}
////|====Stack====|
////{-------------}
//template <typename S>
//class Stack {
//public:
//	Node<S>* top;
//	Stack() :top(nullptr) {}
//	void push(S data);	//for inserting
//	S pop();			//for deleting
//	bool isEmpty();		//for checking if stack is empty
//	void display(char operation = '\0');	//display the elements in the stack, null if nothing
//	bool isOperator(S op);	//will check if operator or not
//	int getPrecedence(S op);	//will check the precedence of the operator
//	string infixToPostfix(string& infix);
//	string infixToPrefix(string& infix);
//};
//template<typename S>
//void Stack<S>::push(S data) {
//	Node<S>* newNode = new Node<S>(data);
//	newNode->next = top;
//	top = newNode;
//	display(data);
//}
//template<typename S>
//S Stack<S>::pop() {
//	if (isEmpty()) { cout << "\nStack is empty.\n";		return '\0'; }
//	S data = top->data;
//	Node<S>* temp = top;
//	top = top->next;
//	delete temp;
//	display();
//	return data;
//}
//template<typename S>
//bool Stack<S>::isEmpty() { if (top == nullptr) { return true; }	return false; }
//template<typename S>
//void Stack<S>::display(char operation) {
//	cout << "\nStack: ";
//	Node<S>* current = top;
//	while (current != nullptr) {
//		cout << current->data << " ";
//		current = current->next;
//	}
//	if (operation != S()) {
//		cout << operation;
//	}
//	cout << endl;
//}
//template<typename S>
//bool Stack<S>::isOperator(S op) {
//	if (op == '+' || op == '-' || op == '*' || op == '/' || op == '%') { return true; }
//	return false;
//}
//template<typename S>
//int Stack<S>::getPrecedence(S op) {
//	if (op == '+' || op == '-') { return 1; }
//	else if (op == '*' || op == '/' || op == '%') { return 2; }
//	else { return 0; }
//}
//template<typename S>
//string Stack<S>::infixToPostfix(string& infix) {
//	string result;
//	for (int i = 0; i < infix.length(); i++) {
//		char ch = infix[i];
//		if (ch == '1' || ch == '2' || ch == '3' || ch == '4' || ch == '5' || ch == '6' || ch == '7' || ch == '8' || ch == '9' || ch == '0') {
//			result = result + ch;	//appending operand to the result
//		}
//		//pushing parenthesis on the stack
//		else if (ch == '(') { push(ch); }
//		else if (ch == ')') {
//			//popping and appending elements from stack/equation until we found an opening parenthesis
//			while (isEmpty() == false && top->data != '(') {
//				result = result + pop();
//			}
//			pop();	//popping the parenthesis from equation
//		}
//		else if (isOperator(ch) == true) {
//			//popping and appending from stack/equation while top has higher precedence
//			while (isEmpty() == false && getPrecedence(top->data) <= getPrecedence(ch) && top->data != '(') {
//				result = result + pop();
//			}
//			push(ch);	//pushing the current operator on the stack
//		}
//	}//popping and appending remaining elements from the stack
//	while (isEmpty() == false) {
//		//done specially for removing brackets
//		if (top->data == '(') { pop(); }
//		else { result = result + pop(); }
//	}
//	return result;
//}
//template<typename S>
//string Stack<S>::infixToPrefix(string& infix) {
//	string reversed_infix = infix;
//	//reversing the stack
//	for (int i = 0, j = reversed_infix.length() - 1; i <= j; ++i, --j) {
//		swap(reversed_infix[i], reversed_infix[j]);
//	}
//	//for reversing brackets
//	for (int i = 0; i < reversed_infix.length(); i++) {
//		char ch = reversed_infix[i];
//		if (ch == '(') { reversed_infix[i] = ')'; }
//		else if (ch == ')') { reversed_infix[i] = '('; }
//	}
//	//converting reversed infix equation into postfix
//	string postFixExp = infixToPostfix(reversed_infix);
//	for (int i = 0, j = postFixExp.length() - 1; i < j; ++i, --j) {
//		swap(postFixExp[i], postFixExp[j]);	//then reversing it to get the prefix equation
//	}
//	return postFixExp;
//}
//
//int main()
//{
//	Stack<char> stack1;
//	string infixExp;
//	int choice;
//	cout << "Write the infix expression: ";	getline(cin, infixExp);
//	cout << "Infix: " << infixExp;
//	cout << "\nOptions:\n1.Postfix\n2.Prefix\n";
//	cout << "Enter your choice: ";	cin >> choice;
//	if (choice == 1) { string postfixExp = stack1.infixToPostfix(infixExp);	cout << "Postfix: " << postfixExp << endl; }
//	else if (choice == 2) { string prefixExp = stack1.infixToPrefix(infixExp); cout << "Prefix: " << prefixExp << endl; }
//	else { cout << "Invalid choice.\n"; }
//	return 0;
//}