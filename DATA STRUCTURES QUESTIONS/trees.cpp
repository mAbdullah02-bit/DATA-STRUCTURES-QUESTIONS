//#include<iostream>
//#include<queue>
//#include<stack>
//using namespace std;
//
//class Node {
//public:
//	int data;
//	Node* left, * right;
//
//	Node(int d) {
//		right = left = nullptr;
//		data = d;
//	}
//};
//
//class BinarySearchTree {
//public:
//
//	Node* root;
//	BinarySearchTree() :root(nullptr) {}
//	void insert(int data) {
//		Node* ptr = new Node(data);
//
//		if (root == nullptr)
//		{
//			root = ptr;
//			return;
//		}
//		else
//		{
//
//			Node* temp = root;
//			while (temp != nullptr)
//			{
//
//				if (temp->data > data)
//				{
//					if (temp->left == nullptr) {
//						temp->left = ptr;
//						return;
//					}
//					else
//						temp = temp->left;
//				}
//				if (temp->data < data)
//				{
//					if (temp->right == nullptr) {
//						temp->right = ptr;
//						return;
//					}
//					else
//						temp = temp->right;
//				}
//
//
//			}
//
//		}
//
//
//	}
//	bool search(int data) {
//
//		Node* temp = root;
//
//		while (temp != nullptr)
//		{
//
//			if (data > temp->data)
//			{
//				if (temp->right != nullptr)
//					temp = temp->right;
//				else {
//					cout << "not found\n";
//					return false;
//				}
//			}
//			else if (data < temp->data) {
//
//				if (temp->left != nullptr)
//					temp = temp->left;
//				else {
//					cout << "not found\n";
//					return false;
//				}
//			}
//			else {
//				cout << "Found...\n";
//				return true;
//			}
//
//
//
//
//		}
//
//	}
//	void Display() {
//		int ch;
//		cout << "Choose Display Option: ";
//		cout << "1 In Order Traversal: ";
//		cout << "2 Preorder Traversal: ";
//		cout << "3 Postorder Traversal: ";
//		cout << "4 level order Traversal: ";
//		cout << "5 reverse level order Traversal: ";
//		cin >> ch;
//		if (ch == 1)
//			inorder(root);
//		else if (ch == 2)
//			preorder(root);
//		else if (ch == 3)
//			postorder(root);
//		else if (ch == 4)
//			levelorder(root);
//		else if (ch == 5)
//			reverselevelorder(root);
//		else
//			cout << "invalid choice!..\n";
//	}
//	void reverselevelorder(Node* root) {
//
//		if (root == nullptr)
//		{
//			cout << "Tree is empty!...\n";
//			return;
//		}
//		queue<Node*> q;
//		stack<Node*> s;
//		Node* temp = root;
//		q.push(temp);
//		q.push(NULL);
//
//		while (!q.empty())
//		{
//			Node* temp = q.front();
//			s.push(temp);
//			q.pop();
//			if (temp == NULL) {
//
//				cout << endl;
//				if (!q.empty())q.push(NULL);
//			}
//			else
//			{
//
//
//				if (temp->left)
//				{
//					q.push(temp->left);
//				}
//				if (temp->right)
//				{
//					q.push(temp->right);
//				}
//			}
//		}
//
//		while (!s.empty())
//		{
//			if (s.top() == NULL)
//			{
//				cout << endl;
//				s.pop();
//			}
//			cout << s.top()->data << " ";
//			s.pop();
//		}
//	}
//	void levelorder(Node* root) {
//
//		if (root == nullptr)
//		{
//			cout << "Tree is empty!...\n";
//			return;
//		}
//		queue<Node*> q;
//		Node* temp = root;
//		q.push(temp);
//		q.push(NULL);
//		while (!q.empty())
//		{
//			Node* temp = q.front();
//			q.pop();
//			if (temp == NULL) {
//				cout << endl;
//				if (!q.empty())q.push(NULL);
//			}
//			else
//			{
//
//				cout << temp->data << " ";
//				if (temp->left)
//				{
//					q.push(temp->left);
//				}
//				if (temp->right)
//				{
//					q.push(temp->right);
//				}
//			}
//
//
//
//		}
//
//
//	}
//	void inorder(Node* root) {
//
//		if (root != nullptr)
//		{
//
//
//			inorder(root->left);
//			cout << root->data << " ";
//			inorder(root->right);
//
//		}
//
//	}
//	void preorder(Node* root) {
//
//		if (root != nullptr)
//		{
//
//			cout << root->data << " ";
//			preorder(root->left);
//			preorder(root->right);
//		}
//
//	}
//	void postorder(Node* root) {
//		if (root != nullptr)
//		{
//
//			postorder(root->left);
//			postorder(root->right);
//			cout << root->data << " ";
//		}
//
//
//	}
//	void deleteNode(int val, Node*& node)
//
//	{
//
//		if (node == NULL)
//
//			return;
//
//		else if (val < node->data) {
//
//			deleteNode(val, node->left);
//
//		}
//
//		else if (val > node->data) {
//
//			deleteNode(val, node->right);
//
//		}
//
//		else {
//
//			if (val == node->data) {
//
//				if (node->left == nullptr) {
//
//					Node* temp = node;
//
//					node = node->right;
//
//					delete temp;
//
//				}
//
//				else if (node->right == nullptr)
//				{
//
//					Node* temp = node;
//
//					node = node->left;
//
//					delete temp;
//
//				}
//
//				else
//				{
//
//					Node* temp = findMaxFromLeft(node->left);
//
//					int data = temp->data;
//
//					deleteNode(temp->data, root);
//
//					node->data = data;
//
//				}
//
//			}
//
//		}
//
//	}
//	Node* findMaxFromLeft(Node* node)
//
//	{
//
//		while (node && node->right != nullptr)
//
//			node = node->right;
//
//		return node;
//
//	}
//};
//int main() {
//	BinarySearchTree tree;
//
//	tree.insert(8);
//	tree.insert(5);
//	tree.insert(2);
//	tree.insert(9);
//	tree.insert(1);
//	tree.insert(20);
//	tree.insert(7);
//
//	tree.Display();
//	tree.deleteNode(9,tree.root);
//
//	tree.Display();
//	return 0;
//}