//#include <iostream>
//using namespace std;
//struct Node {
//	int data;
//	Node* next;
//	Node(int data) {
//		this->data = data;
//		next = nullptr;
//	}
//};
//class Graph_list {
//private:
//	int vertices;
//	Node** adjacency_list;
//
//public:
//	Graph_list(int num) {
//		vertices = num;	//initializing vertices
//		adjacency_list = new Node * [vertices];	//allocating space
//		for (int i = 0; i <= vertices; ++i) {
//			adjacency_list[i] = nullptr;	//and nullifying it
//		}
//	}
//
//	void add_edge_undirected(int from, int to) {
//		Node* newNode_from = new Node(to);	//allocating list to within made list from vertices
//		newNode_from->next = adjacency_list[from];		//putting element on next of original from adjacency list
//		adjacency_list[from] = newNode_from;	//connecting to make a link from fromNode
//		Node* newNode_to = new Node(from);	//allocating list from within made list from vertices
//		newNode_to->next = adjacency_list[to];	//putting element on next of original from adjacency to
//		adjacency_list[to] = newNode_to;	//connecting to make a link from newNode
//	}
//
//	bool dfs(int currentVertex, int* visited, int shaded) {	//chose dfs for this thing
//		visited[currentVertex] = shaded;	//for visiting vertices
//		Node* current = adjacency_list[currentVertex];
//		while (current != nullptr) {	//traversing through the neighbors of list's kth node
//			int adjacent_vertex = current->data;
//			if (visited[adjacent_vertex] == -1) {	//recursive checking for visted vertices
//				if (dfs(adjacent_vertex, visited, 1 - shaded) == false) {
//					return false;
//				}
//			}
//			else if (visited[adjacent_vertex] == visited[currentVertex]) {	//for same color, not bipartite
//				return false;
//			}
//
//			current = current->next;
//		}
//
//		return true; //all vertices are found with no mixing
//	}
//
//	bool bipartite_check() {
//		int* visited = new int[vertices]; //array to store colors (0 and 1)
//		for (int i = 0; i < vertices; ++i) {
//			visited[i] = -1; //initialize all colors as not visiting (-1)
//		}
//
//		for (int shaded = 0; shaded < vertices; shaded++) {
//			if (visited[shaded] == -1) {
//				if (dfs(shaded, visited, 0) == false) {
//					cout << "This is not a bipartite graph.\n";
//					delete[] visited;
//					return false;
//				}
//			}
//		}
//
//		cout << "This is a bipartite graph.\n";
//		delete[] visited;
//		return true;
//	}
//
//	void print_graph() {
//		for (int i = 1; i <= vertices; ++i) {	//printing list
//			cout << i << ":-> ";
//			Node* current = adjacency_list[i];
//			while (current != nullptr) {	//traversing for neighbors
//				cout << current->data << " ";
//				current = current->next;
//			}
//			cout << endl;
//		}
//	}
//};
//int main()
//{
//	int size, edges;
//	int from, to;
//	cout << "Enter the vertices of the graph: ";
//	cin >> size;
//	Graph_list obj(size);
//	cout << "Enter the number of edges: ";	cin >> edges;
//	for (int i = 0; i < edges; i++) {
//		cout << "Enter the starting vertex: ";	cin >> from;
//		cout << "Enter the ending vertex: ";	cin >> to;
//		obj.add_edge_undirected(from, to);
//	}
//	obj.print_graph();
//	cout << "\n\nStatus:\n";
//	obj.bipartite_check();
//	system("pause>3");
//	return 0;
//}