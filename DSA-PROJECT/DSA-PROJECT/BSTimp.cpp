#include <iostream>
using namespace std;

class BNode {
public:
    BNode* left;
    BNode* right;
    string username;

  
    BNode(string s) : username(s), left(nullptr), right(nullptr) {}
};

class BST {
private:
    BNode* root;

   

   
    BNode* insert(BNode* root, string d) {
        if (root == nullptr) {
            return new BNode(d);
        }
        if (d < root->username) {
            root->left = insert(root->left, d);
        }
        else if (d > root->username) {
            root->right = insert(root->right, d);
        }
        else {
            cout << "USERNAME ALREADY EXISTS!... Choose Another username\n";
        }
        return root;
    }

   
    BNode* deleteNode(BNode* root, string d) {
        if (root == nullptr) {
            return root;
        }
        if (d > root->username) {
            root->right = deleteNode(root->right, d);
        }
        else if (d < root->username) {
            root->left = deleteNode(root->left, d);
        }
        else {
            // Node to be deleted found
            if (root->left == nullptr) {
                BNode* temp = root->right;
                delete root;
                return temp;
            }
            else if (root->right == nullptr) {
                BNode* temp = root->left;
                delete root;
                return temp;
            }
            else {
               
                BNode* temp = findMax(root->left);  
                root->username = temp->username;   
                root->left = deleteNode(root->left, temp->username);  
            }
        }
        return root;
    }


    BNode* findMax(BNode* root) {
        while (root->right != nullptr) {
            root = root->right;
        }
        return root;
    }

public:
    bool search(string username) {
        BNode* nodePtr = root;

        while (nodePtr != nullptr) {
            if (nodePtr->username == username) {
                return true;
            }
            else if (username < nodePtr->username) {
                nodePtr = nodePtr->left;
            }
            else {
                nodePtr = nodePtr->right;
            }
        }

        return false;
    }
    BST() : root(nullptr) {}

    
    

 
    void insert(string d) {
        root = insert(root, d);
    }

   
    void deleteNode(string d) {
        root = deleteNode(root, d);
    }

    
    void display(BNode* root) {
        if (root == nullptr) return;
        display(root->left);
        cout << root->username << " ";
        display(root->right);
    }

    
    void display() {
        cout << "Tree (In-order): ";
        display(root);
        cout << endl;
    }
};
