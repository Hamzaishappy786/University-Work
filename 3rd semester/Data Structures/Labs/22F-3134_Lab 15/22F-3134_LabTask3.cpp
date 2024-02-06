//#include <iostream>
//using namespace std;
//
//void printSolution(int* distance, int numVertices) {    //function for printing the whole distance from source
//    cout << "Vertex    Distance from Source\n";
//    for (int i = 0; i < numVertices; i++) {
//        cout << i << "\t\t\t" << distance[i] << "\n";
//    }
//}
//void dijkstra_theorem(int** adjacencyMatrix, int source, int numVertices) {
//    int infinity = 1000;
//    int* distance = new int[numVertices];  //arrayfor storing the shortest distance from source to the neighbors
//    bool* shortestPathTreeSet = new bool[numVertices];  //array for keeping track of vertices included in the shortest path tree
//    for (int i = 0; i < numVertices; i++) {
//        distance[i] = infinity;     //initializing distance and shortest tree path
//        shortestPathTreeSet[i] = false;
//    }
//    distance[source] = 0;  //distance from source to itself
//    for (int count = 0; count < numVertices - 1; count++) { //for finding the shortest path
//        int maxValue = 1000;
//        int minValue = maxValue;
//        int minIndex = -1;
//
//        for (int vertex = 0; vertex < numVertices; vertex++) {
//            if (!shortestPathTreeSet[vertex] && distance[vertex] < minValue) {
//                minValue = distance[vertex];
//                minIndex = vertex;
//            }
//        }
//        int currentVertex = minIndex;   //for checking minimum distance between neighbors
//        shortestPathTreeSet[currentVertex] = true;
//        for (int adjacentVertex = 0; adjacentVertex < numVertices; adjacentVertex++) {
//            if (!shortestPathTreeSet[adjacentVertex] && adjacencyMatrix[currentVertex][adjacentVertex] && distance[currentVertex] != infinity) {
//                int newDistance = distance[currentVertex] + adjacencyMatrix[currentVertex][adjacentVertex];
//                if (newDistance < distance[adjacentVertex]) {
//                    distance[adjacentVertex] = newDistance;
//                }
//            }
//        }
//    }
//    printSolution(distance, numVertices);
//    delete[] distance;  //deallocating memory
//    delete[] shortestPathTreeSet;
//}
//
//int main() {
//    int numVertices;
//    int** adjacencyMatrix;
//
//    cout << "Enter the number of vertices: ";
//    cin >> numVertices;
//    adjacencyMatrix = new int* [numVertices];   //dynamically allocating memory
//    for (int i = 0; i < numVertices; i++) {
//        adjacencyMatrix[i] = new int[numVertices];
//    }
//    cout << "Enter the adjacency matrix:\n";
//    for (int i = 0; i < numVertices; ++i) {
//        for (int j = 0; j < numVertices; ++j) {
//            cin >> adjacencyMatrix[i][j];
//        }
//    }
//    int sourceVertex = 0;  //source vertex for algorithm
//    dijkstra_theorem(adjacencyMatrix, sourceVertex, numVertices);
//    for (int i = 0; i < numVertices; i++) {
//        delete[] adjacencyMatrix[i];
//    }
//    delete[] adjacencyMatrix;
//    return 0;
//}