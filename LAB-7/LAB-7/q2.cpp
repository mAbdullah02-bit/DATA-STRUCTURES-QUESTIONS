//#include<iostream>
//using namespace std;
//class node
//{
//public:
//	int data;
//	node* left;
//	node* right;
//	node(int data)
//	{
//		this->data = data;
//		left = NULL;
//		right = NULL;
//	}
//};
//class qnode
//{
//public:
//	node* nod;
//	qnode* next;
//	qnode(node* nod)
//	{
//		this->nod = nod;
//		next = NULL;
//	}
//};
//class queue
//{
//public:
//	qnode* front;
//	qnode* rear;
//	queue()
//	{
//		front = NULL;
//		rear = NULL;
//	}
//	bool isempty();
//	void enqueue(node* n);
//	node* dequeue();
//};
//node* queue::dequeue()
//{
//	if (isempty())
//	{
//		cout << "Queue is empty\n";
//		return NULL;
//	}
//	qnode* current = front;
//	node* temp = front->nod;
//	front = front->next;
//	if (front == NULL)
//	{
//		rear = NULL;
//	}
//	delete current;
//	return temp;
//}
//void queue::enqueue(node* n)
//{
//	qnode* q = new qnode(n);
//	if (isempty())
//	{
//		front = rear = q;
//		return;
//	}
//	rear->next = q;
//	rear = q;
//}
//bool queue::isempty()
//{
//	return front == NULL;
//}
//class tree
//{
//public:
//	node* root;
//	tree() : root(NULL) {}
//	void insert(int data, char position);
//	void insert1(node* p, node* n, char position);
//	void BSF();
//};
//void tree::BSF()
//{
//	queue q;
//	if (root == NULL)
//	{
//		cout << "Tree is empty\n";
//		return;
//	}
//	q.enqueue(root);
//	while (!q.isempty())
//	{
//		node* temp = q.dequeue();
//		cout << temp->data << endl;
//		if (temp->left != NULL)
//		{
//			q.enqueue(temp->left);
//		}
//		if (temp->right != NULL)
//		{
//			q.enqueue(temp->right);
//		}
//	}
//}
//void tree::insert1(node* p, node* n, char position)
//{
//	if (root == NULL)
//	{
//		root = n;
//		return;
//	}
//	if (position == 'l')
//	{
//		if (p->left == NULL)
//		{
//			p->left = n;
//		}
//		else
//		{
//			insert1(p->left, n, position);
//		}
//	}
//	else if (position == 'r')
//	{
//		if (p->right == NULL)
//		{
//			p->right = n;
//		}
//		else
//		{
//			insert1(p->right, n, position);
//		}
//	}
//	else
//	{
//		cout << "Invalid input\n";
//	}
//}
//void tree::insert(int data, char position)
//{
//	node* n = new node(data);
//	insert1(root, n, position);
//}
//int main()
//{
//	tree t;
//	cout << "Inserting random elements:\n";
//	for (int i = 1; i <= 9; i++)
//	{
//		int r = rand() % 30 + 1;
//		t.insert(r, 'l');
//		t.insert(r + 1, 'r');
//	}
//	cout << "displaying Elements:\n";
//	t.BSF();
//	cout << endl;
//	
//	return 0;
//}
