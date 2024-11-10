//#include <iostream>
//using namespace std;
//
//class Node {
//public:
//    int data;
//    Node* left;
//    Node* right;
//
//    Node(int val) : data(val), left(nullptr), right(nullptr) {}
//};
//
//class Heap {
//public:
//    Node* root;
//
//    Heap() : root(nullptr) {}
//
//   
//    Node* insert(Node* node, int val) {
//        if (!node) return new Node(val);
//        if (!node->left) node->left = insert(node->left, val);
//        else if (!node->right) node->right = insert(node->right, val);
//        else if (node->left && !node->left->left) insert(node->left, val);
//        else insert(node->right, val);
//
//        return node;
//    }
//
//    
//    void minHeapify(Node* node) {
//        if (!node) return;
//
//        Node* smallest = node;
//        if (node->left && node->left->data < smallest->data) {
//            smallest = node->left;
//        }
//        if (node->right && node->right->data < smallest->data) {
//            smallest = node->right;
//        }
//
//       
//        if (smallest != node) {
//            swap(node->data, smallest->data);
//            minHeapify(smallest);
//        }
//    }
//
//    
//    void convertminHeap(Node* node) {
//        if (!node) return;
//
//        
//        convertminHeap(node->left);
//        convertminHeap(node->right);
//        minHeapify(node);
//    }
//
//    
//    void inorder(Node* node) {
//        if (!node) return;
//        inorder(node->left);
//        cout << node->data << " ";
//        inorder(node->right);
//    }
//};
//
//int main() {
//    Heap h;
//
//    
//    h.root = h.insert(h.root, 50);
//    h.insert(h.root, 30);
//    h.insert(h.root, 40);
//    h.insert(h.root, 10);
//    h.insert(h.root, 20);
//    h.insert(h.root, 35);
//    h.insert(h.root, 45);
//
//    cout << "Max heap inorder: ";
//    h.inorder(h.root);
//    cout << endl;
//
//   
//    h.convertminHeap(h.root);
//
//    cout << "Converted to Min heap inroder: ";
//    h.inorder(h.root);
//    cout << endl;
//
//    return 0;
//}
