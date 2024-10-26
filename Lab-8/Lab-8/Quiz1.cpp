//#include <iostream>
//#include <string>
//using namespace std;
//
//
//class node {
//public:
//    string data;
//    node* left;
//    node* right;
//
//    node(const string& value) : data(value), left(nullptr), right(nullptr) {}
//};
//
//
//class queuenode {
//public:
//    node* treenode;
//    queuenode* next;
//
//    queuenode(node* node) : treenode(node), next(nullptr) {}
//};
//
//
//class queue {
//private:
//    queuenode* front;
//    queuenode* rear;
//
//public:
//    queue() : front(nullptr), rear(nullptr) {}
//
//    void enqueue(node* node) {
//        queuenode* newnode = new queuenode(node);
//        if (rear) {
//            rear->next = newnode;
//        }
//        rear = newnode;
//        if (!front) {
//            front = newnode;
//        }
//    }
//
//    node* dequeue() {
//        if (!front) return nullptr;
//        node* node = front->treenode;
//        queuenode* temp = front;
//        front = front->next;
//        if (!front) {
//            rear = nullptr;
//        }
//        delete temp;
//        return node;
//    }
//
//    bool isempty() {
//        return front == nullptr;
//    }
//
//    ~queue() {
//        while (!isempty()) {
//            dequeue();
//        }
//    }
//};
//
//
//class binarytree {
//private:
//    node* root;
//
//public:
//    binarytree() : root(nullptr) {}
//
//    void insert(const string& value) {
//        node* newnode = new node(value);
//        if (!root) {
//            root = newnode;
//            return;
//        }
//
//       
//        queue queue;
//        queue.enqueue(root);
//
//        while (!queue.isempty()) {
//            node* current = queue.dequeue();
//
//            if (!current->left) {
//                current->left = newnode;
//                return;
//            }
//            else {
//                queue.enqueue(current->left);
//            }
//
//            if (!current->right) {
//                current->right = newnode;
//                return;
//            }
//            else {
//                queue.enqueue(current->right);
//            }
//        }
//    }
//
//    void bfs() {
//        if (!root) {
//            cout << "tree is empty." << endl;
//            return;
//        }
//
//        queue queue;
//        queue.enqueue(root);
//
//        while (!queue.isempty()) {
//            node* current = queue.dequeue();
//            cout << current->data << " ";
//
//            if (current->left) {
//                queue.enqueue(current->left);
//            }
//            if (current->right) {
//                queue.enqueue(current->right);
//            }
//        }
//        cout << endl;
//    }
//
//    bool search(const string& value) {
//        if (!root) return false;
//
//        queue queue;
//        queue.enqueue(root);
//
//        while (!queue.isempty()) {
//            node* current = queue.dequeue();
//            if (current->data == value) {
//                return true; 
//            }
//
//            if (current->left) {
//                queue.enqueue(current->left);
//            }
//            if (current->right) {
//                queue.enqueue(current->right);
//            }
//        }
//        return false; 
//    }
//};
//
//int main() {
//    binarytree bt;
//    int choice;
//    string value;
//
//    do {
//        cout << "\nbinary tree menu:\n";
//        cout << "1. insert\n";
//        cout << "2. breadth-first traversal\n";
//        cout << "3. search\n";
//        cout << "4. exit\n";
//        cout << "enter your choice: ";
//        cin >> choice;
//
//        switch (choice) {
//        case 1:
//            cout << "enter value to insert: ";
//            cin >> value;
//            bt.insert(value);
//            break;
//        case 2:
//            cout << "breadth-first traversal: ";
//            bt.bfs();
//            break;
//        case 3:
//            cout << "enter value to search: ";
//            cin >> value;
//            if (bt.search(value)) {
//                cout << "value found in the tree.\n";
//            }
//            else {
//                cout << "value not found in the tree.\n";
//            }
//            break;
//        case 4:
//            cout << "exiting...\n";
//            break;
//        default:
//            cout << "invalid choice. please try again.\n";
//            break;
//        }
//    } while (choice != 4);
//
//    return 0;
//}
