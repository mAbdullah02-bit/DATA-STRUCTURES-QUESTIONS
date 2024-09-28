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
//    int Size() {
//        return size;
//    }
//
//    void deleteMiddle(int currentIndex,int mid) {
//        if (currentIndex == mid) {
//            pop();
//            return;
//        }
//
//        int temp = pop();
//        deleteMiddle(currentIndex + 1,mid);
//        push(temp);
//    }
//    void getmiddle() {
//        int c = 0;
//        int mid = Size() / 2;
//        deleteMiddle(c,mid);
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
//    cout << "Stack before deleting middle element: ";
//    s.display();
//    s.getmiddle();
//
//
//    cout << "Stack after deleting middle element: ";
//    s.display();
//
//    return 0;
//}
