//#include<iostream>
//using namespace std;
//
//class Node {
//public:
//    Node* right, * left;
//    char data;
//    Node(char d) { right = left = nullptr; data = d; }
//};
//
//class BST {
//    Node* root;
//public:
//    BST() { root = nullptr; }
//
//    void insert(char ch) {
//        Node* ptr = new Node(ch);
//
//        if (root == nullptr) {
//            root = ptr;
//            return;
//        }
//
//        Node* current = root;
//        Node* parent = nullptr;
//
//        while (current != nullptr) {
//            parent = current;
//
//            if (ch > current->data) {
//                current = current->right;
//            }
//            else if (ch < current->data) {
//                current = current->left;
//            }
//            else {
//                cout << "Cannot insert duplicates\n";
//                return;
//            }
//        }
//
//        if (ch > parent->data)
//            parent->right = ptr;
//        else
//            parent->left = ptr;
//    }
//
//    void search(char ch) {
//        search(root, ch);
//    }
//
//    void search(Node* root, char ch) {
//        if (root == nullptr) {
//            cout << "NOT FOUND\n";
//            return;
//        }
//
//        if (ch > root->data)
//            search(root->right, ch);
//        else if (ch < root->data)
//            search(root->left, ch);
//        else {
//            cout << "Found with value: " << ch << endl;
//            return;
//        }
//    }
//
//    void inorder() {
//        inorder(root);
//        cout << endl;
//    }
//
//    void inorder(Node* root) {
//        if (root != nullptr) {
//            inorder(root->left);
//            cout << root->data << " ";
//            inorder(root->right);
//        }
//    }
//
//    void preorder() {
//        preorder(root);
//        cout << endl;
//    }
//
//    void preorder(Node* root) {
//        if (root != nullptr) {
//            cout << root->data << " ";
//            preorder(root->left);
//            preorder(root->right);
//        }
//    }
//
//    void postorder() {
//        postorder(root);
//        cout << endl;
//    }
//
//    void postorder(Node* root) {
//        if (root != nullptr) {
//            postorder(root->left);
//            postorder(root->right);
//            cout << root->data << " ";
//        }
//    }
//
//    int countleaves() {
//        return countleaves(root);
//    }
//
//    int countleaves(Node* root) {
//        if (root == nullptr) {
//            return 0;
//        }
//        if (root->left == nullptr && root->right == nullptr) {
//            return 1;
//        }
//        return countleaves(root->left) + countleaves(root->right);
//    }
//
//    int getlength() {
//        return getlength(root);
//    }
//
//    int getlength(Node* root) {
//        if (root == nullptr) {
//            return 0;
//        }
//        return 1 + getlength(root->left) + getlength(root->right);
//    }
//
//    void deletenode(char data) {
//        deletenode(root, data);
//    }
//
//    void deletenode(Node*& root, char data) {
//        if (root == nullptr) {
//            cout << "Not found\n";
//            return;
//        }
//        else if (data > root->data)
//            deletenode(root->right, data);
//        else if (data < root->data)
//            deletenode(root->left, data);
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
//                root->data = temp->data;
//                deletenode(root->left, temp->data);
//            }
//        }
//    }
//
//    Node* findMaxFromLeft(Node* node) {
//        while (node && node->right != nullptr)
//            node = node->right;
//        return node;
//    }
//};
//
//
//int main() {
//    BST tree;
//    char ch;
//    
//    for (int i = 0; i < 10; i++)
//    {
//        cout << "ENTER : ";
//        cin >> ch;
//        tree.insert(ch);
//    }
//
//
//
//
//    cout << "Inorder: ";
//    tree.inorder();
//
//    cout << "Preorder : ";
//    tree.preorder();
//
//    cout << "Postorder : ";
//    tree.postorder();
//
//
//    cout << " leaf nodes= " << tree.countleaves() << endl;
//
//   
//    cout << "Length of tree: " << tree.getlength() << endl;
//
//
//    cout << "Searching for node 'G': ";
//    tree.search('G');
//
// 
//    cout << "Deleting node 'D':" << endl;
//    tree.deletenode('D');
//    cout << "Inorder traversal after deletion: ";
//    tree.inorder();
//
//    return 0;
//}
