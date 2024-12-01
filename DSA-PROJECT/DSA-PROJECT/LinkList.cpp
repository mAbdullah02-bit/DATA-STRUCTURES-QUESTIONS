#include<iostream>
using namespace std;

class LNode {
public:
	string name,password,security;
	LNode* next;
	LNode() { next = nullptr; }

};
class Linkedlist
{
public:
	Linkedlist() : head(nullptr){}
	
	void insertdata(string data) {


		LNode* ptr = new LNode;
		ptr->name = data;
		
	ptr->next = nullptr;
		if (head == nullptr)
		{
			head = ptr;
		}
		else
		{
			LNode* curr = head;

			while (curr->next != nullptr)
				curr = curr->next;
			curr->next = ptr;

		}

	}
	void insertdata(string data,string pass,string security) {
	

		LNode* ptr = new LNode;
		ptr->name = data;
		ptr->password = pass;
		ptr->security = security;
		ptr->next = nullptr;
		if (head == nullptr)
		{
			head = ptr;
		}
		else
		{
			LNode* curr = head;

			while (curr->next != nullptr)
			curr = curr->next;
			curr->next = ptr;
			
		}
	
	}


	
	bool deleteNode(string key) {
	

		LNode* temp = nullptr;
		if (head==nullptr)
		{
			return 0;
		}
		if (head->name == key)
		{
			temp = head;
			head = head->next;
			delete temp;
			return 1;
		}
		else
		{
			LNode* curr = head;

			while (curr->next != nullptr)
			{
				if (curr->next->name == key)
				{
				
					temp=curr->next;
					curr->next = curr->next->next;
					delete temp;
					
					
					return 1;
				}
				curr = curr->next;
			}
		}
			cout << "USER NOT FOUND HAVING  Name " << key << endl;
			return 0;
	}
	

	void display() {
		if (head == nullptr)
		{
			cout << "No Users At The Moment!....\n";
			return ;
		}
		else
		{
			LNode* curr = head;
			while (curr != nullptr) {
				cout << curr->name<<"->" ;
				curr = curr->next;
			}
			
		}

	}
	
	bool search(string data) {
	
		if (head == nullptr)
		{
			
			return false;
		}
		else
		{
			LNode* curr = head;

			while (curr != nullptr)
			{
				if (curr->name == data )
					return true;

				curr = curr->next;
			}
			return false;
			cout << "USER NOT FOUND HAVING  Name " << data << endl;
		}
	
	
	}
	void updatepassword(string name,string pass) {
		if (head == nullptr)
		{
			cout << "No Users At The Moment!....\n";
			return ;
		}
		else
		{
			LNode* curr = head;

			while (curr != nullptr)
			{
				if (curr->name == name)
					curr->password = pass;

				curr = curr->next;
			}

			cout << "USER NOT FOUND HAVING  Name " << name << endl;
		}
	
	}
	bool searchsecurity(string name,string questio) {

		if (head == nullptr)
		{
			cout << "No Users At The Moment!....\n";
			return false;
		}
		else
		{
			LNode* curr = head;

			while (curr != nullptr)
			{
				if (curr->name == name && curr->security==questio)
					return true;

				curr = curr->next;
			}
			return false;
			cout << "USER NOT FOUND HAVING  Name " << name << endl;
		}


	}
	bool validate(string name , string pass) {
		if (head == nullptr)
		{
			cout << "No Users At The Moment!....\n";
			return false;
		}
		else
		{
			LNode* curr = head;

			while (curr != nullptr)
			{
				if (curr->name == name&& curr->password==pass)
					return true;

				curr = curr->next;

			}



			return false;
			cout << "USER NOT FOUND HAVING  Name " << name << endl;
		}
	
	}
private:
	LNode* head;
};