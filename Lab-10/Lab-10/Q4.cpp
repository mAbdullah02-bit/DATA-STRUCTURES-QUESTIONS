#include <iostream>
using namespace std;

class BST {
    struct Node {
        int data;
        Node* left;
        Node* right;

        Node(int val) : data(val), left(NULL), right(NULL) {}
    };

    Node* root;

public:
    BST() : root(NULL) {}

   
    Node* insert(Node* node, int data) {
        if (!node) return new Node(data);

        if (data < node->data)
            node->left = insert(node->left, data);
        else
            node->right = insert(node->right, data);

        return node;
    }

    void insert(int data) {
        root = insert(root, data);
    }


    int countNodes(Node* node) {
        if (!node) return 0;
        return 1 + countNodes(node->left) + countNodes(node->right);
    }

   
    void storeInorder(Node* node, int arr[], int& i) {
        if (!node) return;

        storeInorder(node->left, arr, i);
        arr[i++] = node->data;
        storeInorder(node->right, arr, i);
    }

    
    void setPreorder(Node* node, int arr[], int& i) {
        if (!node) return;

        node->data = arr[i++]; 
        setPreorder(node->left, arr, i);
        setPreorder(node->right, arr, i);
    }

   
    void convertToMinHeap() {
        int n = countNodes(root);   
        int* arr = new int[n];      

        int index = 0;
        storeInorder(root, arr, index);   

        index = 0;
        setPreorder(root, arr, index);    

        delete[] arr;  
    }

    
    void preorder(Node* node) {
        if (node==nullptr) return;

        cout << node->data << " ";
        preorder(node->left);
        preorder(node->right);
    }

   
    void preorder() {
        preorder(root);
        cout << endl;
    }
};

int main() {

    BST bst;
    bst.insert(4);
    bst.insert(2);
    bst.insert(6);
    bst.insert(1);
    bst.insert(3);
    bst.insert(5);
    bst.insert(7);

    cout << "Preorder traversal before conversion: ";
    bst.preorder();
    bst.convertToMinHeap();

   
    cout << "Preorder traversal after conversion: ";
    bst.preorder();

    return 0;
}
