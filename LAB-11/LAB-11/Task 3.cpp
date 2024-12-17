//#include <iostream>
//using namespace std;
//const int maxnumber = 9999999999;
//int tspNearestNeighbor(int graph[4][4], int startCity, int n) {
//	bool visited[4] = { false };
//	int route[4];
//	
//	int currentCity = startCity;
//	int totalCost = 0;
//	visited[currentCity] = true;
//	route[0] = currentCity;
//	for (int step = 1; step < n; ++step) {
//		int nearestCity = -1;
//		int minDistance = maxnumber;
//	
//		for (int nextCity = 0; nextCity < n; ++nextCity) {
//			if (!visited[nextCity] && graph[currentCity][nextCity] < minDistance) {
//				nearestCity = nextCity;
//				minDistance = graph[currentCity][nextCity];
//			}
//		}
//	
//		if (nearestCity == -1) {
//			cerr << "Error: Unable to find an unvisited city. Ensure the graph is connected." << endl;
//			return-1;
//		}
//		
//		visited[nearestCity] = true;
//		route[step] = nearestCity;
//		totalCost += minDistance;
//		currentCity = nearestCity;
//	}
//	if (graph[currentCity][startCity] == maxnumber) {
//		cerr << "Error: No path exists to return to the starting city." << endl;
//		return-1;
//	}
//	totalCost += graph[currentCity][startCity];
//	cout << "Route using Nearest Neighbor Heuristic: ";
//	for (int i = 0; i < n; ++i) {
//		cout << route[i] << "-> ";
//	}
//	cout << startCity << endl;
//	return totalCost;
//}
//int main() {
//	int graph[4][4] = {
//	{0, 10, 15, 20},
//	{10, 0, 35, 25},
//	{15, 35, 0, 30},
//	{20, 25, 30, 0}
//	};
//	int startCity = 0;
//	cout << "Using Nearest Neighbor Heuristic to solve TSP..." << endl;
//	int minCost = tspNearestNeighbor(graph, startCity, 4);
//	if (minCost != -1) {
//		cout << "Total cost: " << minCost << endl;
//	}
//	else {
//		cerr << "Failed to calculate TSP due to errors." << endl;
//	}
//	system("pause");
//	return 0;
//}