//#include <iostream>
//using namespace std;
//
//class BST {
//public:
//    int* arr;
//    int index = 0;
//    int length = 0;
//
//    BST(int x) {
//        arr = new int[x];
//        index = 0;
//
//        for (int i = 0; i < x; i++) arr[i] = -1;  
//    }
//
//    void insert(int data) {
//        if (index == 10) {
//            cout << "Array is full!\n";
//            return;
//        }
//
//        int index = 1;
//        while (arr[index] != -1) {
//            if (data < arr[index]) {
//                index = 2 * index; 
//            }
//            else {
//                index = 2 * index + 1; 
//            }
//            if (index >= 10) {
//                cout << "Index out of bounds!\n";
//                return;
//            }
//        }
//        arr[index] = data;
//        length++;
//    }
//
//    int getlength() {
//        return length;
//    }
//
//    int leafnodes() {
//        int c = 0;
//        for (int i = 1; i < 10; i++) {
//            if (arr[i] != -1 && arr[2 * i] == -1 && arr[2 * i + 1] == -1) {
//                c++;  
//            }
//        }
//        return c;
//    }
//
//    void deletenode(int data) {
//        int index = 1;
//        while (index < 10 && arr[index] != -1) {
//            if (arr[index] == data) {
//                break;
//            }
//            else if (data < arr[index]) {
//                index = 2 * index;
//            }
//            else {
//                index = 2 * index + 1;  
//            }
//        }
//
//        if (arr[index] == -1) {
//            cout << "Element not found!\n";
//            return;
//        }
//
//    
//        if (arr[2 * index] == -1 && arr[2 * index + 1] == -1) {
//            arr[index] = -1;
//            length--;
//            cout << "Deleted\n";
//        }
//    
//        else if (arr[2 * index] == -1) {
//            arr[index] = arr[2 * index + 1];  
//            arr[2 * index + 1] = -1;
//            length--;
//            cout << "Deleted\n";
//        }
//        else if (arr[2 * index + 1] == -1) {
//            arr[index] = arr[2 * index]; 
//            arr[2 * index] = -1;
//            length--;
//            cout << "Deleted\n";
//        }
//     
//        else {
//            int minIndex = findminimumfromright(2 * index + 1);
//            arr[index] = arr[minIndex]; 
//            deleteminimum(minIndex);
//            cout << "Deleted\n";
//        }
//    }
//
//    int findminimumfromright(int index) {
//        while (index * 2 < 10 && arr[index * 2] != -1) {
//            index = 2 * index;  
//        }
//        return index;
//    }
//
//    void deleteminimum(int index) {
//        if (arr[2 * index] == -1 && arr[2 * index + 1] == -1) {
//            arr[index] = -1;  
//        }
//        else if (arr[2 * index] == -1) {
//            arr[index] = arr[2 * index + 1];  
//            arr[2 * index + 1] = -1;
//        }
//        else {
//            arr[index] = arr[2 * index];  
//            arr[2 * index] = -1;
//        }
//    }
//
//    void search(int n) {
//        int index = 1;
//
//        while (index < 10 && arr[index] != -1) {
//            if (n > arr[index]) {
//                index = index * 2 + 1;              }
//            else if (n < arr[index]) {
//                index = index * 2;  
//            }
//            else {
//                cout << "FOUND\n";
//                return;
//            }
//        }
//        cout << "NOT FOUND!\n";
//    }
//
//    void preorder(int index) {
//        if (index < 10 && arr[index] != -1) {
//            cout << arr[index] << " ";
//            preorder(2 * index);
//            preorder(2 * index + 1);
//        }
//    }
//
//    void inorder(int index) {
//        if (index < 10 && arr[index] != -1) {
//            inorder(2 * index);
//            cout << arr[index] << " ";
//            inorder(2 * index + 1);
//        }
//    }
//
//    void postorder(int index) {
//        if (index < 10 && arr[index] != -1) {
//            postorder(2 * index);
//            postorder(2 * index + 1);
//            cout << arr[index] << " ";
//        }
//    }
//
//    void display() {
//        for (int i = 1; i < 9; i++) {
//            if (arr[i] == -1) cout << " x ";
//            else cout << arr[i] << " ";
//        }
//        cout << endl;
//    }
//};
//
//int main() {
//    BST t(10);
//    int n;
//    for (int i = 0; i < 9; i++) {
//        cout << "ENTER NO: ";
//        cin >> n;
//        t.insert(n);
//    }
//
//    cout << "Displaying...\n";
//    t.display();
//
//    cout << "INORDER\n";
//    t.inorder(1);
//    cout << "\nPreORDER\n";
//    t.preorder(1);
//    cout << "\nPostORDER\n";
//    t.postorder(1);
//    cout << endl;
//
//    cout << "Displaying...\n";
//    t.display();
//    cout << "Leafnodes: " << t.leafnodes() << endl;
//
//    t.deletenode(7);  
//    t.display();
//    t.deletenode(1);  
//    t.display();
//    t.deletenode(6);  
//    t.display();
//    cout << "Leafnodes: " << t.leafnodes() << endl;
//
//    cout << "LENGTH of Tree: \n" << t.getlength();
//
//    return 0;
//}
