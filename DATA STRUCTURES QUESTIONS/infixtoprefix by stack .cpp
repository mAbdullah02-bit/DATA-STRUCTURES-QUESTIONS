//#include <iostream>
//#include <string>
//using namespace std;
//
//class Node {
//public:
//    Node* next;
//    char data;
//};
//
//class Stack {
//public:
//    Node* top;
//    Stack() : top(nullptr) {}
//
//    void push(char d) {
//        Node* ptr = new Node;
//        ptr->data = d;
//        ptr->next = top;
//        top = ptr;
//    }
//
//    char pop() {
//        if (isempty()) {
//            return '\0';
//        }
//        Node* temp = top;
//        char ch = top->data;
//        top = top->next;
//        delete temp;
//        return ch;
//    }
//
//    char peek() {
//        if (isempty()) {
//            return '\0';
//        }
//        return top->data;
//    }
//
//    bool isempty() { return (top == nullptr); }
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
//
//            if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9')) {
//                postfixstr += ch;
//            }
//
//            else if (ch == '(' || ch == '{' || ch == '[') {
//                push(ch);
//            }
//
//            else if (ch == ')' || ch == '}' || ch == ']') {
//                while (!isempty() && (peek() != '(' && peek() != '{' && peek() != '[')) {
//                    postfixstr += pop();
//                }
//                if (!isempty()) {
//                    pop();
//                }
//            }
//
//            else {
//                while (!isempty() && precedence(peek()) >= precedence(ch)) {
//                    postfixstr += pop();
//                }
//                push(ch);
//            }
//        }
//
//
//        while (!isempty()) {
//            postfixstr += pop();
//        }
//
//        return postfixstr;
//    }
//};
//
//string reversestring(string str) {
//    string s="";
//    Stack stck;
//    for (int i = 0; i < str.length(); i++)
//    {
//        if (str[i] == '(' )
//        stck.push(')');
//        else if(str[i] == '{')
//        stck.push('}');
//        else if (str[i] == '[')
//        stck.push(']');
//        else if (str[i] == ')')
//            stck.push('(');
//        else if (str[i] == '}')
//            stck.push('{');
//        else if (str[i] == ']')
//            stck.push('[');
//        else
//            stck.push(str[i]);
//       
//        
//    }
//    while (!stck.isempty())
//    {
//        s += stck.top->data;
//            stck.pop();
//    }
//
//
//    return s;
//
//
//
//
//
//}
//
//int main() {
//    string str;
//    cout << "Enter an infix statement: ";
//    getline(cin, str);
//    str = reversestring(str);
//    Stack s;
//    string postfixstr = s.convertstring(str);
//    str= reversestring(postfixstr);
//
//    cout << "Postfix statement: " << str << endl;
//
//    return 0;
//}
