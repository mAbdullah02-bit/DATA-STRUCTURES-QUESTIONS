#pragma once

#include <iostream>
#include <string>
using namespace std;

class LNode {
public:
    int data;
    string name;
    LNode* next;
    LNode(int value, string n);
};

class LList {
public:
    LNode* head;
    LList();
    void insertAtEnd(int value, string name);
    void display() const;
};

class Node {
public:
    int freq;
    string name;
    int height;
    Node* left;
    Node* right;
    LList next;
    Node(int f, string n);
};

class AVL {
    Node* root;
    int height(Node* node);
    int max(int a, int b);
    Node* leftRotate(Node* x);
    Node* rightRotate(Node* y);
    int getBalanceFactor(Node* node);
    Node* insert(Node* node, int freq, string name);
    Node* minValueNode(Node* node);
    Node* deleteNode(Node* root, int freq);
    void playSong(Node* node, int freq, string name);
    void inorder(Node* node);
public:
    AVL();
    void insert(int freq, string name);
    void playSong(int freq, string name);
    void display();
};


