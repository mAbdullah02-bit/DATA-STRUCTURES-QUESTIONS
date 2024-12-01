#include <iostream>
#include <queue>
#include <stack>
using namespace std;

class Node {
public:
    string data;
    Node* next;

    Node(string s) {
        data = s;
        next = nullptr;
    }
};

class Graph {
public:
    Node* list[10];
    int noofvertices;
    string color[10];

    Graph() {
        noofvertices = 0;
        for (int i = 0; i < 10; i++) {
            list[i] = nullptr;
        }
    }

    void addVertex(string s) {
        if (noofvertices < 10) {
            list[noofvertices] = new Node(s);
            noofvertices++;
        }
        else {
            cout << "Maximum vertices reached.\n";
        }
    }

    void addEdge(string from, string to) {
        int fromIndex = getVertexIndex(from);
        int toIndex = getVertexIndex(to);

        if (fromIndex == -1 || toIndex == -1) {
            cout << "One or both vertices do not exist.\n";
            return;
        }

        Node* newNode = new Node(to);
        newNode->next = list[fromIndex]->next;
        list[fromIndex]->next = newNode;
    }

    void BFS(string startVertex) {
        int startIndex = getVertexIndex(startVertex);
        if (startIndex == -1) {
            cout << "Start vertex does not exist.\n";
            return;
        }

        queue<int> q;
        for (int i = 0; i < noofvertices; i++) {
            color[i] = "white";
        }

        q.push(startIndex);
        color[startIndex] = "gray";

        cout << "BFS Traversal: ";
        while (!q.empty()) {
            int currentIndex = q.front();
            q.pop();
            cout << list[currentIndex]->data << " ";

            Node* temp = list[currentIndex]->next;
            while (temp != nullptr) {
                int neighborIndex = getVertexIndex(temp->data);
                if (color[neighborIndex] == "white") {
                    q.push(neighborIndex);
                    color[neighborIndex] = "gray";
                }
                temp = temp->next;
            }
            color[currentIndex] = "black";
        }
        cout << endl;
    }

    void DFS(string startVertex) {
        int startIndex = getVertexIndex(startVertex);
        if (startIndex == -1) {
            cout << "Start vertex does not exist.\n";
            return;
        }

        for (int i = 0; i < noofvertices; i++) {
            color[i] = "white";
        }

        cout << "DFS Traversal: ";
        DFSRecursive(startIndex);
        cout << endl;
    }

    void DFSRecursive(int index) {
        color[index] = "gray";
        cout << list[index]->data << " ";

        Node* temp = list[index]->next;
        while (temp != nullptr) {
            int neighborIndex = getVertexIndex(temp->data);
            if (color[neighborIndex] == "white") {
                DFSRecursive(neighborIndex);
            }
            temp = temp->next;
        }
        color[index] = "black";
    }

    void display() {
        cout << "GRAPH Adjacency List:\n";
        for (int i = 0; i < noofvertices; i++) {
            cout << list[i]->data << " -> ";
            Node* temp = list[i]->next;
            while (temp != nullptr) {
                cout << temp->data << " ";
                temp = temp->next;
            }
            cout << endl;
        }
    }

    int getVertexIndex(string s) {
        for (int i = 0; i < noofvertices; i++) {
            if (list[i]->data == s) return i;
        }
        return -1;
    }
};

int main() {
    Graph g;


    g.addVertex("A");
    g.addVertex("B");
    g.addVertex("C");
    g.addVertex("D");


    g.addEdge("A", "B");
    g.addEdge("A", "C");
    g.addEdge("B", "D");
    g.addEdge("C", "D");


    g.display();
    cout << endl;


    g.BFS("A");
    cout << endl;

    g.DFS("A");

    return 0;
}

