#include <iostream>
using namespace std;
class Graph_Matrix {
private:
	int vertices;
	bool** adjacency_matrix;
public:
	Graph_Matrix(int num_vertices) {
		vertices = num_vertices;	//initializing vertices
		adjacency_matrix = new bool*[num_vertices];	 //putting false(0) in the adjacency matrix
		for (int i = 0; i < num_vertices; i++) {
			adjacency_matrix[i] = new bool[num_vertices];
			for (int j = 0; j < num_vertices; j++) {
				adjacency_matrix[i][j] = false;
			}
		}
	}
	void add_edge_directed(int from, int to) {
		adjacency_matrix[from][to] = true;	//just putting true(1) on one point
	}
	void add_edge_undirected(int from, int to) {
		adjacency_matrix[from][to] = true;	//putting true(1) on two points
		adjacency_matrix[to][from] = true;	//making our matrix symmetric
	}
	void print_graph() {
		for (int i = 0; i < vertices; i++) {	//for printing graph
			for (int j = 0; j < vertices; j++) {
				cout << adjacency_matrix[i][j] << " ";
			}
			cout << endl;
		}
	}
};
struct Node {	//linked list for adjacency list
	int data;
	Node* next;
	Node(int data) {
		this->data = data;
		next = nullptr;
	}
};
class Graph_list {
private:
	int vertices;
	Node** adjacency_list;

public:
	Graph_list(int num) {
		vertices = num;	//initializing vertices
		adjacency_list = new Node*[vertices];	//allocating space
		for (int i = 0; i < vertices; ++i) {
			adjacency_list[i] = nullptr;	//and nullifying it
		}
	}

	void add_edge_directed(int from, int to) {
		Node* newNode = new Node(to);	//allocating list to within made list from vertices
		newNode->next = adjacency_list[from];	//putting element on next of original from element
		adjacency_list[from] = newNode;	//connecting to make a link from original node
	}

	void add_edge_undirected(int from, int to) {
		Node* newNode_from = new Node(to);	//allocating list to within made list from vertices
		newNode_from->next = adjacency_list[from];		//putting element on next of original from adjacency list
		adjacency_list[from] = newNode_from;	//connecting to make a link from fromNode
		Node* newNode_to = new Node(from);	//allocating list from within made list from vertices
		newNode_to->next = adjacency_list[to];	//putting element on next of original from adjacency to
		adjacency_list[to] = newNode_to;	//connecting to make a link from newNode
	}

	void print_graph() {
		for (int i = 0; i < vertices; ++i) {	//printing list
			cout << i << ":-> ";	//node by node
			Node* current = adjacency_list[i];
			while (current != nullptr) {
				cout << current->data << " ";	//data from nodes
				current = current->next;
			}
			cout << endl;
		}
	}
};
int main()
{
	int size, option_matrix_or_list, option_directed_or_undirected;
	int from, to, edges, i = 0;
	while (true) {
		cout << "Enter the number of nodes: ";	cin >> size;
		cout << "\n1.Adjacency matrix\n";
		cout << "2.Adjacency list\n";
		cout << "0.Exit\n";
		cout << "\nEnter your choice: ";	cin >> option_matrix_or_list;
		if (option_matrix_or_list == 1) {
			Graph_Matrix graph(size);
			cout << "\n1.Directed\n";
			cout << "2.Undirected\n";
			cout << "\nEnter your choice: ";	cin >> option_directed_or_undirected;
			if (option_directed_or_undirected == 1) {
				cout << "\nEnter the total number of edges: ";	cin >> edges;
				if (edges <= size * size) {
					while (i != edges) {
						cout << "Enter the start: ";	cin >> from;
						cout << "Enter the end: ";	 cin >> to;
						if (from >= size || to >= size) {
							cout << "Enter valid starting and ending point.\n";
						}
						else {
							graph.add_edge_undirected(from, to);
							i++;
						}
					}
					graph.print_graph();
				}
				else {
					cout << "Invalid number of edges.\n";
				}

			}
			else if (option_directed_or_undirected == 2) {
				cout << "\nEnter the total number of edges: ";	cin >> edges;
				if (edges <= size * size) {
					while (i != edges) {
						cout << "Enter the start: ";	cin >> from;
						cout << "Enter the end: ";	 cin >> to;
						if (from >= size || to >= size) {
							cout << "Enter valid starting and ending point.\n";
						}
						else {
							graph.add_edge_undirected(from, to);
							i++;
						}
					}
					graph.print_graph();
				}
				else {
					cout << "Invalid number of edges.\n";
				}
			}
			else {
				cout << "Invalid option.\n";
				int choice;
				cout << "\nEnter 0 to end the program.\n";
				cout << "\nEnter any number to start again.";
				cout << "\nEnter your choice: ";	cin >> choice;
				if (choice == 0) {
					cout << "\nThanks for using our code.\n";
					break;
				}
			}
		}
		else if (option_matrix_or_list == 2) {
			Graph_list graph(size);
			cout << "\n1.Directed\n";
			cout << "2.Undirected\n";
			cout << "\nEnter your choice: ";	cin >> option_directed_or_undirected;
			if (option_directed_or_undirected == 1) {
				cout << "\nEnter the total number of edges: ";	cin >> edges;
				if (edges <= size * size) {
					while (i != edges) {
						cout << "Enter the start: ";	cin >> from;
						cout << "Enter the end: ";	 cin >> to;
						if (from >= size || to >= size) {
							cout << "Enter valid starting and ending point.\n";
						}
						else {
							graph.add_edge_undirected(from, to);
							i++;
						}
					}
					graph.print_graph();
				}
				else {
					cout << "Invalid number of edges.\n";
				}
			}
			else if (option_directed_or_undirected == 2) {
				cout << "\nEnter the total number of edges: ";	cin >> edges;
				if (edges <= size * size) {
					while (i != edges) {
						cout << "Enter the start: ";	cin >> from;
						cout << "Enter the end: ";	 cin >> to;
						if (from >= size || to >= size) {
							cout << "Enter valid starting and ending point.\n";
						}
						else {
							graph.add_edge_undirected(from, to);
							i++;
						}
					}
					graph.print_graph();
				}
				else {
					cout << "Invalid number of edges.\n";
				}
				cout << "Invalid option.\n";
			}
			int choice;
			cout << "\nEnter 0 to end the program.\n";
			cout << "\nEnter any number to start again.";
			cout << "\nEnter your choice: ";	cin >> choice;
			if (choice == 0) {
				cout << "\nThanks for using our code.\n";
				break;
			}
		}
		else if (option_matrix_or_list == 0) {
			cout << "Thanks for using our code.\n";
			break;
		}
		system("pause");
	}
	system("pause");
}