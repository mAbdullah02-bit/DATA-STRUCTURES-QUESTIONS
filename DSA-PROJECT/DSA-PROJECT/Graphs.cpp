#include<iostream>
#include"Stackimp.cpp"
#include"Queueimp.cpp"
#include"BSTimp.cpp"
#include<queue>

using namespace std;

class Node{
	//EACH USERs DETAILS 
public:
	string username, password, city, lastlogin;
	// Posts Stack for personal posts, messages stack for recieved messages,
	//  followerposts stack for when friends post anything it goes here
	Stack posts, messages,followerposts;
	// request queue for recieved requests, notification for recieved notifications
	// inbox of eaxh user when he sends to other firend;
	Queue requests, notifications, inbox;
	Node* next;
	Node(string name, string pass, string City, string Lastlogin) //Parameterized Constructor 
		:username(name), password(pass),city(City),lastlogin(Lastlogin),next(nullptr){}
};

class Graph {
	int noofusers;
	Node* Users[20];
	BST usernames;
	int size;
	string color[10];
	Graph() {
		noofusers = 0;
		size = 20;
		for (int i = 0; i < size; i++) {
			Users[i] = nullptr;
		}
	}
	void addUser(string name,string password,string city,string lastlogin) {
		if (noofusers < size) {
			if (usernames.insert(name)) {
			Users[noofusers] = new Node(name,password,city,lastlogin);
			noofusers++;
			}
		}
		else
		{
			size = size * 2;
			Node** temp = new Node * [size];
		}
		
	
	}
	void addfriend(string from ,string to) {
		int fromindex = getVertexIndex(from);
		int toindex = getVertexIndex(to);
		if (fromindex == -1 || toindex == -1) {
			cout << "One or both Users do not exist.\n";
			return;
		}
		Node* newNode = new Node(Users[toindex]->username, Users[toindex]->password, Users[toindex]->city, Users[toindex]->lastlogin);
		newNode->next = Users[fromindex]->next;
		Users[fromindex]->next = newNode;
		cout << "Friend Added Succesfully\n";
		cout<<"\n\nUser: "<<Users[fromindex]->requests.deque()<<" and User "<< Users[toindex]->requests.deque()<<" You both are now friends\n\n";

	}
	void insertfriendrequest(string from, string to) {
	
		int toindex = getVertexIndex(to);
		if ( toindex == -1) {
			cout << "User do not exist.\n";
			return;
		}
		
		Users[toindex]->requests.enque(to,from);

	}
	void displayfriendrequests(string user) {
		int index = getVertexIndex(user);
		if (index == -1 ) {
			cout << "User do not exist.\n";
			return;
		}
		Users[index]->requests.display();
	}
	int getVertexIndex(string s) {
		for (int i = 0; i < noofusers; i++) {
			if (Users[i]->username == s) return i;
		}
		return -1;
	}
	void BFS(string startVertex) {
		int startIndex = getVertexIndex(startVertex);
		if (startIndex == -1) {
			cout << "Start vertex does not exist.\n";
			return;
		}

		queue<int> q;
		for (int i = 0; i < noofusers; i++) {
			color[i] = "white";
		}

		q.push(startIndex);
		color[startIndex] = "gray";

		cout << "BFS Traversal: ";
		while (!q.empty()) {
			int currentIndex = q.front();
			q.pop();
			cout << Users[currentIndex]->username << " ";

			Node* temp = Users[currentIndex]->next;
			while (temp != nullptr) {
				int neighborIndex = getVertexIndex(temp->username);
				if (color[neighborIndex] == "white") {
					q.push(neighborIndex);
					color[neighborIndex] = "gray";
				}
				temp = temp->next;
			}
			color[currentIndex] = "black";
		}
		cout << endl;
	}

	

	
};