//#include <iostream>
//using namespace std;
//
//struct Node {
//    int fromV;
//    int toV;
//    int weight;
//    Node* next;
//};
//
//class Queue {
//private:
//    Node* front;
//    Node* rear;
//
//public:
//    Queue() {
//        front = nullptr;
//        rear = nullptr;
//    }
//
//    void enqueue(int fromV, int toV, int weight) {
//        Node* n = new Node{ fromV, toV, weight, nullptr };
//        if (rear != nullptr) {
//            rear->next = n;
//        }
//        rear = n;
//        if (front == nullptr) {
//            front = n;
//        }
//    }
//
//    void dequeue() {
//        if (isEmpty()) {
//            cout << "Empty queue" << endl;
//            return;
//        }
//        Node* temp = front;
//        cout << temp->fromV << " -> " << temp->toV << ", weight: " << temp->weight << endl;
//        front = front->next;
//        if (front == nullptr) {
//            rear = nullptr;
//        }
//        delete temp;
//    }
//
//    bool isEmpty() {
//        return (front == nullptr);
//    }
//
//    ~Queue() {
//        while (!isEmpty()) {
//            dequeue();
//        }
//    }
//};
//
//class Graph {
//    int** arr;
//    int* vertices;
//    bool directional;
//    int vertexsize;
//
//public:
//    Graph(int n) : vertexsize(n), directional(true) {
//        arr = new int* [n];
//        for (int i = 0; i < n; i++) {
//            arr[i] = new int[n];
//            for (int j = 0; j < n; j++) {
//                arr[i][j] = 0;
//            }
//        }
//        vertices = new int[n];
//        for (int i = 0; i < n; i++) {
//            vertices[i] = i;
//        }
//    }
//
//    void AddVertex(int vertex) {
//        if (vertex < vertexsize) {
//            vertices[vertex] = vertex;
//        }
//        else {
//            cout << "Vertex limit exceeded!" << endl;
//        }
//    }
//
//    void addedge(int n, int m, int weight) {
//        if (n >= vertexsize || m >= vertexsize) {
//            cout << "Invalid vertex or edge!" << endl;
//            return;
//        }
//        arr[n][m] = weight;
//        if (!directional) {
//            arr[m][n] = weight;
//        }
//        cout << "Edge added between " << n << " and " << m << " containing weight " << weight << endl;
//    }
//
//    void DisplayGraph() {
//        Queue q;
//        for (int i = 0; i < vertexsize; i++) {
//            for (int j = i + 1; j < vertexsize; j++) {
//                if (arr[i][j] != 0) {
//                    q.enqueue(vertices[i], vertices[j], arr[i][j]);
//                }
//            }
//        }
//
//        cout << "Graph edges and weights:" << endl;
//        while (!q.isEmpty()) {
//            q.dequeue();
//        }
//    }
//
//
//};
//
//int main() {
//    Graph g(5);
//
//    g.addedge(0, 1, 2);
//    g.addedge(1, 2, 3);
//    g.addedge(2, 1, 3);
//    g.addedge(2, 3, 4);
//    g.addedge(3, 4, 5);
//    g.addedge(4, 0, 6);
//
//    g.DisplayGraph();
//
//    return 0;
//}
