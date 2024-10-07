//#include<iostream>
//using namespace std;
//
//class node {
//public:
//    int data;
//    node* left;
//    node* right;
//    node(int data) : data(data), left(nullptr), right(nullptr) {}
//};
//
//class qnode {
//public:
//    node* nod;
//    qnode* next;
//    qnode(node* nod) : nod(nod), next(nullptr) {}
//};
//
//class queue {
//public:
//    qnode* front;
//    qnode* rear;
//    queue() : front(nullptr), rear(nullptr) {}
//
//    bool isempty() {
//        return front == nullptr;
//    }
//
//    void enqueue(node* n) {
//        qnode* q = new qnode(n);
//        if (isempty()) {
//            front = rear = q;
//            return;
//        }
//        rear->next = q;
//        rear = q;
//    }
//
//    node* dequeue() {
//        if (isempty()) {
//            cout << "Queue is empty\n";
//            return nullptr;
//        }
//        qnode* current = front;
//        node* temp = front->nod;
//        front = front->next;
//        if (front == nullptr) {
//            rear = nullptr;
//        }
//        delete current;
//        return temp;
//    }
//};
//
//class tree {
//public:
//    node* root;
//
//    tree() : root(nullptr) {}
//
//    void insert(int data, char position) {
//        node* n = new node(data);
//        insert1(root, n, position);
//    }
//
//    void insert1(node* p, node* n, char position) {
//        if (root == nullptr) {
//            root = n;
//            return;
//        }
//        if (position == 'l') {
//            if (p->left == nullptr) {
//                p->left = n;
//            }
//            else {
//                insert1(p->left, n, position);
//            }
//        }
//        else if (position == 'r') {
//            if (p->right == nullptr) {
//                p->right = n;
//            }
//            else {
//                insert1(p->right, n, position);
//            }
//        }
//        else {
//            cout << "Invalid input\n";
//        }
//    }
//
//    void BSF() {
//        queue q;
//        if (root == nullptr) {
//            cout << "Tree is empty\n";
//            return;
//        }
//        q.enqueue(root);
//        while (!q.isempty()) {
//            node* temp = q.dequeue();
//            cout << temp->data << endl;
//            if (temp->left != nullptr) {
//                q.enqueue(temp->left);
//            }
//            if (temp->right != nullptr) {
//                q.enqueue(temp->right);
//            }
//        }
//    }
//
//    int parent(node* n, int data) {
//        if (n == nullptr) return -1;
//        if (data == root->data) {
//            cout << "Node has no parent\n";
//            return -1;
//        }
//        if ((n->left != nullptr && n->left->data == data) || (n->right != nullptr && n->right->data == data)) {
//            return n->data;
//        }
//        int search = parent(n->left, data);
//        if (search != -1) return search;
//        return parent(n->right, data);
//    }
//
//    void child(node* n, int data) {
//        if (n->data == data) {
//            if (n->left != nullptr) {
//                cout << "left child = " << n->left->data << endl;
//            }
//            else {
//                cout << "no left child\n";
//            }
//            if (n->right != nullptr) {
//                cout << "right child = " << n->right->data << endl;
//            }
//            else {
//                cout << "no right child\n";
//            }
//            return;
//        }
//        if (n->left != nullptr) {
//            child(n->left, data);
//        }
//        if (n->right != nullptr) {
//            child(n->right, data);
//        }
//    }
//
//    int rootdata() {
//        return root->data;
//    }
//
//    bool checkleave(node* n, int data) {
//        if (n == nullptr) return false;
//        if (n->data == data) {
//            return (n->left == nullptr && n->right == nullptr);
//        }
//        return checkleave(n->left, data) || checkleave(n->right, data);
//    }
//
//    bool ancestor(node* n, int data) {
//        if (n == nullptr) return false;
//        if (n->data == data) return true;
//        bool searchleft = ancestor(n->left, data);
//        bool searchright = ancestor(n->right, data);
//        if (searchleft || searchright) {
//            cout << n->data << " ";
//            return true;
//        }
//        return false;
//    }
//
//    void decessor(node* n, int data) {
//        if (n == nullptr) return;
//        if (n->data == data) {
//            printdecessor(n);
//            return;
//        }
//        decessor(n->left, data);
//        decessor(n->right, data);
//    }
//
//    void printdecessor(node* n) {
//        if (n == nullptr) return;
//        if (n->left) {
//            cout << n->data << " ";
//            printdecessor(n->left);
//        }
//        if (n->right) {
//            cout << n->data << " ";
//            printdecessor(n->right);
//        }
//    }
//
//    bool sublings(node* n, int data1, int data2) {
//        if (n == nullptr) return false;
//        if (n->left != nullptr && n->right != nullptr &&
//            ((n->left->data == data1 && n->right->data == data2) ||
//                (n->right->data == data1 && n->left->data == data2))) {
//            return true;
//        }
//        return sublings(n->left, data1, data2) || sublings(n->right, data1, data2);
//    }
//
//    int level(node* n, int data, int count) {
//        if (n == nullptr) return 0;
//        if (n->data == data) return count;
//        int num = level(n->left, data, count + 1);
//        if (num != 0) return level(n->left, data, count + 1);
//        return level(n->right, data, count + 1);
//    }
//
//    bool internalnode(node* n, int data) {
//        if (n == nullptr) return false;
//        if (n->left != nullptr || n->right != nullptr) {
//            return true;
//        }
//        return internalnode(n->left, data) || internalnode(n->right, data);
//    }
//
//    void subtree(node* n, int data) {
//        if (n == nullptr) return;
//        if (n->data == data) {
//            printsubtree(n);
//            return;
//        }
//        subtree(n->left, data);
//        subtree(n->right, data);
//    }
//
//    void printsubtree(node* n) {
//        if (n == nullptr) return;
//        cout << n->data << " ";
//        printdecessor(n->right);
//        cout << "\nleft tree : ";
//        printdecessor(n->left);
//    }
//
//    int depth(node* n) {
//        if (n == nullptr) return -1;
//        int leftdepth = depth(n->left);
//        int rightdepth = depth(n->right);
//        return 1 + max(leftdepth, rightdepth);
//    }
//
//    int leftnode(node* n, int data) {
//        if (n == nullptr) return -1;
//        if (n->data == data) {
//            return n->left ? n->left->data : -1;
//        }
//        int num = leftnode(n->left, data);
//        if (num != -1) return leftnode(n->left, data);
//        return leftnode(n->right, data);
//    }
//
//    int rightnode(node* n, int data) {
//        if (n == nullptr) return -1;
//        if (n->data == data) {
//            return n->right ? n->right->data : -1;
//        }
//        int num = rightnode(n->left, data);
//        if (num != -1) return leftnode(n->left, data);
//        return rightnode(n->right, data);
//    }
//};
//
//int main() {
//    tree t;
//    cout << "Insertion:\n";
//    	cout << "Inserting random elements:\n";
//	for (int i = 1; i <= 9; i++)
//	{
//		int r = rand() % 30 + 1;
//
//        
//            t.insert(i, 'l');
//            t.insert(i + 6, 'r');
//        
//	}
//    	cout << "displaying Elements:\n";
//   	t.BSF();
//   	cout << endl;
//
//    
//    cout << "parent = " << t.parent(t.root, 10) << endl;
//    cout << endl;
//
//   
//    t.child(t.root, 10);
//    cout << endl;
//
//
//    cout << "Root Data = " << t.rootdata() << endl;
//    cout << endl;
//
//    cout << "Check leave = " << t.checkleave(t.root, 9) << endl;
//    cout << endl;
//
//    cout << "Ancestors = ";
//    t.ancestor(t.root, 12);
//    cout << endl;
//    cout << endl;
//
//    cout << "Decessor = ";
//    t.decessor(t.root, 2);
//    cout << endl;
//    cout << endl;
//
//    cout << "Sublings = " << t.sublings(t.root, 1, 6) << endl;
//    cout << endl;
//
//    cout << "Level = " << t.level(t.root, 3, 1) << endl;
//    cout << endl;
//
//    cout << "Internal Node = " << t.internalnode(t.root, 4) << endl;
//    cout << endl;
//
//    cout << "Subtree = ";
//    t.subtree(t.root, 2);
//    cout << endl;
//
//    cout << "Depth = " << t.depth(t.root) << endl;
//    cout << endl;
//
//    cout << "Left Node = " << t.leftnode(t.root, 3) << endl;
//    cout << endl;
//
//    cout << "Right Node = " << t.rightnode(t.root, 3) << endl;
//
//    return 0;
//}
