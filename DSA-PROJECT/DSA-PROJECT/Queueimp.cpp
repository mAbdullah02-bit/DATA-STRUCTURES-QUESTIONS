#include<iostream>
using namespace std;

class QNode {
public:
	string data;
	string from;
	string to;
	QNode* next;
	QNode(string s, string d) { next = nullptr; data = s; from = s; }
};
class Queue {
	QNode* front, * rear;
public:	Queue() { front = rear = nullptr; }
	  void enque(string d,string from) {
		  QNode* ptr = new QNode(d,from);
		  if (!isempty())
		  {
			  front = rear = ptr;
			  return;
		  }
		  rear->next = ptr;
		  rear = rear->next;
	  }
	  bool isempty() { return (front==nullptr); }
	  string front() { return front->data; }
	  string deque() {
		  if (!isempty())
		  {
			  cout << "Nothing to Delete\n";

			  return "";
		  }
		  string d = front->data;
		  QNode* temp = front;
		  front = front->next;
		  delete temp;
		  return d;

	  
	  }
	  void display() {
		  QNode* temp = front;
		  while (temp!=nullptr)
		  {
			  cout<<"Friend Request From: "<<temp->from<<" to " << temp->data << "\n";
			  temp = temp->next;
		  }

	  }
};