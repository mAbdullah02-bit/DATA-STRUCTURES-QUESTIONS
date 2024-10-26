//#include<iostream>
//using namespace std;
//class node {
//	int data;
//	int key;
//	node* pre, * next;
//public:
//	node()
//	{
//		data = 0; key = 0; pre = NULL; next = NULL;
//	}
//	void setdata(int d)
//	{
//		data = d;
//	}
//	int getdata()
//	{
//		return data;
//	}
//	void setkey(int key)
//	{
//		this->key = key;
//	}
//	int getkey()
//	{
//		return key;
//	}
//	void setpre(node* pr)
//	{
//		pre = pr;
//	}
//	node* getpre()
//	{
//		return pre;
//	}
//	void setnext(node* next)
//	{
//		this->next = next;
//	}
//	node* getnext()
//	{
//		return next;
//	}
//};
//class doubly {
//	node* head;
//public:
//	doubly()
//	{
//		head = NULL;
//	}
//	void insert_at_begin(int data, int key)		//Time complexity = O(1)
//	{
//		node* ptr = new node;
//		ptr->setkey(key);
//		ptr->setdata(data);
//		if (head == NULL)
//		{
//			head = ptr;
//			head->setpre(NULL);
//			head->setnext(NULL);
//		}
//		else {
//			ptr->setpre(NULL);
//			ptr->setnext(head);
//			head->setpre(ptr);
//			head = ptr;
//		}
//	}
//	void insert_in_middle(int data, int key, int key2)			//Time complexity = O(n) where n equals to number of nodes in list
//	{
//		node* ptr = new node;
//		ptr->setkey(key);
//		ptr->setdata(data);
//		if (head == NULL)
//		{
//			head = ptr;
//			head->setpre(NULL);
//			head->setnext(NULL);
//		}
//		else {
//			node* temp = head;
//			while (temp != NULL)
//			{
//
//				if (temp->getkey() == key2)
//				{
//					if (temp->getnext() != NULL)	//if not the last node
//					{
//						ptr->setnext(temp->getnext());
//						temp->getnext()->setpre(ptr);
//					}
//					else
//					{
//						ptr->setnext(NULL);
//					}
//
//					ptr->setpre(temp);
//					temp->setnext(ptr);
//					break;
//				}
//				temp = temp->getnext();
//			}
//		}
//		cout << "Key not found\n";
//	}
//	void insert_at_end(int data, int key)	//Time complexity = O(n) where n equals to number of nodes in list
//	{
//		node* ptr = new node;
//		ptr->setkey(key);
//		ptr->setdata(data);
//		if (head == NULL)
//		{
//			head = ptr;
//			head->setpre(NULL);
//			head->setnext(NULL);
//		}
//		else {
//			node* temp = head;
//			while (temp->getnext() != NULL)
//			{
//				temp = temp->getnext();
//			}
//			temp->setnext(ptr);
//			ptr->setpre(temp);
//			ptr->setnext(NULL);
//		}
//	}
//	void insertat_end(node* n)	//Time complexity = O(n) where n equals to number of nodes in list
//	{
//		if (head == NULL)
//		{
//			head = n;
//			head->setpre(NULL);
//			head->setnext(NULL);
//		}
//		else {
//			node* temp = head;
//			while (temp->getnext() != NULL)
//			{
//				temp = temp->getnext();
//			}
//			temp->setnext(n);
//			n->setpre(temp);
//			n->setnext(NULL);
//		}
//	}
//	void delte_first_node()	//Time complexity = O(1)
//	{
//		if (head == NULL)
//		{
//			cout << "Nothing to delete bruhhh\n";
//			return;
//		}
//		if (head->getnext() == NULL)	//in case of only one node
//		{
//			head = NULL;
//			return;
//		}
//		head->getnext()->setpre(NULL);
//		head = head->getnext();
//
//	}
//	void delete_a_node(int key)		//Time complexity = O(n) where n equals to number of nodes in list
//	{
//		if (head == NULL)
//		{
//			cout << "Nothing to delete bruhhh\n";
//			return;
//		}
//		node* temp = head;
//		if (head->getnext() == NULL)	//in case of only one node
//		{
//			head = NULL;
//			return;
//		}
//		if (head->getkey() == key)
//		{
//			head = head->getnext();
//			head->setpre(NULL);
//			delete temp;
//			temp = NULL;
//		}
//		while (temp != NULL)
//		{
//			if (temp->getkey() == key)
//			{
//				if (temp->getnext() != NULL)	//if not the last node
//				{
//					temp->getnext()->setpre(temp->getpre());
//				}
//				temp->getpre()->setnext(temp->getnext());
//				delete temp;
//				temp = NULL;
//				return;
//			}
//			temp = temp->getnext();
//		}
//	}
//	void delete_last()
//	{
//		if (head == NULL)
//		{
//			cout << "Nothing to delete bruhhh\n";
//			return;
//		}
//		node* temp = head;
//		if (head->getnext() == NULL)	//in case of only one node
//		{
//			head = NULL;
//			return;
//		}
//		while (temp->getnext() != NULL)
//		{
//			temp = temp->getnext();
//		}
//		temp->getpre()->setnext(NULL);
//		delete temp;
//		temp = NULL;
//	}
//	void search(int data) //Time complexity = O(n) where n equals to number of nodes in list
//	{
//		if (head == NULL)
//		{
//			cout << "Nothing to showw bruhhh\n";
//			return;
//		}
//		else {
//			node* temp = head;
//			while (temp->getnext() != NULL)
//			{
//				if (temp->getdata() == data)
//				{
//					cout << "Key: " << temp->getkey() << " Data: " << temp->getdata() << endl;
//					return;
//				}
//				temp = temp->getnext();
//			}
//		}
//		cout << "No node found with this data: \n";
//	}
//	void display()          //Time complexity = O(n) where n equals to number of nodes in list
//	{
//		node* temp = head;
//		while (temp != NULL)
//		{
//			cout << "Key: " << temp->getkey() << " Data: " << temp->getdata() << endl;
//			temp = temp->getnext();
//		}
//
//	}
//	node* gethead() {
//		return head;
//	}
//	void mid1()
//	{
//		doubly objodd, objeven;
//		node* temp_even = head;
//		node* temp_odd = head;
//		temp_even = head->getnext();
//		while (temp_odd->getnext() != NULL && temp_odd->getnext()->getnext() != nullptr) {
//			objodd.insertat_end(temp_odd);
//			objeven.insertat_end(temp_even);
//			temp_odd = temp_odd->getnext()->getnext();
//			temp_even = temp_even->getnext()->getnext();
//		}
//		node* temp = objodd.gethead();
//		while (temp->getnext() != NULL)
//		{
//			temp = temp->getnext();
//		}
//		temp->setnext(objeven.gethead());
//		objodd.display();
//	}
//
//	void mid2() {
//		doubly objodd, objeven;
//		node* temp_odd = head;
//		node* temp_even = head->getnext();
//
//		while (temp_odd != nullptr || temp_even != nullptr)
//		{
//			if (temp_odd != nullptr)
//			{
//				node* next_odd = NULL;
//				if (temp_odd->getnext() != nullptr) {
//					next_odd = temp_odd->getnext()->getnext();
//				}
//				objodd.insertat_end(new node(*temp_odd));
//				temp_odd = next_odd;
//			}
//
//			if (temp_even != nullptr)
//			{
//				node* next_even = NULL;
//				if (temp_even->getnext() != nullptr) {
//					next_even = temp_even->getnext()->getnext();
//				}
//				objeven.insertat_end(new node(*temp_even));
//				temp_even = next_even;
//			}
//		}
//
//		node* temp = objodd.gethead();
//		while (temp->getnext() != nullptr)
//		{
//			temp = temp->getnext();
//		}
//
//		temp->setnext(objeven.gethead());
//		//if (objeven.gethead() != nullptr)
//		{
//			objeven.gethead()->setpre(temp);
//		}
//
//		objodd.display();
//	}
//
//};
//void input(int& data, int& key)
//{
//	cout << "Enter data: ";
//	cin >> data;
//	cout << "Enter key: ";
//	cin >> key;
//}
//int main()
//{
//	doubly obj;
//	int data, key, ch;
//	while (true)
//	{
//		cout << "Menu:\n";
//		cout << "1.Insert node at beginning\n";
//		cout << "2.Insert node in middle\n";
//		cout << "3.Insert node at end\n";
//		cout << "4.Delete first node\n";
//		cout << "5.Delete node\n";
//		cout << "6.Delete last node\n";
//		cout << "7.Display list\n";
//		cout << "8.Search node\n";
//		cout << "9.Exit\n";
//		cout << "Enter your choice: ";
//		cin >> ch;
//
//		if (ch == 1)
//		{
//			input(data, key);
//			obj.insert_at_begin(data, key);
//		}
//		else if (ch == 2)
//		{
//			input(data, key);
//			int key2;
//			cout << "Enter key of the node after which you want to insert: ";
//			cin >> key2;
//			obj.insert_in_middle(data, key, key2);
//		}
//		else if (ch == 3)
//		{
//			input(data, key);
//			obj.insert_at_end(data, key);
//		}
//		else if (ch == 4)
//		{
//			obj.delte_first_node();
//		}
//		else if (ch == 5)
//		{
//			cout << "Enter key to delete: ";
//			int key2; cin >> key2;
//			obj.delete_a_node(key2);
//		}
//		else if (ch == 6)
//		{
//			obj.delete_last();
//		}
//		else if (ch == 7)
//		{
//			obj.display();
//		}
//		else if (ch == 8)
//		{
//			cout << "Enter data to search: ";
//			int d; cin >> d;
//			obj.search(d);
//		}
//		else if (ch == 9)
//		{
//			cout << "exititing\n";
//			break;
//		}
//		else if (ch == 10)
//			obj.mid2();
//		else {
//			cout << "Enter valid choice\n";
//			continue;
//		}
//	}
//	return 0;
//}