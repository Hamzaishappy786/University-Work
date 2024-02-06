#include<iostream>
#include<string>
using namespace std;
struct stackelement {
	char character;
	stackelement* next;
	stackelement(char character) {
		this->character = character;
		next = NULL;
	}
};
class stack {
	stackelement* topofstack;
	string data;
public:
	stack() :topofstack(nullptr) {}
	stackelement* createnode(char t) {
		stackelement* nn = new stackelement(t);
		return nn;
	}
	bool isempty() {
		if (topofstack == nullptr) {
			return true;
		}
		else {
			return false;
		}
	}

	void insert(char ch) {
		if (ch >= '0' || ch <= '1') {
			data = data + ch;
		}
		else if (ch == '+' || ch == '-' || ch == '*' || ch == '!' || ch == '>') {
			while (!isempty() && precedence(ch) <= precedence(topofstack->character) && topofstack->character != '(') {
				char popstack = pop();
				data = data + popstack;
			}
			push(ch);
		}
		else if (ch == '(') {
			push(ch);
		}
		else if (ch == ')') {
			while (!isempty() && topofstack->character != '(') {
				char popstack = pop();
				data = data + popstack;
			}
			pop();
		}
		cout << "current=" << ch << "\t\t" << "Stack=";
		stackelement* temp = topofstack;
		while (temp != NULL) {
			//cout << temp->character;
			temp = temp->next;
		}
		//cout << "\t\t" << "string=" << data;
		//cout << "\n";
	}

