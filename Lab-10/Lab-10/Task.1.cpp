//#include<iostream>
//using namespace std;
//
//class Heap {
//public:
//	int arr[100];
//		int size;
//		Heap() { size = 0; arr[0] = -1; }
//		void print() {
//			for (int i = 1; i < size; i++)
//			{
//				cout << arr[i] << "  ";
//			}
//			cout << endl;
//		}
//		bool isempty() { return (size == 0); }
//		bool isfull(){ return (size == 100); }
//		void heapify_up() {
//			int index = size;
//			while (index>0)
//			{
//				if (arr[index] > arr[index / 2])
//					swap(arr[index], arr[index/2]);
//				index = index / 2;
//
//			}
//		
//		}
//		void heapify_down() {
//			int index = size;
//			while (index > 0)
//			{
//				if (arr[index] < arr[index / 2]) {
//					swap(arr[index], arr[index / 2]);
//					index = index / 2;
//				}
//				else break;
//
//			}
//
//		}
//};
//int main() {
//
//
//
//
//	return 0;
//}