#include <iostream>
using namespace std;

class QNode {
public:
    string data;   // Message or main data
    string from;   // Sender
    string to;     // Receiver
    QNode* next;   // Pointer to the next node

    QNode(string f, string t) : from(f), to(t), next(nullptr) {
        data = from;  // Example data
    } QNode(string f) : next(nullptr) {
        data = f;  // Example data
    }
};

class Queue {
    QNode* front;  
    QNode* rear;   
    int numofitems;

public:
    Queue() : front(nullptr), rear(nullptr), numofitems(0) {}

    void enque(string from, string to) {
        QNode* ptr = new QNode(from, to);

        if (isEmpty()) {  
            front = rear = ptr;
        }
        else {
            rear->next = ptr; 
            rear = rear->next;
        }
        numofitems++;  
    }
    void enque(string data) {
        QNode* ptr = new QNode(data);

        if (isEmpty()) {
            front = rear = ptr;
        }
        else {
            rear->next = ptr;
            rear = rear->next;
        }
        numofitems++;
    }
    bool isEmpty() {
        return numofitems == 0;
    }

    string deque() {
        if (isEmpty()) { 
            cout << "Nothing to Delete\n";
            return "";
        }

        string d = front->data;  
        QNode* temp = front;
        front = front->next;  
        if (front == nullptr) {
            rear = nullptr;  
        }
        delete temp;  
        numofitems--;  
        return d;
    }

    void display() {
        QNode* temp = front;
        int x = 0;

        while (temp != nullptr) {
            x++;
            cout  << x << " | " << temp->data << " |   \n";
            temp = temp->next;
        }

        cout << "\nTOTAL count: " << x << endl;
    }
};
