
#include <iostream>
#include <string>
#include<ctime>
#include "Stack.cpp"
#include "Queue.cpp"
using namespace std;

class Users {
public:
    struct Edge {
        string friendName;
        string relation;
        string timestamp;
        string status;
        Edge* next;
    };

    struct Messages {
        string friendName;
        queue messages; // Use the provided stack implementation
        Messages* next;

        Messages(string fname) : friendName(fname), next(nullptr) {}
    };
    struct Vertex {
        queue followRequests;
        queue notifications;
        stack posts;
        stack newsFeed;

        string name;
        string security_question;
        string password;
        string city;
        string color; // For BFS traversal (white, gray, black)

        Edge* adj;
        Vertex* next;
        Messages* msgStack;  // Linked list to hold message stacks for each friend

        Vertex() : msgStack(nullptr) {}
    };
    class VQNode {
    public:
        Vertex* data;
        VQNode* next;

        VQNode() {
            data = nullptr;
            next = nullptr;
        }
    };

    class vertexQueue {
        VQNode* front;
        VQNode* back;

    public:
        vertexQueue() {
            front = nullptr;
            back = nullptr;
        }

        bool VIsEmpty() {
            return (front == nullptr);
        }

        void Venqueue(Vertex* v) {
            VQNode* nd = new VQNode;
            nd->data = v;
            nd->next = nullptr;

            if (VIsEmpty()) {
                front = back = nd;
            }
            else {
                back->next = nd;
                back = nd;
            }
        }

        Vertex* Vdequeue() {
            if (VIsEmpty()) {
                return nullptr;
            }
            VQNode* temp = front;
            Vertex* v = front->data;
            front = front->next;
            delete temp;
            if (!front) {
                back = nullptr;
            }
            return v;
        }
    };
    Vertex* head;

    Users() : head(nullptr) {}
    Vertex* findVertex(string name) {
        Vertex* current = head;
        while (current) {
            if (current->name == name) {
                return current;
            }
            current = current->next;
        }
        return nullptr;
    } bool DigitsInPass(string p) {
        for (int i = 0; i < p.length(); i++) {
            if (p[i] >= '0' && p[i] <= '9') {
                return true;
            }
        }
        return false;
    }


    void addUser(string name, string password, string city, string security) {
        Vertex* newVertex = new Vertex;
        newVertex->name = name;
        newVertex->password = password;
        newVertex->security_question = security;
        newVertex->city = city;
        newVertex->color = "white"; // Initialize with "white"
        newVertex->adj = nullptr;
        newVertex->next = nullptr;

        if (head == nullptr) {
            head = newVertex;
            return;
        }
        Vertex* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newVertex;
    }

    string getTimestamp() {
        time_t t = time(0);
        char buffer[26];
        ctime_s(buffer, sizeof(buffer), &t);
        string timestamp = buffer;

        return timestamp;
    }

    void addRelation(string fromName, string toName, string relation, string status) {
        Vertex* fromVertex = findVertex(fromName);
        Vertex* toVertex = findVertex(toName);

        if (fromVertex && toVertex) {
            Edge* newNode = new Edge;
            newNode->timestamp = getTimestamp();
            newNode->friendName = toName;
            newNode->relation = relation;
            newNode->status = status;
            newNode->next = fromVertex->adj;
            fromVertex->adj = newNode;
        }
        else {
            cout << "\033[36m\t\t\t\t  Cannot add the relation from " << fromName << " to " << toName << endl;
        }
    }



    void displayGraph() {
        Vertex* current = head;

        cout << "\033[36m\t\t\t\t\t\t\t Following are all the Accounts:\n";
        while (current) {
            cout << "\033[36m\t\t\t\t  Account Name: " << current->name << " (" << current->city << " ) -> ";
            Edge* temp = current->adj;
            while (temp) {
                cout << "\t\t\t\t\t\t\t  " << temp->friendName << " [Relation: " << temp->relation << " | Status: " << temp->status << "] \n";
                temp = temp->next;
            }
            cout << endl;
            current = current->next;
        }
    }

