//#include<iostream>
//using namespace std;
//
//template <class T>
//class Node {
//public:
//    Node* next;
//    T x, y;
//};
//
//template <class T>
//class Queue {
//public:
//    Node<T>* rear;
//    Node<T>* front;
//
//    Queue() : rear(nullptr), front(nullptr) {}
//
//    void Enqueue(T data, T y) {
//        Node<T>* ptr = new Node<T>;
//        ptr->x = data;
//        ptr->y = y;
//        ptr->next = nullptr;
//
//        if (front == nullptr) {
//            front = ptr;
//            rear = ptr;
//            return;
//        }
//        rear->next = ptr;
//        rear = ptr;
//    }
//
//    void display() {
//        if (isempty()) {
//            cout << "Queue is empty!..\n";
//            return;
//        }
//        Node<T>* curr = front;
//        while (curr != nullptr) {
//            cout << "( " << curr->x << "," << curr->y << " )   ";
//            curr = curr->next;
//        }
//        cout << endl;
//    }
//
//    void linkfront(Queue& q) {
//        if (q.rear != nullptr) {
//            q.rear->next = front;
//        }
//    }
//
//    void dequeue() {
//        if (isempty()) {
//            cout << "QUEUE is Empty!\n";
//            return;
//        }
//
//
//        cout << "The person from queue " << front->x << " with Ticket no " << front->y << " went through.." << endl;
//        Node<T>* temp = front;
//        front = front->next;
//        delete temp;
//    }
//
//    bool isempty() {
//        return front == nullptr;
//    }
//};
//
//int main() {
//    Queue<int> q1, q2, q3;
//
//    for (int i = 1; i <= 10; ++i) {
//        q1.Enqueue(0, i);
//    }
//    q1.display();
//    for (int i = 1; i <= 10; ++i) {
//        q2.Enqueue(1, i);
//    }
//    q2.display();
//
//    for (int i = 1; i <= 10; ++i) {
//        q3.Enqueue(2, i);
//    }
//    q3.display();
//
//  
//    q2.linkfront(q1);  
//    q3.linkfront(q2);
//
//    q1.display();
//
//    while (!q1.isempty())
//    {
//        q1.dequeue();
//    }
//
//
//    return 0;
//}
