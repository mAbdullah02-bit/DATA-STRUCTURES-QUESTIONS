#pragma once

class Node {
public:
    Node* right;
    Node* left;
    int data;

    Node(int d);
};

class BST {
public:
    Node* root;

    BST();
    void insert(int data);
    void search(int data);
    void inorder();
    void preorder();
    void postorder();

    void deletenode(int data);
    
    Node* arraytoBST(int arr[], int start, int end);


    void search(Node* root, int data);
    void inorder(Node* root);
    void preorder(Node* root);
    void postorder(Node* root);
    Node* buildBST(int arr[]);
    void deletenode(Node*& root, int data);
    Node* findMaxFromLeft(Node* node);
    void sortrecursive(int arr[], int size,int&,int&);
    Node* buildtree(int arr[], int start, int end);
};

