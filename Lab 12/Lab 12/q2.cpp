//#include <iostream>
//#include <stack>
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
//        adjmatrix[toIndex][fromIndex] = 1; // For undirected graph
//    }
//
//    int findVertexIndex(string s) {
//        for (int i = 0; i < noofvertices; i++) {
//            if (vertices[i] == s) return i;
//        }
//        return -1;
//    }
//
//    void DFS(string startvertex) {
//        stack<int> s;
//        for (int i = 0; i < noofvertices; i++) {
//            color[i] = "white";
//        }
//
//        int startindex = findVertexIndex(startvertex);
//        s.push(startindex);
//        cout << "DFS Traversal: ";
//        while (!s.empty()) {
//            int index = s.top();
//            s.pop();
//
//            if (color[index] == "white") {
//                cout << vertices[index] << " ";
//                color[index] = "gray";
//
//                for (int i = 0; i < noofvertices; i++) {
//                    if (adjmatrix[index][i] == 1 && color[i] == "white") {
//                        s.push(i);
//                    }
//                }
//                color[index] = "black";
//            }
//        }
//        cout << endl;
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
//    g.addvertices("1");
//    g.addvertices("2");
//    g.addvertices("3");
//    g.addvertices("4");
//    g.addEdge("1", "2");
//    g.addEdge("2", "3");
//    g.addEdge("1", "3");
//    g.addEdge("3", "4");
//    g.addEdge("2", "4");
//
//    g.display();
//    cout << endl << endl;
//
//    g.DFS("1");
//    return 0;
//}