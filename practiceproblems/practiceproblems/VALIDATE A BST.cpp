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
//    void insert(int data) {
//        Node* ptr = new Node(data);
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
//            if (data > current->data) {
//                current = current->right;
//            }
//            else if (data < current->data) {
//                current = current->left;
//            }
//            else {
//                cout << "Cannot insert duplicates\n";
//                return;
//            }
//        }
//
//        if (data > parent->data)
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
//
//    bool validateBST(Node* root,int min,int max) {
//    
//        if (root ==nullptr)
//        {
//            return true;
//        }
//        if(root->data>=min && root->data<=max)    
//        {
//          bool  left = validateBST(root->left, min, root->data);
//          bool right = validateBST(root->right, root->data, max);
//          return left && right;
//        }else
//        return false;
//
//
//    }
//    bool validateBST() { return validateBST(root,INT16_MIN,INT16_MAX); }
//};
//
//
//int main() {
//    BST tree;
//    int data;
//    
//    for (int i = 0; i < 10; i++)
//    {
//        cout << "ENTER : ";
//        cin >> data;
//        tree.insert(data);
//    }
//  cout<<  tree.validateBST();
//
//
//
//    
//
//    return 0;
//}
