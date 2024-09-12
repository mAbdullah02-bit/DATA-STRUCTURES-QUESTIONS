//#include<iostream>
//using namespace std;
//
//class Node {
//public:
//
//	int data;
//	Node* next;
//
//
//
//};
//class Doublylist {
//	Node* head;
//	Node* tail;
//	int len ;
//public:
//
//	Doublylist() : head(nullptr), tail(nullptr), len(0){}
//
//	void insertNodeAtBeginning(int data) {
//
//		Node* ptr = new Node;
//		ptr->data = data;
//		ptr->next = nullptr;
//	
//		if (head == nullptr) {
//			head = ptr;
//			tail = ptr;
//			ptr->next = head;
//		}
//		else
//		{
//
//
//
//			ptr->next = head;
//			tail->next = ptr;
//			head = ptr;
//
//		}
//			len++;
//
//	}
//	void insertNodeInMiddle(int data, int key) {
//
//		Node* ptr = new Node;
//		ptr->data = data;
//
//		if (head == nullptr)
//		{
//			head = ptr;
//			return;
//		}
//		else
//		{
//			Node* curr = head;
//
//			while (curr != tail)
//			{
//				if (curr->data == key)
//				{
//					if (curr == tail) {
//						tail = ptr;
//						ptr->next = head;
//					}
//					else
//					{
//
//					ptr->next = curr->next;
//					curr->next = ptr;
//					}
//					len++;
//					return;
//				}
//				curr = curr->next;
//			}
//			cout << "NODE NOT FOUND WITH DATA " << key << endl;
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
//			tail = ptr;
//		}
//		else
//		{
//			
//
//			tail->next = ptr;
//			ptr->next = head;
//			tail = ptr;
//		}
//		len++;
//	}
//
//	bool deleteFirstNode() {
//
//		Node* temp;
//		if (head == nullptr)
//		{
//			cout << "LIST IS EMPTY: " << endl;;
//			return 0;
//		}
//		else
//		{
//			temp = head;
//			if (head->next == head)
//				head = nullptr;
//			else {
//			head = head->next;
//			tail->next = head;
//			}
//			delete temp;
//			len--;
//			return 1;
//		}
//	}
//
//
//	bool deleteNode(int key) {
//		if (head == nullptr)
//		{
//			return 0;
//		}
//
//		Node* temp = nullptr;
//
//		if (head->data == key)
//		{
//			temp = head;
//			head = head->next;
//			tail->next = nullptr;
//			if (head->next == NULL)head = nullptr;
//			delete temp;
//			len--;
//			return 1;
//		}
//		else
//		{
//			Node* curr = head;
//
//			while (curr != tail)
//			{
//				if (curr->next->data == key)
//				{
//					temp = curr->next;
//					if (curr->next == tail) {
//						tail = curr;
//						tail->next = head;
//					}
//
//					else
//					{
//						curr->next = curr->next->next;
//						
//					}
//
//
//
//
//
//					delete temp;
//					len--;
//					return 1;
//				}
//				curr = curr->next;
//			}
//		}
//		cout << "NODE NOT FOUND WITH DATA " << key << endl;
//		return 0;
//
//	}
//	bool deleteLastNode() {
//		Node* temp;
//		if (head==nullptr || tail==nullptr)
//		{
//			return 0;
//		}
//		if (head->next == head)
//		{
//			temp = head;
//			head = nullptr;
//			delete temp;
//			len--;
//			return 1;
//		}
//		else
//		{
//
//			Node* curr = head;
//		
//			while (curr->next != tail)
//				curr = curr->next;
//
//
//			temp = curr->next;
//			tail = curr;
//			tail->next = head;
//			delete temp;
//			len--;
//			return 1;
//		}
//		return 0;
//	}
//
//	void display() {
//		if (head == nullptr)
//		{
//			cout << "LIST IS EMPTY: " << endl;;
//			return;
//		}
//		else
//		{
//			Node* curr = head;
//			int c = len;
//			while (c != 0) {
//				cout << curr->data << "->";
//				curr = curr->next;
//				c--;
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
//			int c = len;
//			while (c !=0)
//			{
//				if (curr->data == data)
//					return 1;
//
//
//				c--;
//
//				curr = curr->next;
//			}
//			return 0;
//			cout << "NODE NOT FOUND WITH DATA " << data << endl;
//		}
//
//	}
//};
//int main() {
//	Doublylist list;
//	int choice, data, key;
//	bool check;
//	do {
//		cout << "\nMenu:\n";
//		cout << "1. Prepend Node\n";
//		cout << "2. append Node\n";
//		cout << "3. Insert Node After\n";
//		cout << "4. Delete first Node \n";
//		cout << "5. Delete  Node \n";
//		cout << "6. Delete last Node \n";
//		cout << "7. search a node\n";
//		cout << "8. Print List\n";
//		cout << "0. Exit\n";
//		cout << "Enter your choice: ";
//		cin >> choice;
//
//		switch (choice) {
//		case 1:
//			cout << "Enter data to append: ";
//			cin >> data;
//			list.insertNodeAtBeginning(data);
//			break;
//		case 2:
//			cout << "Enter data to prepend: ";
//			cin >> data;
//			list.insertNodeAtEnd(data);
//			break;
//
//		case 3:
//			cout << "Enter data and key to insert after:";
//
//			cin >> data >> key;
//			list.insertNodeInMiddle(data, key);
//			break;
//		case 4:
//
//			check = list.deleteFirstNode();
//			if (check)
//				cout << "Node  Deleted\n";
//			else cout << "Node not Found";
//
//			break;
//		case 5:
//			cout << "Enter data to delete Node:";
//
//			cin >> data;
//			check = list.deleteNode(data);
//			if (check)
//				cout << "Node  Deleted\n";
//			else cout << "Node not Found";
//
//			break;
//		case 6:
//
//			check = list.deleteLastNode();
//			if (check)
//				cout << "Node  Deleted\n";
//			else cout << "Node not Found";
//
//			break;
//
//		case 7:
//			cout << "Enter data to delete Node:";
//
//			cin >> data;
//
//			check = list.search(data);
//			if (check)
//				cout << "Node  Found\n";
//			else cout << "Node not Found";
//			break;
//
//		case 8:
//
//			cout << "printing: ";
//			list.display();
//			break;
//		case 0:
//			cout << "Exiting...\n";
//			break;
//		default:
//			cout << "Invalid choice. Please try again.\n";
//		}
//	} while (choice != 0);
//
//	return 0;
//}
//
