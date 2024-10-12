//#include<iostream>
//using namespace std;
//
//
//class Queue {
//
//private:
//
//	string* queueArray;
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
//	Queue(int size) { queueArray = new string[size]; front = rear = -1;  numItems = 0; 
//	queueSize = size;
//	}
//
//	~Queue() {
//		delete[] queueArray; queueArray
//			= nullptr;
//	}
//
//	bool isEmpty() { return  numItems == 0; }
//
//	bool isFull() {
//		if (queueSize == numItems) { return true; }
//		else 
//		return false;
//		
//	}
//
//	bool enqueue(string x) {
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
//	string dequeue() {
//		if (isEmpty())
//
//		{
//
//			cout << "The queue is empty.\n";
//
//			return "\0";
//
//		}
//
//
//
//		front = (front + 1) % queueSize;
//
//		string num = queueArray[front];
//		queueArray[front] = " ";
//
//		numItems--;
//
//
//		return num;
//		
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
//	void display() {
//	
//		for (int i = (front+1)%queueSize; i < queueSize ; i++)
//		{
//			cout << " <- " << queueArray[i];
//		}
//		cout << endl;
//	
//	}
//
//};
//
//int main() {
//	Queue l1(5);
//	l1.dequeue();
//	l1.enqueue("Ali");
//	l1.enqueue("Abdullah");
//	l1.enqueue("bilal");
//	l1.enqueue("Reyyan asim");
//	l1.enqueue("Juad jaweel");
//	l1.display();
//	l1.enqueue("billu");
//	cout << l1.dequeue()<<" went through\n";
//	cout << l1.dequeue()<<" went through\n";
//	l1.display();
//
//	return 0;
//}