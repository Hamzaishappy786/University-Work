//#include <iostream>
//using namespace std;
//class Graph {
//private:
//	int vertices;
//	int** adjacency_matrix;
//public:
//	Graph(int vertices) {	//constructor
//		this->vertices = vertices;
//		adjacency_matrix = new int* [vertices];	//allocating memory for matrix
//		for (int i = 0; i < vertices; ++i) {
//			adjacency_matrix[i] = new int[vertices];
//			for (int j = 0; j < vertices; ++j) {
//				adjacency_matrix[i][j] = 0;
//			}
//		}
//	}
//
//	void add_edge_undirected(int to, int from) {	//for adding edges
//		adjacency_matrix[to][from] = 1;	//i trued both of them for undirected graph
//		adjacency_matrix[from][to] = 1;
//	}
//
//	void dfs(int node, bool* visited) {	//dfs for getting in depth of our graph
//		visited[node] = true;	//first visting node is true
//		for (int i = 0; i < vertices; ++i) {	//now checking it's neighbors
//			if (adjacency_matrix[node][i] && !visited[i]) {
//				dfs(i, visited);
//			}
//		}
//	}
//
//	int countSpanningTrees() {	//for counting spanning trees
//		int connected_vertices = 0;
//		bool* visited = new bool[vertices] {false};
//		for (int i = 0; i < vertices; ++i) {	//counting the connected vertices
//			if (visited[i] == false) {
//				dfs(i, visited);
//				connected_vertices++;
//			}
//		}
//		int edges = 0;	//turning edges 0 for starters
//		for (int i = 0; i < vertices; ++i) {	//now checking the graph from a single vertex
//			for (int j = i + 1; j < vertices; ++j) {	//checking the graph from it's neighbors
//				edges = edges + adjacency_matrix[i][j];
//			}
//		}
//		int determinant = edges - vertices + connected_vertices;
//		delete[] visited;
//		return determinant;
//	}
//
//	~Graph() {	//deallocating memory
//		for (int i = 0; i < vertices; ++i) {
//			delete[] adjacency_matrix[i];
//		}
//		delete[] adjacency_matrix;
//	}
//};
//
//int main() {
//	int nodes, edges;
//	int start, end;
//	cout << "Enter the number of nodes: ";
//	cin >> nodes;
//
//	Graph graph(nodes);
//	cout << "Enter the number of edges: ";
//	cin >> edges;
//	cout << endl;
//	for (int i = 0; i < edges; ++i) {
//		cout << "Enter the starting vertex: ";	cin >> start;
//		cout << "Enter the ending vertex: ";	cin >> end;
//		graph.add_edge_undirected(start - 1, end - 1);
//	}
//	cout << "The number of spanning trees in the given graph is: " << graph.countSpanningTrees() + 1 << endl;
//	system("pause>3");
//	return 0;
//}