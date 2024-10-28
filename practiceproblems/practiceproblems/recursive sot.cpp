#include<iostream>
using namespace std;
    void sortrecursive(int arr[], int size, int& i,int & j) {
        if (j == size)
        {
            i=i+1;
            j = i ;
        }
        if (i == size && j == size)
        {
            return;
        }
        if (arr[i] > arr[j])
        {
            swap(arr[i], arr[j]);
        }
        j++;
        sortrecursive(arr, size, i, j);

    }
int main() {
    int arr[5]{ 5,1,7,0,3 };
    int i = 0;
    int j = i + 1;
    sortrecursive(arr, sizeof(arr) / sizeof(arr[0])-1, i,j);

    for (int i = 0; i < 5; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}