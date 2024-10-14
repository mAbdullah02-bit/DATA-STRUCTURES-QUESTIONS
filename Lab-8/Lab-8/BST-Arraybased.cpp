#include<iostream>
using namespace std;

class Node {
public:
	int data;
	Node* left, * right;
	Node(int data) { left = right = nullptr; this->data = data; }
	Node() { left = right = nullptr; }

};

class BST {
	Node* root;
public:




};