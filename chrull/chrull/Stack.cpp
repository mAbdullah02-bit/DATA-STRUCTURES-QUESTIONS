#include<iostream>
#include <string>
using namespace std;
struct Node {
	string name;
	string timestampp;
	Node* next;
	Node() {
		next = nullptr;
	}
};

class stack {
	Node* top;
public:

	stack() {
		top = nullptr;
	}



	void push(string n, string t) {
		Node* newn = new Node;
		newn->name = n;
		newn->timestampp = t;
		newn->next = top;
		top = newn;
	}

	void pop() {
		if (isEmpty()) {
			cout << "\033[36m\t\t\t\t\t\t\t  Empty" << endl;
			return;
		}
		Node* temp = top;
		top = top->next;
		delete temp;
	}

	string peek() {
		return top->name;
	}

	bool isEmpty() {
		if (top == nullptr) {
			return true;
		}
		return false;
	}

	void display() {

		Node* temp = top;
		while (temp) {
			cout << "\033[36m\t\t\t\t\t\t\t " << temp->name << endl;
			cout << "\033[36m\t\t\t\t\t\t\t " << temp->timestampp;
			temp = temp->next;
			cout << endl << endl;
		}
	}
};