//#include <iostream>
//#include <string>
//using namespace std;
//
//class Node {
//public:
//    Node* next;
//    int data;
//};
//
//class Stack {
//public:
//    Node* top;
//    Stack() : top(nullptr) {}
//
//    void push(int d) {
//        Node* ptr = new Node;
//        ptr->data = d;
//        ptr->next = top;
//        top = ptr;
//        printStack();
//    }
//
//    int pop() {
//        if (isempty()) {
//            return -1; 
//        }
//        Node* temp = top;
//        int ch = top->data;
//        top = top->next;
//        delete temp;
//        printStack();
//        return ch;
//    }
//
//    int peek() {
//        if (isempty()) {
//            return -1;  
//        }
//        return top->data;
//    }
//
//    bool isempty() { return (top == nullptr); }
//
//    void printStack() {
//        cout << "Stack: ";
//        Node* temp = top;
//        while (temp != nullptr) {
//            cout << temp->data << " ";  
//            temp = temp->next;
//        }
//        cout << endl;
//    }
//
//    int precedence(char ch) {
//        if (ch == '^')
//            return 3;
//        else if (ch == '*' || ch == '/')
//            return 2;
//        else if (ch == '+' || ch == '-')
//            return 1;
//        return -1;
//    }
//
//    string convertstring(string str) {
//        string postfixstr = "";
//        for (int i = 0; i < str.length(); i++) {
//            char ch = str[i];
//
//            if (isdigit(ch)) {
//                while (i < str.length()  && str[i]!=' ') {
//                    postfixstr += str[i];
//                    i++;
//                }
//               
//                i--;
//            }
//            else if (ch == '(') {
//                push(ch);
//            }
//            else if (ch == ')') {
//                while (!isempty() && peek() != '(') {
//                    postfixstr += (char)pop();
//                    cout << "Output: " << postfixstr << endl;
//                }
//                if (!isempty()) {
//                    pop();
//                }
//            }
//            else {
//                while (!isempty() && precedence(peek()) >= precedence(ch)) {
//                    postfixstr += (char)pop();
//                    cout << "Output: " << postfixstr << endl;
//                }
//                push(ch);
//            }
//        }
//
//        while (!isempty()) {
//            postfixstr += (char)pop();
//            cout << "Output: " << postfixstr << endl;
//        }
//
//        return postfixstr;
//    }
//
//    int findresult(int a, int b, char ch) {
//        if (ch == '+')
//            return a + b;
//        else if (ch == '-')
//            return a - b;
//        else if (ch == '*')
//            return a * b;
//        else if (ch == '/')
//            return a / b;
//        else if (ch == '%')
//            return a % b;
//        return 0;
//    }
//
//    int evaluate(string str) {
//        Stack stk;
//        int operand2, operand1;
//        for (int i = 0; i < str.length(); i++) {
//            char ch = str[i];
//
//            if (isdigit(ch)) {
//                stk.push(ch - '0');
//            }
//            else if (ch == '+' || ch == '-' || ch == '/' || ch == '*' || ch == '%') {
//                operand2 = stk.pop();
//                operand1 = stk.pop();
//                stk.push(findresult(operand1, operand2, ch));
//                cout << "Result pushed to stack: " << findresult(operand1, operand2, ch) << endl;
//            }
//        }
//        return stk.pop();
//    }
//};
//
//string reversestring(string str) {
//    string s = "";
//    Stack stck;
//    for (int i = 0; i < str.length(); i++) {
//        if (str[i] == '(')
//            stck.push(')');
//        else if (str[i] == ')')
//            stck.push('(');
//        else
//            stck.push(str[i]);
//    }
//    while (!stck.isempty()) {
//        s += (char)stck.pop();
//    }
//    return s;
//}
//
//string remove(string str) {
//    string s = "";
//    for (int i = 0; i < str.length(); i++) {
//        if (str[i] != ' ') {
//            s += str[i];
//        }
//    }
//    return s;
//}
//
//int main() {
//    int choice;
//    Stack stk;
//    string str;
//
//    cout << "1 for infix to postfix\n";
//    cout << "2 for infix to prefix\n";
//    cin >> choice;
//
//    string infix = "45 * (5 / 6) + 2 - 8";
//    infix = remove(infix);
//
//    if (choice == 1) {
//        str = stk.convertstring(infix);
//        cout << "Postfix expression: " << str << endl;
//        cout << "Evaluation: " << stk.evaluate(str) << endl;
//    }
//    else if (choice == 2) {
//        str = reversestring(infix);
//        str = stk.convertstring(str);
//        str = reversestring(str);
//        cout << "Prefix expression: " << str << endl;
//        cout << "Evaluation: " << stk.evaluate(str) << endl;
//    }
//
//    return 0;
//}