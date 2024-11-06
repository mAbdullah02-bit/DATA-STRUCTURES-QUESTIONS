#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int val) : data(val), next(nullptr) {}
};

class Queue {
private:
    Node* rear;   // Rear of the queue

public:
    Node* front;  // Front of the queue
    Queue() : front(nullptr), rear(nullptr) {}

    // Enqueue operation
    void enqueue(int val) {
        Node* newNode = new Node(val);
        if (rear == nullptr) {
            // If queue is empty, front and rear are the same
            front = rear = newNode;
            return;
        }
        // Add the new node at the end and update rear
        rear->next = newNode;
        rear = newNode;
    }

    // Dequeue operation
    void dequeue() {
        if (front == nullptr) {
            cout << "Queue is empty, cannot dequeue.\n";
            return;
        }
        // Remove the front node
        Node* temp = front;
        front = front->next;
        if (front == nullptr) {  // If the queue becomes empty
            rear = nullptr;
        }
        delete temp;
    }

    // Peek operation - view the front element
    int peek() const {
        if (front == nullptr) {
            cout << "Queue is empty.\n";
            return -1;  // Return an invalid value when queue is empty
        }
        return front->data;
    }

    // Check if the queue is empty
    bool isEmpty() const {
        return front == nullptr;
    }

    // Destructor to free memory
    ~Queue() {
        while (front != nullptr) {
            dequeue();
        }
    }
    int reverseprint(Node* curr,int &c) {

        if (curr->next==nullptr)
        {
            if(curr->data>c)
            return curr->data;
            else return c;
        }
        if (c < curr->data) {
            c = curr->data;
        }
        reverseprint(curr->next,c);
       
        
    }
    void reverse() {
        if (isEmpty()) {
            return;
        }
        int a = peek();
        dequeue();
        reverse();
        enqueue(a);
    

    }
    void getelement(Queue &nq) {
        Node* curr = front, *ptr=front->next;
        while (ptr!=nullptr)
        {
            if (curr->data < 0) { nq.enqueue(curr->data); }
            else if (curr->data > 0 && ptr->data < 0) { nq.enqueue(ptr->data); }
            else if (curr->data > 0 && ptr->data > 0) { nq.enqueue(0); }
            curr = ptr;
            ptr = ptr->next;
        }
    
    }
    void display() {
        Node* curr = front;
        while (curr != nullptr)
        {
            cout << curr->data << "  ";
            curr = curr->next;
        }
    }
};

int main() {
    Queue q,nq;

    q.enqueue(-8);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(-7);
    q.enqueue(10);
    cout << endl;
    q.display();
    cout << endl;
    int c = 0;
  cout<<  q.reverseprint(q.front,c);
    nq.display();


  

    return 0;
}
