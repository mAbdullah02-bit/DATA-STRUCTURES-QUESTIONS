//#include<iostream>
//using namespace std;
//class node {
//public:
//	node* next;
//	char data;
//	node()
//	{
//		next = nullptr;
//		data = 0;
//	}
//};
//class queue {
//	node* front;
//	node* rear;
//public:
//	queue() {
//		front = rear = nullptr;
//	}
//	void enqueue(char d)
//	{
//		node* ptr = new node;
//		ptr->data = d;
//		ptr->next = nullptr;
//		if (rear == nullptr)
//		{
//			front = rear = ptr;
//		}
//		else
//		{
//			rear->next = ptr;
//			rear = ptr;
//		}
//	}
//
//	char dequeue()
//	{
//		if (front == nullptr)
//		{
//			cout << "nothing to remove\n";
//			return -1;
//		}
//		node* temp = front;
//		char dd = temp->data;
//		front = front->next;
//		if (front == nullptr)
//		{
//			rear = nullptr;
//		}
//		delete temp;
//		return dd;
//	}
//	bool isempty()
//	{
//		if (front == nullptr)
//			return true;
//		else return false;
//	}
//	void display()
//	{
//		while (!isempty())
//		{
//			cout << dequeue();
//		}
//		cout << endl;
//	}
//};
//class Stack {
//	node* top;
//public:
//	Stack() {
//		top = nullptr;
//	}
//	void push(char d)
//	{
//		node* ptr = new node;
//		ptr->data = d;
//		ptr->next = top;
//		top = ptr;
//	}
//	char pop()
//	{
//		if (isempty())
//		{
//			cout << "Nothing to pop\n:";
//			return -1;
//		}
//		node* temp = top;
//		char dd = temp->data;
//		top = top->next;
//		delete temp;
//		return dd;
//	}
//	bool isempty()
//	{
//		if (top == nullptr)
//		{
//			return true;
//		}
//		else return false;
//	}
//	void display()
//	{
//		while (!isempty())
//		{
//			cout << pop();
//		}
//	}
//};
//bool check_alpha(char ch)
//{
//	if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z'))
//	{
//		return true;
//	}
//	else false;
//}
//bool palindrome(string str)
//{
//	Stack st;
//	queue qq;
//	for (int i = 0; i < str.length(); i++)
//	{
//		if (check_alpha(str[i]))
//		{
//			st.push(str[i]);
//			qq.enqueue(str[i]);
//		}
//	}
//	for (int i = 0; i < str.length() / 2; i++)
//	{
//		if (st.pop() != qq.dequeue())
//		{
//			return false;
//		}
//	}
//	return true;
//
//}
//int main()
//{
//	string str = "12321";
//	if (palindrome(str))
//		cout << "given string is palindrome\n";
//	else cout << "not palindrome\n";
//	return 0;
//}