//#include <iostream>
//using namespace std;
//
//struct Node {
//    int data;
//    Node* next;
//};
//
//class Stack {
//    Node* Top;
//    int size;
//public:
//    Stack() {
//        Top = nullptr;
//        size = 0;
//    }
//
//    bool push(int value) {
//        Node* newNode = new Node;
//        if (!newNode) {
//            return false;
//        }
//        newNode->data = value;
//        newNode->next = Top;
//        Top = newNode;
//        size++;
//        return true;
//    }
//
//    int pop() {
//        if (isEmpty()) {
//            return '\0';
//        }
//        Node* temp = Top;
//        int poppedValue = temp->data;
//        Top = Top->next;
//        delete temp;
//        size--;
//        return poppedValue;
//    }
//
//    bool isEmpty() {
//        return Top == nullptr;
//    }
//
//    void display() {
//        if (isEmpty()) {
//            cout << "Stack is empty" << endl;
//            return;
//        }
//        Node* current = Top;
//        while (current != nullptr) {
//            cout << current->data << " ";
//            current = current->next;
//        }
//        cout << endl;
//    }
//
//    int getSize() {
//        return size;
//    }
//
//    void pushatbottom(int n) {
//        if (isEmpty())
//        {
//            push(n);
//            return;
//        }
//        int x = pop();
//        pushatbottom(n);
//        push(x);
//    }
//  
//    void reverse() {
//        if (isEmpty()) {
//            return;
//        }
//
//        int top = pop();
//
//        reverse();
//        pushatbottom(top);
//
//    }
//};
//
//int main() {
//    Stack s;
//    s.push(4);
//    s.push(3);
//    s.push(2);
//    s.push(1);
//
//    cout << "Stack before pushing last element: ";
//    s.display();
//    s.reverse();
// 
//
//    cout << "Stack after pushing last  element: ";
//    s.display();
//
//    return 0;
//}
