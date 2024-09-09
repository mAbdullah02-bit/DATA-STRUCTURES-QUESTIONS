#include<iostream>
#include<string>
using namespace std;

class Node{
public:
	string name;
	Node* next=NULL;
	Node* prev=NULL;



};


class doublycircular {

public:
	Node* head;
	Node* tail;
	int len=0;
	doublycircular() { head = nullptr; tail = nullptr; }

	void appendsong(string name) {
		Node* ptr = new Node;
		ptr->name = name;

		if (head == NULL)
		{

			tail = head = ptr;
			ptr->prev = NULL;
			ptr->next = head;	len++;
		}
		else
		{

			
			tail->next = ptr;
			ptr->prev = tail;
			ptr->next = head;
			head->prev = ptr;
			tail = ptr;
			len++;
		}





	}


	void deletenode(string name) {
		if (head == nullptr)
		{
			cout << "NO SONGS IN THE LIST!....\n";
		}
		else
		{

		Node* curr = head;
			
		int c = len;
		while (c != 0)
		{
			if (curr->name == name)
			{
				if (head->name==name)
				{
					if (head->next != nullptr)
						head = head->next;
					else head == nullptr;
					delete curr;
					len--;
					return;
				}
				else
				{

				curr->next->prev = curr->prev;
				curr->prev->next = curr->next;
				len--;
				delete curr;
				return;
				}
			}
			c--;
			curr = curr->next;
		}
		}

	}
		void playnextorprev(Node* song){
			if (song==nullptr)
			{
				cout << "NO SONGS IN THE LIST!....\n";
			}
			else
				cout << song->name << endl;

		}
		
		void displaylist() {
			if (head == nullptr)
			{
				cout << "NO SONGS IN THE LIST!....\n";
			}
			else {
				Node* curr = head;
				int c = len;
				while (c!=0) {

					cout << "SONG NAME: " << curr->name << endl;;
					curr = curr->next;
					c--;
				}



			}
		
		}
		void shuffle() {
			if (head==nullptr)
			{
				cout << "NO SONGS IN THE LIST!....\n";
			}
			else
			{

			int c=rand()% len;
			Node* curr = head;
			while (c != 0) {
			
				curr = curr->next;
				c--;
			}
			cout << "SONG NAME: " << curr->name << endl;
			}
		
		}
};
int main() {

	srand(time(0));
	doublycircular	 list;
	Node* curr=NULL ;
	int choice;
	string title;

	do {
		cout << "\n--- Music Player Menu ---\n";
		cout << "1. Add Song\n";
		cout << "2. Remove Song\n";
		cout << "3. Play Next Song\n";
		cout << "4. Play Previous Song\n";
		cout << "5. Display list\n";
		cout << "6. Shuffle Play\n";
		cout << "0. Exit\n";
		cout << "Enter your choice: ";
		cin >> choice;

		switch (choice) {
		case 1:
			cout << "Enter the song title: ";
			cin.ignore();
			getline(cin, title);
			list.appendsong(title);
			if (curr==nullptr)
				curr = list.head;
			
			
			break;

		case 2:
			if (list.head != nullptr)
			{
				cout << "Enter the name of song to delete: ";
				cin.ignore();
				getline(cin, title);
				list.deletenode(title);
				if (list.head == nullptr)
					curr = nullptr;
			}
			else cout << "LIST IS EMPTY!......\n";
			break;

		case 3:
			
			 curr = curr->next;
			 list.playnextorprev(curr);
			 if (curr!=NULL)
			 
			 


			break;

		case 4:
			if (curr != NULL) {
				curr = curr->prev;
			list.playnextorprev(curr);
			}
			break;

		case 5:
			list.displaylist();
			break;

		case 6:
			
			list.shuffle();
			break;

		case 0:
			cout << "Exiting the music player.\n";
			break;

		default:
			cout << "Invalid choice! Please try again.\n";
		}
	} while (choice != 0);






	system("pause");
	return 0;
}