	void evaluatinginfixexpression2(string dat) {
		int i = 0;
		while (i < dat.length()) {
			cout << "current=" << data[i] << "\t";
			if ((dat[i] == '0' || dat[i] == '9')) {
				if (dat[i] != ' ') {
					push(dat[i]);
				}
			}
			else {
				char ch;
				int value;
				int num1 = pop() - '0';
				int num2 = pop() - '0';
				cout << "\tnum1=" << num1 << "\t" << "num2=" << num2 << "\t";
				if (dat[i] == '+') {
					if (num1 == 1 || num2 == 1) {
						value = 1;
					}
					else {
						value = 0;
					}
					push('0' + value);
				}
				else if (dat[i] == '-') {
					if (num1 == 1 && num2 == 1) {
						value = 1;
					}
					else {
						value = 0;
					}
					push('0' + value);
				}
				else if (dat[i] == '*') {
					if (num1 == 0 || num2 == 0) {
						value = 0;
					}
					else {
						value = 1;
					}
					push('0' + value);
				}
				else if (dat[i] == '!') {
					if (num1 == 1) {
						value = 1;
					}
					else {
						value = 0;
					}
					push('0' + value);
				}
			}
		//	cout << "\t\t" << "Stack=";
			stackelement* temp = topofstack;
			while (temp != NULL) {
			//	cout << temp->character;
				temp = temp->next;
			}
			cout << endl;
			i++;
		}
		int finalanswer = pop() - '0';
	//	cout << "final answer" << finalanswer;
	}
	void remaining() {
		while (!isempty()) {
			char ch = pop();
			if (ch == '(') {
				pop();
			}
			else {
				data = data + ch;
			}
		}
	}
	void push(char ch) {
		stackelement* newnode = new stackelement(ch);
		if (topofstack == nullptr) {
			topofstack = newnode;
		}
		else {
			newnode->next = topofstack;
			topofstack = newnode;
		}
	}
	char pop() {
		char ch;
		stackelement* tempptr = topofstack;
		if (tempptr != NULL) {
			if (tempptr->next != NULL) {
				topofstack = tempptr->next;
			}
			else {
				topofstack = NULL;
			}
			ch = tempptr->character;
			delete tempptr;
		}
		else {
		//	cout << "list is empty";
			//ch = '\0';
		}
		return ch;
	}
	int precedence(char op) {
		if (op == '-') {
			return 1;
		}
		if (op == '>') {
			return 2;
		}
		else if (op == '+') {
			return 3;
		}
		else if (op == '*') {
			return 4;
		}
		else if(op=='!') {
			return 5;
		}
		else {
			return 0;
		}
		
	}
	string finaloutput() {
		return data;
	}
};
void truthtableinnitialization(int numberofvariables, int lengthoftruthtab, int** truthtable,int *elements) {
	int division=0, temporary = lengthoftruthtab, temporaryextension;
	for (int i = 0; i < numberofvariables; i++) {
		for (int k = i; k >= 0; k--) {
			division++;
		}
		for (int k = 0; k < division; k++) {
			temporary /= 2;
		}
		temporaryextension = temporary;
		for (int j = 0; j < lengthoftruthtab; j++) {
			if (elements[i] == 0) {
				truthtable[i][j] = 1;
			}
			else if (temporaryextension != 0) {
				if (truthtable[i][j - 1] == 1) {
					truthtable[i][j] = 1;
				}
				else {
					truthtable[i][j] = 0;
				}
			}
			else {
				temporaryextension = temporary;
				if (truthtable[i][j - 1] == 1) {
					truthtable[i][j] = 0;
				}
				else {
					truthtable[i][j] = 1;
				}
			}
			elements[i]++;
			temporaryextension--;
		}
		temporary = lengthoftruthtab;
		division = 0;
	}
}
int numofvariables(string expression,string& variables) {
	int numberofvariables=0;
	for (int i = 0; i < expression.length(); i++) {
		if (expression[i] >= 'a' && expression[i] <= 'z' || expression[i] >= 'A' && expression[i] <= 'Z') {
			variables = variables + expression[i];
			numberofvariables++;
		}
	}
	return numberofvariables;
}
string evaluatinganswer(string data) {
	stack s1;
	int j = 0;
	reverse(data.begin(), data.end());
	for (int i = 0; i < data.length(); i++) {
		if (data[i] == ')') {
			data[i] = '(';
		}
		else {
			data[i] == ')';
		}
	}
	//cout << endl;
	while (j < data.length()) {
		s1.insert(data[j]);
		j++;
	}
	//cout << "\n\ninfix to prefix conversion\n";
	s1.remaining();
	//s1.printprefix();
	string str = s1.finaloutput();
	reverse(str.begin(), str.end());
	//cout << str;
	s1.evaluatinginfixexpression2(str);
//	s1.emptyingthestring();
	return str;
}
int main() {
	int numberofvariables = 0,lengthoftruthtable=1, ** truthtable, * elements;
	string expression, variables="", solvingexpresion;
	bool expressionvalidity=true;
	char* ch;
	// check expression is valid or not 
	for (int j = 0; j < 1; j++) {
		cout << "1.Eneter * for AND\n";
		cout << "2.Enter + for OR\n";
		cout << "3.Enter ! for NOT\n";
		cout << "4.Enter > for implies\n";
		cout << "5.Enter - for biconditional\n";
		cout << "Enter expression: ";
		cin >> expression;
		for (int i = 0; i < expression.length(); i++) {
			if (i != 0) {
				if (((expression[i] >= 'a' && expression[i] <= 'z' || expression[i] >= 'A' && expression[i] <= 'Z') && (expression[i - 1] >= 'a' && expression[i - 1] <= 'z' || expression[i - 1] >= 'A' && expression[i - 1] <= 'Z') )|| (expression[i]==expression[i-1])) {
					expressionvalidity = false;
					break;
				}
			}
		}
		if (expressionvalidity == false) {
			cout << " you have entered wrong expression enter again"<<endl;
			j--;
		}
	}
	//number of variables
	numberofvariables = numofvariables(expression, variables); 
	cout << numberofvariables;

	//length of a whole truthtable
	for (int i = 0; i < numberofvariables; i++) {
		lengthoftruthtable *= 2;
	}
	cout <<lengthoftruthtable;
	elements = new int[numberofvariables];
//	solvingexpresion = new int[numberofvariables];
	for (int i = 0; i < numberofvariables; i++) {
		elements[i] = 0;
	}
	truthtable = new int* [numberofvariables];
	ch = new char[numberofvariables];
	for (int i = 0; i < numberofvariables; i++) {
		truthtable[i] = new int[lengthoftruthtable];
	}

	//printing truthtable
	cout << "Printing truth tables" << endl;
	for (int i = 0; i < numberofvariables; i++) {
		cout << variables[i] << "\t\t";
	}
	cout << expression;
	solvingexpresion = expression;
	truthtableinnitialization(numberofvariables, lengthoftruthtable, truthtable, elements);
	cout << endl;
	int count = 0;
	for (int i = 0; i < lengthoftruthtable; i++) {
		for (int j = 0; j < numberofvariables; j++) {
			 ch[j] = truthtable[j][i]+'0';
			 cout << ch[j] << "\t\t";
			//cout << truthtable[j][i]<<"\t\t";
		}
		for (int k = 0; k <expression.length(); k++) {
			if (solvingexpresion[k] >= 'a' && solvingexpresion[k] <= 'z' || solvingexpresion[k] >= 'A' && solvingexpresion[k] <= 'Z') {
				solvingexpresion[k] = ch[count];
				count++;
			}
		}
		cout << solvingexpresion;
//		string str=evaluatinganswer(solvingexpresion);
		//cout << str;
		cout << expression;
		solvingexpresion = "";
		solvingexpresion = expression;
		cout << endl;
	}
	system("pause");
	return 0;
}