#include <iostream>
using namespace std;

template <typename T>
struct Queue {
    struct Node {
        T vertex1;
        T vertex2;
        Node* next;
    };

    Node* front;
    Node* rear;

    Queue() : front(nullptr), rear(nullptr) {}

    void enqueue(T v1, T v2) {
        Node* newNode = new Node();
        newNode->vertex1 = v1;
        newNode->vertex2 = v2;
        newNode->next = nullptr;

        if (rear == nullptr) {
            front = rear = newNode;
            return;
        }
        rear->next = newNode;
        rear = newNode;
    }

    void displayQueue() {
        Node* current = front;
        while (current != nullptr) {
            cout << "(" << current->vertex1 << ", " << current->vertex2 << ") ";
            current = current->next;
        }
        cout << endl;
    }

    bool isEmpty() {
        return front == nullptr;
    }

    ~Queue() {
        Node* current = front;
        while (current != nullptr) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
    }
};

template <typename T>
class Graph {
private:
    struct Edge {
        T vertex;
        Edge* next;
    };

    Edge** adjList;
    T* vertices;
    int numVertices;

public:
    Graph(int size) {
        adjList = new Edge * [size];
        vertices = new T[size];
        numVertices = size;

        for (int i = 0; i < size; ++i) {
            adjList[i] = nullptr;
        }
    }

    void addVertex(T vertex) {
        T* newVertices = new T[numVertices + 1];
        Edge** newAdjList = new Edge * [numVertices + 1];

        for (int i = 0; i < numVertices; ++i) {
            newVertices[i] = vertices[i];
            newAdjList[i] = adjList[i];
        }

        newVertices[numVertices] = vertex;
        newAdjList[numVertices] = nullptr;

        delete[] vertices;
        delete[] adjList;

        vertices = newVertices;
        adjList = newAdjList;
        numVertices++;
    }

    void addEdge(T vertex1, T vertex2) {
        if (vertex1 == vertex2) {
            cout << "Error: Invalid edge (self-loop)." << endl;
            return;
        }

        Edge* newEdge1 = new Edge{ vertex2, adjList[vertex1] };
        adjList[vertex1] = newEdge1;

        Edge* newEdge2 = new Edge{ vertex1, adjList[vertex2] };
        adjList[vertex2] = newEdge2;
    }

    void displayGraph() {
        Queue<T> queue;

        for (int i = 0; i < numVertices; ++i) {
            Edge* current = adjList[i];
            while (current != nullptr) {
                if (i < current->vertex) {
                    queue.enqueue(vertices[i], vertices[current->vertex]);
                }
                current = current->next;
            }
        }

        cout << "Edges in the graph: ";
        queue.displayQueue();
    }

    ~Graph() {
        for (int i = 0; i < numVertices; ++i) {
            Edge* current = adjList[i];
            while (current != nullptr) {
                Edge* temp = current;
                current = current->next;
                delete temp;
            }
        }
        delete[] adjList;
        delete[] vertices;
    }
};

int main() {
    Graph<int> g(5); 

    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(3, 4);

    cout << "Graph before adding a new vertex:" << endl;
    g.displayGraph();

    g.addVertex(5);

    g.addEdge(4, 5);
    g.addEdge(2, 5);

    cout << "\nGraph after adding vertex 5 and edges:" << endl;
    g.displayGraph();

    system("pause");
    return 0;
}
