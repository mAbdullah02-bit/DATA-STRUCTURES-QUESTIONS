//#include <iostream>
//#include<string>
//using namespace std;
//
//class Node {
//public:
//	Node* next;
//	int data;
//
//
//};
//class QUEUE {
//	Node* front;
//	Node* rear;
//public:
//
//
//	QUEUE() {
//		front = rear = nullptr;
//	}
//
//	void Enqueue(int data) {
//		Node* ptr;
//		ptr->data = data;
//		ptr->next = nullptr;
//		if (isempty())
//		{
//			front = rear = ptr;
//		}
//		else
//		{
//
//			rear->next = rear;
//
//
//		}
//
//
//	}
//	int Dequeue() {
//	
//		if (isempty())
//		{
//			cout << "LIST IS EMPTY!...\n";
//			return 0;
//		}
//		int data = front->data;
//		Node* temp = front;
//		front = front->next;
//		delete temp;
//		return data;	
//	}
//
//	bool isempty()
//	{
//		if (front == rear)
//		{
//			return true;
//		}
//		return false;
//	}
//
//};
//int main() {
//
//
//
//
//	system("pause");
//
//	return 0;
//
//}