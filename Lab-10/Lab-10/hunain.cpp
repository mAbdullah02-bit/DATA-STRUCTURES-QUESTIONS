#include<iostream>
using namespace std;
class node
{
public:
	int data;
	node* left;
	node* right;
	int height;
	node(int data)
	{
		this->data = data;
		left = NULL;
		right = NULL;
		height = 1;
	}
};
class tree
{
private:
	node* root;
	node* insert(node* n, int data);
	void inorder(node* n);
	node* deletion(node* n, int data);
public:
	tree()
	{
		root = NULL;
	}
	int height(node* n);
	int max(int x, int y);
	int balance(node* n);
	node* singleright(node* n1);
	node* singleleft(node* n1);
	node* leftright(node* n1);
	node* rightleft(node* n1);
	void insert1(int data);
	void realinorder();
	void del(int data);
	node* root1();
};
node* tree::root1()
{
	return root;
}

node* tree::deletion(node* n, int data)
{
	if (n == NULL)
	{
		return NULL;
	}
	else if (data < n->data)
	{
		n->left = deletion(n->left, data);
	}
	else if (data > n->data)
	{
		n->right = deletion(n->right, data);
	}
	else
	{
		if (n->left == NULL && n->right == NULL)
		{
			delete n;
			return NULL;
		}
		else if (n->left != NULL && n->right == NULL)
		{
			node* temp = n->left;
			delete n;
			return temp;
		}
		else if (n->right != NULL && n->left == NULL)
		{
			node* temp = n->right;
			delete n;
			return temp;
		}
		else
		{
			node* current = n->right;
			while (current->left)
			{
				current = current->left;
			}
			n->data = current->data;
			n->right = deletion(n->right, current->data);
		}
	}
	n->height = 1 + max(height(n->left), height(n->right));

	if (balance(n) == 2 && balance(n->left) >= 0)
	{
		return singleright(n);
	}

	else if (balance(n) == 2 && balance(n->left) < 0)
	{
		n->left = singleleft(n->left);
		return singleright(n);
	}

	else if (balance(n) == -2 && balance(n->right) < 0)
	{
		return singleleft(n);
	}

	else if (balance(n) == -2 && balance(n->right) > 0)
	{
		n->right = singleright(n->right);
		return singleleft(n);
	}

	return n;
}
void tree::del(int data)
{
	root = deletion(root, data);
}
void tree::inorder(node* n)
{
	if (n == NULL)
	{
		return;
	}
	inorder(n->left);
	cout << n->data << " ";
	inorder(n->right);
}
void tree::realinorder()
{
	inorder(root);
}
node* tree::insert(node* n, int data)
{
	if (n == NULL)
	{
		n = new node(data);
	}
	else if (data < n->data)
	{
		n->left = insert(n->left, data);
		if (height(n->left) - height(n->right) == 2)
		{
			if (data < n->data)
			{
				n = singleright(n);
			}
			else
			{
				n = leftright(n);
			}
		}
	}
	else if (data > n->data)
	{
		n->right = insert(n->right, data);
		if (height(n->left) - height(n->right) == -2)
		{
			if (data > n->data)
			{
				n = singleleft(n);
			}
			else
			{
				n = rightleft(n);
			}
		}
	}
	n->height = max(height(n->left), height(n->right)) + 1;
	return n;
}
void tree::insert1(int data)
{
	root = insert(root, data);
}
node* tree::rightleft(node* n1)
{
	n1->right = singleright(n1->left);
	return singleright(n1);
}
node* tree::leftright(node* n1)
{
	n1->left = singleleft(n1->left);
	return singleright(n1);
}

node* tree::singleleft(node* n1)
{
	node* n2 = n1->right;
	n1->right = n2->left;
	n2->left = n1;
	n1->height = 1 + max(height(n1->left), height(n1->right));
	n2->height = 1 + max(height(n2->left), height(n2->right));

	return n2;
}
// rotate right
node* tree::singleright(node* n1)
{
	node* n2 = n1->left;
	n1->left = n2->right;
	n2->right = n1;
	n1->height = 1 + max(height(n1->left), height(n1->right));
	n2->height = 1 + max(height(n2->left), height(n2->right));

	return n2;
}
// balancefactor
int tree::balance(node* n)
{
	return height(n->left) - height(n->right);
}
// height
int tree::height(node* n)
{
	if (n == NULL)
	{
		return 0;
	}
	return 1 + max(height(n->left), height(n->right));
}
// maximum
int tree::max(int x, int y)
{
	if (x > y)
	{
		return x;
	}
	else
	{
		return y;
	}
}

void getting(tree& t3, node* n)
{
	if (n == NULL)
	{
		return;
	}
	t3.insert1(n->data);
	getting(t3, n->left);
	getting(t3, n->right);
}

tree merge(tree t1, tree t2)
{
	tree t3;
	getting(t3, t1.root1());
	getting(t3, t2.root1());
	return t3;
}


int main()
{
	tree t1;
	tree t2;
	int num = 0;

	t1.insert1(1);
	t1.insert1(2);
	t1.insert1(5);
	t1.insert1(4);
	t1.insert1(3);

	cout << "Output: ";
	t1.realinorder();
	cout << endl << endl;

	t2.insert1(70);
	t2.insert1(40);
	t2.insert1(10);
	t2.insert1(30);
	t2.insert1(55);

	cout << "Output: ";
	t2.realinorder();
	cout << endl << endl;


	tree t3 = merge(t1, t2);

	cout << "Output: ";
	t3.realinorder();
	cout << endl << endl;

	system("pause");
	return 0;
}