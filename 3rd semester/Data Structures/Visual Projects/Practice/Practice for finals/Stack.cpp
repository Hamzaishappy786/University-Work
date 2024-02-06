//#include <iostream>
//using namespace std;
//class Stack {
//	int size;
//	int top;
//	int* arr;
//public:
//	Stack(int size) :size(size), top(-1) { arr = new int[size]; }
//	bool isEmpty() {
//		return top == -1;
//	}
//	void push(int data) {
//		if (top == size - 1) {
//			cout << "Stack overflow.";
//		}
//		else if (top < size - 1) {
//			arr[++top] = data;
//		}
//	}
//	int pop() {
//		if (!isEmpty()) {
//			return arr[top--];
//		}
//		else {
//			cout << "Stack is empty.";
//			return -1;
//		}
//	}
//	int size() {
//		return top + 1;
//	}
//	void display() {
//		for (int i = 0; i <= top; i++) {
//			cout << arr[i] << " ";
//		}
//		cout << endl;
//	}
//};
//int main()
//{
//
//	return 0;
//}
//bool isOperator(char ch) {
//	return ch == '+' || ch == '-' || ch == '*' || ch == '/';
//}
//int precedence(char op) {
//	if (op == '+' || op == '-') { return 1; }
//	else if (op == '*' || op == '/') { return 2; }
//	return 0;
//}
//string infixToPostfix(const string& infix) {
//	string postFix;
//	const int SIZE = infix.length();
//	char* operatorStack = new char[SIZE];
//	int top = -1;
//	for (int i = 0; i < infix.length(); i++) {
//		char ch = infix[i];
//		if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9')) {
//			postFix += ch;
//		} else if (ch == '(') {
//			operatorStack[++top] = ch;	//push method
//		} else if (ch == ')') {
//			while (top != -1 && operatorStack[top] != '(') {
//				postFix += operatorStack[top--];	//pop method
//			}
//			operatorStack[++top] = ch;
//		} else if (isOperator(ch)) {
//			while (top != -1 && precedence(ch) <= precedence(operatorStack[top])) {
//				postFix += operatorStack[top--];
//			}
//			operatorStack[++top] = ch;
//		}
//	}
//	while (top != -1) {
//		postFix += operatorStack[top--];
//	}
//	delete[]operatorStack;
//	return postFix;
//}
//int evaluate_postfix(const char* postfix) {
//	const int SIZE = strlen(postfix);
//	int* operand_stack = new int[SIZE];
//	int top = -1;
//	for (int i = 0; i < SIZE; i++) {
//		char ch = postfix[i];
//		if (ch >= '0' && ch <= '9') {
//			operand_stack[++top] = ch - '0';
//		}
//		else if (isOperator(ch) == true) {
//			int second_operand = operand_stack[top--];
//			int first_operand = operand_stack[top--];
//			int result;
//			if (ch == '+') {
//				result = first_operand + second_operand;
//			}else if (ch == '-') {
//				result = first_operand - second_operand;
//			}else if (ch == '*') {
//				result = first_operand * second_operand;
//			}else if (ch == '/') {
//				result = first_operand / second_operand;
//			}
//			operand_stack[++top] = result;
//		}
//		else {
//			cout << "Gand marao.html";
//		}
//	}
//	int final_result = operand_stack[top];
//	delete[]operand_stack;
//	return final_result;
//}
//int evaluate_prefix(const char* prefix) {
//	const int SIZE = strlen(prefix);
//	int* operand_stack = new int[SIZE];
//	int top = -1;
//	for (int i = strlen(prefix); i >= 0; i--) {
//		char ch = prefix[i];
//		if (ch >= '0' && ch <= '9') {
//			operand_stack[++top] = ch - '0';
//		}
//		else if (isOperator(ch) == true) {
//			int first_operand = operand_stack[top--];
//			int second_operand = operand_stack[top--];
//			int result;
//			if (ch == '+') {
//				result = first_operand + second_operand;
//			}else if (ch == '-') {
//				result = first_operand - second_operand;
//			}else if (ch == '*') {
//				result = first_operand * second_operand;
//			}else if (ch == '/') {
//				result = first_operand / second_operand;
//			}
//			operand_stack[++top] = result;
//		}
//		else {
//			cout << "Gand marao.html";
//		}
//	}
//	int final_result = operand_stack[top];
//	delete[]operand_stack;
//	return final_result;
//}
//
//int main()
//{
//	char stack[] = "23*5+";
//	char stack2[] = "+*235";
//	int result = evaluate_postfix(stack);
//	cout << result;
//	int result2 = evaluate_prefix(stack2);
//	cout << result2;
//	string infix = "(2*3)+5";
//	string postFix = infixToPostfix(infix);
//	cout << postFix;
//	return 0;
//}
//#include <iostream>
//
//const int MAX_VERTICES = 7;
//struct Edge {
//    int destination;
//};
//struct Graph {
//    Edge adjList[MAX_VERTICES][MAX_VERTICES];
//    int vertices;
//};
//
//void addEdge(Graph& graph, int source, int destination) {
//    Edge edge;
//    edge.destination = destination;
//    graph.adjList[source][destination] = edge;
//     edge.destination = source;
//     graph.adjList[destination][source] = edge;
//}
//
//void DFSUtil(const Graph& graph, int vertex, bool visited[]) {
//    visited[vertex] = true;
//    std::cout << vertex << " ";
//    for (int i = 0; i < graph.vertices; ++i) {
//        if (graph.adjList[vertex][i].destination != -1 && !visited[i]) {
//            DFSUtil(graph, i, visited);
//        }
//    }
//}
//
//void DFS(const Graph& graph, int startVertex) {
//    bool visited[MAX_VERTICES];
//    for (int i = 0; i < MAX_VERTICES; ++i) {
//        visited[i] = false;
//    }
//    DFSUtil(graph, startVertex, visited);
//}
//
//int main() {
//    Graph graph;
//    graph.vertices = 7; // Change the number of vertices as needed
//    for (int i = 0; i < MAX_VERTICES; ++i) {
//        for (int j = 0; j < MAX_VERTICES; ++j) {
//            graph.adjList[i][j].destination = -1;
//        }
//    }
//
//    addEdge(graph, 0, 1);
//    addEdge(graph, 0, 2);
//    addEdge(graph, 1, 3);
//    addEdge(graph, 1, 4);
//    addEdge(graph, 2, 5);
//    addEdge(graph, 2, 6);
//
//    std::cout << "DFS starting from vertex 0: ";
//    DFS(graph, 0);
//
//    return 0;
//}
