#include<iostream>
using namespace std;

class Node {
public:
	int data;
	Node* next;


};
class Linkedlist
{
public:
	Linkedlist() : head(nullptr){}
	void insertNodeAtBeginning(int data) {
		Node* ptr=new Node;
		ptr->data = data;
		ptr->next = nullptr;
		if (head == nullptr) {
			head = ptr;
		}
		else
		{
		
				
ptr->next = head;


head = ptr;
		}
			
	}                
	void insertNodeInMiddle(int data, int key) {
	
		Node* ptr = new Node;
		ptr->data = data;
		if (head==nullptr)
		{
			head = ptr;
			return;
		}
		else
		{
		Node*	curr = head;

		while (curr->next!=nullptr)
		{
			if (curr->data==key)
			{

				ptr->next = curr->next;
				curr->next = ptr;
				return;
			}
			curr = curr->next;
		}
		cout << "NODE NOT FOUND WITH DATA " << key << endl;
		}
	
	
	}

	void insertNodeAtEnd(int data) {
	

		Node* ptr = new Node;
		ptr->data = data;
		ptr->next = nullptr;
		if (head == nullptr)
		{
			head = ptr;
		}
		else
		{
			Node* curr = head;

			while (curr->next != nullptr)
			curr = curr->next;
			curr->next = ptr;
			
		}
	
	}

	bool deleteFirstNode() {
	
		Node* temp;
		if (head==nullptr)
		{
			cout << "LIST IS EMPTY: " << endl;;
			return 0;
		}
		else
		{
			temp = head;
			head = head->next;
			delete temp;
			return 1;
		}
	}

	
	bool deleteNode(int key) {
	

		Node* temp = nullptr;
		if (head==nullptr)
		{
			return 0;
		}
		if (head->data == key)
		{
			temp = head;
			head = head->next;
			delete temp;
			return 1;
		}
		else
		{
			Node* curr = head;

			while (curr->next != nullptr)
			{
				if (curr->next->data == key)
				{
				
					temp=curr->next;
					curr->next = curr->next->next;
					delete temp;
					
					
					return 1;
				}
				curr = curr->next;
			}
		}
			cout << "NODE NOT FOUND WITH DATA " << key << endl;
			return 0;
	}
	bool deleteLastNode() {
		if (head==nullptr)
		{
			return 0;
		}
		Node* temp;
		if (head->next == nullptr)
		{
			temp = head;
			head = nullptr;
			delete temp;
			return 1;
		}
		else
		{

		Node* curr = head;

		while (curr->next->next != nullptr)
			curr = curr->next;
	
		temp = curr->next;
		curr->next = nullptr;
		delete temp;
		return 1;
		}
		return 0;
	}

	void display() {
		if (head == nullptr)
		{
			cout << "LIST IS EMPTY: " << endl;;
			return ;
		}
		else
		{
			Node* curr = head;
			while (curr != nullptr) {
				cout << curr->data<<"->" ;
				curr = curr->next;
			}
			
		}

	}
	bool search(int data) {
	
		if (head == nullptr)
		{
			cout << "LIST IS EMPTY!....\n";
			return 0;
		}
		else
		{
			Node* curr = head;

			while (curr->next != nullptr)
			{
				if (curr->data == data)
					return 1;
				

					
				
				curr = curr->next;
			}
			return 0;
			cout << "NODE NOT FOUND WITH DATA " << data << endl;
		}
	

	
	}

	bool detectloop() {
		bool detectloop() {
			if (!head) return false; 

			Node* slow = head;
			Node* fast = head;

			while (fast != nullptr && fast->next != nullptr) {
				slow = slow->next; 
				fast = fast->next->next; 

				if (slow == fast) {
					return true;
				}
			}

			return false; 
		}
private:
	Node* head;
};


int main() {
	Linkedlist list;
	
	list.insertNodeAtEnd(5);
	list.insertNodeAtEnd(1);
	list.insertNodeAtEnd(6);
	list.insertNodeAtEnd(8);
	


	return 0;
}