#include<iostream>
using namespace std;

class BNode {
public:
	BNode* left, * right;
	string username;
	BNode(string s) { left =right= nullptr; username = s; }

};
class BST {
	BNode* root;
public:
bool search(BNode* root,string d) {
		if (root == nullptr) { return false; }
		else if (root->username == d)return true;
		else if (d > root->username) {return  search(root->right,d); }
		else if (d < root->username) { return search(root->left,d); }
	
	}
bool search(string username) {
	return search(root, username);
}
bool insert(BNode* root,string d) {
	if (root == nullptr) { BNode* ptr = new BNode(d); return true; }
	else if (d < root->username)
	{
		 insert(root->left, d);
	}
	else if (d > root->username)
	{
		insert(root->right, d);
	}
	else {
	cout << "USERNAME ALREADY EXISTS!... Choose Another username\n";
	return false;
	}


}
bool insert(string d) {
	bool check = insert(root, d);
	return check;
}
BNode* deleteNode(BNode*& root,string d) {
	if (root == nullptr) {
		return root;
	}
	else if (d > root->username) { deleteNode(root->right, d); }
	else if (d < root->username) { deleteNode(root->left, d); }
	else
	{

		if (root->left == nullptr) {
			root = root->right;
		}
		else if (root->right== nullptr) {
			root = root->left;
		}
		else
		{
			BNode* temp= findmaxfromleft(root->left);
			string data = temp->username;
			deleteNode(root->left, data);
			root->username = data;
		}
		

	}

}
BNode* findmaxfromleft(BNode* root) {
	while (root->right!=nullptr)
	{
		root = root->right;
	}
	return root;
}
};