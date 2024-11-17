//#include <iostream>
//using namespace std;
//
//class Graph
//{
//private:
//    int num_vertices;
//    int** adj_matrix;
//
//public:
//
//    Graph(int vertices)
//    {
//        num_vertices = vertices;
//        adj_matrix = new int* [num_vertices];
//        for (int i = 0; i < num_vertices; i++)
//        {
//            adj_matrix[i] = new int[num_vertices];
//            for (int j = 0; j < num_vertices; j++)
//            {
//                adj_matrix[i][j] = 0;
//            }
//        }
//    }
//
//
//    ~Graph()
//    {
//        for (int i = 0; i < num_vertices; i++)
//        {
//            delete[] adj_matrix[i];
//        }
//        delete[] adj_matrix;
//    }
//
//
//    void add_edge(int u, int v)
//    {
//        if (u >= 0 && v >= 0 && u < num_vertices && v < num_vertices && u != v)
//        {
//            adj_matrix[u][v] = 1;
//            adj_matrix[v][u] = 1;
//        }
//        else
//        {
//            cout << "Invalid edge!" << endl;
//        }
//    }
//
//
//    void remove_edge(int u, int v)
//    {
//        if (u >= 0 && v >= 0 && u < num_vertices && v < num_vertices)
//        {
//            adj_matrix[u][v] = 0;
//            adj_matrix[v][u] = 0;
//        }
//        else
//        {
//            cout << "Invalid edge!" << endl;
//        }
//    }
//
//
//    bool is_connected(int u, int v)
//    {
//        if (u >= 0 && v >= 0 && u < num_vertices && v < num_vertices)
//        {
//            return adj_matrix[u][v] == 1;
//        }
//        else
//        {
//            cout << "Invalid vertices!" << endl;
//            return false;
//        }
//    }
//
//
//
//    void display()
//    {
//        cout << "Adjacency Matrix:" << endl;
//        for (int i = 0; i < num_vertices; i++)
//        {
//            for (int j = 0; j < num_vertices; j++)
//            {
//                cout << adj_matrix[i][j] << " ";
//            }
//            cout << endl;
//        }
//    }
//};
//
//int main()
//{
//    int vertices;
//    cout << "Enter the number of vertices: ";
//    cin >> vertices;
//
//    Graph g(vertices);
//
//    g.add_edge(0, 1);
//    g.add_edge(0, 2);
//    g.add_edge(1, 2);
//    g.add_edge(1, 3);
//
//
//    g.display();
//
//
//    cout << "Is there an edge between 0 and 1? " << (g.is_connected(0, 1) ? "Yes" : "No") << endl;
//
//    
//    g.remove_edge(0, 1);
//    cout << "After removing edge between 0 and 1:" << endl;
//    g.display();
//
//    return 0;
//}