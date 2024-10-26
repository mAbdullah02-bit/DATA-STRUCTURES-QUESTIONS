//#include <iostream>
//using namespace std;
//
//class Node {
//public:
//    Node* right, * left;
//    int data;
//    Node(int d) { right = left = nullptr; data = d; }
//};
//
//class BST {
//    Node* root;
//public:
//    BST() { root = nullptr; }
//
//    void insert(int data) {
//        Node* ptr = new Node(data);
//
//        if (root == nullptr) {
//            root = ptr;
//            return;
//        }
//
//        Node* current = root;
//        Node* parent = nullptr;
//
//        while (current != nullptr) {
//            parent = current;
//
//            if (data > current->data) {
//                current = current->right;
//            }
//            else if (data < current->data) {
//                current = current->left;
//            }
//            else {
//                cout << "Cannot insert duplicates\n";
//                return;
//            }
//        }
//
//        if (data > parent->data)
//            parent->right = ptr;
//        else
//            parent->left = ptr;
//    }
//
//    void search(int data) {
//        search(root, data);
//    }
//
//    void search(Node* root, int data) {
//        if (root == nullptr) {
//            cout << "NOT FOUND\n";
//            return;
//        }
//
//        if (data > root->data)
//            search(root->right, data);
//        else if (data < root->data)
//            search(root->left, data);
//        else {
//            cout << "Found with value: " << data << endl;
//        }
//    }
//
//    void deletenode(int data) {
//        deletenode(root, data);
//    }
//
//    void deletenode(Node*& root, int data) {
//        if (root == nullptr) {
//            cout << "Not found\n";
//            return;
//        }
//        else if (data > root->data)
//            deletenode(root->right, data);
//        else if (data < root->data)
//            deletenode(root->left, data);
//        else {
//            if (root->left == nullptr) {
//                Node* temp = root;
//                root = root->right;
//                delete temp;
//            }
//            else if (root->right == nullptr) {
//                Node* temp = root;
//                root = root->left;
//                delete temp;
//            }
//            else {
//                Node* temp = findMaxFromLeft(root->left);
//                root->data = temp->data;
//                deletenode(root->left, temp->data);
//            }
//        }
//    }
//
//    Node* findMaxFromLeft(Node* node) {
//        while (node && node->right != nullptr)
//            node = node->right;
//        return node;
//    }
//    void preorder() {
//        preorder(root);
//        cout << endl;
//    }
//
//    void preorder(Node* root) {
//        if (root != nullptr) {
//            cout << root->data << " ";
//            preorder(root->left);
//            preorder(root->right);
//        }
//    }
//
//    void postorder() {
//        postorder(root);
//        cout << endl;
//    }
//
//    void postorder(Node* root) {
//        if (root != nullptr) {
//            postorder(root->left);
//            postorder(root->right);
//            cout << root->data << " ";
//        }
//    }
//    void inorder() {
//        inorder(root);
//        cout << endl;
//    }
//
//    void inorder(Node* root) {
//        if (root != nullptr) {
//            inorder(root->left);
//            cout << root->data << " ";
//            inorder(root->right);
//        }
//    }
//};
//
//int main() {
//    BST tree;
//    int data;
//
//    for (int i = 0; i < 5; i++) {
//        cout << "Enter data: ";
//        cin >> data;
//        tree.insert(data);
//    }
//
//    cout << "Inorder: ";
//    tree.inorder();
//    cout << "Inorder: ";
//    tree.preorder();
//    cout << "Inorder: ";
//    tree.postorder();
//
//    cout << "Search for an element: ";
//    cin >> data;
//    tree.search(data);
//
//    cout << "Delete an element: ";
//    cin >> data;
//    tree.deletenode(data);
//
//    cout << "Inorder after deletion: ";
//    tree.inorder();
//
//    return 0;
//}
