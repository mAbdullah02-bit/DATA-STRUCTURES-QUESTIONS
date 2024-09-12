//#include<iostream>
//using namespace std;
//
//class Node {
//public:
//	int data;
//	Node* next;
//
//
//};
//class Linkedlist
//{
//public:
//	Linkedlist() : head(nullptr){}
//	void insertNodeAtBeginning(int data) {
//		Node* ptr=new Node;
//		ptr->data = data;
//		ptr->next = nullptr;
//		if (head == nullptr) {
//			head = ptr;
//		}
//		else
//		{
//		
//				
//ptr->next = head;
//
//
//head = ptr;
//		}
//			
//	}                
//	void insertNodeInMiddle(int data, int key) {
//	
//		Node* ptr = new Node;
//		ptr->data = data;
//		if (head==nullptr)
//		{
//			head = ptr;
//			return;
//		}
//		else
//		{
//		Node*	curr = head;
//
//		while (curr->next!=nullptr)
//		{
//			if (curr->data==key)
//			{
//
//				ptr->next = curr->next;
//				curr->next = ptr;
//				return;
//			}
//			curr = curr->next;
//		}
//		cout << "NODE NOT FOUND WITH DATA " << key << endl;
//		}
//	
//	
//	}
//
//	void insertNodeAtEnd(int data) {
//	
//
//		Node* ptr = new Node;
//		ptr->data = data;
//		ptr->next = nullptr;
//		if (head == nullptr)
//		{
//			head = ptr;
//		}
//		else
//		{
//			Node* curr = head;
//
//			while (curr->next != nullptr)
//			curr = curr->next;
//			curr->next = ptr;
//			
//		}
//	
//	}
//
//	bool deleteFirstNode() {
//	
//		Node* temp;
//		if (head==nullptr)
//		{
//			cout << "LIST IS EMPTY: " << endl;;
//			return 0;
//		}
//		else
//		{
//			temp = head;
//			head = head->next;
//			delete temp;
//			return 1;
//		}
//	}
//
//	
//	bool deleteNode(int key) {
//	
//
//		Node* temp = nullptr;
//		if (head==nullptr)
//		{
//			return 0;
//		}
//		if (head->data == key)
//		{
//			temp = head;
//			head = head->next;
//			delete temp;
//			return 1;
//		}
//		else
//		{
//			Node* curr = head;
//
//			while (curr->next != nullptr)
//			{
//				if (curr->next->data == key)
//				{
//				
//					temp=curr->next;
//					curr->next = curr->next->next;
//					delete temp;
//					
//					
//					return 1;
//				}
//				curr = curr->next;
//			}
//		}
//			cout << "NODE NOT FOUND WITH DATA " << key << endl;
//			return 0;
//	}
//	bool deleteLastNode() {
//		if (head==nullptr)
//		{
//			return 0;
//		}
//		Node* temp;
//		if (head->next == nullptr)
//		{
//			temp = head;
//			head = nullptr;
//			delete temp;
//			return 1;
//		}
//		else
//		{
//
//		Node* curr = head;
//
//		while (curr->next->next != nullptr)
//			curr = curr->next;
//	
//		temp = curr->next;
//		curr->next = nullptr;
//		delete temp;
//		return 1;
//		}
//		return 0;
//	}
//	void RemoveDuplicates() {
//
//		if (head==nullptr)
//		{
//			return;
//		}
//		
//		Node* temp;
//		for (Node* i = head; i->next!=nullptr ; )
//		{
//			for (Node* j = i; j->next != nullptr;)
//			{
//				if (i->data == j->next->data) {
//					temp = j->next;
//					j->next = j->next->next;
//					delete temp;
//				}
//				if (j->next!=nullptr)
//				j = j->next;
//				
//
//			}
//			i = i->next;
//		}
//	
//	}
//		void sortlist() {
//		if (!head) {
//			cout << "LIST IS EMPTY!\n";
//			return;
//		}
//		if (!head->next) {
//			cout << "LIST ALREADY SORTED.\n";
//			return;
//		}
//
//		for (Node* i = head; i != nullptr; i = i->next) {
//			for (Node* j = i->next; j != nullptr; j = j->next) {
//				if (i->data > j->data) {
//					swap(i->data, j->data);
//				}
//			}
//		}
//		cout << "LIST SORTED.\n";
//	}
//	void display() {
//		if (head == nullptr)
//		{
//			cout << "LIST IS EMPTY: " << endl;;
//			return ;
//		}
//		else
//		{
//			Node* curr = head;
//			while (curr != nullptr) {
//				cout << curr->data<<"->" ;
//				curr = curr->next;
//			}
//			
//		}
//
//	}
//	bool search(int data) {
//	
//		if (head == nullptr)
//		{
//			cout << "LIST IS EMPTY!....\n";
//			return 0;
//		}
//		else
//		{
//			Node* curr = head;
//
//			while (curr->next != nullptr)
//			{
//				if (curr->data == data)
//					return 1;
//				
//
//					
//				
//				curr = curr->next;
//			}
//			return 0;
//			cout << "NODE NOT FOUND WITH DATA " << data << endl;
//		}
//	
//	
//	}
//private:
//	Node* head;
//};
//
//
//int main() {
//	Linkedlist list;
//	int choice,data,key;
//	bool check;
//	do {
//cout << "\nMenu:\n";
//cout << "1. Append Node\n";
//cout << "2. Prepend Node\n";
//cout << "3. Insert Node After\n";
//cout << "4. Delete first Node \n";
//cout << "5. Delete  Node \n";
//cout << "6. Delete last Node \n";
//cout << "7. search a node\n";
//cout << "8. Print List\n";
//cout << "0. Exit\n";
//cout << "Enter your choice: ";
//cin >> choice;
//
//switch (choice) {
//case 1:
//cout << "Enter data to append: ";
//cin >> data;
//list.insertNodeAtBeginning(data);
//break;
//case 2:
//cout << "Enter data to prepend: ";
//cin >> data ;
//list.insertNodeAtEnd(data);
//break;
//
//case 3:
//	cout << "Enter data and key to insert after:";
//
//	cin >> data>>key ;
//list.insertNodeInMiddle(data,key);
//break;
//case 4:
//
//check= list.deleteFirstNode();
//if (check)
//cout << "Node  Deleted\n";
//else cout << "Node not Found";
//
//break;
//case 5:
//	cout << "Enter data to delete Node:";
//
//	cin >> data;
//	check = list.deleteNode(data); 
//	if (check)
//		cout << "Node  Deleted\n";
//	else cout << "Node not Found";
//
//	break;
//case 6:
//
//	check = list.deleteLastNode();
//	if (check)
//		cout << "Node  Deleted\n";
//	else cout << "Node not Found";
//
//	break;
//
//case 7:
//	cout << "Enter data to delete Node:";
//
//	cin >> data;
//	
//	check=list.search( data);
//	if (check)
//		cout << "Node  Found\n";
//	else cout << "Node not Found";
//	break;
//
//case 8:
//
//cout << "printing: ";
//list.display(); 
//break;
//case 9:
//
//	cout << "printing: ";
//	list.RemoveDuplicates();
//	break;
//case 0:
//cout << "Exiting...\n";
//break;
//default:
//cout << "Invalid choice. Please try again.\n";
//}
//} while (choice != 0);
//
//
//	return 0;
//}