//#include<iostream>
//using namespace std;
//
//class Node {
//public:
//    int data;
//    Node* next;
//    Node* prev;
//    Node() {
//        data = 0;
//        next = nullptr;
//        prev = nullptr;
//    }
//};
//
//class Doublylinkedlist {
//public:
//    Doublylinkedlist() {
//        head = nullptr;
//        tail = nullptr;
//    }
//
//    ~Doublylinkedlist() {
//        Node* current = head;
//        Node* next;
//        while (current != nullptr) {
//            next = current->next;
//            delete current;
//            current = next;
//        }
//        head = tail = nullptr;
//    }
//
//    void append(int data) {
//        Node* ptr = new Node;
//        ptr->data = data;
//
//        if (head == nullptr) {
//            head = ptr;
//            tail = ptr;
//        }
//        else {
//            tail->next = ptr;
//            ptr->prev = tail;
//            tail = ptr;
//        }
//    }
//
//    void deletenode(int data) {
//        if (head == nullptr) {
//            cout << "List is Empty....\n";
//            return;
//        }
//
//        Node* curr = head;
//        while (curr != nullptr) {
//            if (curr->data == data) {
//                if (curr == head) {
//                    head = curr->next;
//                    if (head != nullptr)
//                        head->prev = nullptr;
//                }
//                else if (curr == tail) {
//                    tail = curr->prev;
//                    tail->next = nullptr;
//                }
//                else {
//                    curr->prev->next = curr->next;
//                    curr->next->prev = curr->prev;
//                }
//                delete curr;
//                cout << "Deleted node with data " << data << "\n";
//                return;
//            }
//            curr = curr->next;
//        }
//        cout << "Node with data " << data << " not found.\n";
//    }
//
//    void reverse() {
//    
//
//        Node* curr = head, * prev = nullptr, *forw;
//
//        tail = head;
//        while (curr)
//        {
//
//            forw = curr->next;
//            curr->next = prev;
//            curr->prev = forw;
//            prev = curr;
//            curr = forw;
//         
//        }
//
//           
//        head = prev;
//    
//    }
//
//
//    void display() {
//        if (head == nullptr) {
//            cout << "List is empty.\n";
//            return;
//        }
//
//        Node* curr = head;
//        while (curr != nullptr) {
//            cout << curr->data << " ";
//            curr = curr->next;
//        }
//        cout << "\n";
//    }
//
//private:
//    Node* head;
//    Node* tail;
//};
//
//int main() {
//    Doublylinkedlist dll;
//
//
//    dll.append(10);
//    dll.append(20);
//    dll.append(30);
//    dll.append(40);
//    cout << "List after appending elements: ";
//    dll.display();
//
//    dll.reverse();
//  
//
//    cout << "Final List: ";
//    dll.display();
//
//    return 0;
//}
