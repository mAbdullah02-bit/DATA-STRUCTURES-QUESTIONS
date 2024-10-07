#include <iostream>
using namespace std;
class queue
{
	int* arr;
	int front;
	int rear;
	int numitems;
	int size;
public:
	queue() {
		size = 7;
		arr = new int[size];
		front = 0;
		rear = -1;
		numitems = 0;
	}
	~queue()
	{
		delete[] arr;
	}
	bool isfull();
	bool isempty();
	void enqueue(int value);
	void dequeue();
	int frontindex();
};
int queue::frontindex()
{
	return arr[front];
}
void queue::dequeue()
{
	if (isempty())
	{
		cout << "Queue is empty\n";
	}
	else
	{
front = (front + 1) % size;
numitems--;
	}
}
void queue::enqueue(int value)
{
	if (isfull())
	{
		cout << "Queue is full\n";
	}
	else
	{
		rear = (rear + 1) % size;
		arr[rear] = value;
		numitems++;
	}
}
bool queue::isempty()
{
	if (numitems == 0)
	{
		return true;
	}
	return false;
}
bool queue::isfull()
{
	if (numitems == size)
	{
		return true;
	}
	return false;
}
class tree {
	queue q1;
	int* tree_arr;
	int size;
	int counter;
public:
	tree()
	{
		size = 7;
		tree_arr = new int[size];
		counter = 1;
		for (int i = 0; i < size; i++)
		{
		tree_arr[i] = -1;
		}
	}
	~tree()
	{
		delete[] tree_arr;
	}
	void creatingtree(int value)
	{
		if (counter < size)
		{
			tree_arr[counter] = value;
			cout << counter << endl;
			counter++;
		}
		else
		{
	cout << "Tree is full, cannot insert more elements.\n";
		}
	}
	void bsf()
	{
		if (counter <= 1)
		{
			cout << "Tree is empty\n";
			return;
		}
		q1.enqueue(tree_arr[1]);
		while (!q1.isempty())
		{
			int index = q1.frontindex();
			q1.dequeue();
			cout << tree_arr[index] << endl;
			int left = 2 * index;
			if (left < counter)
			{
				q1.enqueue(tree_arr[left]);
			}
			int right = 2 * index + 1;
			if (right < counter)
			{
				q1.enqueue(tree_arr[right]);
			}
		}
	}
};
int main()
{
	tree t;
	cout << "INsertion = \n";
	for (int i = 1; i <= 6; i++)
	{
	t.creatingtree(i);
	}
	cout << endl;
	cout << "BSF = \n";
	t.bsf();

	return 0;
}