//#include <iostream>
//#include <string>
//using namespace std;
//
//template <typename T>
//class Node {
//public:
//    Node* left, * right;
//    T id;
//    int h;
//    string date, name, title;
//
//    Node(T data, const string& date, const string& name, const string& title) {
//        this->id = data;
//        h = 1;
//        left = right = nullptr;
//        this->date = date;
//        this->name = name;
//        this->title = title;
//    }
//};
//
//template <typename T>
//class AvlTree {
//public:
//    Node<T>* root;
//    AvlTree() { root = nullptr; }
//
//    bool isempty() { return (root == nullptr); }
//
//    void inorder() {
//        inorder(root);
//        cout << endl;
//    }
//
//    void inorder(Node<T>* root) {
//        if (root != nullptr) {
//            inorder(root->left);
//            cout << "ID: " << root->id << ", Name: " << root->name << ", Date: " << root->date << ", Title: " << root->title << endl;
//            inorder(root->right);
//        }
//    }
//
//    Node<T>* insert(Node<T>* root, T id, const string& date, const string& name, const string& title) {
//        if (root == nullptr) {
//            return new Node<T>(id, date, name, title);
//        }
//        else if (id > root->id) {
//            root->right = insert(root->right, id, date, name, title);
//        }
//        else if (id < root->id) {
//            root->left = insert(root->left, id, date, name, title);
//        }
//        else {
//            cout << "Cannot enter duplicates\n";
//            return root;
//        }
//
//        root->h = 1 + max(height(root->left), height(root->right));
//        return balance(root);
//    }
//
//    Node<T>* deletenode(Node<T>*& root, T data) {
//        if (root == nullptr) {
//            cout << "Not found\n";
//            return nullptr;
//        }
//        else if (data > root->id) {
//            root->right = deletenode(root->right, data);
//        }
//        else if (data < root->id) {
//            root->left = deletenode(root->left, data);
//        }
//        else {
//            if (root->left == nullptr) {
//                Node<T>* temp = root;
//                root = root->right;
//                delete temp;
//            }
//            else if (root->right == nullptr) {
//                Node<T>* temp = root;
//                root = root->left;
//                delete temp;
//            }
//            else {
//                Node<T>* temp = findMaxFromLeft(root->left);
//                root->id = temp->id;
//                root->date = temp->date;
//                root->name = temp->name;
//                root->title = temp->title;
//                root->left = deletenode(root->left, temp->id);
//            }
//        }
//
//        if (root == nullptr) return root;
//        root->h = 1 + max(height(root->left), height(root->right));
//        return balance(root);
//    }
//
//    Node<T>* findMaxFromLeft(Node<T>* node) {
//        while (node && node->right != nullptr)
//            node = node->right;
//        return node;
//    }
//
//    int height(Node<T>* root) {
//        return root ? root->h : 0;
//    }
//
//    int getbalancefactor(Node<T>* root) {
//        return height(root->left) - height(root->right);
//    }
//
//    Node<T>* rightrotate(Node<T>* x) {
//        Node<T>* y = x->left;
//        Node<T>* z = y->right;
//        y->right = x;
//        x->left = z;
//        x->h = 1 + max(height(x->left), height(x->right));
//        y->h = 1 + max(height(y->left), height(y->right));
//        return y;
//    }
//
//    Node<T>* leftrotate(Node<T>* x) {
//        Node<T>* y = x->right;
//        Node<T>* z = y->left;
//        y->left = x;
//        x->right = z;
//        x->h = 1 + max(height(x->left), height(x->right));
//        y->h = 1 + max(height(y->left), height(y->right));
//        return y;
//    }
//
//    Node<T>* balance(Node<T>* node) {
//        int balanceFactor = getbalancefactor(node);
//
//        // LL
//        if (balanceFactor > 1 && getbalancefactor(node->left) >= 0) {
//            return rightrotate(node);
//        }
//
//        // RR
//        if (balanceFactor < -1 && getbalancefactor(node->right) <= 0) {
//            return leftrotate(node);
//        }
//
//        // LR
//        if (balanceFactor > 1 && getbalancefactor(node->left) < 0) {
//            node->left = leftrotate(node->left);
//            return rightrotate(node);
//        }
//
//        // RL
//        if (balanceFactor < -1 && getbalancefactor(node->right) > 0) {
//            node->right = rightrotate(node->right);
//            return leftrotate(node);
//        }
//
//        return node;
//    }
//
//    bool isAVL(Node<T>* node) {
//        if (node == nullptr) return true;
//        int balanceFactor = getbalancefactor(node);
//        return (balanceFactor >= -1 && balanceFactor <= 1) && isAVL(node->left) && isAVL(node->right);
//    }
//};
//
//int main() {
//    AvlTree<int> tree;
//    int id;
//    string date, name, title;
//
//    for (int i = 0; i < 5; ++i) {
//        cout << "Enter ID, Name, Date, Title: ";
//        cin >> id >> name >> date >> title;
//        tree.root = tree.insert(tree.root, id, date, name, title);
//        tree.inorder();
//    }
//
//    cout << "Enter ID to delete: ";
//    cin >> id;
//    tree.root = tree.deletenode(tree.root, id);
//    tree.inorder();
//
//    if (tree.isAVL(tree.root)) {
//        cout << "The tree is AVL balanced." << endl;
//    }
//    else {
//        cout << "The tree is not AVL balanced." << endl;
//    }
//
//    return 0;
//}
