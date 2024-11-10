//#include<iostream>
//using namespace std;
//
//class Heap {
//public:
//	int *arr;
//		int size;
//		int capacity;
//		Heap() { size = 0;  capacity = 100; arr = new int[capacity]; arr[0] = -1; }
//		void print() {
//			for (int i = 1; i <= size; i++)
//			{
//				cout << arr[i] << "  ";
//			}
//			cout << endl;
//		}
//		bool isempty() { return (size == 0); }
//		bool isfull(){ return (size == capacity); }
//	/*	void heapify_up() {
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
//		}*/
//
//	int getmin() { return arr[1]; }
//	void insert(int n) { 
//		
//		if (!isfull()) {
//
//			size++;
//			int index = size;
//			arr[index] = n;
//			while (index > 1)
//			{
//				int parent = index / 2;
//				if (arr[parent] > arr[index])
//				{
//					swap(arr[parent], arr[index]);
//					index = parent;
//				}
//				else return;
//
//			}
//		}
//		else cout << "Cant insert Heap full!..\n";
//
//
//	}
//	void deleteelement() {
//	
//		if (isempty()) {
//			cout << "EMPTY!..\n";
//			return;
//		}
//		arr[1] = arr[size];
//		size--;
//
//		int i = 1;
//		while (i<size)
//		{
//			int l = 2 * i;
//			int r = 2 * i + 1;
//
//			if (l<size && arr[l]<arr[i]) {
//				swap(arr[i], arr[l]);
//				i = l;
//
//			}
//			else if (r<size && arr[r]<arr[i]) {
//				swap(arr[i], arr[r]);
//				r = l;
//
//			}
//			else return;
//		}
//	}
//};
//int main() {
//	int n;
//	Heap h;
//	//cin >> n;
//	//h.insert(n);
//	//cin >> n;
//	//h.insert(n);
//	//cin >> n;
//	//h.insert(n);
//	//cin >> n;
//	//h.insert(n);
//	//cin >> n;
//	//h.insert(n);
//	//cin >> n;
//	//h.insert(n	);
//	//cin >> n;
//	//h.insert(n	);
//	cout << "Inserting values.....";
//	h.insert(20);
//	h.insert(30);
//	h.insert(32);
//	h.insert(40);
//	h.insert(50);
//	h.insert(55);
//	h.print();
//	cout << "\n\nMIN VALUE: ";
//	cout<<h.getmin();
//	cout << "\n\nDeleting values: ";
//	h.deleteelement();
//	cout << "\n\nAfter Deleting values: ";
//	h.print();
//	return 0;
//}