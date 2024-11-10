//#include<iostream>
//using namespace std;
//
//class Heap {
//public:
//    int* arr;
//    int size;
//    int capacity;
//    Heap() {
//        size = 0;
//        capacity = 100;
//        arr = new int[capacity];
//        arr[0] = -1;
//    }
//
//    void print() {
//        for (int i = 1; i <= size; i++) {
//            cout << arr[i] << "  ";
//        }
//        cout << endl;
//    }
//
//    bool isempty() { return (size == 0); }
//    bool isfull() { return (size == capacity); }
//
//    void heapify_up() {
//        int index = size;
//        while (index > 1) {
//            if (arr[index] > arr[index / 2]) {
//                swap(arr[index], arr[index / 2]);
//            }
//            index = index / 2;
//        }
//    }
//
//    void heapify_down(int index) { 
//        while (index <= size) {
//            int left = 2 * index;
//            int right = 2 * index + 1;
//            int largest = index;
//
//            if (left <= size && arr[left] > arr[largest]) {
//                largest = left;
//            }
//            if (right <= size && arr[right] > arr[largest]) {
//                largest = right;
//            }
//            if (largest != index) {
//                swap(arr[index], arr[largest]);
//                index = largest;
//            }
//            else {
//                break;
//            }
//        }
//    }
//
//    int getmax() { return arr[1]; }
//
//    void insert(int n) {
//        if (!isfull()) {
//            size++;
//            int index = size;
//            arr[index] = n;
//            heapify_up();  
//        }
//        else {
//            cout << "Can't insert; Heap full!..\n";
//        }
//    }
//
//    void deleteelement() {
//        if (isempty()) {
//            cout << "EMPTY!..\n";
//            return;
//        }
//        arr[1] = arr[size];
//        size--;
//        heapify_down(1);  
//    }
//
//    void func() {
//        int s1 = size; 
//        for (int i = size; i > 1; i--) {
//            swap(arr[1], arr[i]);  
//            size--; 
//            heapify_down(1);  
//            print();  
//        }
//        size = s1; 
//    }
//};
//
//int main() {
//    Heap h;
//
//    cout << "Inserting values.....\n";
//    h.insert(20);
//    h.insert(30);
//    h.insert(32);
//    h.insert(40);
//    h.insert(50);
//    h.insert(55);
//    h.print();
//
//    cout << "\n\nMax VALUE: ";
//    cout << h.getmax();
//
//    cout << "\n\nDeleting values: ";
//    h.deleteelement();
//    cout << "\n\nAfter Deleting values: ";
//    h.print();
//
//    cout << "\nHEAPIFYING TILL SIZE == 1 \n\n";
//    h.func();
//    return 0;
//}
