#include <iostream>
using namespace std;

// Function declarations
void PrimsMST(int** arr, int Check_Vertex[], int size); // Prim's MST
void KruskalMST(int** arr, int size);                  // Kruskal's MST

int main() {
    int n;  // Number of vertices
    cout << "Enter number of vertices: ";
    cin >> n;
    //Input values   0 4 4 0 0 0 4 0 2 0 0 0 4 2 0 3 4 2 0 0 3 0 3 0 0 0 4 3 0 3 0 0 2 0 3 0
    // Dynamic memory allocation for adjacency matrix
    int** arr = new int* [n];
    for (int i = 0; i < n; i++)
        arr[i] = new int[n];

    // Input adjacency matrix
    cout << "Input the adjacency matrix:\n";
    for (int i = 0; i < n; i++) {
        cout << " Enter Row " << i << " elements: ";
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }

    // Array to track visited vertices for Prim's algorithm
    int* Check_Vertex = new int[n];
    Check_Vertex[0] = true;  // Start with the first vertex
    for (int i = 1; i < n; i++) {
        Check_Vertex[i] = false;  // Mark all other vertices as unvisited
    }

    // Call Prim's MST function
    PrimsMST(arr, Check_Vertex, n);
    cout << endl;

    // Call Kruskal's MST function
    KruskalMST(arr, n);

    // Cleanup dynamically allocated memory
    for (int i = 0; i < n; i++) {
        delete[] arr[i];
    }
    delete[] arr;
    delete[] Check_Vertex;

    return 0;
}

// Kruskal's algorithm to find MST
void KruskalMST(int** arr, int size) {
    // Array to track the parent of each vertex (for cycle detection)
    int* parent = new int[size];
    for (int i = 0; i < size; i++) {
        parent[i] = i;  // Initially, each vertex is its own parent
    }

    int sum = 0;     // Total weight of MST
    int edges = 0;   // Number of edges included in MST

    cout << "EDGES : WEIGHT\n";

    // Repeat until we have size - 1 edges in the MST
    while (edges < size - 1) {
        int minWeight = INT_MAX; // Initialize minimum weight as maximum possible
        int e1 = -1, e2 = -1;    // To store the vertices of the selected edge

        // Find the smallest edge that does not form a cycle
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                if (arr[i][j] != 0 && arr[i][j] < minWeight) {  // Checking for valid edge if its there
                    if (parent[i] != parent[j]) { // Making sure that no cycle is formed
                        minWeight = arr[i][j]; // Updating the minimum weight
                        e1 = i;  // Storing the indexess for 
                        e2 = j;  // Storing the indexess for 
                      
                    }
                }
            }
        }

        // If a valid edge is found, adding it to MST Sum
        if (e1 != -1 && e2 != -1) { // Displaying edge by edge
            cout << e1 << " - " << e2 << " : " << arr[e1][e2] << endl;

            
            int oldParent = parent[e2]; // Tracking old parent of edge2
            for (int i = 0; i < size; i++) {
                if (parent[i] == oldParent) {
                    parent[i] = parent[e1]; // Updating the parent to new value
                }
            }

            sum += arr[e1][e2]; // Add weight of the edge to total sum for TOtAL Cost of MST
            edges++;            // Increment edge count for next traversal
        }
    }

    cout << "MINIMUM COST USING KRUSKAL: " << sum << endl;

    delete[] parent; // Free memory for parent array
    return;
}

// Prim's algorithm to find MST
void PrimsMST(int** arr, int Check_Vertex[], int size) {
    int sum = 0;     // Total weight of MST
    int edges = 0;   // Number of edges included in MST

    cout << "EDGES : WEIGHT\n";

    // Repeat until we have size - 1 edges in the MST
    while (edges < size - 1) {
        int min = INT_MAX; // Initialize minimum weight as maximum possible
        int e1 = 0, e2 = 0; // To store the vertices of the selected edge

        // Find the smallest edge connecting a visited and unvisited vertex
        for (int i = 0; i < size; i++) {
            if (Check_Vertex[i] == true) { // Check only visited vertices
                for (int j = 0; j < size; j++) {
                    if (arr[i][j] < min) { // Find minimum weight edge
                        if (Check_Vertex[j] == false && arr[i][j] != 0) {
                            min = arr[i][j];
                            e1 = i;
                            e2 = j;
                        }
                    }
                }
            }
        }

        // Add the selected edge to the MST
        cout << e1 << " - " << e2 << " : " << arr[e1][e2] << endl;
        sum += arr[e1][e2];      // Add weight of the edge to total sum
        Check_Vertex[e2] = true; // Mark the vertex as visited
        edges++;                 // Increment edge count
    }

    cout << "MINIMUM COST USING PRIMS: " << sum << endl;
    return;
}
