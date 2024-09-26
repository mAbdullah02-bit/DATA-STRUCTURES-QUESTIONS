//#include <iostream>
//#include <string.h>
//using namespace std;
//
//struct Node {
//    char data;
//    Node* next;
//};
//
//class Stack {
//    Node* Top;
//
//public:
//    Stack() {
//        Top = nullptr;
//    }
//
//    bool push(char value) {
//        Node* newNode = new Node;
//        if (!newNode) {
//            return false;
//        }
//        newNode->data = value;
//        newNode->next = Top;
//        Top = newNode;
//        return true;
//    }
//
//    char pop() {
//        if (isEmpty()) {
//            return '\0';
//        }
//        Node* temp = Top;
//        char poppedValue = temp->data;
//        Top = Top->next;
//        delete temp;
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
//    bool isPalindrome(string str) {
//        int length = str.length();
//        for (int i = 0; i < length; i++) {
//            push(str[i]);
//        }
//        for (int i = 0; i < length; i++) {
//            if (pop() != str[i]) {
//                return false;
//            }
//        }
//        return true;
//    }
//};
//
//int main() {
//    Stack s;
//    string input = "123";
//    if (s.isPalindrome(input)) {
//        cout << input << " is a palindrome." << endl;
//    }
//    else {
//        cout << input << " is not a palindrome." << endl;
//    }
//
//    return 0;
//}
