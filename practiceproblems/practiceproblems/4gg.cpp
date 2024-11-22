//#include <iostream>
//using namespace std;
//
//class Node {
//public:
//    Node* left, * right;
//    int id, h;
//
//    Node(int data) {
//        this->id = data;
//        h = 1;
//        left = right = nullptr;
//    }
//};
//
//class AvlTree {
//public:
//    Node* root;
//    AvlTree() { root = nullptr; }
//
//    bool isempty() { return (root == nullptr); }
//
//    void inorder() {
//        inorder(root);
//        cout << endl;
//    }
//
//    void inorder(Node* root) {
//        if (root != nullptr) {
//            inorder(root->left);
//            cout << "ID: " << root->id << endl;
//            inorder(root->right);
//        }
//    }
//
//    Node* insert(Node* root, int id) {
//        if (root == nullptr) {
//            return new Node(id);
//        }
//        else if (id > root->id) {
//            root->right = insert(root->right, id);
//        }
//        else if (id < root->id) {
//            root->left = insert(root->left, id);
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
//    Node* deletenode(Node*& root, int data) {
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
//                Node* temp = root;
//                root = root->right;
//                delete temp;
//            }
//            else if (root->right == nullptr) {
//                Node* temp = root;
//                root = root->left;
//                delete temp;
//            }
//            else {
//                Node* temp = findMaxFromLeft(root->left);
//                root->id = temp->id;
//                root->left = deletenode(root->left, temp->id);
//            }
//        }
//
//        if (root == nullptr) return root;
//        root->h = 1 + max(height(root->left), height(root->right));
//        return balance(root);
//    }
//
//    Node* findMaxFromLeft(Node* node) {
//        while (node && node->right != nullptr)
//            node = node->right;
//        return node;
//    }
//
//    int height(Node* root) {
//        if (root == nullptr) {
//            return 0;
//        }
//        return root->h;
//    }
//
//    int getbalancefactor(Node* root) {
//        return height(root->left) - height(root->right);
//    }
//
//    Node* rightrotate(Node* x) {
//        Node* y = x->left;
//        Node* z = y->right;
//        y->right = x;
//        x->left = z;
//
//        x->h = 1 + max(height(x->left), height(x->right));
//        y->h = 1 + max(height(y->left), height(y->right));
//        return y;
//    }
//
//    Node* leftrotate(Node* x) {
//        Node* y = x->right;
//        Node* z = y->left;
//        y->left = x;
//        x->right = z;
//
//        x->h = 1 + max(height(x->left), height(x->right));
//        y->h = 1 + max(height(y->left), height(y->right));
//        return y;
//    }
//
//    Node* balance(Node* node) {
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
//    bool isAVL(Node* node) {
//        if (node == nullptr) return true;
//
//        int balanceFactor = getbalancefactor(node);
//        return (balanceFactor >= -1 && balanceFactor <= 1) && isAVL(node->left) && isAVL(node->right);
//    }
//
//
//    void mergeTrees(Node*& root, Node* other) {
//        if (other == nullptr) return;
//        root = insert(root, other->id);
//        mergeTrees(root, other->left);
//        mergeTrees(root, other->right);
//    }
//};
//
//int main() {
//    AvlTree T1, T2;
//    int id;
//
//    for (int i = 0; i < 5; ++i) {
//        cout << "Enter Data for T1: ";
//        cin >> id;
//        T1.root = T1.insert(T1.root, id);
//    }
//
//    cout << "Tree T1 (Inorder):" << endl;
//    T1.inorder();
//
//    for (int i = 0; i < 4; ++i) {
//        cout << "Enter Data for T2: ";
//        cin >> id;
//        T2.root = T2.insert(T2.root, id);
//    }
//
//    cout << "Tree T2 (Inorder):" << endl;
//    T2.inorder();
//
//
//    T1.mergeTrees(T1.root, T2.root);
//    cout << "Merged Tree T1 (Inorder):" << endl;
//    T1.inorder();
//
//    if (T1.isAVL(T1.root)) {
//        cout << "The tree is AVL balanced." << endl;
//    }
//    else {
//        cout << "The tree is not AVL balanced." << endl;
//    }
//
//    return 0;
//}
