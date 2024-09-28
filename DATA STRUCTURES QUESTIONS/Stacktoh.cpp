//#include<iostream>
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
//    void printStack(int stackNumber) {
//        cout << "Stack " << stackNumber << ": ";
//        if (top == nullptr) {
//            cout << "----\n";
//            return;
//        }
//        Node* temp = top;
//        while (temp != nullptr) {
//            cout << temp->data << " ";
//            temp = temp->next;
//        }
//        cout << endl;
//    }
//};
//
//int main() {
//    Stack stk1, stk2, stk3;
//
//    // Initialize stack 1 with data
//    stk1.push(4);
//    stk1.push(3);
//    stk1.push(2);
//    stk1.push(1);
//
//    stk1.printStack(1);
//    stk2.printStack(2);
//    stk3.printStack(3);
//
//    int c = 0, choice, ch;
//    int x;
//    do {
//        c++;
//
//        cout << "1 -> Move from STACK 1\n";
//        cout << "2 -> Move from STACK 2\n";
//        cout << "3 -> Move from STACK 3\n";
//        cout << "4 -> SOrting is done\n";
//        cin >> ch;
//
//        switch (ch) {
//        case 1:
//            if (stk1.isempty()) cout << "STack is empty!";
//            else
//            {
//                stk1.printStack(1);
//                x = stk1.pop();
//                cout << "Choose stack to enter (2 or 3): ";
//                cin >> choice;
//
//                if (choice == 2) {
//                    if (x < stk2.peek() || stk2.isempty()) {
//                        stk2.push(x);
//                    }
//                    else {
//                        cout << "Error!..\n";
//                        stk1.push(x); 
//                    }
//                }
//                else if (choice == 3) {
//                    if (x < stk3.peek() || stk3.isempty()) {
//                        stk3.push(x);
//                    }
//                    else {
//                        cout << "Error!..\n";
//                        stk1.push(x);
//                    }
//                }
//                else {
//                    cout << "Invalid choice!\n";
//                }
//            }
//            break;
//
//        case 2:
//            if (stk2.isempty())cout << "STack is empty!";
//            else
//            {
//            stk2.printStack(2);
//            x = stk2.pop();
//            cout << "Choose stack to enter (1 or 3): ";
//            cin >> choice;
//
//            if (choice == 1) {
//                if (x < stk1.peek() || stk1.isempty()) {
//                    stk1.push(x);
//                }
//                else {
//                    cout << "Error!..\n";
//                    stk2.push(x);
//                }
//            }
//            else if (choice == 3) {
//                if (x < stk3.peek() || stk3.isempty()) {
//                    stk3.push(x);
//                }
//                else {
//                    cout << "Error!..\n";
//                    stk2.push(x);
//                }
//            }
//            else {
//                cout << "Invalid choice!\n";
//            }
//        }
//            break;
//
//        case 3:
//            if (stk3.isempty())cout << "STack is empty!";
//            else
//            {
//
//            stk3.printStack(3);
//            x = stk3.pop();
//            cout << "Choose stack to enter (1 or 2): ";
//            cin >> choice;
//
//            if (choice == 1) {
//                if (x < stk1.peek() || stk1.isempty()) {
//                    stk1.push(x);
//                }
//                else {
//                    cout << "Error!..\n";
//                    stk3.push(x);
//                }
//            }
//            else if (choice == 2) {
//                if (x < stk2.peek() || stk2.isempty()) {
//                    stk2.push(x);
//                }
//                else {
//                    cout << "Error!..\n";
//                    stk3.push(x);
//                }
//            }
//            else {
//                cout << "Invalid choice!\n";
//            }
//            }
//            break;
//
//        case 4:
//          
//                cout << "You won!\n";
//           
//            break;
//
//        default:
//            cout << "Invalid option\n";
//            break;
//        }
//
//        
//        stk1.printStack(1);
//        stk2.printStack(2);
//        stk3.printStack(3);
//
//        if (c == 30) {
//            cout << "You lose!\n";
//        }
//
//    } while (c < 30 && ch != 4);
//
//    return 0;
//}
