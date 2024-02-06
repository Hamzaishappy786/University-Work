#include <iostream>
using namespace std;
struct Node {
	int data;
	Node* next;
	Node(int data) {
		this->data = data;
		next = nullptr;
	}
};
class Graph_Matrix {
private:
	int vertices;
	bool** adjacency_matrix;
public:
	Graph_Matrix(int num_vertices) {
		vertices = num_vertices;	//initializing vertices
		adjacency_matrix = new bool* [num_vertices];	 //putting false(0) in the adjacency matrix
		for (int i = 1; i <= num_vertices; i++) {
			adjacency_matrix[i] = new bool[num_vertices];
			for (int j = 1; j <= num_vertices; j++) {
				adjacency_matrix[i][j] = false;
			}
		}
	}
	void add_edge_directed(int from, int to) {
		adjacency_matrix[from][to] = true;	//putting true(1) on two points
	}
	void bfs(int start_vertex, int vertixes[]) {	//breadth first search algorithm
		bool* visited = new bool[vertices];	//allocation for keeping track of visited vertices
		for (int i = 0; i < vertices; ++i) {
			visited[i] = false;		//keeping all of them false in the start
		}
		//queue
		int* queue = new int[vertices];	//for bfs traversal, made a queue
		int front = 0, rear = 0;
		visited[start_vertex] = true;	//marking the starting vertex as visited
		queue[rear] = start_vertex;	//now enqueuing it
		rear++;

		while (front != rear) {	//traversal
			int current_vertex = queue[front++];	//dequeing a vertex
			cout << current_vertex << " ";		//printing that vertex

			for (int i = 0; i < vertices; ++i) {	//exploring neighbors of that vertex
				if (adjacency_matrix[current_vertex][i] == 1 && visited[i] == false) {	//if there is an edge and vertex is not visited
					visited[i] = true;		//marking it true
					queue[rear] = i;		//and making an edge towards it
					rear++;
				}
			}
		}
		int counter = 0;
		for (int i = 0; i < vertices; i++) {
			for (int j = 0; j < vertices; j++) {
				if (queue[i] == vertixes[j]) {
					counter++;
				}
			}
		}
		if (counter == vertices) {
			cout << "\nGraph is connected.\n";
		}
		else {
			cout << "\nGraph is not connected.\n";
		}
		delete[] visited;	//deallocating memory
		delete[] queue;
	}
	void print_graph() {
		for (int i = 1; i <= vertices; i++) {	//for printing graph
			for (int j = 1; j <= vertices; j++) {
				cout << adjacency_matrix[i][j] << " ";
			}
			cout << endl;
		}
	}
};
int main()
{
	Graph_Matrix first(5);
	Graph_Matrix second(6);
	Graph_Matrix third(6);
	int first_vertices[5] = {1,2,3,4,5};
	int second_vertices[6] = {1,2,3,4,5,6};
	int third_vertices[6] = { 1,2,3,4,5,6 };

	first.add_edge_directed(1, 2);	first.add_edge_directed(2, 1);
	first.add_edge_directed(2, 3);	first.add_edge_directed(3, 2);
	first.add_edge_directed(3, 1);	first.add_edge_directed(1, 3);
	first.add_edge_directed(4, 5);	first.add_edge_directed(5, 4);

	second.add_edge_directed(1, 4);	second.add_edge_directed(4, 1);
	second.add_edge_directed(4, 5);	second.add_edge_directed(5, 4);
	second.add_edge_directed(1, 5);	second.add_edge_directed(5, 1);
	second.add_edge_directed(2, 3);	second.add_edge_directed(3, 2);
	second.add_edge_directed(3, 5);	second.add_edge_directed(5, 3);
	second.add_edge_directed(5, 2);	second.add_edge_directed(2, 5);

	third.add_edge_directed(1, 2);	third.add_edge_directed(2, 1);
	third.add_edge_directed(2, 3);	third.add_edge_directed(3, 2);
	third.add_edge_directed(3, 1);	third.add_edge_directed(1, 3);
	third.add_edge_directed(4, 5);	third.add_edge_directed(5, 4);
	third.add_edge_directed(5, 6);	third.add_edge_directed(6, 5);
	third.add_edge_directed(6, 4);	third.add_edge_directed(4, 6);

	cout << "Graph 1:\n";
	first.print_graph();
	cout << "\nTraversing graph 1: ";
	first.bfs(1, first_vertices);
	cout << "\nGraph 2:\n";
	second.print_graph();
	cout << "\nTraversing graph 2: ";
	second.bfs(1, second_vertices);
	cout << "\nGraph 3:\n";
	third.print_graph();
	cout << "\nTraversing graph 2: ";
	third.bfs(1, third_vertices);
	system("pause>3");
	return 0;
}