    void DisplayNames(string name) {
        if (!head) {
            cout << "\033[36m\t\t\t\t\t\t\t  No Accounts Made Till Now.\n";
            return; // Exit if the graph is empty
        }
        cout << "\033[36m\t\t\t\t  Enter the name username from the following, of the person you want to follow: \n";
        // Reset all vertices to "white"
        Vertex* temp = head;
        while (temp) {
            temp->color = "white";
            temp = temp->next;
        }

        vertexQueue q;

        cout << "\033[36m\t\t\t\t\t\t\t  All Accounts:\n";

        // Start BFS for all components
        temp = head;
        while (temp) {
            if (temp->color == "white") { // If the vertex is unvisited
                q.Venqueue(temp);
                temp->color = "gray";

                while (!q.VIsEmpty()) {
                    Vertex* u = q.Vdequeue();
                    if (u->name != name) {
                        cout << "\033[36m\t\t\t\t\t\t\t  " << u->name << endl; // Display the name of the vertex
                    }
                    // Traverse all adjacent vertices of u
                    Edge* edge = u->adj;
                    while (edge) {
                        Vertex* adjVertex = findVertex(edge->friendName);
                        if (adjVertex && adjVertex->color == "white") {
                            adjVertex->color = "gray";
                            q.Venqueue(adjVertex);
                        }
                        edge = edge->next;
                    }

                    u->color = "black";
                }
            }
            temp = temp->next; // Move to the next vertex in the graph
        }

        cout << endl; // Print a newline after traversal
    }

    bool bfs(string targetName) {
        bool found = false;  // Flag to track if the targetName is found

        if (!head) {
            cout << "\033[36m\t\t\t\t\t\t\t  No Accounts Made Till Now.\n";
            return false; // Return false if graph is empty
        }

        // Reset all vertices to "white"
        Vertex* temp = head;
        while (temp) {
            temp->color = "white";
            temp = temp->next;
        }

        vertexQueue q;

        // Start BFS for all components
        temp = head;
        while (temp) {
            if (temp->color == "white") { // If the vertex is unvisited
                q.Venqueue(temp);
                temp->color = "gray";

                while (!q.VIsEmpty()) {
                    Vertex* u = q.Vdequeue();

                    // Check if the current vertex matches the targetName
                    if (u->name == targetName) {
                        found = true;
                    }

                    // Traverse all adjacent vertices of u
                    Edge* edge = u->adj;
                    while (edge) {
                        Vertex* adjVertex = findVertex(edge->friendName);
                        if (adjVertex && adjVertex->color == "white") {
                            adjVertex->color = "gray";
                            q.Venqueue(adjVertex);
                        }
                        edge = edge->next;
                    }

                    u->color = "black";
                }
            }
            temp = temp->next; // Move to the next vertex in the graph
        }

        cout << endl;

        // Return true if the targetName was found, otherwise return false
        return found;
    }
    void securityQuestion(string name) {
        string father;
        Vertex* v = findVertex(name);
        cout << "\033[36m\t\t\t\t\t   Enter Father name for security check: ";
        cin >> father;
        if (father == v->security_question) {
            string password;
            cout << "\033[36m\t\t\t\t\t\t\t  Enter new password: ";
            cin >> password;
            v->password = password;
            cout << "\033[36m\t\t\t\t\t\t\t  Password reset!!!\n";
        }
    }



    bool passwordChecker(string name, string pass) {
        Vertex* vertex = findVertex(name);
        if (vertex->password.length() != pass.length()) {
            return false;
        }
        for (int i = 0; i < vertex->password.length(); i++) {
            if (vertex->password[i] != pass[i]) {
                return false;
            }
        }
        return true;
    }
    void displayVertex(string name) {
        // Find the vertex by its name
        Vertex* vertex = findVertex(name);

        if (vertex) {
            cout << "\033[36m\t\t\t\t\t\t\t  Name: " << vertex->name << "\n";
            cout << "\033[36m\t\t\t\t\t\t\t  Password: " << vertex->password << "\n";
            cout << "\033[36m\t\t\t\t\t\t\t  City: " << vertex->city << "\n";
            cout << "\033[36m\t\t\t\t\t\t\t  Followers:\n";

            // Display all adjacent vertices and their relations
            Edge* edge = vertex->adj;
            if (edge) {
                while (edge) {
                    cout << "\033[36m - " << edge->friendName << " [Relation: " << edge->relation << " | Status: " << edge->status << "]";
                    edge = edge->next;
                }
            }
        }

    }

    bool isAlreadyFollowing(string fromName, string toName) {
        Vertex* username = findVertex(fromName);
        Edge* temp = username->adj;
        while (temp) {
            if (temp->friendName == toName) {
                return true;
            }
            temp = temp->next;
        }
        return false;
    }
    void sendRequest(string fromName, string toName) {
        string notification = "Your have a new Follow request from " + fromName;
        Vertex* toVertex = findVertex(toName);
        if (toVertex->followRequests.search(fromName)) {
            cout << "\033[36m\t\t\t\t\t\t\t  Follow Request Already sent!\n";
        }
        else {
            toVertex->followRequests.enqueue(fromName);
            cout << "\033[36m\t\t\t\t\t\t\t  Follow request sent to " << toName << endl;
            toVertex->notifications.enqueue(notification);
        }
    }
    void checkRequest(string currentUserName) {

        Vertex* nameVertex = findVertex(currentUserName);
        if (nameVertex->followRequests.IsEmpty()) {
            cout << "\033[36m\t\t\t\t\t\t\t  No Follow Requests\n";
        }
        else {
            nameVertex->followRequests.display();
        }
    }


