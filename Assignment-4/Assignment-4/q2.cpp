//#include <iostream>
//
//using namespace std;
//
//void KruskalMST(int arr[][4], int size);
//
//int main() {
//    int n = 4;
//    int graph[4][4] = {
//        {0, 10, 15, 20},
//        {10, 0, 35, 25},
//        {15, 35, 0, 30},
//        {20, 25, 30, 0}
//    };
//
//    KruskalMST(graph, n);
//    return 0;
//}
//
//void KruskalMST(int arr[][4], int size) {
//    int* parent = new int[size];
//    for (int i = 0; i < size; i++) {
//        parent[i] = i;
//    }
//
//    int sum = 0;
//    int edges = 0;
//
//    cout << "EDGES : WEIGHT\n";
//
//    while (edges < size - 1) {
//        int minWeight = INT_MAX;
//        int e1 = -1, e2 = -1;
//
//        for (int i = 0; i < size; i++) {
//            for (int j = 0; j < size; j++) {
//                if (arr[i][j] != 0 && arr[i][j] < minWeight) {
//                    if (parent[i] != parent[j]) {
//                        minWeight = arr[i][j];
//                        e1 = i;
//                        e2 = j;
//                    }
//                }
//            }
//        }
//
//        if (e1 != -1 && e2 != -1) {
//            cout << e1 << " - " << e2 << " : " << arr[e1][e2] << endl;
//
//            int oldParent = parent[e2];
//            for (int i = 0; i < size; i++) {
//                if (parent[i] == oldParent) {
//                    parent[i] = parent[e1];
//                }
//            }
//
//            sum += arr[e1][e2];
//            edges++;
//        }
//    }
//
//    cout << "MINIMUM COST USING KRUSKAL: " << sum << endl;
//    delete[] parent;
//    return;
//}
