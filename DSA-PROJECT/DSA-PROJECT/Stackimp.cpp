#include<iostream>
using namespace std;

class SNode {
public:
	string data;
	string from;
	string to;
	SNode* next;
	SNode(string s) { next = nullptr; data = s; }
};
class Stack {
	SNode* top;
public:

	Stack() {
		top = nullptr;
	}
	string peek() { return top->data; }
	void push(string d) {
		SNode* ptr = new SNode(d);
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
			cout << "NOTHING HERE :<( \n";
			return "";
		}
		string data = peek();
		SNode* temp = top;
		top = top->next;
		delete temp;
		return data;
	}

	void display() {
		if (top == nullptr)
		{
			cout << "NOTHING to display:<( \n";
			return;
		}
		while (top!=nullptr)
		{
			
			cout << top->data << " \n ";
		top=	top->next;
		}

	}

};
