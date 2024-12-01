#include<iostream>
#include"Stackimp.cpp"
#include"Queueimp.cpp"
#include"BSTimp.cpp"
#include"Linklist.cpp"
#include<queue>
const string RESET1 = "\033[0m";
const string RED1 = "\033[31m";
const string GREEN1 = "\033[32m";
const string YELLOW1 = "\033[33m";
const string BLUE1 = "\033[34m";
const string MAGENTA1 = "\033[35m";
const string CYAN1 = "\033[36m";
const string WHITE1 = "\033[37m";
const string BOLD1 = "\033[1m";


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
public:
	Graph() {
		noofusers = 0;
		size = 20;
		for (int i = 0; i < size; i++) {
			Users[i] = nullptr;
		}
	}
	bool addUser(string name,string password,string city,string lastlogin) {
		if (noofusers < size) {
			
				Users[noofusers] = new Node(name, password, city, lastlogin);
				usernames.insert(name);
				noofusers++;
				return true;
			
		}
		else
		{
			//size = size * 2;     
			//Node** temp = new Node * [size]; 

		
			//for (int i = 0; i < noofusers; i++) {
			//	temp[i] = Users[i];
			//}

			//
			//delete[] Users;
			////Users = temp;
		}
			
		
	
	}

	bool searchuser(string name) {
		return usernames.search(name);
	}
	void setnewpassword(string username, string pass) {
		int index = getVertexIndex(username);

		if (index == -1) {
			cout << " User do not exist.\n";
			return;
		}
		Users[index]->password = pass;

	}
	void setlatestime(string username,string time) {
		int index = getVertexIndex(username);

		if (index == -1) {
			cout << " User do not exist.\n";
			return;
		}
		Users[index]->lastlogin = time;

	}
	void addfollower(string from, string to) {
		int fromindex = getVertexIndex(from);
		int toindex = getVertexIndex(to);

		if (fromindex == -1 || toindex == -1) {
			cout << "One or both Users do not exist.\n";
			return;
		}

		Node* temp = Users[fromindex]->next;
		while (temp != nullptr) {
			if (temp->username == Users[toindex]->username) {
				cout << RED1 << "ALREADY FOLLOWING!.." << RESET1 << endl;
				return; 
			}
			temp = temp->next;
		}

		
		Node* newNode = new Node(Users[toindex]->username, Users[toindex]->password, Users[toindex]->city, Users[toindex]->lastlogin);
		newNode->posts = Users[toindex]->posts;
		newNode->next = Users[fromindex]->next;
		Users[fromindex]->next = newNode;

		cout << GREEN1 << "Followed Successfully\n" << RESET1;
		cout << GREEN1 << "\n\nUser: " << Users[fromindex]->username << " ! YOU now follow " << Users[toindex]->username << " \n\n" << RESET1;
	}

	void addpost(string post, string from) {
		int fromindex = getVertexIndex(from);
		
		if (fromindex == -1 ) {
			cout << "User do not exist.\n";
			return;
		}
		Users[fromindex]->posts.push(post,from);
	}
	void viewfollowerposts(string user) {
		int index = getVertexIndex(user);
		if (index == -1) {
			cout << "User do not exist.\n";
			return;
		}
	Node* temp=	Users[index]->next;

	while (temp!=nullptr)
	{
		temp->posts.displayposts(temp->username);
		
		temp = temp->next;
	}
	

	}
	void displayposts(string user) {
		int index = getVertexIndex(user);
		if (index == -1) {
			cout << "User do not exist.\n";
			return;
		}
		Users[index]->posts.displayposts(Users[index]->username);
	}
	void sendfollowrequest(string from, string to) {
		int toindex = getVertexIndex(to);
		int fromindex = getVertexIndex(from);

		if (toindex == -1) {
			cout << RED1 << "User does not exist.\n" << RESET1;
			return;
		}

		
		QNode* temp = Users[toindex]->requests.front;
		while (temp != nullptr) {
			if (temp->from == from) {
				cout << RED1 << "Follow request already sent!.." << RESET1 << endl;
				return;
			}
			temp = temp->next;
		}

		
		string str = "Friend Request Received from " + from;
		Users[toindex]->requests.enque(from, to);
		Users[toindex]->notifications.enque(str);

		cout << GREEN1 << "Follow request sent successfully.\n" << RESET1;
	}





	void sendMessage(string message,string from, string to) {

		int toindex = getVertexIndex(to);
		int fromindex = getVertexIndex(from);
		if (toindex == -1|| fromindex==-1) {
			cout << "one or both Users do not exist.\n";
			return;
		}
		Users[fromindex]->messages.push(message, from, to);
		Users[toindex]->messages.push(message,from, to);
		string str = message + " Recieved from " + from;
		Users[toindex]->notifications.enque(str);



	}
	void displaynotificatios(string user) {
		int index = getVertexIndex(user);
		if (index == -1) {
			cout << "User do not exist.\n";
			return;
		}
		Users[index]->notifications.display();
	}
	void displayfollowers(string user) {
		int index = getVertexIndex(user);
		if (index == -1) {
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

	
	void ShowSuggestions(string username) {
		int startIndex = getVertexIndex(username);
		if (startIndex == -1) {
			cout << "User does not exist.\n";
			return;
		}

		
		Linkedlist displayed;

		
		displayed.insertdata(username);
		Node* temp = Users[startIndex]->next;
		while (temp != nullptr) {
			displayed.insertdata(temp->username); 
			temp = temp->next;
		}

		cout << "Friend Suggestions for " << username << ":\n";

		
		temp = Users[startIndex]->next;
		bool suggestions = false;

		while (temp != nullptr) {
			int friendIndex = getVertexIndex(temp->username); 
			if (friendIndex == -1) {
				temp = temp->next;
				continue; 
			}

			
			Node* friendTemp = Users[friendIndex]->next;
			while (friendTemp != nullptr) {
				if (!displayed.search(friendTemp->username)) {
					
					cout << "- " << friendTemp->username << endl;
					displayed.insertdata(friendTemp->username); 
					suggestions = true;
				}
				friendTemp = friendTemp->next;
			}

			temp = temp->next;
		}

	
		if (!suggestions) {
			cout << "No friend suggestions available.\n";
		}
	}

	
};