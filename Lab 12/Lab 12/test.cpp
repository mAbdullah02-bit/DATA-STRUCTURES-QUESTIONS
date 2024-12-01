#include <iostream>
using namespace std;

const int maximum = 9999999;

struct Node {
    int vertex;
    int weight;
    Node* next;
};

void addEdge(Node** adjacencyList, int src, int dest, int weight) {
    Node* newNode = new Node{ dest, weight, adjacencyList[src] };
    adjacencyList[src] = newNode;
}

void Dijkstra(Node** adjacencyList, int vertices, int start) {
    int* distance = new int[vertices];
    bool* visited = new bool[vertices];

    for (int i = 0; i < vertices; i++) {
        distance[i] = maximum;
        visited[i] = false;
    }

    distance[start] = 0;

    for (int count = 0; count < vertices - 1; count++) {
        int minDistance = maximum, u = -1;

        for (int i = 0; i < vertices; i++) {
            if (!visited[i] && distance[i] < minDistance) {
                minDistance = distance[i];
                u = i;
            }
        }

        if (u == -1) break; 
        visited[u] = true;

        Node* temp = adjacencyList[u];
        while (temp != nullptr) {
            int v = temp->vertex;
            int weight = temp->weight;
            if (!visited[v] && distance[u] + weight < distance[v]) {
                distance[v] = distance[u] + weight;
            }
            temp = temp->next;
        }
    }

    cout << "Vertex\tDistance from Source\n";
    for (int i = 0; i < vertices; i++) {
        cout << i << "\t" << distance[i] << endl;
    }

    delete[] distance;
    delete[] visited;
}

int main() {
    const int vertices = 5;
    Node** adjacencyList = new Node * [vertices];
    for (int i = 0; i < vertices; i++) {
        adjacencyList[i] = nullptr;
    }

    addEdge(adjacencyList, 0, 1, 10);
    addEdge(adjacencyList, 0, 3, 30);
    addEdge(adjacencyList, 0, 4, 100);
    addEdge(adjacencyList, 1, 0, 10);
    addEdge(adjacencyList, 1, 2, 50);
    addEdge(adjacencyList, 2, 1, 50);
    addEdge(adjacencyList, 2, 3, 20);
    addEdge(adjacencyList, 2, 4, 10);
    addEdge(adjacencyList, 3, 0, 30);
    addEdge(adjacencyList, 3, 2, 20);
    addEdge(adjacencyList, 3, 4, 60);
    addEdge(adjacencyList, 4, 0, 100);
    addEdge(adjacencyList, 4, 2, 10);
    addEdge(adjacencyList, 4, 3, 60);

    int startVertex;
    cout << "Enter the starting vertex: ";
    cin >> startVertex;

    Dijkstra(adjacencyList, vertices, startVertex);

    for (int i = 0; i < vertices; i++) {
        Node* temp = adjacencyList[i];
        while (temp != nullptr) {
            Node* toDelete = temp;
            temp = temp->next;
            delete toDelete;
        }
    }
    delete[] adjacencyList;

    return 0;
}
