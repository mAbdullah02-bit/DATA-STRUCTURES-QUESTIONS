//#include <iostream>
//using namespace std;
//
//void PrimsMST(int graph[4][4], int Check_Vertex[], int size) {
//    int sum = 0;
//    int edges = 0;
//
//    cout << "EDGES : WEIGHT\n";
//
//    while (edges < size - 1) {
//        int min = INT_MAX;
//        int e1 = 0, e2 = 0;
//
//        for (int i = 0; i < size; i++) {
//            if (Check_Vertex[i] == true) {
//                for (int j = 0; j < size; j++) {
//                    if (graph[i][j] < min) {
//                        if (Check_Vertex[j] == false && graph[i][j] != 0) {
//                            min = graph[i][j];
//                            e1 = i;
//                            e2 = j;
//                        }
//                    }
//                }
//            }
//        }
//
//        cout << e1 << " - " << e2 << " : " << graph[e1][e2] << endl;
//        sum += graph[e1][e2];
//        Check_Vertex[e2] = true;
//        edges++;
//    }
//
//    cout << "MINIMUM COST USING PRIMS: " << sum << endl;
//}
//
//int main() {
//    int graph[4][4] = {
//        {0, 10, 15, 20},
//        {10, 0, 35, 25},
//        {15, 35, 0, 30},
//        {20, 25, 30, 0}
//    };
//
//    int n = 4;
//    int Check_Vertex[4] = { true, false, false, false };
//
//    PrimsMST(graph, Check_Vertex, n);
//
//    return 0;
//}
