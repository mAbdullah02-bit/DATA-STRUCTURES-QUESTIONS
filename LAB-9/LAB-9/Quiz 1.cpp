//#include <iostream>
//using namespace std;
//
//class Node {
//public:
//    Node* left, * right;
//    string data;
//    Node(string data) { left = right = nullptr; this->data = data; }
//};
//
//class QueueNODE {
//public:
//    QueueNODE* next;
//    Node* treeNode;
//
//    QueueNODE(Node* treeNode) { next = nullptr; this->treeNode = treeNode; }
//};
//
//class Queue {
//    QueueNODE* rear, * front;
//
//public:
//    Queue() { rear = front = nullptr; }
//
//    void enqueue(Node* treeNode) {
//        QueueNODE* ptr = new QueueNODE(treeNode);
//        if (front == nullptr) {
//            front = rear = ptr;
//        }
//        else {
//            rear->next = ptr;
//            rear = ptr;
//        }
//    }
//
//    Node* dequeue() {
//        if (front == nullptr) {
//            cout << "Queue is Empty!\n";
//            return nullptr;
//        }
//
//        QueueNODE* temp = front;
//        Node* treeNode = temp->treeNode;
//        front = front->next;
//
//        if (front == nullptr) {
//            rear = nullptr;
//        }
//
//        delete temp;
//        return treeNode;
//    }
//
//    bool isEmpty() {
//        return front == nullptr;
//    }
//};
//
//class BinaryTree {
//    Node* root;
//
//public:
//    BinaryTree() { root = nullptr; }
//
//    void Buildtree() {
//        root = BuildtreeHelper();
//    }
//
//    Node* BuildtreeHelper() {
//        string data;
//        cin >> data;
//        if (data == "-1") {
//            return nullptr;
//        }
//
//        Node* newNode = new Node(data);
//        cout << "Enter data for left : " ;
//        newNode->left = BuildtreeHelper();
//        cout << "Enter data for right:  ";
//        newNode->right = BuildtreeHelper();
//        return newNode;
//    }
//
//    void inorder(Node* root) {
//        if (root != nullptr) {
//            inorder(root->left);
//            cout << root->data << " ";
//            inorder(root->right);
//        }
//    }
//
//    bool SearchBFS(string data) {
//        if (root == nullptr) {
//            cout << "TREE IS EMPTY\n";
//            return false;
//        }
//
//        Queue q;
//        q.enqueue(root);
//
//        while (!q.isEmpty()) {
//            Node* temp = q.dequeue();
//            if (temp->data == data) {
//                return true;
//            }
//            if (temp->left != nullptr) {
//                q.enqueue(temp->left);
//            }
//            if (temp->right != nullptr) {
//                q.enqueue(temp->right);
//            }
//        }
//
//        return false;
//    }
//
//    void BFS() {
//        if (root == nullptr) {
//            cout << "TREE IS EMPTY\n";
//            return;
//        }
//
//        Queue q;
//        q.enqueue(root);
//
//        while (!q.isEmpty()) {
//            Node* temp = q.dequeue();
//            cout << temp->data << endl;
//            if (temp->left != nullptr) {
//                q.enqueue(temp->left);
//            }
//            if (temp->right != nullptr) {
//                q.enqueue(temp->right);
//            }
//        }
//    }
//
//    Node* getRoot() {
//        return root;
//    }
//};
//
//int main() {
//    BinaryTree tree;
//    cout << "Build the tree root node value:\n";
//    tree.Buildtree();
//
//    cout << "\nBFS traversal:\n";
//    tree.BFS();
//    cout << endl;
//
//    string data;
//    cout << "Enter data to search: ";
//    cin >> data;
//
//    if (tree.SearchBFS(data)) {
//        cout << "Found NODE" << endl;
//    }
//    else {
//        cout << "NODE Not Found" << endl;
//    }
//
//    return 0;
//}
