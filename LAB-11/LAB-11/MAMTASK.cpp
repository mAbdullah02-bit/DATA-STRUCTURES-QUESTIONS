#include<iostream>
using namespace std;

class Node {
public:
	string data;
	Node* next;
	Node(string s) { data = s; next = nullptr; }

};
class Graph {
public:
	Node* list[10];
	int noofvertices;
	Graph() {
		noofvertices = 0; for (int i = 0; i < 10; i++)
		{
			list[i] = 0;
		}
	}
	void addvertex(string s) {

		if (noofvertices < 10) {
			list[noofvertices] = new Node(s);
			noofvertices++;
		}
		else
		{
			cout << "MAX Verteces reached" << endl;
		}

	}
	void addEdge(string from, string to) {
		int fromindex = getVertexIndex(from);
		int toindex = getVertexIndex(to);
		if (fromindex == -1 || toindex == -1) {
			cout << "One of both vertices do not exist" << endl;
		return;
		}
		Node* newNode = new Node(to);
		newNode->next = list[fromindex]->next;
		list[fromindex]->next = newNode;
	}

	void display() {
		cout << "GRAPH Adjacency List:" << endl;
		for (int i = 0; i < noofvertices; i++)
		{
			cout << list[i]->data << " -> ";
			Node* temp = list[i]->next;
			while (temp!=nullptr)
			{
				cout << temp->data << " ";
				temp = temp->next;
			}
		}
	
	}
int	getVertexIndex(string s) {
	for (int i = 0; i < noofvertices; i++)
	{
		if (list[i]->data == s)return i;
	}


	return -1;
	}
};

int main() {

	Graph g;

	g.addvertex("A");
	g.addvertex("B");
	g.addvertex("C");
	g.addvertex("D");
	g.addEdge("A", "B");
	g.addEdge("A", "C");
	g.addEdge("B", "D");
	g.addEdge("C", "D");
	g.display();
	return 0;
}