//#include<iostream>
//using namespace std;
//
//
//void sort(int arr[],int n) {
//
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = i+1; j < n; j++)
//		{
//			if (arr[i] > arr[j])swap(arr[i], arr[j]);
//		}
//
//	}
//
//}
//
//int main() {
//	int arr[10] = { 5,8,9,2,4,0,1,4,6,3 }; 
//	cout << "Given Array: \n";
//	for (int  i = 0; i < 10; i++)
//	{
//		cout << arr[i] << " ";
//	}
//	int k;
//	sort(arr, 10);
//	cout << "Enter value of k: ";
//	cin >> k;
//
//	cout << "k Elements: ";
//	for (int i = 0; i < k; i++)
//	{
//		cout << arr[i] << "  ";
//	}cout << endl;
//	return 0;
//}