//#include<iostream>
//using namespace std;
//
//class Node {
//public:
//
//	int data;
//	Node* next;
//	Node* prev;
//
//
//};
//class Doublylist {
//	Node* head;
//	Node* tail;
//public:
//
//	Doublylist() : head(nullptr), tail(nullptr) {}
//
//	void insertNodeAtBeginning(int data) {
//		Node* ptr = new Node;
//		ptr->data = data;
//		ptr->next = nullptr;
//		ptr->prev = nullptr;
//		if (head == nullptr) {
//			head = ptr;
//			tail = ptr;
//		}
//		else
//		{
//
//	
//			
//			ptr->next=head;
//			head->prev = ptr;
//			head = ptr;
//			
//
//		}
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
//			while (curr->next != nullptr)
//			{
//				if (curr->data == key)
//				{
//
//					ptr->next = curr->next;
//					ptr->prev = curr;
//					curr->next = ptr;
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
//			ptr->prev = nullptr;
//		}
//		else
//		{
//			Node* curr = head;
//
//			while (curr->next != nullptr)
//				curr = curr->next;
//			curr->next = ptr;   //  MAKE THIS WITH TAIL Functionality to avoid loop
//			ptr->prev = curr;
//			tail = ptr;
//		}
//
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
//			head = head->next;
//			if(head!=nullptr)
//			head->prev = nullptr;
//			delete temp;
//			return 1;
//		}
//	}
//
//
//	bool deleteNode(int key) {
//
//
//		if (head == nullptr)
//		{
//			return 0;
//		}
//		Node* temp = nullptr;
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
//			while (curr != nullptr)
//			{
//				if (curr->data == key)
//				{
//					temp = curr;
//					if (curr == tail) {
//						curr->prev->next = nullptr;
//					tail=	curr->prev;
//					}
//					
//					else
//						{
//							curr->prev->next = curr->next;
//							curr->next->prev = curr->prev;
//						}
//
//
//
//
//
//						delete temp;
//
//						return 1;
//					}
//					curr = curr->next;
//				}
//			}
//			cout << "NODE NOT FOUND WITH DATA " << key << endl;
//			return 0;
//		
//	}
//	bool deleteLastNode() {
//		if (head == nullptr)
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
//			Node* curr = head;
//
//			while (curr->next != nullptr)
//				curr = curr->next;
//
//			temp = curr;
//			curr->prev->next = nullptr;
//			delete temp;
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
//			while (curr != nullptr) {
//				cout << curr->data << "->";
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
//			while (curr != nullptr)
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
//	}
//
//	void sortlist() {
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
//};
//
//	int main() {
//		Doublylist list;
//		int choice, data, key;
//		bool check;
//		do {
//			cout << "\nMenu:\n";
//			cout << "1. Prepend Node\n";
//			cout << "2. append Node\n";
//			cout << "3. Insert Node After\n";
//			cout << "4. Delete first Node \n";
//			cout << "5. Delete  Node \n";
//			cout << "6. Delete last Node \n";
//			cout << "7. search a node\n";
//			cout << "8. Print List\n";
//			cout << "9. SORT List\n";
//			cout << "0. Exit\n";
//			cout << "Enter your choice: ";
//			cin >> choice;
//
//			switch (choice) {
//			case 1:
//				cout << "Enter data to append: ";
//				cin >> data;
//				list.insertNodeAtBeginning(data);
//				break;
//			case 2:
//				cout << "Enter data to prepend: ";
//				cin >> data;
//				list.insertNodeAtEnd(data);
//				break;
//
//			case 3:
//				cout << "Enter data and key to insert after:";
//
//				cin >> data >> key;
//				list.insertNodeInMiddle(data, key);
//				break;
//			case 4:
//
//				check = list.deleteFirstNode();
//				if (check)
//					cout << "Node  Deleted\n";
//				else cout << "Node not Found";
//
//				break;
//			case 5:
//				cout << "Enter data to delete Node:";
//
//				cin >> data;
//				check = list.deleteNode(data);
//				if (check)
//					cout << "Node  Deleted\n";
//				else cout << "Node not Found";
//
//				break;
//			case 6:
//
//				check = list.deleteLastNode();
//				if (check)
//					cout << "Node  Deleted\n";
//				else cout << "Node not Found";
//
//				break;
//
//			case 7:
//				cout << "Enter data to delete Node:";
//
//				cin >> data;
//
//				check = list.search(data);
//				if (check)
//					cout << "Node  Found\n";
//				else cout << "Node not Found";
//				break;
//			
//			case 8:
//
//				cout << "printing: ";
//				list.display();
//				break;
//			case 9:
//				list.sortlist();
//				break;
//			case 0:
//				cout << "Exiting...\n";
//				break;
//			default:
//				cout << "Invalid choice. Please try again.\n";
//			}
//		} while (choice != 0);
//
//		return 0;
//	}
//
//
