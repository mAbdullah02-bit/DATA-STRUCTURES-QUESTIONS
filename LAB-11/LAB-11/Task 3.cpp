#include <iostream>
#include <string>
using namespace std;

template <typename T>
struct Node {
    T fromV;
    T toV;
    int weight;
    Node* next;
};

template <typename T>
class Queue {
private:
    Node<T>* front;
    Node<T>* rear;

public:
    Queue() : front(nullptr), rear(nullptr) {}

    void enqueue(T fromV, T toV, int weight) {
        Node<T>* n = new Node<T>{ fromV, toV, weight, nullptr };
        if (rear != nullptr) {
            rear->next = n;
        }
        rear = n;
        if (front == nullptr) {
            front = n;
        }
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Empty queue" << endl;
            return;
        }
        Node<T>* temp = front;
        cout << temp->fromV << " -> " << temp->toV << ", weight: " << temp->weight << endl;
        front = front->next;
        if (front == nullptr) {
            rear = nullptr;
        }
        delete temp;
    }

    bool isEmpty() {
        return (front == nullptr);
    }

    ~Queue() {
        while (!isEmpty()) {
            dequeue();
        }
    }
};

template <typename T>
class Graph {
private:
    int** arr;
    T* vertices;
    bool directional;
    int maxVertices;
    int vertexsize; 

    int findVertexIndex(T vertex) {
        for (int i = 0; i < vertexsize; i++) {
            if (vertices[i] == vertex) {
                return i;
            }
        }
        return -1;
    }

public:
    Graph(int n, bool isDirectional = false)
        : maxVertices(n), directional(isDirectional), vertexsize(0) {
        arr = new int* [n];
        for (int i = 0; i < n; i++) {
            arr[i] = new int[n];
            for (int j = 0; j < n; j++) {
                arr[i][j] = 0;
            }
        }
        vertices = new T[n];
    }

    void AddVertex(T vertex) {
        if (vertexsize < maxVertices) {
            vertices[vertexsize] = vertex;
            vertexsize++;
            cout << "Vertex added: " << vertex << endl;
        }
        else {
            cout << "Vertex limit exceeded!" << endl;
        }
    }

    void addedge(T vertex1, T vertex2, int weight = 1) {
        int index1 = findVertexIndex(vertex1);
        int index2 = findVertexIndex(vertex2);

        if (index1 == -1 || index2 == -1) {
            cout << "Invalid vertex: " << vertex1 << " or " << vertex2 << endl;
            return;
        }

        arr[index1][index2] = weight;
        if (!directional) {
            arr[index2][index1] = weight;
        }
        cout << "Edge added between vertex " << vertex1 << " and " << vertex2 << " with weight " << weight << endl;
    }

    void DisplayGraph() {
        Queue<T> q;
        for (int i = 0; i < vertexsize; i++) {
            for (int j = i + 1; j < vertexsize; j++) {
                if (arr[i][j] != 0) {
                    q.enqueue(vertices[i], vertices[j], arr[i][j]);
                }
            }
        }

        cout << "Graph edges and weights:" << endl;
        while (!q.isEmpty()) {
            q.dequeue();
        }
    }

    ~Graph() {
        for (int i = 0; i < maxVertices; i++) {
            delete[] arr[i];
        }
        delete[] arr;
        delete[] vertices;
    }
};

int main() {
    Graph<string> g(5);

    g.AddVertex("A");
    g.AddVertex("B");
    g.AddVertex("C");
    g.AddVertex("D");
    g.AddVertex("E");

    g.addedge("A", "B", 2);
    g.addedge("B", "C", 3);
    g.addedge("C", "D", 4);
    g.addedge("D", "E", 5);
    g.addedge("E", "A", 6);

    g.DisplayGraph();

    return 0;
}
