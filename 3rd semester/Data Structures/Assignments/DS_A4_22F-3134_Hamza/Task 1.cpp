//#include <iostream>
//#include <fstream>
//using namespace std;
//
//#define red "\033[0;31m"
//#define green "\033[0;32m"
//#define reset "\033[0m"
//#define sky_blue "\033[0;36m"
//
//const int rows = 15;
//const int cols = 15;
//const int obstacle = 1;
//const int empty = 0;
//const int up_cost = 2;
//const int right_cost = 2;
//const int diagonal_cost = 3;
//
//void readgraph(int grid[rows][cols], string filename) {
//    ifstream file(filename);
//    if (file.is_open()) {
//        for (int i = 0; i < rows; ++i) {
//            for (int j = 0; j < cols; ++j) {
//                file >> grid[i][j];
//            }
//        }
//        file.close();
//    }
//}
//void displaygraph(const int grid[rows][cols]) {
//    int empty = 0;
//    for (int i = 0; i < rows; ++i) {
//        for (int j = 0; j < cols; ++j) {
//            if (grid[i][j] == obstacle) {
//                cout << sky_blue << "1 " << reset;
//            }
//            else if (grid[i][j] == empty) {
//                cout << green << "0 " << reset;
//            }
//            else if (grid[i][j] == -1) {
//                cout << red << "* " << reset;
//            }
//        }
//        cout << endl;
//    }
//}
//bool isvalid(int x, int y) {    //for checking if the graph is valid
//    return x >= 0 && x < rows && y >= 0 && y < cols;
//}
//bool bfs(int graph[rows][cols], int startx, int starty, int goalx, int goaly) {  //performing bfs
//    int empty = 0;
//    int queue[rows * cols];
//    bool visited[rows][cols] = { false };
//    int parentx[rows][cols];
//    int parenty[rows][cols];
//    int front = 0, rear = 0;
//
//    queue[rear++] = startx * cols + starty;
//    visited[startx][starty] = true;
//
//    while (front < rear) {
//        int current = queue[front++];
//        int x = current / cols;
//        int y = current % cols;
//
//        if (x == goalx && y == goaly) {
//            //goal reached, reconstruct path
//            cout << "bfs: goal reached!" << endl;
//            int cost = 0;
//            int path[rows * cols];
//            int pathindex = 0;
//
//            while (x != startx || y != starty) {
//                path[pathindex++] = x * cols + y;
//                int tempx = parentx[x][y];
//                int tempy = parenty[x][y];
//                cost += 2; //assuming all moves have a cost of 2
//                x = tempx;
//                y = tempy;
//            }
//            path[pathindex++] = startx * cols + starty;
//
//            for (int i = 0; i < pathindex; ++i) {
//                int point = path[i];
//                int row = point / cols;
//                int col = point % cols;
//                graph[row][col] = -1;    //visited paths are marked -1
//                if (i % 10 == 0) cout << endl;
//                cout << red << "(" << reset << sky_blue << row << ", " << col << reset << red << ")" << reset << green << "->" << reset;
//            }
//            cout << endl << endl;
//            displaygraph(graph);
//            cout << "sequence of actions: move up or right" << endl;
//            cout << "total cost: " << cost << endl;
//
//            return true;
//        }
//        if (isvalid(x - 1, y) && !visited[x - 1][y] && graph[x - 1][y] == empty) {      //up movement
//            queue[rear++] = (x - 1) * cols + y;
//            visited[x - 1][y] = true;
//            parentx[x - 1][y] = x;
//            parenty[x - 1][y] = y;
//        }
//        if (isvalid(x, y + 1) && !visited[x][y + 1] && graph[x][y + 1] == empty) {   //right movement
//            queue[rear++] = x * cols + y + 1;
//            visited[x][y + 1] = true;
//            parentx[x][y + 1] = x;
//            parenty[x][y + 1] = y;
//        }
//        if (isvalid(x - 1, y + 1) && !visited[x - 1][y + 1] && graph[x - 1][y + 1] == empty) {   //up-diagonal movement
//            queue[rear++] = (x - 1) * cols + y + 1;
//            visited[x - 1][y + 1] = true;
//            parentx[x - 1][y + 1] = x;
//            parenty[x - 1][y + 1] = y;
//        }
//    }
//
//    cout << "bfs: goal not reachable." << endl;
//    return false;
//}
//
//// function to perform dfs
//bool dfs(int grid[rows][cols], int startx, int starty, int goalx, int goaly) {
//    int empty = 0;
//    int stack[rows * cols];
//    bool visited[rows][cols] = { false };
//    int parentx[rows][cols];
//    int parenty[rows][cols];
//    int top = -1;
//
//    stack[++top] = startx * cols + starty;
//    visited[startx][starty] = true;
//
//    while (top >= 0) {
//        int current = stack[top--];
//        int x = current / cols;
//        int y = current % cols;
//
//        if (x == goalx && y == goaly) {
//            cout << "dfs: goal reached!" << endl;
//            int cost = 0;
//            int path[rows * cols];
//            int pathindex = 0;
//
//            while (x != startx || y != starty) {
//                path[pathindex++] = x * cols + y;
//                int tempx = parentx[x][y];
//                int tempy = parenty[x][y];
//                cost += 2; // assuming all moves have cost 2
//                x = tempx;
//                y = tempy;
//            }
//            path[pathindex++] = startx * cols + starty;
//            for (int i = pathindex - 1; i >= 0; --i) {
//                int point = path[i];
//                int row = point / cols;
//                int col = point % cols;
//                grid[row][col] = -1; // mark path with unvisited
//                cout << "(" << row + 1 << "," << col + 1 << ") ";
//            }
//            cout << endl;
//            cout << "sequence of actions: move up or right" << endl;
//            cout << "total cost: " << cost << endl;
//            displaygraph(grid);
//
//            return true;
//        }
//        if (isvalid(x - 1, y + 1) && !visited[x - 1][y + 1] && grid[x - 1][y + 1] == empty) { // up-diagonal movement
//            stack[++top] = (x - 1) * cols + y + 1;
//            visited[x - 1][y + 1] = true;
//            parentx[x - 1][y + 1] = x;
//            parenty[x - 1][y + 1] = y;
//        }
//        if (isvalid(x, y + 1) && !visited[x][y + 1] && grid[x][y + 1] == empty) { // right movement
//            stack[++top] = x * cols + y + 1;
//            visited[x][y + 1] = true;
//            parentx[x][y + 1] = x;
//            parenty[x][y + 1] = y;
//        }
//        if (isvalid(x - 1, y) && !visited[x - 1][y] && grid[x - 1][y] == empty) { // up movement
//            stack[++top] = (x - 1) * cols + y;
//            visited[x - 1][y] = true;
//            parentx[x - 1][y] = x;
//            parenty[x - 1][y] = y;
//        }
//    }
//    cout << "\ndfs: goal not reachable.";
//    return false;
//}
//
//bool dijkstra(int graph[rows][cols], int startx, int starty, int goalx, int goaly) {
//    int empty = 0;
//    const int max = 1000;       //used 1000 instead of infinity
//
//    int mincost[rows][cols];
//    bool visited[rows][cols] = { false };
//    int parentx[rows][cols];
//    int parenty[rows][cols];
//
//    for (int i = 0; i < rows; ++i) {        //initializing everything with infinity or 1000 since there is no command for infinity
//        for (int j = 0; j < cols; ++j) {
//            mincost[i][j] = max;
//        }
//    }
//
//    mincost[startx][starty] = 0;    //starting cell with 0 cost
//
//    while (true) {
//        int mincellx = -1, mincelly = -1, mincellcost = max;    //with the minimum weight
//
//        for (int i = 0; i < rows; ++i) {
//            for (int j = 0; j < cols; ++j) {
//                if (!visited[i][j] && mincost[i][j] < mincellcost) {
//                    mincellx = i;
//                    mincelly = j;
//                    mincellcost = mincost[i][j];
//                }
//            }
//        }
//        //if all cells are visited or might be unreachable, stop the loop
//        if (mincellx == -1 || mincelly == -1 || mincellcost == max) {
//            break;
//        }
//
//        int x = mincellx;
//        int y = mincelly;
//
//        visited[x][y] = true;
//        if (isvalid(x - 1, y)) {    //for up movement
//            int newcost = mincost[x][y] + up_cost;
//            if (graph[x - 1][y] == empty && newcost < mincost[x - 1][y]) {
//                mincost[x - 1][y] = newcost;
//                parentx[x - 1][y] = x;
//                parenty[x - 1][y] = y;
//            }
//        }
//        if (isvalid(x, y + 1)) {    //for right movement
//            int newcost = mincost[x][y] + right_cost;
//            if (graph[x][y + 1] == empty && newcost < mincost[x][y + 1]) {
//                mincost[x][y + 1] = newcost;
//                parentx[x][y + 1] = x;
//                parenty[x][y + 1] = y;
//            }
//        }
//        if (isvalid(x - 1, y + 1)) {     //for diagonally up and right movement
//            int newcost = mincost[x][y] + diagonal_cost;
//            if (graph[x - 1][y + 1] == empty && newcost < mincost[x - 1][y + 1]) {
//                mincost[x - 1][y + 1] = newcost;
//                parentx[x - 1][y + 1] = x;
//                parenty[x - 1][y + 1] = y;
//            }
//        }
//        if (mincost[goalx][goaly] != max) { //goal reached, constucting path
//            cout << "dijkstra: goal reached!" << endl;
//            int totalcost = mincost[goalx][goaly];
//            int path[rows * cols];
//            int pathindex = 0;
//            int x = goalx;
//            int y = goaly;
//
//            while (x != startx || y != starty) {
//                path[pathindex] = x * cols + y;
//                pathindex++;
//                int tempx = parentx[x][y];
//                int tempy = parenty[x][y];
//                totalcost += 2; //assuming all moves have cost of 2
//                x = tempx;
//                y = tempy;
//            }
//            path[pathindex++] = startx * cols + starty;
//
//            for (int i = pathindex - 1; i >= 0; --i) {  //for path displaying
//                int point = path[i];
//                int row = point / cols;
//                int col = point % cols;
//                graph[row][col] = -1; //mark path with unvivited
//                cout << "(" << row + 1 << "," << col + 1 << ") ";
//            }
//            cout << endl;
//            cout << "sequence of actions: move up or right" << endl;
//            cout << "total cost: " << totalcost << endl;
//            displaygraph(graph);
//            return true;
//        }
//    }
//    cout << "\ndijkstra: goal not reachable.";
//    return false;
//}
//
//int main() {
//    int graph[rows][cols];
//    int startx, starty;
//    int goalx,  goaly;
//    cout << "enter the starting x point: ";     cin >> startx;
//    cout << "enter the starting y point: ";     cin >> starty;
//    cout << "enter the ending x point: ";       cin >> goalx;
//    cout << "enter the ending y point: ";       cin >> goaly;
//
//    readgraph(graph, "file.txt");
//    cout << "original grid:" << endl;
//    displaygraph(graph);
//
//    bfs(graph, startx, starty, goalx, goaly);   //bfs
//    dfs(graph, startx, starty, goalx, goaly);   //dfs
//    dijkstra(graph, startx, starty, goalx, goaly);  //dijkstra
//    return 0;
//}