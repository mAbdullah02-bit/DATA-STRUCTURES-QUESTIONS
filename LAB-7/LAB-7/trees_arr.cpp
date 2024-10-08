#include <iostream>
#include <string>
using namespace std;

const int SIZE = 9;


void preOrderArray(int index, string arr[], int size) {
    if (index >= size || arr[index] == "")
        return;
    cout << arr[index] << " ";
    preOrderArray(2 * index + 1, arr, size); 
    preOrderArray(2 * index + 2, arr, size); 
}


void postOrderArray(int index, string arr[], int size) {
    if (index >= size || arr[index] == "")
        return;
    postOrderArray(2 * index + 1, arr, size);  
    postOrderArray(2 * index + 2, arr, size);  
    cout << arr[index] << " ";
}


void inOrderArray(int index, string arr[], int size) {
    if (index >= size || arr[index] == "")
        return;
    inOrderArray(2 * index + 1, arr, size);  
    cout << arr[index] << " ";
    inOrderArray(2 * index + 2, arr, size); 
}

int main() {

    string tree[SIZE] = {"D", "Data Structures", "Data Structures Lab", "Labs", "Assignments", 
                         "Lab 1", "Lab 2", "Assignment 1", "Assignment 2"};

    cout << "Pre-order Traversal: ";
    preOrderArray(0, tree, SIZE);
    cout << endl;

    cout << "Post-order Traversal: ";
    postOrderArray(0, tree, SIZE);
    cout << endl;

    cout << "In-order Traversal: ";
    inOrderArray(0, tree, SIZE);
    cout << endl;

    return 0;
}
