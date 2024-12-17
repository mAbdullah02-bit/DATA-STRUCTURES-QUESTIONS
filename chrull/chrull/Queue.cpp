#include<iostream>
#include<string>
using namespace std;

class QNode {
public:
    string data;
    QNode* next;

    QNode() {
        data = "";
        next = nullptr;
    }
};
class queue {
    QNode* front;
    QNode* back;
public:
    queue() {
        front = nullptr;
        back = nullptr;
    }
    bool IsEmpty() {
        return(front == nullptr);
    }

    void enqueue(string d) {


        QNode* nd = new QNode;
        nd->data = d;
        nd->next = nullptr;

        if (IsEmpty()) {
            front = back = nd;
        }
        else {
            back->next = nd;
            back = nd;
        }
    }
    string peek() {
        return front->data;
    }
    void dequeue() {
        if (IsEmpty()) {
            cout << "\033[36m\t\t\t\t\t\t\t  Empty!! " << endl;
            return;
        }
        QNode* temp = front;
        front = front->next;
        delete temp;
    }

    bool search(string name) {
        if (IsEmpty()) {
            return false;
        }

        QNode* temp = front;
        while (temp != nullptr) {
            if (temp->data == name) {
                return true;
            }
            temp = temp->next;
        }
        return false;
    }

    void Display() {
        if (IsEmpty()) {
            cout << "\t\t\t\t\t\t\t  No Data " << endl;
            return;
        }
        QNode* temp = front;
        while (temp != nullptr) {
            cout << "\t\t\t\t\t\t\t  Data: " << temp->data << endl;

            temp = temp->next;
        }
    }

    void display() {
        if (IsEmpty()) {
            cout << "\t\t\t\t\t\t\t  No Data " << endl;
            return;
        }
        cout << "\t\t\t\t\t\t\t  Friend Requests: " << endl;
        QNode* temp = front;
        while (temp != nullptr) {
            cout << "\t\t\t\t\t\t\t  Data: " << temp->data << endl;
            temp = temp->next;
        }
    }
};