    void askAccept(string currentUserName, string option) {

        Vertex* nameVertex = findVertex(currentUserName);
        string notification;
        string toName = nameVertex->followRequests.peek();
        Vertex* toVertex = findVertex(toName);
        if (option == "yes" || option == "Yes") {
            notification = "Your Follow request has been accepted by " + currentUserName;
            string status = "Active";
            string relation = "Follower";
            //addRelation(currentUserName, toName, relation, status);
            addRelation(toName, currentUserName, relation, status);
            toVertex->notifications.enqueue(notification);
            nameVertex->followRequests.dequeue();
            cout << "\033[36m\t\t\t\t\t\t\t  Follow request Accepted!\n";
        }
        else if (option == "no" || option == "No") {
            notification = "Your Follow request has been rejected by " + currentUserName;
            toVertex->notifications.enqueue(notification);
            nameVertex->followRequests.dequeue();
            cout << "\033[36m\t\t\t\t\t\t\t  Follow request rejected\n";
        }
        else if (option == "bulk" || option == "Bulk") {

            while (!nameVertex->followRequests.IsEmpty()) {
                string toName = nameVertex->followRequests.peek();
                Vertex* toVertex = findVertex(toName);
                notification = "Your Follow request has been accepted by " + currentUserName;
                string status = "Active";
                string relation = "Follower";
                //addRelation(currentUserName, toName, relation, status);
                addRelation(toName, currentUserName, relation, status);
                toVertex->notifications.enqueue(notification);
                nameVertex->followRequests.dequeue();
            }
            cout << "\033[36m\t\t\t\t\t\t\t  All follow requests Accepted!\n";
        }

        else if (option == "back" || option == "Back") {
            cout << "\033[36m\t\t\t\t\t\t\t  Returning to previous menu...\n";
        }
        else {
            cout << "\033[36m\t\t\t\t\t\t\t  Enter a valid option!!";
        }
    }

    void displayFollowing(string name) {
        // Find the vertex with the given name
        Vertex* vertex = findVertex(name);
        if (!vertex->adj) {
            cout << "\033[36m\t\t\t\t\t\t  " << name << " You are Currently Following No One\n";
            return;
        }

        cout << "\033[36m\t\t\t\t\t\t\t  Following:\n";
        Edge* current = vertex->adj;
        while (current) {
            cout << "\033[36m\t\t\t\t\t\t\t  - Name: " << current->friendName << endl;
            cout << "\033[36m\t\t\t\t\t\t\t  Relation: " << current->relation << endl;
            cout << "\033[36m\t\t\t\t\t\t\t  Last Active: " << current->timestamp << endl;
            cout << "\033[36m\t\t\t\t\t\t\t  Status: " << current->status << endl << endl;
            current = current->next;
        }
    }
    void displayFollowers(string name) {
        Vertex* temp = head;
        cout << "\033[36m\t\t\t\t\t\t\t  Followers:\n";
        while (temp) {
            Edge* current = temp->adj;
            while (current) {
                if (current->friendName == name) {
                    cout << "\033[36m\t\t\t\t\t\t\t  Name: " << temp->name << endl;
                }
                current = current->next;
            }
            temp = temp->next;
        }
    }
    void createPost(string name, string post, string timest) {
        Vertex* nameVertex = findVertex(name);
        nameVertex->posts.push(post, timest);
        cout << "\033[36m\t\t\t\t\t\t\t  Post uploaded\n";
        Vertex* temp = head;
        while (temp) {
            Edge* current = temp->adj;
            while (current) {
                if (current->friendName == name) {
                    temp->newsFeed.push(post, timest);
                }
                current = current->next;
            }
            temp = temp->next;
        }
    }
    void displayNewsFeed(string name) {
        Vertex* vertex = findVertex(name);
        if (vertex->newsFeed.isEmpty()) {
            cout << "\033[36m\t\t\t\t\t\t\t  No Posts Yet...\n";
        }
        else {
            cout << "\033[36m\t\t\t\t\t\t\t  News Feed:\n";
            vertex->newsFeed.display();
        }
    }

