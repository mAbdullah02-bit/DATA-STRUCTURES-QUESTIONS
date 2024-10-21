//#include <iostream>
//using namespace std;
//
//// DoublyLinkedList class with CRUD operations
//class DoublyLinkedList {
//private:
//    // Node structure
//    struct Node {
//        int data;
//        Node* next;
//        Node* prev; // Pointer to the previous node (for doubly linked list)
//    };
//
//    // Function to create a new node
//    Node* createNode(int data) {
//        Node* newNode = new Node();
//        newNode->data = data;
//        newNode->next = nullptr;
//        newNode->prev = nullptr;
//        return newNode;
//    }
//
//public:
//    Node* head,*tail;  // Head of the list
//
//    // Constructor to initialize the head to nullptr
//    DoublyLinkedList() {
//        head = nullptr;
//    }
//
//    // Insert at the end (Create operation)
//    void insertAtEnd(int data) {
//        Node* newNode = createNode(data);
//        if (head == nullptr) {
//            head = newNode;
//        }
//        else {
//            Node* temp = head;
//            while (temp->next != nullptr) {
//                temp = temp->next;
//            }
//            temp->next = newNode;
//            newNode->prev = temp;
//            tail = newNode;// Link the new node with the previous one
//        }
//    }
//
//    // Display the list (Read operation)
//    void displayList() {
//        if (head == nullptr) {
//            cout << "List is empty" << endl;
//            return;
//        }
//        Node* temp = head;
//        while (temp != nullptr) {
//            cout << temp->data << " <-> "; // Use <-> to show the two-way link
//            temp = temp->next;
//        }
//        cout << "NULL" << endl;
//    }
//
//    // Update node data (Update operation)
//    void updateNode(int oldValue, int newValue) {
//        Node* temp = head;
//        while (temp != nullptr) {
//            if (temp->data == oldValue) {
//                temp->data = newValue;
//                cout << "Node updated!" << endl;
//                return;
//            }
//            temp = temp->next;
//        }
//        cout << "Node with value " << oldValue << " not found." << endl;
//    }
//
//    // Delete a node by its value (Delete operation)
//    void deleteNode(int value) {
//        if (head == nullptr) {
//            cout << "List is empty." << endl;
//            return;
//        }
//
//        if (head->data == value) {
//            Node* temp = head;
//            head = head->next;
//            if (head != nullptr) {
//                head->prev = nullptr;  // Update the new head's prev pointer
//            }
//            delete temp;
//            cout << "Node deleted!" << endl;
//            return;
//        }
//
//        Node* temp = head;
//        while (temp != nullptr && temp->data != value) {
//            temp = temp->next;
//        }
//
//        if (temp == nullptr) {
//            cout << "Node with value " << value << " not found." << endl;
//        }
//        else {
//            if (temp->next != nullptr) {
//                temp->next->prev = temp->prev;  // Update the next node's prev pointer
//            }
//            if (temp->prev != nullptr) {
//                temp->prev->next = temp->next;  // Update the previous node's next pointer
//            }
//            delete temp;
//            cout << "Node deleted!" << endl;
//        }
//    }
//
//   void rearrange(Node* head) {
//        if (head == nullptr) 
//            return;  
//        else if(head->next == nullptr)
//            return;  
//        Node* curr = head, * temp = nullptr, * head2 = nullptr;
//        int i = 2; 
//        curr = curr->next;
//        head2 = head;
//        while (curr!=nullptr)
//        {
//            if (i%2!=0) { 
//                temp = curr;
//                curr->prev->next = curr->next;
//                if (curr->next!=nullptr){ curr->next->prev = curr->prev;
//                    curr = curr->next;
//                    i++; }
//                temp->next = head2->next;
//                head2->next->prev = temp;
//                head2->next = temp;
//                temp->prev = head2; head2 = temp; }
//            i++;
//            curr = curr->next;
//        }
//
//    }
//      
//};
//
//// Main function to demonstrate the operations
//int main() {
//    DoublyLinkedList list;
//
//    // Case 1 more then 10 values
//    //list.insertAtEnd(0);
//    //list.insertAtEnd(20);
//    //list.insertAtEnd(0);
//    //list.insertAtEnd(40);
//    //list.insertAtEnd(0);
//    //list.insertAtEnd(60);
//    //list.insertAtEnd(0);
//    //list.insertAtEnd(20);
//    //list.insertAtEnd(0);
//    //list.insertAtEnd(40);
//    //list.insertAtEnd(0);
//    //list.insertAtEnd(60);
//    //list.insertAtEnd(0);
//
//    // same as mid paper values
//  /*  list.insertAtEnd(2);
//    list.insertAtEnd(1);
//    list.insertAtEnd(3);
//    list.insertAtEnd(5);
//    list.insertAtEnd(6);
//    list.insertAtEnd(4);
//    list.insertAtEnd(7);*/
//
//    // case 2 3 nodes
//   /*   list.insertAtEnd(1);
//     list.insertAtEnd(5);
//     list.insertAtEnd(3);*/
//   
// /*    case 3  2  nodes*/
//     //list.insertAtEnd(1);
//     //list.insertAtEnd(5);
//    //  case 4 one node
// /*   list.insertAtEnd(5);*/
//    // Read (Display list)
//    cout << "Initial List: ";
//    list.displayList();
//
//    // Rearrange the list
//   
// list.rearrange(list.head);
//    cout << "After Rearranging: ";
//    list.displayList();
//
//
//
//    return 0;
//}
