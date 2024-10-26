#pragma once
#include <iostream>
using namespace std;

class Node {
public:
    Node* left, * right;
    int data;
    int height;

    Node(int data) {
        this->data = data;
        height = 1;
        left = right = nullptr;
    }
};

class AvlTree {
public:
    Node* root;
    AvlTree() { root = nullptr; }
    int height(Node* root);
    bool isempty() { return (root == nullptr); }
    void inorder(Node* root);
    Node* insert(Node* root, int data);
    Node* deletenode(Node*& root, int data);
    bool isAVL(Node* node);
    Node* balance(Node* node);
    int getbalancefactor(Node* root);
    Node* rightrotate(Node* x);
    Node* leftrotate(Node* x);
    Node* findMaxFromLeft(Node* node);
    void mergeTrees(Node*& root, Node* other);
};
