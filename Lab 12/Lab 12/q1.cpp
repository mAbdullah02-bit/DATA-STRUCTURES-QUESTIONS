//#include <iostream>
//#include <queue>
//using namespace std;
//
//const int maxvertices = 10;
//
//class Graph {
//public:
//    string vertices[maxvertices];
//    int adjmatrix[maxvertices][maxvertices];
//    int noofvertices;
//    string color[maxvertices];
//    int distance[maxvertices]; 
//
//    Graph() {
//        noofvertices = 0;
//        for (int i = 0; i < maxvertices; i++) {
//            for (int j = 0; j < maxvertices; j++) {
//                adjmatrix[i][j] = 0;
//            }
//        }
//    }
//
//    void addvertices(string s) {
//        vertices[noofvertices] = s;
//        for (int i = 0; i < noofvertices; i++) {
//            adjmatrix[noofvertices][i] = 0;
//            adjmatrix[i][noofvertices] = 0;
//        }
//        noofvertices++;
//    }
//
//    void addEdge(string from, string to) {
//        int fromIndex = findVertexIndex(from);
//        int toIndex = findVertexIndex(to);
//
//        if (fromIndex == -1 || toIndex == -1) {
//            cout << "One or both vertices not found.\n";
//            return;
//        }
//        adjmatrix[fromIndex][toIndex] = 1;
//    }
//
//    int findVertexIndex(string s) {
//        for (int i = 0; i < noofvertices; i++) {
//            if (vertices[i] == s) return i;
//        }
//        return -1;
//    }
//
//    void BFS(string startvertex) {
//        queue<int> q;
//        for (int i = 0; i < noofvertices; i++) {
//            color[i] = "white";
//            distance[i] = -1; 
//        }
//
//        int startindex = findVertexIndex(startvertex);
//        q.push(startindex);
//        color[startindex] = "gray";
//        distance[startindex] = 0; 
//
//        while (!q.empty()) {
//            int index = q.front();
//            q.pop();
//            cout << vertices[index] << " ";
//
//            for (int i = 0; i < noofvertices; i++) {
//                if (color[i] == "white" && adjmatrix[index][i] == 1) {
//                    q.push(i);
//                    color[i] = "gray";
//                    distance[i] = distance[index] + 1; // Update distance
//                }
//            }
//            color[index] = "black";
//        }
//        cout << endl;
//    }
//
//    void findLength(string from, string to) {
//        int fromIndex = findVertexIndex(from);
//        int toIndex = findVertexIndex(to);
//
//        if (fromIndex == -1 || toIndex == -1) {
//            cout << "One or both vertices not found.\n";
//            return;
//        }
//
//   
//        BFS(from);
//        if (distance[toIndex] != -1) {
//            cout << "Shortest path length from " << from << " to " << to << ": " << distance[toIndex] << endl;
//        }
//        else {
//            cout << "No path exists from " << from << " to " << to << ".\n";
//        }
//    }
//
//    void display() {
//        cout << "   ";
//        for (int i = 0; i < noofvertices; i++) {
//            cout << i << " ";
//        }
//        cout << endl;
//        for (int i = 0; i < noofvertices; i++) {
//            cout << i << "  ";
//            for (int j = 0; j < noofvertices; j++) {
//                cout << adjmatrix[i][j] << " ";
//            }
//            cout << "\n";
//        }
//    }
//};
//
//int main() {
//    Graph g;
//    g.addvertices("A");
//    g.addvertices("B");
//    g.addvertices("C");
//    g.addvertices("D");
//    g.addEdge("A", "B");
//    g.addEdge("B", "C");
//    g.addEdge("A", "C");
//    g.addEdge("C", "D");
//    g.addEdge("B", "D");
//
//    g.display();
//    cout << endl << endl;
//
//    g.BFS("A");
//    cout << endl;
//
//    g.findLength("A", "D");
//    return 0;
//}