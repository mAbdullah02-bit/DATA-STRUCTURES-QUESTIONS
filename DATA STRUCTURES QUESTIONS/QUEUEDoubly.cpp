//#include<iostream>
//using namespace std;
//
//class deque {
//    int* dequeArr;
//    int maxSize, rear, front;
//
//public:
//    deque(int s) {
//        maxSize = s;
//        dequeArr = new int[s];
//        for (int i = 0; i < maxSize; i++) {
//            dequeArr[i] = 0;
//        }
//        rear = front = -1;
//    }
//
//    bool isEmpty() {
//        return (rear == -1 && front == -1);
//    }
//
//    bool isFull() {
//        return ((rear + 1) % maxSize == front);
//    }
//
//    void insertFront(int value) {
//        if (isFull()) {
//            cout << "Deque is full.\n";
//            return;
//        }
//
//        if (isEmpty()) {
//            front = rear = 0;
//        }
//        else {
//            front = (front - 1 + maxSize) % maxSize;
//        }
//
//        dequeArr[front] = value;
//    }
//
//    void insertBack(int value) {
//        if (isFull()) {
//            cout << "Deque is full.\n";
//            return;
//        }
//
//        if (isEmpty()) {
//            front = rear = 0;
//        }
//        else {
//            rear = (rear + 1) % maxSize;
//        }
//
//        dequeArr[rear] = value;
//    }
//
//    int removeFront() {
//        if (isEmpty()) {
//            cout << "Deque is empty.\n";
//            return -1;
//        }
//
//        int value = dequeArr[front];
//        dequeArr[front] = 0;
//
//        if (front == rear) { 
//            front = rear = -1;
//        }
//        else {
//            front = (front + 1) % maxSize;
//        }
//
//        return value;
//    }
//
//    int removeBack() {
//        if (isEmpty()) {
//            cout << "Deque is empty.\n";
//            return -1;
//        }
//
//        int value = dequeArr[rear];
//        dequeArr[rear] = 0;
//
//        if (front == rear) { 
//            front = rear = -1;
//        }
//        else {
//            rear = (rear - 1 + maxSize) % maxSize;
//        }
//
//        return value;
//    }
//
//    void display() {
//        if (isEmpty()) {
//            cout << "Deque is empty.\n";
//            return;
//        }
//
//        int i = front;
//        while (true) {
//            cout << dequeArr[i] << " ";
//            if (i == rear)
//                break;
//            i = (i + 1) % maxSize;
//        }
//        cout << endl;
//    }
//
//    ~deque() {
//        delete[] dequeArr;
//    }
//};
//
//int main() {
//    deque q(10);
//
//    q.insertFront(1);
//    q.display();
//
//    q.insertFront(2);
//    q.display();
//
//    q.insertBack(5);
//    q.display();
//
//    q.insertBack(6);
//    q.display();
//
//    q.insertFront(3);
//    q.display();
//
//    q.insertFront(4);
//    q.display();
//
//    q.insertBack(7);
//    q.display();
//
//    q.insertBack(8);
//    q.display();
//
//    q.removeFront();
//    q.display();
//
//    q.removeBack();
//    q.display();
//
//    return 0;
//}
