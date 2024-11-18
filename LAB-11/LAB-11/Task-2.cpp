//#include<iostream>
//#include<queue>
//using namespace std;
//class Graph {
//	int** arr;
//	bool directional;
//	int  vertexsize;
//	public:
//		Graph(int n) {
//			vertexsize = n;
//			
//			arr = new int*[n];
//		for (int i = 0; i < n; i++)
//		{ 
//			arr[i] = new int[n];
//		}
//
//		for (int i = 0; i < n; i++)
//		{
//			for (int j = 0; j < n; j++)
//			{
//				arr[i][j] = 0;
//			}
//		}
//		directional = true;
//		}
//		void addvertex() { vertexsize++;
//		int** temp;
//		temp = new int* [vertexsize];
//		for (int i = 0; i < vertexsize; i++)
//		{
//		temp[i] = new int[vertexsize];
//		}
//		for (int i = 0; i < vertexsize-1; i++)
//		{
//			for (int i = 0; i < vertexsize-1; i++)
//			{
//				temp[i][i] = arr[i][i];
//			}
//			
//		}
//		
//		}
//		void addedge(int n,int m) {
//			if (n>vertexsize || m> vertexsize)
//			{
//				cout << "Invalid Vertex or edge no!...\n";
//				return;
//			}
//			if (!directional)
//			{
//				arr[m][n] = 1;
//			}
//			arr[n][m] = 1;
//			cout << "Added Between Vertex " << n << " and " << m << endl;
//		}
//		void display() {
//
//			queue<pair<int, int>> q;
//			cout << "   ";
//			for (int i = 0; i < vertexsize; i++)
//			{
//				cout << i << " ";
//			}
//			cout << endl;
//			for (int i = 0; i <vertexsize; i++) {
//				cout << i << "  ";
//				for (int j = 0; j < vertexsize; j++) {
//					cout << arr[i][j] << " ";
//
//					if (arr[i][j] == 1 && (directional || i < j)) {
//						q.push({i, j });
//					}
//				}
//				cout << "\n";
//			}
//
//
//			cout << "\nEdges in the graph:\n";
//			while (!q.empty()) {
//				auto edge = q.front();
//				q.pop();
//				cout << edge.first << " -> " << edge.second << endl;
//			}
//		}
//
//};
//int main() {
//	Graph g(5);
//	int n;
//	//cout << "enter : ";
//	//cin >> n;
//	//cin >> n;
//	g.addedge(0, 1);
//	/*cout << "enter: ";
//	cin >> n;
//	cin >> n;*/
//	g.addedge(1, 2);
//	//cout << "enter: ";
//	//cin >> n;
//	//cin >> n;
//	g.addedge(2, 0);
//	g.display();
//	return 0;
//}