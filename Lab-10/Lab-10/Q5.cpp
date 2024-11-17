////#include <iostream>
////using namespace std;
////
////class Node {
////public:
////    int data;
////    Node* left;
////    Node* right;
////
////    Node(int val) : data(val), left(nullptr), right(nullptr) {}
////};
////
////class Heap {
////public:
////    Node* root;
////
////    Heap() : root(nullptr) {}
////
////   
////    Node* insert(Node* node, int val) {
////        if (!node) return new Node(val);
////        if (!node->left) node->left = insert(node->left, val);
////        else if (!node->right) node->right = insert(node->right, val);
////        else if (node->left && !node->left->left) insert(node->left, val);
////        else insert(node->right, val);
////
////        return node;
////    }
////
////    
////    void minHeapify(Node* node) {
////        if (!node) return;
////
////        Node* smallest = node;
////        if (node->left && node->left->data < smallest->data) {
////            smallest = node->left;
////        }
////        if (node->right && node->right->data < smallest->data) {
////            smallest = node->right;
////        }
////
////       
////        if (smallest != node) {
////            swap(node->data, smallest->data);
////            minHeapify(smallest);
////        }
////    }
////
////    
////    void convertminHeap(Node* node) {
////        if (!node) return;
////
////        
////        convertminHeap(node->left);
////        convertminHeap(node->right);
////        minHeapify(node);
////    }
////
////    
////    void inorder(Node* node) {
////        if (!node) return;
////        inorder(node->left);
////        cout << node->data << " ";
////        inorder(node->right);
////    }
////};
////
////int main() {
////    Heap h;
////
////    
////    h.root = h.insert(h.root, 50);
////    h.insert(h.root, 30);
////    h.insert(h.root, 40);
////    h.insert(h.root, 10);
////    h.insert(h.root, 20);
////    h.insert(h.root, 35);
////    h.insert(h.root, 45);
////
////    cout << "Max heap inorder: ";
////    h.inorder(h.root);
////    cout << endl;
////
////   
////    h.convertminHeap(h.root);
////
////    cout << "Converted to Min heap inroder: ";
////    h.inorder(h.root);
////    cout << endl;
////
////    return 0;
////}
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//#include <iostream>
//using namespace std;
//
//class Node {
//public:
//    int data;
//    Node* left;
//    Node* right;
//
//    Node(int val) {
//        data = val;
//        left = nullptr; 
//        right = nullptr;
//    }
//};
//class Heap {
//public:
//    Node* root;
//
//    Heap() {
//        root = nullptr;
//    }
//
//    Node* insert(Node* n, int val) {
//        if (!n) {
//            return new Node(val);
//        }
//        if (!n->left) {
//            n->left = insert(n->left, val);
//        }
//        else if (!n->right) {
//            n->right = insert(n->right, val);
//        }
//        else if (n->left && !n->left->left) {
//            insert(n->left, val);
//        }
//        else insert(n->right, val);
//
//        return n;
//    }
//
//    void minHeap(Node* n) {
//        if (!n) return;
//
//        Node* min = n;
//        if (n->left && n->left->data < min->data) {
//            min = n->left;
//        }
//        if (n->right && n->right->data < min->data) {
//            min = n->right;
//        }
//
//
//        if (min != n) {
//            swap(n->data, min->data);
//            minHeap(min);
//        }
//    }
//    void convertMin(Node* n) {
//        if (!n) return;
//
//
//        convertMin(n->left);
//        convertMin(n->right);
//        minHeap(n);
//    }
//    void inorder(Node* node) {
//        if (node) {
//            inorder(node->left);
//            cout << node->data << " ";
//            inorder(node->right);
//        }
//    }
//};
//
//int main() {
//    Heap h;
//
//    h.root = h.insert(h.root, 90);
//    h.insert(h.root, 35);
//    h.insert(h.root, 23);
//    h.insert(h.root, 12);
//    h.insert(h.root, 54);
//    h.insert(h.root, 45);
//    h.insert(h.root, 20);
//
//    cout << "inorder: ";
//    h.inorder(h.root);
//    cout << endl;
//    h.convertMin(h.root);
//
//    cout << "Conversion to inroder: ";
//    h.inorder(h.root);
//    cout << endl;
//
//    system("pause");
//    return 0;
//}
