#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};

Node* deleteK(Node* head, int k) {

    Node* curr = head;
    Node* prev = nullptr;

    int c = 0;
    while (curr!=nullptr)
    {
        c++;
        if (c==k)
        {
            Node* temp = curr;
            
                prev->next = curr->next;
                curr = curr->next;
                delete temp;
                c = 1;
        }

        prev = curr;
        if(curr!=nullptr)
        curr = curr->next;

    }


    return head;
}


void printList(Node* head) {

    Node* curr = head;
    while (curr != nullptr) {
        cout << curr->data << " ";
        curr = curr->next;
    }
}
int main() {

    // Create a hard-coded linked list:
    // 1 -> 2 -> 3 -> 4 -> 5 -> 6
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    head->next->next->next->next->next = new Node(6);
    int k = 2;
    head = deleteK(head, k);
    printList(head);

    return 0;
}