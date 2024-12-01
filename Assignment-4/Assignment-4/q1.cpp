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
//            cout << arr[i] << " ";
//        }
//        cout << endl;
//    }
//
//    bool isempty() { return (size == 0); }
//
//    bool isfull() { return (size == capacity); }
//
//    int getmin() { return arr[1]; }
//
//    void insert(int n) {
//        if (!isfull()) {
//            size++;
//            int index = size;
//            arr[index] = n;
//
//            while (index > 1) {
//                int parent = index / 2;
//                if (arr[parent] > arr[index]) {
//                    swap(arr[parent], arr[index]);
//                    index = parent;
//                }
//                else {
//                    return;
//                }
//            }
//        }
//        else {
//            cout << "Can't insert. Heap is full!\n";
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
//        int i = 1;
//
//        while (true) {
//            int l = 2 * i;
//            int r = 2 * i + 1;
//            int smallest = i;
//
//            if (l <= size && arr[l] < arr[smallest]) {
//                smallest = l;
//            }
//            if (r <= size && arr[r] < arr[smallest]) {
//                smallest = r;
//            }
//
//            if (smallest != i) {
//                swap(arr[i], arr[smallest]);
//                i = smallest;
//            }
//            else {
//                return;
//            }
//        }
//    }
//
//    void extractTopK(int k) {
//        cout << "Top " << k << " priority tasks: ";
//        for (int i = 0; i < k && !isempty(); i++) {
//            cout << getmin() << " ";
//            deleteelement();
//        }
//        cout << endl;
//    }
//};
//
//int main() {
//    Heap h;
//    int tasks[] = { 15, 10, 20, 8, 12, 25, 18 };
//    int n = sizeof(tasks) / sizeof(tasks[0]);
//
//  
//    for (int i = 0; i < n; i++) {
//        h.insert(tasks[i]);
//    }
//
//    cout << "Heap after building: ";
//    h.print();
//
//   
//    h.insert(5);
//    cout << "Heap after inserting 5: ";
//    h.print();
//
//    
//    cout << "Extracting top " << h.getmin() << endl;
//    h.deleteelement();
//    cout << "Heap after extracting minimum: ";
//    h.print();
//
// 
//    h.extractTopK(3);
//
//    cout << "Heap after extracting top 3 tasks: ";
//    h.print();
//
//    return 0;
//}
