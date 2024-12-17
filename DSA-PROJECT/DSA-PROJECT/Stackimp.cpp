#include <iostream>
using namespace std;

class SNode {
public:
    string data; // Message 
    string from; // Sender
    string to;   // reciver
    SNode* next;

    // Constructor
    SNode(string msg, string sender, string receiver)
        : data(msg), from(sender), to(receiver), next(nullptr) {}
    SNode(string post, string from) : data(post), from(from), next(nullptr) {}
};

class Stack {
    SNode* top;

public:
     Stack() : top(nullptr) {}

 
    string peek() {
        if (top == nullptr) {
            cout << "Stack is empty!\n";
            return "";
        }
        return top->data;
    }



    void push(string data, string from, string to) {
        SNode* ptr = new SNode(data, from, to);
        ptr->next = top;
        top = ptr;
    }

    void push(string data, string from) {
        SNode* ptr = new SNode(data, from);
        ptr->next = top;
        top = ptr;
    }
    string pop() {
        if (top == nullptr) {
            cout << "NOTHING HERE :<( \n";
            return "";
        }

        string data = top->data;
        SNode* temp = top;
        top = top->next;
        delete temp;
        return data;
    }
    void displayposts(string name) {
        if (top == nullptr) {
            cout << "NO posts from user: " << name << endl;
            return;
        }

        SNode* temp = top;
        int x = 0;
        while (temp != nullptr) {
            x++;
            cout << "Post " << x << ": " << temp->data << " | From: " << temp->from << endl;
            temp = temp->next;
        }
    }
    SNode* gettop() {
        return top;
    }
    Stack& operator=(const Stack& obj) {
        if (this == &obj) { 
            return *this;
        }

   
        Stack tempStack;
        SNode* temp = obj.top;

       
        while (temp != nullptr) {
            tempStack.push(temp->data, temp->from, temp->to); 
            temp = temp->next;
        }

     
        temp = tempStack.top;
        while (temp != nullptr) {
            push(temp->data, temp->from, temp->to); 
            temp = temp->next;
        }

        return *this;
    }


    void display() {
        if (top == nullptr) {
            cout << "NOTHING to display :<( \n";
            return;
        }

        SNode* temp = top; 
        while (temp != nullptr) {
            cout << "Message: " << temp->data << " | From: " << temp->from << " | To: " << temp->to << endl;
            temp = temp->next;
        }
    }
};
