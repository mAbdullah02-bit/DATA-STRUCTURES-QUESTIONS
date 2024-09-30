//#include<iostream>
//using namespace std;
//
//
//class Queue {
//
//private:
//
//	int* queueArray;
//
//	int queueSize;
//
//	int front;
//
//	int rear;
//
//	int numItems;
//
//public:
//
//	Queue(int size) { queueArray = new int[size]; front = rear = -1; }
//
//	~Queue() { delete queueArray; }
//
//	bool isEmpty() { return  numItems == 0; }
//
//	bool isFull() {
//		return queueSize == numItems;
//	}
//
//	bool enqueue(int x) {
//
//		if (isFull())
//		{
//			cout << "QUEUE is FULL.\n";
//			return false;
//		}
//		rear = (rear + 1) % queueSize;
//		queueArray[rear] = x;
//		numItems++;
//		return true;
//	}
//
//	int dequeue() {
//		if (isEmpty())
//
//		{
//
//			cout << "The queue is empty.\n";
//
//			return false;
//
//		}
//
//
//
//		front = (front + 1) % queueSize;
//
//
//		int num = queueArray[front];
//
//
//
//		numItems--;
//
//		return true;
//
//	}
//
//	void makeNull() {
//		front = -1;
//
//		rear = -1;
//
//		numItems = 0;
//
//	}
//
//};
//
//int main() {
//	Queue l1(6);
//
//
//
//
//
//	return 0;
//}