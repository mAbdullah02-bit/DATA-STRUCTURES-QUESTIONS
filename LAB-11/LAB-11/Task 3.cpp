//#include <iostream>
//using namespace std;
//
//template <typename T>
//class Graph {
//    T* vertices;
//    int** arr;
//    bool directional;
//    int vertexsize;
//    int vertexCount;
//
//public:
//    Graph(int n) {
//        vertexsize = n;
//        vertexCount = 0;
//        vertices = new T[vertexsize];
//        arr = new int* [vertexsize];
//        for (int i = 0; i < vertexsize; i++) {
//            arr[i] = new int[vertexsize];
//            for (int j = 0; j < vertexsize; j++) {
//                arr[i][j] = 0;
//            }
//        }
//        directional = false;
//    }
//
//    void addVertex(T vertex) {
//        if (vertexCount >= vertexsize) {
//            cout << "limit reached....\n";
//            return;
//        }
//        vertices[vertexCount++] = vertex;
//    }
//
//    int findVertexIndex(T vertex) {
//        for (int i = 0; i < vertexCount; i++) {
//            if (vertices[i] == vertex) return i;
//        }
//        return -1;
//    }
//
//    void addEdge(T from, T to) {
//        int fromIndex = findVertexIndex(from);
//        int toIndex = findVertexIndex(to);
//
//        if (fromIndex == -1 || toIndex == -1) {
//            cout << "One or both vertices not found.\n";
//            return;
//        }
//
//        arr[fromIndex][toIndex] = 1;
//        if (!directional) {
//            arr[toIndex][fromIndex] = 1;
//        }
//
//        cout << "Added edge between " << from << " and " << to << endl;
//    }
//
//    void display() {
//        cout << "  ";
//        for (int i = 0; i < vertexCount; i++) {
//            cout << vertices[i] << " ";
//        }
//        cout << "\n";
//
//        for (int i = 0; i < vertexCount; i++) {
//            cout << vertices[i] << " ";
//            for (int j = 0; j < vertexCount; j++) {
//                cout << arr[i][j] << " ";
//            }
//            cout << "\n";
//        }
//    }
//
//    ~Graph() {
//        for (int i = 0; i < vertexsize; i++) {
//            delete[] arr[i];
//        }
//        delete[] arr;
//        delete[] vertices;
//    }
//};
//
//int main() {
//    Graph<char> g(5);
//
//    g.addVertex('A');
//    g.addVertex('B');
//    g.addVertex('C');
//    g.addVertex('D');
//
//    g.addEdge('A', 'B');
//    g.addEdge('B', 'C');
//    g.addEdge('C', 'D');
//    g.addEdge('D', 'A');
//
//    g.display();
//    return 0;
//}
