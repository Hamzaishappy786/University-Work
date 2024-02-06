//#include <iostream>
//#include <string>
//using namespace std;
//struct Node {   //for linked list
//    int name;
//    Node* next;
//    Node(int name) {
//        this->name = name;
//        next = nullptr;
//    }
//};
//class Graph_list {  //for adjacency list
//private:
//    int vertices;
//    Node** adjacency_list;
//public:
//    Graph_list(int num) {   //constructor
//        vertices = num;
//        adjacency_list = new Node * [vertices];
//        for (int i = 0; i < vertices; ++i) {
//            adjacency_list[i] = nullptr;
//        }
//    }
//
//    void add_edge_undirected(int from, int to) {
//        Node* newNode_from = new Node(to);  //for tieing one edge
//        newNode_from->next = adjacency_list[from - 1];
//        adjacency_list[from - 1] = newNode_from;
//
//        Node* newNode_to = new Node(from);  //for tying another edge
//        newNode_to->next = adjacency_list[to - 1];
//        adjacency_list[to - 1] = newNode_to;
//    }
//    void print_graph() {    //for printing out the graph
//        for (int i = 0; i < vertices; ++i) {
//            cout << i + 1 << ":-> ";
//            Node* current = adjacency_list[i];
//            while (current != nullptr) {
//                cout << current->name << " ";
//                current = current->next;
//            }
//            cout << endl;
//        }
//    }
//    int find_person_with_most_outgoing_edges() {    //for finding the person with most edges
//        int maxOutgoingEdges = -1;  //starting edges
//        int personWithMostEdges = -1;   //returning factor
//
//        for (int i = 0; i < vertices; ++i) {    //for going through all vertices
//            int outgoingEdges = 0;
//            Node* current = adjacency_list[i];
//            while (current != nullptr) {
//                outgoingEdges++;
//                current = current->next;
//            }
//            if (outgoingEdges > maxOutgoingEdges) {
//                maxOutgoingEdges = outgoingEdges;   //adding edges when connection is detected
//                personWithMostEdges = i + 1;
//            }
//        }
//        return personWithMostEdges;
//    }
//};
//
//int main() {
//    int size, edges;
//    int to, from;
//    cout << "Enter the number of people: ";
//    cin >> size;
//    Graph_list list(size);
//    string* names = new string[size];
//    cin.ignore();
//    for (int i = 0; i < size; i++) {
//        cout << "Enter the name of " << i + 1 << " person: ";   getline(cin, names[i]);
//    }
//    cout << "Enter the number of edges: ";
//    cin >> edges;
//    for (int i = 0; i < edges; i++) {
//        cout << "Enter the connection from a person: ";
//        cin >> from;
//        cout << "Enter the connection to a person: ";
//        cin >> to;
//        list.add_edge_undirected(from, to);
//    }
//    list.print_graph();
//    int found = list.find_person_with_most_outgoing_edges();    //number of person with most connections
//    string found_name = names[found - 1];   //name of the person on the graph
//    cout << "Person with the most connections: " << found_name << endl;
//    delete[] names;
//    return 0;
//}