    void displayPosts(string name) {
        Vertex* vertex = findVertex(name);
        if (vertex->posts.isEmpty()) {
            cout << "\033[36m\t\t\t\t\t\t\t  No Posts Yet...\n";
        }
        else {
            cout << "\033[36m\t\t\t\t\t\t\t  Your Posts:\n";
            vertex->posts.display();
        }
    }


    // Method to find or create a message stack for a friend
    Messages* checkMsgStackExists(Vertex* vertex, string friendName) {
        Messages* current = vertex->msgStack;
        while (current) {
            if (current->friendName == friendName) {
                return current;
            }
            current = current->next;
        }
        // If not found, create a new message stack
        Messages* newstack = new Messages(friendName);
        newstack->next = vertex->msgStack;
        vertex->msgStack = newstack;
        return newstack;
    }


    // Method to send a message to a friend
    void sendMessage(string fromName, string toName, string message) {
        Vertex* fromVertex = findVertex(fromName);
        Vertex* toVertex = findVertex(toName);

        if (toVertex) {
            Messages* fromStack = checkMsgStackExists(fromVertex, toName);
            Messages* toStack = checkMsgStackExists(toVertex, fromName);
            string notification = "You have a New Message From " + fromName;
            fromStack->messages.enqueue(message);
            toStack->messages.enqueue(message);
            toVertex->notifications.enqueue(notification);
            cout << "\033[36m\t\t\t\t\t\t\t  Message sent from " << fromName << " to " << toName << endl;
        }
        else {
            cout << "\033[36m\t\t\t\t\t\t\t  Input a valid user!\n";
        }
    }

    // Method to display messages with a friend
    void displayMessage(string name, string friendName) {
        Vertex* vertex = findVertex(name);

        Messages* current = vertex->msgStack;
        while (current) {
            if (current->friendName == friendName) {
                cout << "\033[36m\t\t\t\t\t\t\t  Messages with " << friendName << ":\n";
                queue messages = current->messages;
                /*while (!messages.IsEmpty()) {
                    messages.display();
                    messages.dequeue();
                }*/
                messages.Display();
                return;
            }
            current = current->next;
        }
        cout << "\033[36m\t\t\t\t\t\t\t  No messages found with " << friendName << endl;

    }

    void displayNotifications(string name) {
        Vertex* vertex = findVertex(name);
        if (vertex->notifications.IsEmpty()) {
            cout << "\033[36m\t\t\t\t\t\t\t  No Notifications Yet...\n";
        }
        else {
            cout << "\033[36m\t\t\t\t\t\t\t  Notifications:\n";
            vertex->notifications.display();
        }
        while (!vertex->notifications.IsEmpty()) {
            vertex->notifications.dequeue();
        }
    }

    void followSuggestions(string name) {
        Vertex* vertex = findVertex(name);
        cout << "\033[36m\t\t\t\t\t\t\t  Following Suggestions:\n";
        if (vertex->adj == nullptr) {
            cout << "\033[36m\t\t\t\t\t\t\t  No suggestions!\n";
            return;
        }
        else {
            Edge* current = vertex->adj;
            while (current) {
                Vertex* Following = findVertex(current->friendName);
                Edge* following = Following->adj;
                while (following) {
                    if (following->friendName != name) {
                        cout << "\033[36m\t\t\t\t\t\t\t " << following->friendName << endl;
                    }
                    following = following->next;

                }
                current = current->next;
            }
        }

    }
    void MutualFriends(string name) {
        Vertex* vertex = findVertex(name);
        Vertex* temp = head;

        while (temp) {
            if (temp != vertex) {
                Edge* myEdge = vertex->adj;
                Edge* otherEdge = temp->adj;
                cout << "\033[36m\t\t\t\t\t\t\t  Your mutual Friends with " << temp->name << ": \n";
                while (myEdge) {
                    while (otherEdge) {
                        if (myEdge->friendName == otherEdge->friendName) {
                            cout << "\033[36m\t\t\t\t\t\t\t" << myEdge->friendName << endl;
                        }
                        otherEdge = otherEdge->next;
                    }
                    otherEdge = temp->adj;
                    myEdge = myEdge->next;
                }
            }
            temp = temp->next;
        }

    }

    ~Users() {
        while (head) {
            Vertex* toDelete = head;
            head = head->next;

            Edge* temp = toDelete->adj;
            while (temp) {
                Edge* toDeleteEdge = temp;
                temp = temp->next;
                delete toDeleteEdge;
            }

            delete toDelete;
        }
    }
};
