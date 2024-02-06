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
		adjacency_matrix[from][to] = true;	//putting true(1) one points
	}
	void print_graph() {
		for (int i = 0; i < vertices; i++) {	//for printing graph
			for (int j = 0; j < vertices; j++) {
				cout << adjacency_matrix[i][j] << " ";
			}
			cout << endl;
		}
	}
	bool checking_cycle(int vertex, bool* visited, int parent) {
		visited[vertex] = true;
		for (int neighbor = 0; neighbor < vertices; neighbor++) {	//traversing in the row of a vertex
			if (adjacency_matrix[vertex][neighbor] == true) {
				if (visited[neighbor] == false) {	//checking for any visited vertex
					if (checking_cycle(neighbor, visited, vertex) == true)	return true;
				}
				else if (neighbor != parent)	return true;	//if the visited neighbor is not the parent, then all is set
			}
		}
		return false;	//other wise not all is set
	}
	bool isCyclic() {
		bool* visited = new bool[vertices];		//allocating memory for visited vertices
		for (int i = 0; i < vertices; i++) {
			visited[i] = false;		//currently turning data to false, since vertices are not visited yet
		}
		for (int i = 0; i < vertices; i++) {
			if (visited[i] == false) {
				if (checking_cycle(i, visited, -1) == true)	return true;	//when the cycle is found
			}
		}
		delete[] visited;
		return false;	//else false
	}
	~Graph_Matrix() {	//destructor
		for (int i = 0; i < vertices; i++)	delete[]adjacency_matrix[i];
		delete[]adjacency_matrix;
	}
};
int main()
{
	int to, from;
	int vertices, edges;
	cout << "Enter the number of vertices: ";	cin >> vertices;
	cout << "Enter the number of edges: ";		cin >> edges;
	Graph_Matrix graph(vertices);
	cout << "\nEnter the edges: \n";
	for (int i = 0; i < edges; i++) {
		cout << "Enter the edge from: ";	cin >> from;
		cout << "Enter the edge to: ";	cin >> to;
		graph.add_edge_directed(from - 1, to - 1);
	}
	cout << "\nGraph:\n";
	graph.print_graph();
	cout << endl;
	if (graph.isCyclic() == true) {
		cout << "The graph has a cycle.\n";
	}
	else {
		cout << "The graph does not have a cycle.\n";
	}
	return 0;
}