#include<iostream>
using namespace std;

class QNode {
public:
	string data;
	string from;
	string to;
	QNode* next;
	QNode(string s, string d) { next = nullptr; data = s; to = d; }
};
class Queue {
	QNode* front, * rear;
public:	Queue() { front = rear = nullptr; }
	  void enque(string from,string to) {
		  QNode* ptr = new QNode(from,to);
		  if (!isempty())
		  {
			  front = rear = ptr;
			  return;
		  }
		  rear->next = ptr;
		  rear = rear->next;
	  }
	  bool isempty() { return (front==nullptr); }
	  
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
		  int x=0;
		  while (temp!=nullptr)
		  {
			  x++;
			  cout<<"Follower "<<x<<" | " << temp->data << " |   ";
			  temp = temp->next;
		  }
		  cout << "Follower count" << x << endl;;
;	  }
};