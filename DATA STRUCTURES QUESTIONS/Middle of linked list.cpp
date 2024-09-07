////#include<iostream>
////using namespace std;
////
////class Node {
////public:
////    int data;
////    Node* next;
////
////    Node(int value) {
////        data = value;
////        next = nullptr;
////    }
////};
////
////class LinkedList {
////private:
////public:
////    Node* head;
////    Node* tail;
////
////    LinkedList() {
////        head = nullptr;
////    }
////
////    // Function to add a node at the end of the list
////    void append(int value) {
////        Node* newNode = new Node(value);
////
////        if (head == nullptr) {
////            head = newNode;
////        }
////        else {
////            Node* temp = head;
////            while (temp->next != nullptr) {
////                temp = temp->next;
////            }
////            temp->next = newNode;
////        }
////    }
////
////    // Function to display the linked list
////    void display() {
////        if (head == nullptr) {
////            cout << "List is empty." << endl;
////            return;
////        }
////
////        Node* temp = head;
////        while (temp != nullptr) {
////            cout << temp->data << " -> ";
////            temp = temp->next;
////        }
////        cout << "NULL" << endl;
////    }
////
////    // Function to delete a node by value
////    void deleteNode(int value) {
////        if (head == nullptr) {
////            cout << "List is empty, nothing to delete." << endl;
////            return;
////        }
////
////        if (head->data == value) {
////            Node* temp = head;
////            head = head->next;
////            delete temp;
////            return;
////        }
////
////        Node* temp = head;
////        Node* prev = nullptr;
////
////        while (temp != nullptr && temp->data != value) {
////            prev = temp;
////            temp = temp->next;
////        }
////
////        if (temp == nullptr) {
////            cout << "Value not found in the list." << endl;
////            return;
////        }
////
////        prev->next = temp->next;
////        delete temp;
////    }
////
////    void reverseprint(Node* head) {
////        if (head==NULL)
////        {
////            return;
////        }
////        
////        reverseprint(head->next);
////        cout << head->data << "->";
////    
////    }
////    int getlength() {
////        tail = head;
////        int c = 0;
////        while (tail->next != nullptr) {
////            c++;
////        tail = tail->next;
////        }
////
////        return c;
////    }
////
////    Node* rotatelist(int k) {
////    
////        int x=getlength();
////        if (k%x==0)
////        {
////            return head;
////        }
////        else 
////        {
////            x = k % x;
////            tail->next = head;
////            int y = k - x;
////         
////            Node* temp = head;
////            while (y!=0)
////            {
////              
////                temp = temp->next;
////                y--;
////            }
////            head = temp->next;
////            temp->next = nullptr;
////
////
////
////
////        }
////        return head;
////    
////    }
////};
////
////int main() {
////    LinkedList list;
////
////    list.append(10);
////    list.append(20);
////    list.append(30);
////    list.append(40);
////    list.append(50);
////
////    cout << "Linked List: ";
////    list.display();
////
////    list.rotatelist(3);
////
////    cout << "Linked List: ";
////    list.display();
////
////    system("pause");
////    return 0;
////}
//
//
//
//
//
//
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
//        cout << "NULL" << endl;
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
//   
//    int getlength() {
//        Node* temp = head;
//        int c = 0;
//        while (temp != nullptr) {
//            c++;
//            temp = temp->next;
//        }
//        return c;
//    }
//
//
//    Node* rotatelist(int k) {
//        if (head == nullptr || k == 0) {
//            return head;
//        }
//
//        int length = getlength();
//        k = k % length;
//
//        if (k == 0) {
//            return head;
//        }
//
//        Node* temp = head;
//        Node* tail = head;
//
//        while (tail->next != nullptr) {
//            tail = tail->next;
//        }
//        tail->next = head;
//     
//        int splitPoint = length - k - 1;
//        
//
//        for (int i = 0; i < splitPoint; i++) {
//            temp = temp->next;
//        }
//
//      head=  temp->next;
//      temp->next = nullptr;
//
//
//        return head;
//    }
//};
//
//int main() {
//    LinkedList list;
//
//    list.append(10);
//    list.append(20);
//    list.append(30);
//    list.append(40);
//    list.append(50);
//
//    cout << "Linked List: ";
//    list.display();
//
//    list.rotatelist(19);
//
//    cout << "Rotated Linked List: ";
//    list.display();
//
//    return 0;
//}
