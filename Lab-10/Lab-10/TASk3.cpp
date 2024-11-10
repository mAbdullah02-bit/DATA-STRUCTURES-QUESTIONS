//#include <iostream>
//using namespace std;
//
//class Heap {
//public:
//    int* arr;
//    int size;
//    int capacity;
//
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
//            int parent = index / 2;
//            if (arr[parent] > arr[index]) {
//                swap(arr[parent], arr[index]);
//                index = parent;
//            }
//            else {
//                return;
//            }
//        }
//    }
//
//    void heapify_down(int start, int end) {
//        int index = start;
//        while (index <= end) {
//            int left = 2 * index;
//            int right = 2 * index + 1;
//            int smallest = index;
//
//            if (left <= end && arr[left] < arr[smallest]) {
//                smallest = left;
//            }
//            if (right <= end && arr[right] < arr[smallest]) {
//                smallest = right;
//            }
//
//            if (smallest != index) {
//                swap(arr[index], arr[smallest]);
//                index = smallest;
//            }
//            else {
//                break;
//            }
//        }
//    }
//
//    void heapsort() {
//        int s1 = size;
//        for (int i = s1; i > 1; i--) {
//            swap(arr[1], arr[i]);
//            size--;
//            heapify_down(1, size);
//        }
//        size = s1;  
//    }
//
//    void displaykelements(int k) {
//        int j = size;
//        for (int i = 1; i <= k; i++){
//
//            cout << arr[j] << "  ";
//            j--;
//        }
//        cout << endl;
//    }
//
//    int getmin() { return arr[1]; }
//
//    void insert(int n) {
//        if (!isfull()) {
//            size++;
//            arr[size] = n;
//            heapify_up();  
//        }
//        else {
//            cout << "Cannot insert; Heap full!\n";
//        }
//    }
//
//    void deleteelement() {
//        if (isempty()) {
//            cout << "Heap is empty!\n";
//            return;
//        }
//        arr[1] = arr[size];
//        size--;
//        heapify_down(1, size);  
//    }
//};
//
//int main() {
//    Heap h;
//
//    cout << "Inserting values...\n";
//    h.insert(20);
//    h.insert(60);
//    h.insert(32);
//    h.insert(40);
//    h.insert(50);
//    h.insert(45);
//    h.print();
//
//    h.heapsort();
//    cout << "Sorted Heap: ";
//    h.print();
//
//    cout << "\nEnter value to display first k elements: ";
//    int k;
//    cin >> k;
//    if (k > 0 && k <= h.size) {
//        h.displaykelements(k);
//    }
//    else {
//        cout << "Invalid k given.\n";
//    }
//
//    return 0;
//}
