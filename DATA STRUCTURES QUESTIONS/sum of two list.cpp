//#include<iostream>
//using namespace std;
//
//class Node {
//public:
//    int data;
//    Node* next;
//
//    Node(int value) {
//        data = value;
//        next = nullptr;
//    }
//};
//
//class LinkedList {
//public:
//    Node* head;
//
//    LinkedList() {
//        head = nullptr;
//    }
//
//
//    void append(int value) {
//        Node* newNode = new Node(value);
//
//        if (head == nullptr) {
//            head = newNode;
//        }
//        else {
//            Node* temp = head;
//            while (temp->next != nullptr) {
//                temp = temp->next;
//            }
//            temp->next = newNode;
//        }
//    }
//
// 
//    void display() {
//        if (head == nullptr) {
//            cout << "List is empty." << endl;
//            return;
//        }
//
//        Node* temp = head;
//        while (temp != nullptr) {
//            cout << temp->data << " -> ";
//            temp = temp->next;
//        }
//   
//    }
//
//
//    void deleteNode(int value) {
//        if (head == nullptr) {
//            cout << "List is empty, nothing to delete." << endl;
//            return;
//        }
//
//        if (head->data == value) {
//            Node* temp = head;
//            head = head->next;
//            delete temp;
//            return;
//        }
//
//        Node* temp = head;
//        Node* prev = nullptr;
//
//        while (temp != nullptr && temp->data != value) {
//            prev = temp;
//            temp = temp->next;
//        }
//
//        if (temp == nullptr) {
//            cout << "Value not found in the list." << endl;
//            return;
//        }
//
//        prev->next = temp->next;
//        delete temp;
//    }
//
//    Node* reverse(Node* l1) {
//        Node* forw, *prev=nullptr, *curr;
//        curr = l1;
//        while (curr!=nullptr)
//        {
//            forw = curr->next;
//            curr->next = prev;
//            prev = curr;
//            curr = forw;
//        }
//        head = prev;
//    
//        return  prev;
//    
//    }
//
//    Node* Sumoflists(Node*l2) {
//    
//        if (l2 == nullptr && head == nullptr) { return NULL; }
//           else if (l2 == nullptr) { return head; } 
//           else if (head == nullptr) { return l2; }
//
//        Node* l1 = head,*temp=nullptr,*curr;
//        LinkedList result;
//        l1 = reverse(l1);
//        l2 = reverse(l2);
//        int carry = 0,sum=0,num=0;
//
//        if (getlength(l1) > getlength(l2)) {
//            curr = l1;
//            temp = l2;
//        }
//        else {
//            curr = l2;
//            temp = l1;
//        }
//
//        while (curr!=nullptr)
//        {
//            sum = 0;
//            if (temp==nullptr)
//            {
//                if (curr->data+carry>9)
//                {
//                    num = (curr->data + carry) % 10; carry = (curr->data + carry) / 10;
//                result.append(num);
//                }else
//                result.append(curr->data+carry);
//              
//            }
//            else
//            {
//
//            sum = curr->data + temp->data+carry;
//            carry = 0;
//            if (sum>9)
//            {
//                num = sum % 10;
//                carry = sum / 10;
//            }
//            else
//            {
//                num = sum;
//                carry = 0;
//            }
//            result.append(num);
//
//            temp = temp->next;
//            }
//            curr = curr->next;
//
//        }
//            
//        if (carry!=0)
//        {
//            result.append(carry);
//        }
//
//
//    
//   
//    return   reverse(result.head);
//    }
//
//        int getlength(Node* head) {
//        Node* temp = head;
//        int c = 0;
//        while (temp != nullptr) {
//            c++;
//            temp = temp->next;
//        }
//        return c;
//    }
//   
//};
//
//int main() {
//    LinkedList list;
//    LinkedList list2;
//    
//    //list.append(2);
//    //list.append(4);
//    //list.append(5);
//    list.append(9);
//    list.append(9);
//    list.append(9);
//    //list.append(9);
// 
//    list2.append(1);
//    list2.append(2);
//    list2.append(3);
//    //list2.append(9);
//    cout << "\n\n\t\t";
//    list.display();
//    cout << "\n\t\t";
//    list2.display();
//  
//
//    Node* result = list.Sumoflists(list2.head);
//  
//    cout << "\n\t\t_____________\n";
//
//    cout << "\n\tResult: ";
//    list.head = result;
//    list.display();
//
//    return 0;
//}