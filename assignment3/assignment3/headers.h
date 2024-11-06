#pragma once

#include <iostream>
#include <climits>
using namespace std;

class node {
public:
    int data;
    node* left;
    node* right;
    node(int data, node* left = NULL, node* right = NULL);
};

class BST {
    node* root;
    node* insertion(node* root, int n);
    int maxPathSum(node* root, int& sum);

public:
    BST();
    node* getRoot();
    void insert(int n);
    int findMaxPathSum();
    void inorder(node* n) const;
};
