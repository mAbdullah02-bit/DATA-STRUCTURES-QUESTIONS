//#include<iostream>
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
//			cout << "   0 1 2 3 4 \n\n";
//			for (int i = 0; i < vertexsize; i++)
//			{
//				cout << i << "  ";
//				for (int j = 0; j < vertexsize; j++)
//				{
//					cout << arr[i][j] << " ";
//				}
//				cout << endl;
//			}
//			cout << endl;
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