//#include <iostream>
//using namespace std;
//void display_MinimalSpanningTree(int parent[], int** graph, int size) {
//    cout << "Edge \tWeight\n";  //for printing out the spanning tree
//    for (int i = 1; i < size; i++)
//        cout << parent[i] << " - " << i << "\t" << graph[i][parent[i]] << endl;
//}
//void primMinimalSpanningTree(int** graph, int size) {   //using prim's algorithm
//    int max_limit = 1000;    //max limit for out graph's weights
//    bool* mstSet = new bool[size];      //for checking whether the vertex is included in the spanning tree
//    int* parent = new int[size];    //for storing the parent of vertex int the spanning tree
//    int* weights = new int[size];       //for storing weights in between the vertices
//
//    for (int i = 0; i < size; i++) {
//        weights[i] = max_limit;
//        mstSet[i] = false;
//    }
//    weights[0] = 0; //first vertex
//    parent[0] = -1; //no parent
//    for (int count = 0; count < size - 1; count++) {
//        int min = max_limit;
//        int min_index;
//        for (int vertex = 0; vertex < size; vertex++) {
//            if (!mstSet[vertex] && weights[vertex] < min) {
//                min = weights[vertex];
//                min_index = vertex;
//            }
//        }
//        int chosen_vertex = min_index;  //selected vertex
//        mstSet[chosen_vertex] = true;   //truing chosen vertex
//
//        for (int v = 0; v < size; v++) {    //updating weights and parent values for neighbors
//            if (graph[chosen_vertex][v] && !mstSet[v] && weights[v] > graph[chosen_vertex][v]) {
//                weights[v] = graph[chosen_vertex][v];
//                parent[v] = chosen_vertex;
//            }
//        }
//    }
//    display_MinimalSpanningTree(parent, graph, size);
//}
//
//int main()
//{
//    int size;
//    cout << "Enter the size(sizexsize) of the matrix(graph): "; cin >> size;
//    int** graph;
//    graph = new int* [size];
//    for (int i = 0; i < size; i++) {
//        graph[i] = new int[size];
//    }
//    cout << "Enter the adjacency matrix:\n";
//    for (int i = 0; i < size; ++i) {
//        for (int j = 0; j < size; ++j) {
//            cin >> graph[i][j];
//        }
//    }
//    primMinimalSpanningTree(graph, size);
//    return 0;
//}