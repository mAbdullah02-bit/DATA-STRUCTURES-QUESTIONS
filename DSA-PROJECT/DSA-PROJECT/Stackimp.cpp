#include<iostream>
using namespace std;

class Node {
public:
	string data;

	Node* next;
	Node(string s) { next = nullptr; data = s; }
};
class Stack {
	Node* top;
public:

	Stack() {
		top = nullptr;
	}
	string peek() { return top->data; }
	void push(string d) {
		Node* ptr = new Node(d);
		if (top == nullptr) {
			top = ptr;
		return;
		}
		ptr->next = top;
		top = ptr;
		return;
	}
	string pop() {
		if (top == nullptr)
		{

		}

	}

};