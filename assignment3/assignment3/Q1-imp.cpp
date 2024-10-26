//#include "BSTClasses.h"
//#include <iostream>
//using namespace std;
//
//
//Node::Node(int d) {
//    right = left = nullptr;
//    data = d;
//}
//
//
//BST::BST() {
//    root = nullptr;
//}
//
//void BST::insert(int data) {
//    Node* ptr = new Node(data);
//    if (root == nullptr) {
//        root = ptr;
//        return;
//    }
//    Node* current = root;
//    Node* parent = nullptr;
//    while (current != nullptr) {
//        parent = current;
//        if (data > current->data) {
//            current = current->right;
//        }
//        else if (data < current->data) {
//            current = current->left;
//        }
//        else {
//            cout << "Cannot insert duplicates\n";
//            return;
//        }
//    }
//    if (data > parent->data)
//        parent->right = ptr;
//    else
//        parent->left = ptr;
//}
//
//
//void BST::search(int data) {
//    search(root, data);
//}
//
//void BST::search(Node* root, int data) {
//    if (root == nullptr) {
//        cout << "NOT FOUND\n";
//        return;
//    }
//    if (data > root->data)
//        search(root->right, data);
//    else if (data < root->data)
//        search(root->left, data);
//    else {
//        cout << "Found with value: " << data << endl;
//    }
//}
//
//
//void BST::deletenode(int data) {
//    deletenode(root, data);
//}
//
//void BST::deletenode(Node*& root, int data) {
//    if (root == nullptr) {
//        cout << "Not found\n";
//        return;
//    }
//    else if (data > root->data)
//        deletenode(root->right, data);
//    else if (data < root->data)
//        deletenode(root->left, data);
//    else {
//        if (root->left == nullptr) {
//            Node* temp = root;
//            root = root->right;
//            delete temp;
//        }
//        else if (root->right == nullptr) {
//            Node* temp = root;
//            root = root->left;
//            delete temp;
//        }
//        else {
//            Node* temp = findMaxFromLeft(root->left);
//            root->data = temp->data;
//            deletenode(root->left, temp->data);
//        }
//    }
//}
//
//
//Node* BST::findMaxFromLeft(Node* node) {
//    while (node && node->right != nullptr)
//        node = node->right;
//    return node;
//}
//
//void BST::preorder() {
//    preorder(root);
//    cout << endl;
//}
//
//void BST::preorder(Node* root) {
//    if (root != nullptr) {
//        cout << root->data << " ";
//        preorder(root->left);
//        preorder(root->right);
//    }
//}
//
//void BST::postorder() {
//    postorder(root);
//    cout << endl;
//}
//
//void BST::postorder(Node* root) {
//    if (root != nullptr) {
//        postorder(root->left);
//        postorder(root->right);
//        cout << root->data << " ";
//    }
//}
//
//void BST::inorder() {
//    inorder(root);
//    cout << endl;
//}
//
//void BST::inorder(Node* root) {
//    if (root != nullptr) {
//        inorder(root->left);
//        cout << root->data << " ";
//        inorder(root->right);
//    }
//}
