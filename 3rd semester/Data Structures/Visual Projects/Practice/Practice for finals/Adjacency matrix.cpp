//#include <iostream>
//using namespace std;
//#define RED "\033[0;31m"
//#define GREEN "\033[0;32m"
//#define YELLOW "\033[0;33m"
//#define RESET "\033[0m"
//
//class Adjacency_matrix {
//private:
//	int nodes;
//	int** adjMatrix;
//public:
//	Adjacency_matrix(int nodes) :nodes(nodes) {
//		adjMatrix = new int*[nodes];
//		for (int i = 0; i < nodes; i++) {
//			adjMatrix[i] = new int[nodes];
//		}
//		for (int i = 0; i < nodes; i++) {
//			for (int j = 0; j < nodes; j++) {
//				adjMatrix[i][j] = 0;
//			}
//		}
//	}
//	void addEdge(int source, int destination) {
//		adjMatrix[source][destination] = 1;
//		adjMatrix[destination][source] = 1;
//	}
//	void print_matrix() {
//		cout << "\n   ";
//		for (int i = 0; i < nodes; i++) {
//			cout << RED << i << " ";
//		}cout << endl << endl << RESET;
//		for (int i = 0; i < nodes; i++) {
//			cout << RED << i << "  " << RESET;
//			for (int j = 0; j < nodes; j++) {
//				if (adjMatrix[i][j] == 1)
//					cout << GREEN << adjMatrix[i][j] << " " << RESET;
//				else if (adjMatrix[i][j] == 0)
//					cout << YELLOW << adjMatrix[i][j] << " " << RESET;
//			}
//			cout << endl;
//		}
//	}
//	bool check_edge(int source, int destination) {
//		return adjMatrix[source][destination] == 1;
//	}
//	bool connected_or_not() {
//		bool* visited = new bool[nodes];
//		for (int i = 0; i < nodes; i++) {
//			visited[i] = false;
//		}
//		int* dfsStackConnected = new int[nodes];
//		int top = -1;
//		dfsStackConnected[++top] = 0;
//		while (top != -1) {
//			int current = dfsStackConnected[top--];
//			if (!visited[current]) {
//				visited[current] = true;
//				for (int neighbor = 0; neighbor < nodes; neighbor++) {
//					if (adjMatrix[current][neighbor] == 1 && visited[neighbor] == false) {
//						dfsStackConnected[++top] = neighbor;
//					}
//				}
//			}
//		}
//		for (int i = 0; i < nodes; i++) {
//			if (visited[i] == false) {
//				return false;
//			}
//		}
//		return true;
//	}
//	void DFS(int starting_vertex) {
//		bool* visited = new bool[nodes];
//		for (int i = 0; i < nodes; i++) {
//			visited[i] = false;
//		}
//		int* dfsStackConnected = new int[nodes];
//		int top = -1;
//		dfsStackConnected[++top] = starting_vertex;
//		while (top != -1) {
//			int current = dfsStackConnected[top--];
//			if (visited[current] == false) {
//				cout << current << " ";
//				visited[current] = true;
//				for (int i = 0; i < nodes; i++) {
//					if (adjMatrix[current][i] == 1 && visited[i] == false) {
//						dfsStackConnected[++top] = i;
//					}
//				}
//			}
//		}
//		delete[]dfsStackConnected;
//		delete[]visited;
//
//	}
//	~Adjacency_matrix() {
//		for (int i = 0; i < nodes; i++) {
//			delete[] adjMatrix[i];
//		}
//		delete[]adjMatrix;
//	}
//};
//
//struct Node {
//	int data;
//	Node* next;
//	Node(int data) :data(data), next(nullptr) {}
//};
//class Adjacency_list {
//private:
//	int nodes;
//	Node** list;
//public:
//	Adjacency_list(int total) :nodes(total) {
//		list = new Node*[nodes];
//		for (int i = 0; i < nodes; i++) {
//			list[i] = nullptr;
//		}
//	}
//	void addEdge(int source, int destination) {
//		Node* newNode = new Node(destination);
//		newNode->next = list[source];
//		list[source] = newNode;
//
//		Node* nextNode = new Node(source);
//		nextNode->next = list[destination];
//		list[destination] = nextNode;
//	}
//	void print_list() {
//		for (int i = 0; i < nodes; i++) {
//			cout << GREEN << i << RESET << YELLOW << "->" << RESET;
//			Node* current = list[i];
//			while (current != nullptr) {
//				cout << RED << " " << current->data << RESET;
//				current = current->next;
//			}
//			cout << endl;
//		}
//	}
//	bool check_edge(int source, int destination) {
//		Node* current = list[source];
//		while (current != nullptr) {
//			if (current->data == destination) {
//				return true;
//			}
//			current = current->next;
//		}
//		return false;
//	}
//	void DFS(int starting_vertex) {
//		bool* visited = new bool[nodes];
//		for (int i = 0; i < nodes; i++) {
//			visited[i] = false;
//		}
//		int* dfsStackList = new int[nodes];
//		int top = -1;
//		dfsStackList[++top] = starting_vertex;
//		while (top != -1) {
//			int current = dfsStackList[top--];
//			if (visited[current] == false) {
//				cout << current << " ";
//				visited[current] = true;
//				Node* neighborNode = list[current];
//				while (neighborNode != nullptr) {
//					int neighbor = neighborNode->data;
//					if (visited[neighbor] == false) {
//						dfsStackList[++top] = neighbor;
//					}
//					neighborNode = neighborNode->next;
//				}
//			}
//		}
//		delete[]dfsStackList;
//		delete[]visited;
//	}
//	bool connected_or_not() {
//		bool* visited = new bool[nodes];
//		for (int i = 0; i < nodes; i++) {
//			visited[i] = false;
//		}
//		int* dfsStackConnected = new int[nodes];
//		int top = -1;
//		dfsStackConnected[++top] = 0;
//		while (top != -1) {
//			int current = dfsStackConnected[top--];
//			if (visited[current] == false) {
//				visited[current] = true;
//				Node* neighborNode = list[current];
//				while (neighborNode != nullptr) {
//					int neighbor = neighborNode->data;
//					if (visited[neighbor] == false) {
//						dfsStackConnected[++top] = neighbor;
//					}
//					neighborNode = neighborNode->next;
//				}
//			}
//		}
//		for (int i = 0; i < nodes; i++) {
//			if (visited[i] == false) {
//				return false;
//			}
//		}
//		return true;
//	}
//	~Adjacency_list() {
//		for (int i = 0; i < nodes; i++) {
//			delete[]list[i];
//		}
//		delete[]list;
//	}
//};
//int main()
//{
//	Adjacency_matrix graph(6);
//	graph.addEdge(1, 2);	graph.addEdge(1, 3);	graph.addEdge(1, 4);
//	graph.addEdge(2, 3);	graph.addEdge(2, 5);
//	graph.addEdge(3, 4);	graph.addEdge(3, 1);	graph.addEdge(3, 3);	graph.addEdge(3, 4);
//	graph.addEdge(4, 1);	graph.addEdge(1, 5);
//	graph.addEdge(5, 1);	graph.addEdge(5, 0);
//	graph.print_matrix();
//	cout << graph.check_edge(1, 6) << " ";
//	cout << graph.connected_or_not();	cout << endl;
//	graph.DFS(2);
//	cout << endl << endl;
//	
//	Adjacency_list list(6);
//	list.addEdge(1, 2);	list.addEdge(1, 3);	list.addEdge(1, 4);
//	list.addEdge(2, 3);	list.addEdge(2, 5);
//	list.addEdge(3, 4);	list.addEdge(3, 1);	list.addEdge(3, 3);	list.addEdge(3, 4);
//	list.addEdge(4, 1);	list.addEdge(1, 5);
//	list.addEdge(5, 1);	list.addEdge(5, 0);
//	list.print_list();
//	cout << list.check_edge(1, 6) << " ";
//	cout << list.connected_or_not() << endl;
//	list.DFS(2);
//	return 0;
//}